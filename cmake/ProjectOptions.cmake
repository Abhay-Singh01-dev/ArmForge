function(armforge_setup_options)
    option(ARMFORGE_BUILD_TESTS "Build ArmForge tests" ON)
    option(ARMFORGE_BUILD_BENCHMARKS "Build ArmForge benchmark stubs" OFF)
    option(ARMFORGE_WARNINGS_AS_ERRORS "Treat compiler warnings as errors" OFF)
    option(ARMFORGE_ENABLE_LTO "Enable interprocedural optimization when supported" OFF)
endfunction()

