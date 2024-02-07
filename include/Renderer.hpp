#ifndef RENDERER_H
#define RENDERER_H

#include "Simulation.hpp"
#include <iostream> 

class Renderer {

public:
    virtual void run() = 0;
    virtual void render() = 0;
    
    Renderer(int w, int h, Simulation* sim)
        : screen_width(w), screen_height(h), simulation(sim)
    {
        std::cout << "Renderer(int, int, simulation)\n";
    };

    virtual ~Renderer() = default;

protected:
    int screen_width;
    int screen_height;
    Simulation* simulation;
};

#endif // !RENDERER_H
