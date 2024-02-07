#include "Simulation.hpp"

#include <iostream>

Simulation::Simulation()
{
    
    std::cout << "Simulation()\n"; 

    // Handle any memory mangagement for containers
    particles.reserve(1024);
    
    for (std::vector<Particle<Vector2f>*>& quadVec: quadrants) {
        quadVec.reserve(1024 / quadrants.size());
    }
}

Simulation::~Simulation()
{
    std::cout << "~Simulation()\n"; 

    particles.clear();
    
    for (std::vector<Particle<Vector2f>*>& quadVec: quadrants) {
        quadVec.clear();
    }
}

void Simulation::insertParticle(Vector2f&& pos, Vector2f&& vel, Vector2f&& acc, float&& m)
{
    particles.emplace_back(Particle<Vector2f>(
                            std::move(pos),
                            std::move(vel),
                            std::move(acc),
                            m));
}

void Simulation::update()
{

}

std::vector<Particle<Vector2f>>& Simulation::getParticleVector()
{
    return particles;
}

std::array<std::vector<Particle<Vector2f>*>, QUADRANT_SIZE>& Simulation::getQuadrantArray()
{
    return quadrants;
}
