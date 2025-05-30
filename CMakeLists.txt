cmake_minimum_required(VERSION 3.30)
project(AEDTrabalho C)

set(CMAKE_C_STANDARD 11)

include(FetchContent)
function(include_dependency libName gitURL gitTag)
    FetchContent_Declare(${libName}
        GIT_REPOSITORY ${gitURL}
            GIT_TAG    ${gitTag}
            GIT_SHALLOW TRUE
            GIT_PROGRESS TRUE
    )
    FetchContent_MakeAvailable(${libName})
endfunction()

set(LIB1 raylib)
find_package(${LIB1} QUIET)
if (NOT ${LIB1}_FOUND)
    include_dependency(${LIB1} http://github.com/raysan5/raylib.git 5.0)
endif ()

add_executable(AEDTrabalho main.c)

target_include_directories(AEDTrabalho PRIVATE ${raylib_INCLUDE_DIRS})

target_link_libraries(AEDTrabalho PRIVATE ${LIB1})
