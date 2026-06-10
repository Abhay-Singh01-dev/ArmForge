add_executable(armforge_benchmark_stub
    benchmark_stub.cpp
)
target_link_libraries(armforge_benchmark_stub PRIVATE ArmForge::armforge)
target_compile_options(armforge_benchmark_stub PRIVATE ${ARMFORGE_WARNINGS})

