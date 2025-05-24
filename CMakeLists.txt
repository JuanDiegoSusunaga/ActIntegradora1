cmake_minimum_required(VERSION 3.30)

project(sonarqube_unit_test VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(${CMAKE_SOURCE_DIR})

# Solo archivos fuente reales (.cpp, .h)
set(SOURCES
    main.cpp
)

add_executable(main ${SOURCES})

# Opciones
option(ENABLE_TESTING "Enable a Unit Testing build." ON)
option(ENABLE_COVERAGE "Enable coverage reporting" ON)

# Flags de cobertura
if (ENABLE_COVERAGE)
    message(STATUS "Enabling coverage flags for GCC/Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -fprofile-arcs -ftest-coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif()

# Copiar archivos necesarios al build dir
configure_file(${CMAKE_SOURCE_DIR}/transmission1.txt ${CMAKE_BINARY_DIR}/transmission1.txt COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/transmission2.txt ${CMAKE_BINARY_DIR}/transmission2.txt COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/mcode1.txt ${CMAKE_BINARY_DIR}/mcode1.txt COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/mcode2.txt ${CMAKE_BINARY_DIR}/mcode2.txt COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/mcode3.txt ${CMAKE_BINARY_DIR}/mcode3.txt COPYONLY)

# GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.11.0
)
FetchContent_MakeAvailable(googletest)

if(ENABLE_TESTING)
    enable_testing()

    function(add_test_executable name source)
        add_executable(${name} ${source})
        target_link_libraries(${name} PRIVATE gtest gtest_main)
        if (ENABLE_COVERAGE)
            target_link_libraries(${name} PRIVATE gcov)
            target_compile_options(${name} PRIVATE --coverage -fprofile-arcs -ftest-coverage)
            target_link_options(${name} PRIVATE --coverage)
        endif()
        add_test(NAME ${name} COMMAND ${name})
    endfunction()

    # Tests
    add_test_executable(BuscarSubcadenaTest tests/test_buscarSubcadena.cpp)
    add_test_executable(ExpandirCentroTest tests/test_expandirCentro.cpp)
    add_test_executable(LCSTest tests/test_lcs.cpp)
    add_test_executable(LeerArchivoTest tests/test_leerArchivo.cpp)
    add_test_executable(PalindromoMasLargoTest tests/test_palindromoMasLargo.cpp)

    # Cobertura
    if (ENABLE_COVERAGE)
        find_program(LCOV lcov)
        if (LCOV)
            add_custom_target(coverage
                COMMAND lcov --capture --directory . --output-file build/coverage.info
                COMMAND genhtml build/coverage.info --output-directory build/coverage_html
                COMMENT "Generating code coverage report"
                VERBATIM
            )
        else()
            message(WARNING "LCOV not found, coverage reporting will not be available")
        endif()
    endif()
endif()
