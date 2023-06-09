cmake_minimum_required(VERSION 3.12)
project({{cookiecutter.name}} VERSION {{cookiecutter.version}} LANGUAGES CXX)

file(GLOB_RECURSE lib_sources ./src/*.cpp)

if(${PROJECT_IS_TOP_LEVEL})

    add_library({{cookiecutter.name}} STATIC ${lib_sources})

    install(
        FILES $<TARGET_FILE:{{cookiecutter.name}}>
        DESTINATION lib
        COMPONENT library)
else()
    add_library({{cookiecutter.name}} OBJECT ${lib_sources})

    set_property(GLOBAL APPEND PROPERTY {{cookiecutter.name}}_OBJECTS $<TARGET_OBJECTS:{{cookiecutter.name}}>)

endif()

target_include_directories({{cookiecutter.name}} INTERFACE src)
target_compile_features({{cookiecutter.name}} PUBLIC cxx_std_20)
add_library(loglund::{{cookiecutter.name}} ALIAS {{cookiecutter.name}})

install(
    DIRECTORY ./src/{{cookiecutter.name}}
    DESTINATION include
    COMPONENT headers
    FILES_MATCHING
    PATTERN "*.hpp"
    PATTERN ./src/{{cookiecutter.name}}/detail EXCLUDE
)

add_executable({{cookiecutter.name}}_hello apps/hello_version.cpp)
target_link_libraries({{cookiecutter.name}}_hello {{cookiecutter.name}})

if(${PROJECT_IS_TOP_LEVEL})

    include(FetchContent)
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/b796f7d44681514f58a683a3a71ff17c94edb0c1.zip
    )

    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    enable_testing()

    file(GLOB_RECURSE test_sources test/*.cpp)
    add_executable({{cookiecutter.name}}_tests ${test_sources})

    target_compile_features({{cookiecutter.name}}_tests PUBLIC cxx_std_11)
    target_link_libraries({{cookiecutter.name}}_tests
        {{cookiecutter.name}}
        gtest_main
    )

    include(GoogleTest)
    gtest_discover_tests({{cookiecutter.name}}_tests)

    add_executable({{cookiecutter.name}}_example examples/{{cookiecutter.name}}_example.cpp)
    target_link_libraries({{cookiecutter.name}}_example  {{cookiecutter.name}})
endif()



