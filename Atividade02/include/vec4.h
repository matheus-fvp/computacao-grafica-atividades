#ifndef VEC4_H
#define VEC4_H

#include <cmath>
#include <iostream>

using std::sqrt;

/**
 * @class vec4
 * @brief A 4D vector class with basic operations.
 */
class vec4 {
public:
    double e[4]; /**< Array to store the vector components. */

    vec4() : e{0, 0, 0, 0} {}
    vec4(double e0, double e1, double e2, double e3) : e{e0, e1, e2, e3} {}

    /**
     * @brief Accessor for the first component of the vector.
     * @return The value of the first component.
     */
    double x() const { return e[0]; }

    /**
     * @brief Accessor for the second component of the vector.
     * @return The value of the second component.
     */
    double y() const { return e[1]; }

    /**
     * @brief Accessor for the third component of the vector.
     * @return The value of the third component.
     */
    double z() const { return e[2]; }

    /**
     * @brief Accessor for the fourth component of the vector.
     * @return The value of the fourth component.
     */
    double w() const { return e[3]; }

    /**
     * @brief Overloaded negation operator.
     * @return A new vector with negated components.
     */
    vec4 operator-() const { return vec4(-e[0], -e[1], -e[2], -e[3]); }

    /**
     * @brief Overloaded subscript operator for read-only access to vector components.
     * @param i Index of the component (0 to 3).
     * @return The value of the specified component.
     */
    double operator[](int i) const { return e[i]; }

    /**
     * @brief Overloaded subscript operator for read-write access to vector components.
     * @param i Index of the component (0 to 3).
     * @return Reference to the specified component.
     */
    double& operator[](int i) { return e[i]; }

    /**
     * @brief Overloaded compound assignment operator for vector addition.
     * @param v The vector to be added.
     * @return Reference to the modified vector.
     */
    vec4& operator+=(const vec4 &v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        e[3] += v.e[3];
        return *this;
    }

    /**
     * @brief Overloaded compound assignment operator for scalar multiplication.
     * @param t The scalar value to multiply the vector by.
     * @return Reference to the modified vector.
     */
    vec4& operator*=(double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        e[3] *= t;
        return *this;
    }

    /**
     * @brief Overloaded compound assignment operator for scalar division.
     * @param t The scalar value to divide the vector by.
     * @return Reference to the modified vector.
     */
    vec4& operator/=(double t) {
        return *this *= 1/t;
    }

    /**
     * @brief Calculates the length (magnitude) of the vector.
     * @return The length of the vector.
     */
    double length() const {
        return sqrt(length_squared());
    }

    /**
     * @brief Calculates the squared length of the vector.
     * @return The squared length of the vector.
     */
    double length_squared() const {
        return e[0] * e[0] + e[1] * e[1] + e[2] * e[2] + e[3] * e[3];
    }
};

/** Alias for a 4D point using the vec4 class. */
using point4 = vec4;

/**
 * @brief Overloaded stream insertion operator for vector output.
 * @param out Output stream.
 * @param v The vector to be printed.
 * @return Reference to the output stream.
 */
inline std::ostream& operator<<(std::ostream &out, const vec4 &v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2] << ' ' << v.e[3];
}

/**
 * @brief Overloaded addition operator for vector addition.
 * @param u The first vector.
 * @param v The second vector.
 * @return The resulting vector after addition.
 */
inline vec4 operator+(const vec4 &u, const vec4 &v) {
    return vec4(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2], u.e[3] + v.e[3]);
}

/**
 * @brief Overloaded subtraction operator for vector subtraction.
 * @param u The first vector.
 * @param v The second vector.
 * @return The resulting vector after subtraction.
 */
inline vec4 operator-(const vec4 &u, const vec4 &v) {
    return vec4(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2], u.e[3] - v.e[3]);
}

/**
 * @brief Overloaded multiplication operator for component-wise vector multiplication.
 * @param u The first vector.
 * @param v The second vector.
 * @return The resulting vector after multiplication.
 */
inline vec4 operator*(const vec4 &u, const vec4 &v) {
    return vec4(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2], u.e[3] * v.e[3]);
}

/**
 * @brief Overloaded multiplication operator for scalar multiplication (vector * scalar).
 * @param t The scalar value.
 * @param v The vector.
 * @return The resulting vector after scalar multiplication.
 */
inline vec4 operator*(double t, const vec4 &v) {
    return vec4(t * v.e[0], t * v.e[1], t * v.e[2], t * v.e[3]);
}

/**
 * @brief Overloaded multiplication operator for scalar multiplication (scalar * vector).
 * @param v The vector.
 * @param t The scalar value.
 * @return The resulting vector after scalar multiplication.
 */
inline vec4 operator*(const vec4 &v, double t) {
    return t * v;
}

/**
 * @brief Overloaded division operator for scalar division (vector / scalar).
 * @param v The vector.
 * @param t The scalar value.
 * @return The resulting vector after scalar division.
 */
inline vec4 operator/(vec4 v, double t) {
    return (1/t) * v;
}

/**
 * @brief Calculates the dot product of two vectors.
 * @param u The first vector.
 * @param v The second vector.
 * @return The dot product of the two vectors.
 */
inline double dot(const vec4 &u, const vec4 &v) {
    return u.e[0] * v.e[0] + u.e[1] * v.e[1] + u.e[2] * v.e[2] + u.e[3] * v.e[3];
}

/**
 * @brief Calculates the unit vector of the given vector.
 * @param v The vector.
 * @return The unit vector of the given vector.
 */
inline vec4 unit_vector(vec4 v) {
    return v / v.length();
}

#endif