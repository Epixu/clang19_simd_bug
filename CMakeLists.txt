cmake_minimum_required(VERSION 3.28)
project(bug)
include(FetchContent)

FetchContent_Declare(
    SIMDe
    GIT_REPOSITORY  https://github.com/simd-everywhere/simde.git
    GIT_TAG         f47e3c5c9ecbea85b4f802e07feebab113c837cd
    SOURCE_DIR      "${CMAKE_SOURCE_DIR}/SIMDe-src"
    SUBBUILD_DIR    "${CMAKE_BINARY_DIR}/SIMDe-subbuild"
	EXCLUDE_FROM_ALL
)
FetchContent_MakeAvailable(SIMDe)

# Build and install SIMD library                                            
add_executable(bug Main.cpp)

if(MSVC)
	# Some SVML functions seem to be broken on x86 MSVC builds				
	# See https://github.com/simd-everywhere/simde/issues/1111				
    target_compile_options(bug INTERFACE -DSIMDE_X86_SVML_NO_NATIVE)
endif()

target_include_directories(bug PUBLIC "${CMAKE_SOURCE_DIR}/SIMDe-src")

enable_testing()
add_test(NAME bug COMMAND bug)
