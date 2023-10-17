#include "vec4.h"
#include <iostream>
#include <cassert>

using namespace std;

void test_default_constructor() {
    vec4 u;
    for(int i = 0; i < u.length(); i++) {
        assert(u[i] == 0.0);
    }
}

void test_parameterized_constructor() {
    vec4 u(3.0, 5.0, 4.2, 3.3);
    assert(u[0] == 3.0);
    assert(u[1] == 5.0);
    assert(u[2] == 4.2);
    assert(u[3] == 3.3);
}

void test_negative_operator() {
    vec4 u(2.0, 6.0, 3.0, 5.0);
    vec4 negated = -u;
    assert(negated[0] == -2.0);
    assert(negated[1] == -6.0);
    assert(negated[2] == -3.0);
    assert(negated[3] == -5.0);
}

void test_addition_operator() {
    vec4 v1(4.0, 7.0, 6.0, 2.0);
    vec4 v2(2.0, 3.0, 3.0, 1.0);
    vec4 result = v1 + v2;
    assert(result[0] == 6.0);
    assert(result[1] == 10.0);
    assert(result[2] == 9.0);
    assert(result[3] == 3.0);
}

void test_subtraction_operator() {
    vec4 u(2.0, 3.0, 4.0, 5.0);
    vec4 v(1.0, 2.0, 3.0, 4.0);
    vec4 result = u - v;

    assert(result[0] == 1.0);
    assert(result[1] == 1.0);
    assert(result[2] == 1.0);
    assert(result[3] == 1.0);
}


void test_multiplication_operator() {
    vec4 v(2.0, 3.0, 4.0, 5.0);
    double t = 2.0;

    vec4 result = v * t;

    assert(result[0] == 4.0);
    assert(result[1] == 6.0);
    assert(result[2] == 8.0);
    assert(result[3] == 10.0);
}

void test_division_operator() {
    vec4 v(2.0, 4.0, 6.0, 8.0);
    double t = 2.0;
    vec4 result = v / t;

    assert(result[0] == 1.0);
    assert(result[1] == 2.0);
    assert(result[2] == 3.0);
    assert(result[3] == 4.0);
}

void test_dot_product() {
    vec4 u(1.0, 2.0, 3.0, 4.0);
    vec4 v(2.0, 3.0, 4.0, 5.0);

    double result = dot(u, v);

    assert(result == 40.0);
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
    cout << "All tests passed!" << endl;
    return 0;
}



