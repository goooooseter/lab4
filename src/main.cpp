#include <iostream>
#include <chrono>
#include "MyVector.hpp"

int main() {
    std::cout << "Move Semantics Performance" << std::endl;
    MyVector a(10000000);

    auto start = std::chrono::high_resolution_clock::now();
    MyVector b = a;
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Copy time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms\n";

    start = std::chrono::high_resolution_clock::now();
    MyVector c = std::move(a);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Move time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms\n\n";

    return 0;
}