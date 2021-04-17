//
// Created by Tegu on 17.4.2021 г..
//

#ifndef INC_3_VECTOR4D_H
#define INC_3_VECTOR4D_H


class Vector4D {
private:
    double a,b,c,d;
public:
    Vector4D();
    Vector4D(double _a, double _b, double _c, double _d);
    double& operator[] (int index);
    friend Vector4D operator+(const Vector4D& _lhs,const Vector4D& _rhs);
    Vector4D& operator+=(const Vector4D& _rhs);
    friend Vector4D operator-(const Vector4D& _lhs,const Vector4D& _rhs);
    Vector4D& operator-=(const Vector4D& _rhs);
    friend Vector4D operator*(const Vector4D& _lhs, const Vector4D& _rhs);
    friend Vector4D operator*(const Vector4D& _lhs, double x);
    Vector4D& operator*=(const Vector4D& _rhs);
    Vector4D& operator*=(double _rhs);
    friend Vector4D operator/(const Vector4D& _lhs,const Vector4D& _rhs);
    Vector4D& operator/=(const Vector4D& _rhs);
    friend bool operator==(const Vector4D& _lhs, const Vector4D& _rhs);
    friend bool operator!=(const Vector4D& _lhs, const Vector4D& _rhs);
    friend bool operator>(const Vector4D& _lhs, const Vector4D& _rhs);
    friend bool operator<(const Vector4D& _lhs, const Vector4D& _rhs);
    friend bool operator>=(const Vector4D& _lhs, const Vector4D& _rhs);
    friend bool operator<=(const Vector4D& _lhs, const Vector4D& _rhs);
    friend bool operator!(const Vector4D& _sth);
    friend Vector4D operator-(const Vector4D& _rhs);
    Vector4D& operator=(const Vector4D& _sth);};


#endif //INC_3_VECTOR4D_H
