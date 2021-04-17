//
// Created by Tegu on 17.4.2021 г..
//

#include "Vector4D.hpp"

Vector4D::Vector4D() {
    a = 0;
    b = 0;
    c = 0;
    d = 0;
}

Vector4D::Vector4D(double _a, double _b, double _c, double _d) {
    a = _a;
    b = _b;
    c = _c;
    d = _d;
}

double &Vector4D::operator[](int index) {
    switch (index) {
        case 0:
            return a;
        case 1:
            return b;
        case 2:
            return c;
        case 3:
            return d;
        default:
            break;
    }
}

Vector4D operator+(const Vector4D &_lhs, const Vector4D &_rhs) {
    return Vector4D(_lhs.a + _rhs.a, _lhs.b + _rhs.b, _lhs.c + _rhs.c, _lhs.d + _rhs.d);
}

Vector4D &Vector4D::operator+=(const Vector4D &_rhs) {
    this->a += _rhs.a;
    this->b += _rhs.b;
    this->c += _rhs.c;
    this->d += _rhs.d;
    return *this;
}

Vector4D operator-(const Vector4D &_lhs, const Vector4D &_rhs) {
    return Vector4D(_lhs.a - _rhs.a, _lhs.b - _rhs.b, _lhs.c - _rhs.c, _lhs.d - _rhs.d);
}

Vector4D &Vector4D::operator-=(const Vector4D &_rhs) {
    this->a -= _rhs.a;
    this->b -= _rhs.b;
    this->c -= _rhs.c;
    this->d -= _rhs.d;
    return *this;
}

Vector4D operator*(const Vector4D &_lhs, const Vector4D &_rhs) {
    return Vector4D(_lhs.a * _rhs.a, _lhs.b * _rhs.b, _lhs.c * _rhs.c, _lhs.d * _rhs.d);
}

Vector4D operator*(const Vector4D &_lhs, double x) {
    return Vector4D(_lhs.a * x, _lhs.b * x, _lhs.c * x, _lhs.d * x);
}

Vector4D &Vector4D::operator*=(const Vector4D &_rhs) {
    this->a *= _rhs.a;
    this->b *= _rhs.b;
    this->c *= _rhs.c;
    this->d *= _rhs.d;
    return *this;
}

Vector4D &Vector4D::operator*=(double _rhs) {
    this->a *= _rhs;
    this->b *= _rhs;
    this->c *= _rhs;
    this->d *= _rhs;
    return *this;
}

Vector4D operator/(const Vector4D &_lhs, const Vector4D &_rhs) {
    return Vector4D(_lhs.a / _rhs.a, _lhs.b / _rhs.b, _lhs.c / _rhs.c, _lhs.d / _rhs.d);
}

Vector4D &Vector4D::operator/=(const Vector4D &_rhs) {
    this->a /= _rhs.a;
    this->b /= _rhs.b;
    this->c /= _rhs.c;
    this->d /= _rhs.d;
    return *this;
}

bool operator==(const Vector4D &_lhs, const Vector4D &_rhs) {
    return (_lhs.a == _rhs.a && _lhs.b == _rhs.b && _lhs.c == _rhs.c && _lhs.d == _rhs.d);
}

bool operator!=(const Vector4D &_lhs, const Vector4D &_rhs) {
    return !(_lhs == _rhs);
}

bool operator>(const Vector4D &_lhs, const Vector4D &_rhs) {
    if (_lhs == _rhs) { return false; }
    if (_lhs.a != _rhs.a) {
        if (_lhs.a > _rhs.a) {
            return true;
        } else {
            return false;
        }
    }
    if (_lhs.b != _rhs.b) {
        if (_lhs.b > _rhs.b) {
            return true;
        } else {
            return false;
        }
    }
    if (_lhs.c != _rhs.c) {
        if (_lhs.c > _rhs.c) {
            return true;
        } else {
            return false;
        }
    }
    if (_lhs.d != _rhs.d) {
        if (_lhs.d > _rhs.d) {
            return true;
        } else {
            return false;
        }
    }
}

bool operator<(const Vector4D &_lhs, const Vector4D &_rhs) {
    if (_lhs == _rhs) { return false; }
    if (_lhs.a != _rhs.a) {
        if (_lhs.a < _rhs.a) {
            return true;
        } else {
            return false;
        }
    }
    if (_lhs.b != _rhs.b) {
        if (_lhs.b < _rhs.b) {
            return true;
        } else {
            return false;
        }
    }
    if (_lhs.c != _rhs.c) {
        if (_lhs.c < _rhs.c) {
            return true;
        } else {
            return false;
        }
    }
    if (_lhs.d != _rhs.d) {
        if (_lhs.d < _rhs.d) {
            return true;
        } else {
            return false;
        }
    }
}

bool operator>=(const Vector4D &_lhs, const Vector4D &_rhs) {
    return (_lhs > _rhs || _lhs == _rhs);
}

bool operator<=(const Vector4D &_lhs, const Vector4D &_rhs) {
    return (_lhs < _rhs || _lhs == _rhs);
}

bool operator!(const Vector4D &_sth) {
    return _sth == Vector4D(0, 0, 0, 0);
}

Vector4D operator-(const Vector4D &_rhs) {
    return Vector4D(-_rhs.a, -_rhs.b, -_rhs.c, -_rhs.d);
}

Vector4D &Vector4D::operator=(const Vector4D &_sth) {
    if (this != &_sth) {
        this->a = _sth.a;
        this->b = _sth.b;
        this->c = _sth.c;
        this->d = _sth.d;
    }
    return *this;
}



