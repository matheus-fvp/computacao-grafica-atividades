#ifndef MAT3_H
#define MAT3_H

#include <iostream>

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

    mat3& operator+=(const mat3& other) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                data[i][j] += other.data[i][j];
            }
        }
        return *this;
    }

    mat3& operator*=(double scalar) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                data[i][j] *= scalar;
            }
        }
        return *this;
    }

    mat3& operator/=(double scalar) {
        return *this *= (1.0 / scalar);
    }

    double* operator[](int i) {
        return data[i];
    }

    const double* operator[](int i) const {
        return data[i];
    }
};

// Matrix Utility Functions

inline std::ostream& operator<<(std::ostream& out, const mat3& m) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            out << m[i][j] << ' ';
        }
        out << '\n';
    }
    return out;
}

inline bool operator==(const mat3 &m1, const mat3 &m2) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(m1[i][j] != m2[i][j]) return false;
        }
    }  
    return true;
}

inline mat3 operator+(const mat3& a, const mat3& b) {
    mat3 result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
    return result;
}

inline mat3 operator-(const mat3& a, const mat3& b) {
    mat3 result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
    return result;
}

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

inline mat3 operator*(const mat3& a, double scalar) {
    mat3 result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = a[i][j] * scalar;
        }
    }
    return result;
}

inline mat3 operator*(double scalar, const mat3& a) {
    return a * scalar;
}

inline mat3 operator/(const mat3& a, double scalar) {
    return a * (1.0 / scalar);
}

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