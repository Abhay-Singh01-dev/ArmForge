cmake_minimum_required(VERSION 3.21)

project(
    ArmForge
    VERSION 0.1.0
    DESCRIPTION "ArmForge optimization repository scaffold for AWS Graviton4"
    LANGUAGES CXX
)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(CTest)
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)
include(ProjectOptions)

armforge_setup_options()
include(CompilerWarnings)

add_library(armforge STATIC
    src/armforge.cpp
    src/attention.cpp
    src/gemm.cpp
    src/dispatch/dispatch.cpp
    src/kernels/kernels_stub.cpp
    src/packing/packing_stub.cpp
    src/validation/validation.cpp
)

add_library(ArmForge::armforge ALIAS armforge)

target_include_directories(armforge
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_features(armforge PUBLIC cxx_std_17)
target_compile_definitions(armforge PRIVATE ARMFORGE_BUILDING_LIBRARY=1)
target_compile_options(armforge PRIVATE ${ARMFORGE_WARNINGS})
set_target_properties(armforge PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    OUTPUT_NAME armforge
)

if(ARMFORGE_ENABLE_LTO)
    include(CheckIPOSupported)
    check_ipo_supported(RESULT armforge_ipo_supported OUTPUT armforge_ipo_output)
    if(armforge_ipo_supported)
        set_property(TARGET armforge PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
    else()
        message(WARNING "IPO/LTO requested but not supported: ${armforge_ipo_output}")
    endif()
endif()

install(
    TARGETS armforge
    EXPORT ArmForgeTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(
    DIRECTORY include/armforge
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/ArmForgeConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/ArmForgeConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/ArmForgeConfig.cmake"
    INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/ArmForge"
)

install(
    FILES
        "${CMAKE_CURRENT_BINARY_DIR}/ArmForgeConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/ArmForgeConfigVersion.cmake"
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/ArmForge"
)

install(
    EXPORT ArmForgeTargets
    NAMESPACE ArmForge::
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/ArmForge"
)

if(ARMFORGE_BUILD_BENCHMARKS)
    add_subdirectory(benchmarks)
endif()

if(BUILD_TESTING AND ARMFORGE_BUILD_TESTS)
    add_subdirectory(tests)
endif()
