#include "mat3.h"
#include <iostream>
#include <cassert>

using namespace std;

void test_division_by_escalar() {
    mat3 m(1, 2, 3, 4, 5, 6, 7, 8, 9);
    double value = 2;
    mat3 result(0.5, 1, 1.5, 2.0, 2.5, 3, 3.5, 4, 4.5);
    assert(m / value == result);
    m /= value;
    assert(m == result);
}

void test_multiply_by_escalar() {
    mat3 m(1, 2, 3, 4, 5, 6, 7, 8, 9);
    double value = 2;
    mat3 result(2, 4, 6, 8, 10, 12, 14, 16, 18);
    assert(m * value == result);
    m *= value;
    assert(m == result);
}

void test_addition_operator() {
    mat3 m1(3, 4, 5, 6, 7, 8, 9, 10, 11);
    mat3 m2(7, 8, 9, 10, 11, -12, 13, 14, -15);
    mat3 result(10, 12, 14, 16, 18, -4, 22, 24, -4);
    assert((m1 + m2) == result);
}

void test_subtraction_operator() {
    mat3 m1(3, 4, 5, 6, 1, 2, 10, 20, 30);
    mat3 m2(7, 8, 9, -10, 20, -4, 5, 10, 100);
    mat3 result(-4, -4, -4, 16, -19, 6, 5, 10, -70);
    assert((m1 - m2) == result);
}

void test_multiply_operator() {
    mat3 m1(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat3 m2(9, 8, 7, 6, 5, 4, 3, 2, 1);
    mat3 m1multiplym2(30, 24, 18, 84, 69, 54, 138, 114, 90);
    mat3 m2multiplym1(90, 114, 138, 54, 69, 84, 18, 24, 30);
    assert(m1 * m2 == m1multiplym2);
    assert(m2 * m1 == m2multiplym1);
}

void test_transpose_operator() {
    mat3 m(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat3 mTranspose(1, 4, 7, 2, 5, 8, 3, 6, 9);
    assert(transpose(m) == mTranspose);
}


int main() {
    test_multiply_by_escalar();
    test_division_by_escalar();
    test_addition_operator();
    test_subtraction_operator();
    test_multiply_operator();
    test_transpose_operator();
    //test_inverse_operator();
    cout << "All tests passed!" << endl;
    return 0;
}