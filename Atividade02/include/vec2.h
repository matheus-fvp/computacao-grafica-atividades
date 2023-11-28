#ifndef VEC2_H
#define VEC2_H

#include <cmath>
#include <iostream>

using std::sqrt;

/**
 * @class vec2
 * @brief A 2D vector class with basic operations.
 */
class vec2 {
public:
    double e[2];

    vec2() : e{0, 0} {}
    vec2(double e0, double e1) : e{e0, e1} {}

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
     * @brief Overloaded negation operator.
     * @return A new vector with negated components.
     */
    vec2 operator-() const { return vec2(-e[0], -e[1]); }

    /**
     * @brief Overloaded subscript operator for read-only access to vector components.
     * @param i Index of the component (0 or 1).
     * @return The value of the specified component.
     */
    double operator[](int i) const { return e[i]; }

    /**
     * @brief Overloaded subscript operator for read-write access to vector components.
     * @param i Index of the component (0 or 1).
     * @return Reference to the specified component.
     */
    double& operator[](int i) { return e[i]; }

    /**
     * @brief Overloaded compound assignment operator for vector addition.
     * @param v The vector to be added.
     * @return Reference to the modified vector.
     */
    vec2& operator+=(const vec2 &v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        return *this;
    }

    /**
     * @brief Overloaded compound assignment operator for scalar multiplication.
     * @param t The scalar value to multiply the vector by.
     * @return Reference to the modified vector.
     */
    vec2& operator*=(double t) {
        e[0] *= t;
        e[1] *= t;
        return *this;
    }

    /**
     * @brief Overloaded compound assignment operator for scalar division.
     * @param t The scalar value to divide the vector by.
     * @return Reference to the modified vector.
     */
    vec2& operator/=(double t) {
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
        return e[0] * e[0] + e[1] * e[1];
    }
};

/** Alias for a 2D point using the vec2 class. */
using point2 = vec2;

/**
 * @brief Overloaded equality operator for vector comparison.
 * @param u The first vector.
 * @param v The second vector.
 * @return True if the vectors are equal, false otherwise.
 */
inline bool operator==(const vec2 &u, const vec2 &v) {
    return u.x() == v.x() && u.y() == v.y();  
}

/**
 * @brief Overloaded stream insertion operator for vector output.
 * @param out Output stream.
 * @param v The vector to be printed.
 * @return Reference to the output stream.
 */
inline std::ostream& operator<<(std::ostream &out, const vec2 &v) {
    return out << v.e[0] << ' ' << v.e[1];
}

/**
 * @brief Overloaded addition operator for vector addition.
 * @param u The first vector.
 * @param v The second vector.
 * @return The resulting vector after addition.
 */
inline vec2 operator+(const vec2 &u, const vec2 &v) {
    return vec2(u.e[0] + v.e[0], u.e[1] + v.e[1]);
}

/**
 * @brief Overloaded subtraction operator for vector subtraction.
 * @param u The first vector.
 * @param v The second vector.
 * @return The resulting vector after subtraction.
 */
inline vec2 operator-(const vec2 &u, const vec2 &v) {
    return vec2(u.e[0] - v.e[0], u.e[1] - v.e[1]);
}

/**
 * @brief Overloaded multiplication operator for component-wise vector multiplication.
 * @param u The first vector.
 * @param v The second vector.
 * @return The resulting vector after multiplication.
 */
inline vec2 operator*(const vec2 &u, const vec2 &v) {
    return vec2(u.e[0] * v.e[0], u.e[1] * v.e[1]);
}

/**
 * @brief Overloaded multiplication operator for scalar multiplication (vector * scalar).
 * @param t The scalar value.
 * @param v The vector.
 * @return The resulting vector after scalar multiplication.
 */
inline vec2 operator*(double t, const vec2 &v) {
    return vec2(t * v.e[0], t * v.e[1]);
}

/**
 * @brief Overloaded multiplication operator for scalar multiplication (scalar * vector).
 * @param v The vector.
 * @param t The scalar value.
 * @return The resulting vector after scalar multiplication.
 */
inline vec2 operator*(const vec2 &v, double t) {
    return t * v;
}

/**
 * @brief Overloaded division operator for scalar division (vector / scalar).
 * @param v The vector.
 * @param t The scalar value.
 * @return The resulting vector after scalar division.
 */
inline vec2 operator/(vec2 v, double t) {
    return (1/t) * v;
}

/**
 * @brief Calculates the dot product of two vectors.
 * @param u The first vector.
 * @param v The second vector.
 * @return The dot product of the two vectors.
 */
inline double dot(const vec2 &u, const vec2 &v) {
    return u.e[0] * v.e[0] + u.e[1] * v.e[1];
}

/**
 * @brief Calculates the unit vector of the given vector.
 * @param v The vector.
 * @return The unit vector of the given vector.
 */
inline vec2 unit_vector(vec2 v) {
    return v / v.length();
}

#endif





