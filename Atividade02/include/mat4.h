#ifndef MAT4_H
#define MAT4_H

#include <iostream>

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

    mat4& operator+=(const mat4& other) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                data[i][j] += other.data[i][j];
            }
        }
        return *this;
    }

    mat4& operator*=(double scalar) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                data[i][j] *= scalar;
            }
        }
        return *this;
    }

    mat4& operator/=(double scalar) {
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

inline std::ostream& operator<<(std::ostream& out, const mat4& m) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            out << m[i][j] << ' ';
        }
        out << '\n';
    }
    return out;
}

inline bool operator==(const mat4 &m1, const mat4 &m2) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(m1[i][j] != m2[i][j]) return false;
        }
    }  
    return true;
}

inline mat4 operator+(const mat4& a, const mat4& b) {
    mat4 result;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
    return result;
}

inline mat4 operator-(const mat4& a, const mat4& b) {
    mat4 result;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
    return result;
}

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

inline mat4 operator*(const mat4& a, double scalar) {
    mat4 result;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result[i][j] = a[i][j] * scalar;
        }
    }
    return result;
}

inline mat4 operator*(double scalar, const mat4& a) {
    return a * scalar;
}

inline mat4 operator/(const mat4& a, double scalar) {
    return a * (1.0 / scalar);
}

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