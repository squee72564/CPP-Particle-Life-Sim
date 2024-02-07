#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include "Vector.hpp"


// Type traits to restrict the template to taking in only our defined
// Vector struct

template <typename T>
struct is_vector : std::false_type {};

template <typename T, std::size_t N>
struct is_vector<Vector<T,N>> : std::true_type {}; 

template <typename T,
          typename = std::enable_if_t<is_vector<T>::value>>
struct Particle {
    T pos;
    T vel;
    T acc;
    float mass;

    Particle() : mass(0.0f) {}

    Particle(const T& p, const T& v, const T& a, float m)
        : pos(p), vel(v), acc(a), mass(m) {}

    Particle(const T&& p, const T&& v, const T&& a, float m)
        : pos(std::move(p)), vel(std::move(v)), acc(std::move(a)), mass(m) {}

    Particle(const Particle& other)
        : pos(other.pos), vel(other.vel), acc(other.acc), mass(other.mass) {};

    Particle(Particle&& other)
        : pos(std::move(other.pos)), vel(std::move(other.vel)), acc(std::move(other.acc)), mass(other.mass) {};

    Particle& operator=(Particle&& other) noexcept
    {
        if (this!= &other) {
            pos = std::move(other.pos);
            vel = std::move(other.vel);
            acc = std::move(other.acc);
            mass = other.mass;
        }

        return *this;
    }
};

#endif
