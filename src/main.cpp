#include <iostream>

#include "RendererSFML.hpp"
#include "Simulation.hpp"
#include "SFML/Graphics.hpp"

#include <array>

enum RendererType {
    SFML = 0,
    SDL,
    RAYLIB,
    DIRECTX,
};

int main()
{
    Simulation simulation;
    
    std::array<Renderer*, 1> renderers {
        new RendererSFML(1920, 1080, &simulation)
    };
    
    renderers[RendererType::SFML]->run();

    delete renderers[0];

    return 0;
}
