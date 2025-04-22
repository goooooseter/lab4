#pragma once

#include <sstream>
#include <string>
#include <iterator>

template<typename T>
void mySwap(T& a, T& b) {
    T temp = std::move(a);
    a = std::move(b);
    b = std::move(temp);
}

template<typename Container>
std::string container_to_string(const Container& c) {
    std::ostringstream oss;
    oss << "{";
    for (auto it = c.begin(); it != c.end(); ++it) {
        oss << *it;
        if (std::next(it) != c.end()) oss << ", ";
    }
    oss << "}";
    return oss.str();
}
