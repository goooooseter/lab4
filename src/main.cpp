#include <iostream>
#include <chrono>
#include "MyVector.hpp"
#include "utils.hpp"
#include <string>
#include <vector>
#include <list>
#include <set>


int main() {
    std::cout << "Move Semantics Performance" << std::endl;
    MyVector a(10000000);

    auto start = std::chrono::high_resolution_clock::now();
    MyVector b = a;
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Copy time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    MyVector c = std::move(a);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Move time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;


    std::cout << "Template Function mySwap" << std::endl;
    int x = 1, y = 2;
    mySwap(x, y);
    std::cout << "Swapped ints: " << x << ", " << y << std::endl;

    std::string s1 = "hello", s2 = "world";
    mySwap(s1, s2);
    std::cout << "Swapped strings: " << s1 << ", " << s2 << std::endl;

    std::cout << "Container to String" << std::endl;
    std::vector<int> v = { 1, 2, 3 };
    std::list<std::string> l = { "a", "b", "c" };
    std::set<double> s = { 1.1, 2.2, 3.3 };
    std::cout << container_to_string(v) << std::endl;
    std::cout << container_to_string(l) << std::endl;
    std::cout << container_to_string(s) << std::endl;

    return 0;
}