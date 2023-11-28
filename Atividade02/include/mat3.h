#ifndef MAT3_H
#define MAT3_H

#include <iostream>

/**
 * @class mat3
 * @brief A 3x3 matrix class with basic operations.
 */
class mat3 {
public:
    double data[3][3];

    mat3() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                data[i][j] = (i == j) ? 1.0 : 0.0;
            }
        }
    }

    mat3(double a, double b, double c, double d, double e, double f, double g, double h, double i) {
        data[0][0] = a;
        data[0][1] = b;
        data[0][2] = c;
        data[1][0] = d;
        data[1][1] = e;
        data[1][2] = f;
        data[2][0] = g;
        data[2][1] = h;
        data[2][2] = i;
    }

    /**
     * @brief Overloaded assignment operator for addition.
     * @param other The matrix to be added.
     * @return Reference to the modified matrix.
     */
    mat3& operator+=(const mat3& other) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                data[i][j] += other.data[i][j];
            }
        }
        return *this;
    }

    /**
     * @brief Overloaded assignment operator for scalar multiplication.
     * @param scalar The scalar value to multiply the matrix by.
     * @return Reference to the modified matrix.
     */
    mat3& operator*=(double scalar) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                data[i][j] *= scalar;
            }
        }
        return *this;
    }

    /**
     * @brief Overloaded assignment operator for scalar division.
     * @param scalar The scalar value to divide the matrix by.
     * @return Reference to the modified matrix.
     * @throws Exception if division by zero is attempted.
     */
    mat3& operator/=(double scalar) {
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

// Matrix Utility Functions

/**
 * @brief Overloaded stream insertion operator for matrix output.
 * @param out Output stream.
 * @param m The matrix to be printed.
 * @return Reference to the output stream.
 */
inline std::ostream& operator<<(std::ostream& out, const mat3& m) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            out << m[i][j] << ' ';
        }
        out << '\n';
    }
    return out;
}

/**
 * @brief Overloaded equality operator for matrix comparison.
 * @param m1 The first matrix.
 * @param m2 The second matrix.
 * @return True if the matrices are equal, false otherwise.
 */
inline bool operator==(const mat3 &m1, const mat3 &m2) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
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
inline mat3 operator+(const mat3& a, const mat3& b) {
    mat3 result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
    return result;
}

/**
 * @brief Overloaded subtraction operator for matrix subtraction.
 * @param a The first matrix.
 * @param b The second matrix.
 * @return The resulting matrix after subtraction.
 */
inline mat3 operator-(const mat3& a, const mat3& b) {
    mat3 result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
    return result;
}

/**
 * @brief Overloaded multiplication operator for matrix multiplication.
 * @param a The first matrix.
 * @param b The second matrix.
 * @return The resulting matrix after multiplication.
 */
inline mat3 operator*(const mat3& a, const mat3& b) {
    mat3 result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            double sum = 0.0;
            for (int k = 0; k < 3; k++) {
                sum += a[i][k] * b[k][j];
            }
            result[i][j] = sum;
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
inline mat3 operator*(const mat3& a, double scalar) {
    mat3 result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = a[i][j] * scalar;
        }
    }
    return result;
}

/**
 * @brief Overloaded multiplication operator for scalar multiplication (scalar * matrix).
 * @param scalar The scalar value.
 * @param a The matrix.
 * @return The resulting matrix after scalar multiplication.
 */
inline mat3 operator*(double scalar, const mat3& a) {
    return a * scalar;
}

/**
 * @brief Overloaded division operator for scalar division (matrix / scalar).
 * @param a The matrix.
 * @param scalar The scalar value.
 * @return The resulting matrix after scalar division.
 */
inline mat3 operator/(const mat3& a, double scalar) {
    return a * (1.0 / scalar);
}

/**
 * @brief Transposes the given matrix.
 * @param m The matrix to be transposed.
 * @return The transposed matrix.
 */
inline mat3 transpose(const mat3& m) {
    mat3 result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = m[j][i];
        }
    }
    return result;
}

#endif