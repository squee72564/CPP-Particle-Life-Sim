#include <iostream>

#include "RendererSFML.hpp"

RendererSFML::RendererSFML()
  : Renderer(1920, 1080, nullptr),
    window(new sf::RenderWindow(sf::VideoMode(screen_width, screen_height), "Particle Life Simulator With SFML"))
{
    std::cout << "RendererSFML()\n";
    window->setFramerateLimit(60);
}

RendererSFML::RendererSFML(int w, int h, Simulation* sim)
  : Renderer(w, h, sim),
    window(new sf::RenderWindow(sf::VideoMode(screen_width, screen_height), "Particle Life Simulator With SFML"))
{
    std::cout << "RendererSFML(int,int,Simulation*)\n";
    window->setFramerateLimit(60);
}

RendererSFML::~RendererSFML()
{
    std::cout << "~RendererSFML()\n";
    simulation = nullptr;
}


void RendererSFML::run()
{
    while (window->isOpen()) {
        pollUserEvent();

        if (simulation != nullptr) {
            simulation->update();
        } else {
            //std::cout << "NULLPTR TO SIMULATION";
        }

        render();
    }
}

void RendererSFML::pollUserEvent()
{
    while (window->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window->close();
                break;

            default:
                break;
        }
    }
}

void RendererSFML::render()
{
    window->clear(sf::Color::Black);

    // Get particles and draw
    std::vector<Particle<Vector2f>>& simulation_particles = simulation->getParticleVector();
    
    sf::VertexArray points(sf::Points, simulation_particles.size());

    for (std::size_t i = 0; i < simulation_particles.size(); ++i) {
       points[i].position.x = simulation_particles[i].pos[0];
       points[i].position.y = simulation_particles[i].pos[1];
       points[i].color = sf::Color::White;
    }

    window->draw(points);

    window->display();
}
