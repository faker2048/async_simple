file(GLOB coro_test_src "*.cpp")

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" AND
    CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL "15.0" AND
    CMAKE_CXX_COMPILER_VERSION VERSION_LESS "16.0")
    # Clang-15 gives incorrect warnings, See https://github.com/llvm/llvm-project/issues/56768
    # and some issues with Generator https://github.com/alibaba/async_simple/issues/372
    list(REMOVE_ITEM coro_test_src "${CMAKE_CURRENT_SOURCE_DIR}/GeneratorTest.cpp")
endif()

add_executable(async_simple_coro_test ${coro_test_src} ${PROJECT_SOURCE_DIR}/async_simple/test/dotest.cpp)

target_link_libraries(async_simple_coro_test async_simple ${deplibs} ${testdeplibs})

add_test(NAME run_async_simple_coro_test COMMAND async_simple_coro_test)
