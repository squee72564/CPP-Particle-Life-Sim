#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cmath>

template <typename T, std::size_t N,
          typename = std::enable_if_t<std::is_arithmetic<T>::value && (N > 1)> >
struct Vector {
    T dim[N];

    Vector() = default;

    template <typename... Args>
    Vector(Args... args) : dim{ static_cast<T>(args)...} {
        static_assert(
            sizeof...(Args) == N,
            "Number of arguments to vector must match dimension.");
    }

    T& operator[](std::size_t i) {
        return dim[i];
    }

    const T& operator[](std::size_t i) const {
        return dim[i];
    }
    
    // vector addition
    Vector operator+(const Vector& other) const {
        Vector result;

        for (std::size_t i = 0; i < N; ++i) {
            result.dim[i] = dim[i] + other.dim[i];
        }

        return result;
    }

    // vector subtraction
    Vector operator-(const Vector& other) const {
        Vector result;

        for (std::size_t i = 0; i < N; ++i) {
            result.dim[i] = dim[i] - other.dim[i];
        }

        return result;
    }

    // scalar multiplication
    Vector operator*(const T scalar) const {
        Vector result;
        for (std::size_t i = 0; i < N; ++i) {
            result.dim[i] = dim[i] * scalar;
        }

        return result;
    }

    // vector dot product
    float dot(const Vector& other) const {
        float result = 0.0f;

        for (std::size_t i = 0; i < N; ++i) {
            result += dim[i] * other.dim[i];
        }

        return result;
    }

    // vector cross product for 3d
    template <std::size_t M = N>
    Vector cross(const Vector<T, M>& other) const {
        static_assert(N == 3 && M == 3, "Cross product only defined for 3 dimensional vectors.");
        return {
            dim[1] * other.dim[2] - dim[2] * other.dim[1],
            dim[2] * other.dim[0] - dim[0] * other.dim[2],
            dim[0] * other.dim[1] - dim[1] * other.dim[0]
        };
    }

    // vector production onto another
    Vector projection(const Vector & onto) const {
        float dotProduct= dot(onto);
        float magSquared = onto.squared_magnitude();
        return onto * (dotProduct / magSquared);
    }

    // angle between two vectors in radians
    float angle(const Vector& other) {
        float dotProduct= dot(other);
        float magProduct = magnitude() * other.magnitude();
        return std::acos(dotProduct / magProduct);
    }

    // vector length
    float magnitude() const {
        float sum = 0;
        
        for (std::size_t i = 0; i < N; ++i) {
            sum += dim[i] * dim[i];
        }

        return std::sqrt(sum);
    }
    
    // vector length squared
    float squared_magnitude() const {
        float sum = 0;
        
        for (std::size_t i = 0; i < N; ++i) {
            sum += dim[i] * dim[i];
        }

        return sum;
    }
    
    // normalized vector
    Vector normalize() const {
        float mag = magnitude();
        if (mag == 0) {
            return *this;
        } 

        Vector result;
        for (std::size_t i = 0; i < N; ++i) {
            result.dim[i] = dim[i] / mag;
        }

        return result;
    }
    
};

#endif
