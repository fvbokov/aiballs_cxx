cmake_minimum_required(VERSION 3.17.0)
project(aiballs)

#find_package(...)
find_package(Threads REQUIRED)
#find_package(Boost REQUIRED)
#find_package(nlohmann_json CONFIG REQUIRED)
find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)

add_executable(application)
file(GLOB_RECURSE applicationSources 
    LIST_DIRECTORIES true 
    CONFIGURE_DEPENDS
    "src/*.cpp"
)
target_sources(application PRIVATE ${applicationSources})
target_include_directories(application PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_compile_features(application PRIVATE cxx_std_20)
set_target_properties(application PROPERTIES
	MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"
)
#target_link_libraries(application PRIVATE ...)
target_link_libraries(application PRIVATE Threads::Threads)
#target_link_libraries(application PRIVATE ${Boost_LIBRARIES})
target_link_libraries(application PRIVATE sfml-system sfml-network sfml-graphics sfml-window)
#target_link_libraries(application PRIVATE nlohmann_json::nlohmann_json)

install(TARGETS application)
