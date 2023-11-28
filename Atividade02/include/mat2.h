#ifndef MAT2_H
#define MAT2_H

#include <iostream>

using namespace std;

/**
 * @class mat2
 * @brief A 2x2 matrix class with basic operations.
 */
class mat2 {
public:
    double data[2][2];

    //Matriz identidade
    mat2() {
        data[0][0] = 1.0;
        data[0][1] = 0.0;
        data[1][0] = 0.0;
        data[1][1] = 1.0;
    }


    mat2(double a, double b, double c, double d) {
        data[0][0] = a;
        data[0][1] = b;
        data[1][0] = c;
        data[1][1] = d;
    }

    /**
     * @brief Overloaded assignment operator for addition.
     * @param other The matrix to be added.
     * @return Reference to the modified matrix.
     */
    mat2& operator+=(const mat2& other) {
        data[0][0] += other.data[0][0];
        data[0][1] += other.data[0][1];
        data[1][0] += other.data[1][0];
        data[1][1] += other.data[1][1];
        return *this;
    }

    /**
     * @brief Overloaded assignment operator for scalar multiplication.
     * @param scalar The scalar value to multiply the matrix by.
     * @return Reference to the modified matrix.
     */
    mat2& operator*=(double scalar) {
        data[0][0] *= scalar;
        data[0][1] *= scalar;
        data[1][0] *= scalar;
        data[1][1] *= scalar;
        return *this;
    }

    /**
     * @brief Overloaded assignment operator for scalar division.
     * @param scalar The scalar value to divide the matrix by.
     * @return Reference to the modified matrix.
     * @throws Exception if division by zero is attempted.
     */
    mat2& operator/=(double scalar) {
        if(scalar == 0) throw "Division by zero"; 
        return *this *= (1.0 / scalar);
    }

    /**
     * @brief Overloaded subscript operator for element access.
     * @param i Row index.
     * @return Pointer to the specified row of the matrix.
     */
    double* operator[](int i) {
        return data[i];
    }

    /**
     * @brief Overloaded const subscript operator for element access.
     * @param i Row index.
     * @return Const pointer to the specified row of the matrix.
     */
    const double* operator[](int i) const {
        return data[i];
    }
};

/**
 * @brief Overloaded stream insertion operator for matrix output.
 * @param out Output stream.
 * @param m The matrix to be printed.
 * @return Reference to the output stream.
 */
inline std::ostream& operator<<(std::ostream& out, const mat2& m) {
    out << m[0][0] << ' ' << m[0][1] << '\n';
    out << m[1][0] << ' ' << m[1][1];
    return out;
}

/**
 * @brief Overloaded equality operator for matrix comparison.
 * @param m1 The first matrix.
 * @param m2 The second matrix.
 * @return True if the matrices are equal, false otherwise.
 */
inline bool operator==(const mat2 &m1, const mat2 &m2) {
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            if(m1[i][j] != m2[i][j]) return false;
        }
    }  
    return true;
}

/**
 * @brief Overloaded addition operator for matrix addition.
 * @param a The first matrix.
 * @param b The second matrix.
 * @return The resulting matrix after addition.
 */
inline mat2 operator+(const mat2& a, const mat2& b) {
    return mat2(a[0][0] + b[0][0], a[0][1] + b[0][1], a[1][0] + b[1][0], a[1][1] + b[1][1]);
}

/**
 * @brief Overloaded subtraction operator for matrix subtraction.
 * @param a The first matrix.
 * @param b The second matrix.
 * @return The resulting matrix after subtraction.
 */
inline mat2 operator-(const mat2& a, const mat2& b) {
    return mat2(a[0][0] - b[0][0], a[0][1] - b[0][1], a[1][0] - b[1][0], a[1][1] - b[1][1]);
}

/**
 * @brief Overloaded multiplication operator for matrix multiplication.
 * @param a The first matrix.
 * @param b The second matrix.
 * @return The resulting matrix after multiplication.
 */
inline mat2 operator*(const mat2& a, const mat2& b) {
    mat2 result;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            result[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
        }
    }
    return result;
}

/**
 * @brief Overloaded multiplication operator for scalar multiplication.
 * @param a The matrix.
 * @param scalar The scalar value.
 * @return The resulting matrix after scalar multiplication.
 */
inline mat2 operator*(const mat2& a, double scalar) {
    return mat2(a[0][0] * scalar, a[0][1] * scalar, a[1][0] * scalar, a[1][1] * scalar);
}

/**
 * @brief Overloaded multiplication operator for scalar multiplication (scalar * matrix).
 * @param scalar The scalar value.
 * @param a The matrix.
 * @return The resulting matrix after scalar multiplication.
 */
inline mat2 operator*(double scalar, const mat2& a) {
    return a * scalar;
}

/**
 * @brief Overloaded division operator for scalar division (matrix / scalar).
 * @param a The matrix.
 * @param scalar The scalar value.
 * @return The resulting matrix after scalar division.
 */
inline mat2 operator/(const mat2& a, double scalar) {
    return a * (1.0 / scalar);
}

/**
 * @brief Transposes the given matrix.
 * @param m The matrix to be transposed.
 * @return The transposed matrix.
 */
inline mat2 transpose(const mat2& m) {
    return mat2(m[0][0], m[1][0], m[0][1], m[1][1]);
}

/**
 * @brief Calculates the inverse of the given matrix.
 * @param m The matrix to be inverted.
 * @return The inverted matrix.
 * @throws Exception if the matrix is singular (non-invertible).
 */
inline mat2 inverse(const mat2& m) {
    mat2 m1(m[1][1], -m[0][1], -m[1][0], m[0][0]);
    double determinant = (m[0][0] * m[1][1]) - (m[0][1] * m[1][0]);
    if(determinant == 0) throw "There is no a inverse matrix";
    return mat2(m1[0][0] / determinant, m1[0][1] / determinant,
    m1[1][0] / determinant, m1[1][1] / determinant);
}

#endif