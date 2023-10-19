#ifndef MAT2_H
#define MAT2_H

#include <iostream>

using namespace std;

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

    mat2& operator+=(const mat2& other) {
        data[0][0] += other.data[0][0];
        data[0][1] += other.data[0][1];
        data[1][0] += other.data[1][0];
        data[1][1] += other.data[1][1];
        return *this;
    }

    mat2& operator*=(double scalar) {
        data[0][0] *= scalar;
        data[0][1] *= scalar;
        data[1][0] *= scalar;
        data[1][1] *= scalar;
        return *this;
    }

    mat2& operator/=(double scalar) {
        if(scalar == 0) throw "Division by zero"; 
        return *this *= (1.0 / scalar);
    }

    double* operator[](int i) {
        return data[i];
    }

    const double* operator[](int i) const {
        return data[i];
    }
};

inline std::ostream& operator<<(std::ostream& out, const mat2& m) {
    out << m[0][0] << ' ' << m[0][1] << '\n';
    out << m[1][0] << ' ' << m[1][1];
    return out;
}

inline bool operator==(const mat2 &m1, const mat2 &m2) {
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            if(m1[i][j] != m2[i][j]) return false;
        }
    }  
    return true;
}

inline mat2 operator+(const mat2& a, const mat2& b) {
    return mat2(a[0][0] + b[0][0], a[0][1] + b[0][1], a[1][0] + b[1][0], a[1][1] + b[1][1]);
}

inline mat2 operator-(const mat2& a, const mat2& b) {
    return mat2(a[0][0] - b[0][0], a[0][1] - b[0][1], a[1][0] - b[1][0], a[1][1] - b[1][1]);
}

inline mat2 operator*(const mat2& a, const mat2& b) {
    mat2 result;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            result[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
        }
    }
    return result;
}

inline mat2 operator*(const mat2& a, double scalar) {
    return mat2(a[0][0] * scalar, a[0][1] * scalar, a[1][0] * scalar, a[1][1] * scalar);
}

inline mat2 operator*(double scalar, const mat2& a) {
    return a * scalar;
}

inline mat2 operator/(const mat2& a, double scalar) {
    return a * (1.0 / scalar);
}

inline mat2 transpose(const mat2& m) {
    return mat2(m[0][0], m[1][0], m[0][1], m[1][1]);
}

inline mat2 inverse(const mat2& m) {
    mat2 m1(m[1][1], -m[0][1], -m[1][0], m[0][0]);
    double determinant = (m[0][0] * m[1][1]) - (m[0][1] * m[1][0]);
    if(determinant == 0) throw "There is no a inverse matrix";
    return mat2(m1[0][0] / determinant, m1[0][1] / determinant,
    m1[1][0] / determinant, m1[1][1] / determinant);
}

#endif