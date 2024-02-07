#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <vector>
#include <array>
#include <cmath>

#include "Particle.hpp"

#define GRID_DEPTH 3 // Divide the screen into 4^GRID_DEPTH tiles

constexpr int QUADRANT_SIZE = std::pow(4, GRID_DEPTH);

using Vector2f = Vector<float,2>;

class Simulation {
private:
    // containers to track particles
    std::vector< Particle< Vector2f > > particles;
    std::array<std::vector< Particle< Vector2f >* >, QUADRANT_SIZE> quadrants;
    
    // simulation dimentions
    int width;
    int height;

    // Unique types
    int num_particle_types;


public:
    Simulation();
    ~Simulation();

    void insertParticle(Vector2f&& pos, Vector2f&& vel, Vector2f&& acc, float&& m);
    void update();

    std::vector<Particle<Vector2f>>& getParticleVector();
    std::array<std::vector<Particle<Vector2f>*>, QUADRANT_SIZE>& getQuadrantArray();
};


#endif
