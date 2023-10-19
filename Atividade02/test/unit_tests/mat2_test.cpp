#include "mat2.h"
#include <iostream>
#include <cassert>

using namespace std;

void test_division_by_escalar() {
    mat2 m(1, 2, 3, 4);
    double value = 2;
    mat2 result(0.5, 1, 1.5, 2.0);
    assert(m / value == result);
    m /= value;
    assert(m == result);
}

void test_multiply_by_escalar() {
    mat2 m(1, 2, 3, 4);
    double value = 2;
    mat2 result(2, 4, 6, 8);
    assert(m * value == result);
    m *= value;
    assert(m == result);
}

void test_addition_operator() {
    mat2 m1(3, 4, 5, 6);
    mat2 m2(7, 8, 9, 10);
    mat2 result(10, 12, 14, 16);
    assert((m1 + m2) == result);
}

void test_subtraction_operator() {
    mat2 m1(3, 4, 5, 6);
    mat2 m2(7, 8, 9, -10);
    mat2 result(-4, -4, -4, 16);
    assert((m1 - m2) == result);
}

void test_multiply_operator() {
    mat2 m1(2, 3, 5, 0);
    mat2 m2(-4, 1, 2, 6);
    mat2 m1multiplym2(-2, 20, -20, 5);
    mat2 m2multiplym1(-3, -12, 34, 6);
    assert(m1 * m2 == m1multiplym2);
    assert(m2 * m1 == m2multiplym1);
}

void test_transpose_operator() {
    mat2 m(2, 3, 1, -5);
    mat2 mTranspose(2, 1, 3, -5);
    assert(transpose(m) == mTranspose);
}

void test_inverse_operator() {
    mat2 mIdentity;
    cout << mIdentity << endl;
    mat2 m(2, 4, 1, 5);
    mat2 mInverse(5.0/6, -4.0/6, -1.0/6, 2.0/6);
    mat2 result = inverse(m);
    assert(mInverse == result);
}


int main() {
    test_multiply_by_escalar();
    test_division_by_escalar();
    test_addition_operator();
    test_subtraction_operator();
    test_multiply_operator();
    test_transpose_operator();
    test_inverse_operator();
    cout << "All tests passed!" << endl;
    return 0;
}