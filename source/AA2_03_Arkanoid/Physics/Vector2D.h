#pragma once
#ifndef SDLPROJECT_VECTOR2D_H
#define SDLPROJECT_VECTOR2D_H
#include <cmath>

template <typename T>
class Vector2D {
public:
    Vector2D() : X(0), Y(0) {}
    Vector2D(T x, T y) : X(x), Y(y) {}

    [[nodiscard]] T Length() const { return sqrt(X * X + Y * Y); };

    Vector2D operator+(const Vector2D &v2) const { return {X + v2.X, Y + v2.Y}; }

    friend Vector2D &operator+=(Vector2D &v1, const Vector2D &v2) {
        v1.X += v2.X;
        v1.Y += v2.Y;
        return v1;
    }

    Vector2D operator-(const Vector2D &v2) const { return {X - v2.X, Y - v2.Y}; }

    friend Vector2D &operator-=(Vector2D &v1, const Vector2D &v2) {
        v1.X -= v2.X;
        v1.Y -= v2.Y;
        return v1;
    }

    Vector2D operator*(T scalar) const { return {X * scalar, Y * scalar}; }

    friend Vector2D &operator*=(Vector2D& v1, const Vector2D& v2) {
        v1.X *= v2.X;
        v1.Y *= v2.Y;
        return v1;
    }

    Vector2D& operator*=(T scalar) {
        X /= scalar;
        Y /= scalar;
        return *this;
    }

    Vector2D operator/(T scalar) const { return {X / scalar, Y / scalar}; }

    Vector2D &operator/=(T scalar) {
        X /= scalar;
        Y /= scalar;
        return *this;
    }

    Vector2D& operator%=(T scalar) {
        X %= scalar;
        Y %= scalar;
        return *this;
    }

    void Normalize() {
        T length = Length();
        if (length > 0) {
            (*this) /= length;
        }
    }

    Vector2D Normalized() {
        T length = Length();
        if (length > 0) {
            return *this / length;
        }
        return *this;
    }

public:
    T X;
    T Y;
};


#endif //SDLPROJECT_VECTOR2D_H
