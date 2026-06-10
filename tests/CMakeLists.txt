add_executable(armforge_unit_smoke
    unit/test_smoke.cpp
)
target_link_libraries(armforge_unit_smoke PRIVATE ArmForge::armforge)
target_compile_options(armforge_unit_smoke PRIVATE ${ARMFORGE_WARNINGS})
add_test(NAME armforge_unit_smoke COMMAND armforge_unit_smoke)

add_executable(armforge_integration_api
    integration/test_api.cpp
)
target_link_libraries(armforge_integration_api PRIVATE ArmForge::armforge)
target_compile_options(armforge_integration_api PRIVATE ${ARMFORGE_WARNINGS})
add_test(NAME armforge_integration_api COMMAND armforge_integration_api)

