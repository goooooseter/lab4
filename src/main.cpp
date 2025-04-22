#include <iostream>
#include <chrono>
#include "MyVector.hpp"
#include "utils.hpp"
#include <string>
#include <vector>
#include <list>
#include <set>
#include "MyArray.hpp"


int main() {
    std::cout << "Move Semantics Performance" << std::endl;
    MyVector a(100000000);

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


    std::cout << "Template Class MyArray" << std::endl;
    MyArray<int, 5> arr1;
    for (int i = 0; i < arr1.size(); ++i) arr1[i] = i * i;
    for (int i = 0; i < arr1.size(); ++i) std::cout << arr1[i] << " ";
    std::cout << std::endl;

    MyArray<std::string, 3> arr2;
    arr2[0] = "one"; arr2[1] = "two"; arr2[2] = "three";
    for (int i = 0; i < arr2.size(); ++i) std::cout << arr2[i] << " ";
    std::cout << std::endl;

    return 0;
}