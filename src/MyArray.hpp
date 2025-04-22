#pragma once

#include <cstddef>
#include <stdexcept>

template<typename T, std::size_t N>
class MyArray {
public:
    T& operator[](std::size_t index) {
        if (index >= N) throw std::out_of_range("Index out of range");
        return data[index];
    }

    const T& operator[](std::size_t index) const {
        if (index >= N) throw std::out_of_range("Index out of range");
        return data[index];
    }

    std::size_t size() const { return N; }

private:
    T data[N];
};