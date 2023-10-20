#include "mat4.h"
#include <iostream>
#include <cassert>

using namespace std;

void test_division_by_escalar() {
    mat4 m(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
    double value = 2;
    mat4 result(0.5, 1, 1.5, 2.0, 2.5, 3, 3.5, 4, 4.5, 5, 5.5, 6, 6.5, 7, 7.5, 8);
    assert(m / value == result);
    m /= value;
    assert(m == result);
}

void test_multiply_by_escalar() {
    mat4 m(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
    double value = 2;
    mat4 result(2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32);
    assert(m * value == result);
    m *= value;
    assert(m == result);
}

void test_addition_operator() {
    mat4 m1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, -14, 15, -16);
    mat4 m2(16, 15, 14, 13, 11, 12, 10, 9, 8, 7, 6, 5, -4, -3, -2, -1);
    mat4 result(17, 17, 17, 17, 16, 18, 17, 17, 17, 17, 17, 17, 9, -17, 13, -17);
    assert((m1 + m2) == result);
}

void test_subtraction_operator() {
    mat4 m1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, -14, 15, -16);
    mat4 m2(16, 15, 14, 13, 11, 12, 10, 9, 8, 7, 6, 5, -4, -3, -2, -1);
    mat4 result(-15, -13, -11, -9, -6, -6, -3, -1, 1, 3, 5, 7, 17, -11, 17, -15);
    assert((m1 - m2) == result);
}

void test_multiply_operator() {
    mat4 m1(1, 2, 3, 4, -5, -6, -7, -8, 9, 10, 11, 12, 13, 14, 15, 16);
    mat4 m2(16, 15, 14, 13, -12, -11, -10, -9, 8, 7, 6, 5, -4, -3, -2, -1);
    mat4 m1multiplym2(0, 2, 4, 6, -32, -34, -36, -38, 64, 66, 68, 70, 96, 98, 100, 102);
    assert(m1 * m2 == m1multiplym2);
}

void test_transpose_operator() {
    mat4 m(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
    mat4 mTranspose(1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15, 4, 8, 12, 16);
    assert(transpose(m) == mTranspose);
}


int main() {
    test_multiply_by_escalar();
    test_division_by_escalar();
    test_addition_operator();
    test_subtraction_operator();
    test_multiply_operator();
    test_transpose_operator();
    cout << "All tests passed!" << endl;
    return 0;
}