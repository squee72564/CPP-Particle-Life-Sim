#ifndef RENDERER_SFML_H
#define RENDERER_SFML_H

#include "Renderer.hpp"
#include <SFML/Graphics.hpp>

class RendererSFML : public Renderer {
public:
    RendererSFML();
    RendererSFML(int, int, Simulation*);
    ~RendererSFML();

    void run() override;
    void pollUserEvent();
    void render() override;

private:
    sf::Event event;
    sf::RenderWindow* window;
};

#endif // RENDERER_SFML_H
