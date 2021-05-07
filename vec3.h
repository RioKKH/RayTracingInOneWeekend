#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt;

class vec3
{
    public:
        vec3() : e{0, 0, 0} {}
        vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

        /**
         * メンバー関数をconst メンバー関数にするには宣言・定義の両方で
         * return-type member-function-name(parameters..._) const
         * とする
         * 以下のメンバー関数は要はgetterなので、メンバー変数を変更出来ては困る
         * そのためにconstメンバー関数として定義されている
         */
        double x() const { return e[0]; }
        double y() const { return e[1]; }
        double z() const { return e[2]; }

        vec3 operator -() const { return vec3(-e[0], -e[1], -e[2]); }
        double operator [] (int i) const { return e[i]; }
        double & operator [] (int i) { return e[i]; }

        vec3 & operator += (const vec3 & v)
        {
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            return *this;
        }

        vec3 & operator *= (const double t)
        {
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            return *this;
        }

        vec3 & operator /= (const double t)
        {
            return *this *= 1/t;
        }

        double length() const
        {
            return sqrt(length_squared());
        }

        double length_squared() const
        {
            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
        }

    public:
        double e[3];
};

// Type aliases for vec3
// 上で定義したvec3クラスを3Dの位置、RGBを表すクラスとして用いる
using point3 = vec3;    // 3D point
using color = vec3;     // RGB color


// vec3 Utility Functions

inline std::ostream & operator << (std::ostream & out, const vec3 & v)
{
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline vec3 operator + (const vec3 & u, const vec3 & v)
{
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline vec3 operator - (const vec3 & u, const vec3 & v)
{
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline vec3 operator * (const vec3 & u, const vec3 & v)
{
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline vec3 operator * (double t, const vec3 & v)
{
    return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

// binary operator * の引数の順番が逆になったもの
inline vec3 operator * (const vec3 & v, double t)
{
    // 上で定義した operator *を用いている
    return t * v;
}

// これの第1パラメータが const vec3 & vでない理由は？
// inline vec3 operator / (const vec3 & v, double t)でも良いのでは？
// -->理由を考察すること
inline vec3 operator / (vec3 v, double t)
{
    return (1/t) * v;
}

// 内積を定義
inline double dot(const vec3 & u, const vec3 & v)
{
    return u.e[0] * v.e[0]
         + u.e[1] * v.e[1]
         + u.e[2] * v.e[2];
}

// 外積を定義
inline vec3 cross(const vec3 & u, const vec3 & v)
{
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

// これも引数はconst vec3 & vでも良いのでは？
inline vec3 unit_vector(vec3 v)
{
    return v / v.length();
}

#endif
