cmake_minimum_required (VERSION 3.14)
set(CRYENGINE_DIR "C:/Program Files (x86)/Crytek/CRYENGINE Launcher/Crytek/CRYENGINE_5.6" CACHE STRING "CRYENGINE root directory.")
set(TOOLS_CMAKE_DIR "${CRYENGINE_DIR}/Tools/CMake")

set(PROJECT_BUILD 1)
set(PROJECT_DIR "${CMAKE_SOURCE_DIR}/../")

include("${TOOLS_CMAKE_DIR}/InitialSetup.cmake")
include("${TOOLS_CMAKE_DIR}/CommonOptions.cmake")

add_subdirectory("${CRYENGINE_DIR}" "${CMAKE_CURRENT_BINARY_DIR}/CRYENGINE")

include("${TOOLS_CMAKE_DIR}/Configure.cmake")

start_sources()

sources_platform(ALL)

add_sources_recursive_search()

end_sources()

CryUnitTestSuite(Crymium.UnitTests)

target_include_directories(${THIS_PROJECT}

PRIVATE
    "${CRYENGINE_DIR}/Code/CryEngine/CryCommon"
    "${CRYENGINE_DIR}/Code/CryEngine/CryAction"
	"../../"
    "../../build/third_party/cef/cef_binary_79.1.27+gd2449e5+chromium-79.0.3945.117_windows64"
	".."
)

target_compile_definitions(${THIS_PROJECT} PRIVATE NOT_USE_CRY_MEMORY_MANAGER)

set_target_properties(Crymium.UnitTests PROPERTIES CXX_STANDARD 17)

target_compile_options(Crymium.UnitTests PRIVATE "/MTd")

target_link_libraries(Crymium.UnitTests PUBLIC Crymium)
target_link_libraries(Crymium.UnitTests PUBLIC gmock)
target_link_libraries(Crymium.UnitTests PUBLIC gmock_main)
target_link_libraries(Crymium.UnitTests PUBLIC gtest)
target_link_libraries(Crymium.UnitTests PUBLIC gtest_main)

SET(CMAKE_CXX_FLAGS "/EHsc")