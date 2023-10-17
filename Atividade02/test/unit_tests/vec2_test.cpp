#include "vec2.h"
#include <iostream>
#include <cassert>

using namespace std;

void test_default_constructor() {
    vec2 u;
    assert(u.x() == 0.0);
    assert(u.y() == 0.0);
}

void test_parameterized_constructor() {
    vec2 u(3.0, 5.0);
    assert(u.x() == 3.0);
    assert(u.y() == 5.0);
}

void test_negative_operator() {
    vec2 u(2.0, 6.0);
    vec2 negated = -u;
    assert(negated.x() == -2.0);
    assert(negated.y() == -6.0);
}

void test_addition_operator() {
    vec2 v1(4.0, 7.0);
    vec2 v2(2.0, 3.0);
    vec2 result = v1 + v2;
    assert(result.x() == 6.0);
    assert(result.y() == 10.0);
}

void test_subtraction_operator() {
    vec2 v1(1.0, 2.0);
    vec2 v2(2.0, 3.0);
    vec2 result = v1 - v2;
    assert(result.x() == -1.0);
    assert(result.y() == -1.0);
}


void test_multiplication_operator() {
    vec2 v(2.0, 3.0);
    vec2 result = v * 4.0;
    assert(result.x() == 8.0);
    assert(result.y() == 12.0);
}

void test_division_operator() {
    vec2 v(5.0, 8.0);
    vec2 result = v / 2.0;
    assert(result.x() == 2.5);
    assert(result.y() == 4.0);
}

void test_dot_product() {
    vec2 v1(6.0, 2.0);
    vec2 v2(3.0, 4.0);
    double result = dot(v1, v2);
    // The dot product of v1 and v2 should be (6 * 3) + (2 * 4) = 26.0
    assert(result == 26.0);
}

void test_dot_product_with_zero() {
    vec2 v1(-1.0, 1.0);
    vec2 v2(3.0, 3.0);
    double result = dot(v1, v2);
    assert(result == 0.0);
}



int main() {

    test_default_constructor();
    test_parameterized_constructor();
    test_negative_operator();
    test_addition_operator();
    test_subtraction_operator();
    test_multiplication_operator();
    test_division_operator();
    test_dot_product();
    test_dot_product_with_zero();
    cout << "All tests passed!" << endl;
    return 0;
}



