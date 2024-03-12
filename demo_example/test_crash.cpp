#include "async_simple/coro/Generator.h"

#include <iostream>
#include <string>

using async_simple::coro::Generator;

Generator<int> impl() {
    co_yield 1;
    co_yield 2;
    co_yield 3;
}

Generator<int> ints() {
    for (int i : impl()) {
      printf("i = %d\n", i);
      co_yield i;
    }
}

int main() {
    for (auto x : ints()) {
        std::cout << x << std::endl;
    }
    return 0;
}