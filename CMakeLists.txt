cmake_minimum_required(VERSION 3.31.6)
project(safeheap_project C)

# Set C standard
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

include_directories(${CMAKE_SOURCE_DIR})

set(SAFEHEAP_SOURCES
    core/memory/memory.c
    core/secure/secure.c
    core/secure/fragmentation/fragmentation.c
    core/secure/object/object.c
    core/secure/wiping/wiping.c
    interface/allocate/allocate.c
)

add_library(safeheap STATIC ${SAFEHEAP_SOURCES})

add_executable(test_safeheap tests/test.c)
target_link_libraries(test_safeheap safeheap)

enable_testing()
add_test(NAME safeheap_tests COMMAND test_safeheap)