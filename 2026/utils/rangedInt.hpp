#ifndef RANGED
#define RANGED

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>


class rangedInt {
private:
    int min_val;
    int max_val;
    int value;
    int clamp(int v) {
        if (v < min_val) return min_val;
        if (v > max_val) return max_val;
        return v;
    }
public:
    rangedInt(int v, int minv, int maxv)
        : min_val(minv), max_val(maxv), value(clamp(v)) {}

    // Assignment
    rangedInt& operator=(int v) {
        value = clamp(v);
        return *this;
    }

    // Addition
    rangedInt& operator+=(int v) {
        value = clamp(value + v);
        return *this;
    }

    // Subtraction
    rangedInt& operator-=(int v) {
        value = clamp(value - v);
        return *this;
    }

    // Implicit conversion to int
    operator int() const { return value; }
};

#endif