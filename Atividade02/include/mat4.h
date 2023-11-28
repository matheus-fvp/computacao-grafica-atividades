#ifndef MAT4_H
#define MAT4_H

#include <iostream>

/**
 * @class mat4
 * @brief A 4x4 matrix class with basic operations.
 */
class mat4 {
public:
    double data[4][4];

    mat4() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                data[i][j] = (i == j) ? 1.0 : 0.0;
            }
        }
    }

    mat4(double a, double b, double c, double d, double e, double f, double g, double h, double i, double j, double k, double l, double m, double n, double o, double p) {
        data[0][0] = a; data[0][1] = b; data[0][2] = c; data[0][3] = d;
        data[1][0] = e; data[1][1] = f; data[1][2] = g; data[1][3] = h;
        data[2][0] = i; data[2][1] = j; data[2][2] = k; data[2][3] = l;
        data[3][0] = m; data[3][1] = n; data[3][2] = o; data[3][3] = p;
    }

    /**
     * @brief Overloaded assignment operator for addition.
     * @param other The matrix to be added.
     * @return Reference to the modified matrix.
     */
    mat4& operator+=(const mat4& other) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
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
    mat4& operator*=(double scalar) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
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
    mat4& operator/=(double scalar) {
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
inline std::ostream& operator<<(std::ostream& out, const mat4& m) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
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
inline bool operator==(const mat4 &m1, const mat4 &m2) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
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
inline mat4 operator+(const mat4& a, const mat4& b) {
    mat4 result;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
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
inline mat4 operator-(const mat4& a, const mat4& b) {
    mat4 result;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
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
inline mat4 operator*(const mat4& a, const mat4& b) {
    mat4 result;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            double sum = 0.0;
            for (int k = 0; k < 4; k++) {
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
inline mat4 operator*(const mat4& a, double scalar) {
    mat4 result;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
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
inline mat4 operator*(double scalar, const mat4& a) {
    return a * scalar;
}

/**
 * @brief Overloaded division operator for scalar division (matrix / scalar).
 * @param a The matrix.
 * @param scalar The scalar value.
 * @return The resulting matrix after scalar division.
 */
inline mat4 operator/(const mat4& a, double scalar) {
    return a * (1.0 / scalar);
}

/**
 * @brief Transposes the given matrix.
 * @param m The matrix to be transposed.
 * @return The transposed matrix.
 */
inline mat4 transpose(const mat4& m) {
    mat4 result;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result[i][j] = m[j][i];
        }
    }
    return result;
}

#endif