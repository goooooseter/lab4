#pragma once

#include <iostream>

class MyVector {
public:
    MyVector(size_t s) : size(s), data(new int[s]) {
        std::fill(data, data + size, 0);
    }

    ~MyVector() {
        delete[] data;
    }

    MyVector(const MyVector& other) : size(other.size), data(new int[other.size]) {
        std::copy(other.data, other.data + size, data);
    }

    MyVector& operator=(const MyVector& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            std::copy(other.data, other.data + size, data);
        }
        return *this;
    }

    MyVector(MyVector&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
    }

    MyVector& operator=(MyVector&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }

private:
    int* data = nullptr;
    size_t size = { 0 };
};