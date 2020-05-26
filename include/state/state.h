#ifndef _STATE_H
#define _STATE_H

#include "entities/player.h"
#include "engine/event/observer.h"

class State: public Observer
{
public:
    State(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~State();

    virtual void update(sf::Time& dt) = 0;
    virtual void updateMousePositions();
    virtual void render(sf::RenderTarget* target = nullptr) = 0;
    virtual void onNotify(sf::Event& event) = 0;

protected:
    sf::RenderWindow* getWindow();

    sf::RenderWindow* _window;
    sf::Vector2i _mousePosWindow;
    sf::Vector2i _mousePosScreen;
    sf::Vector2f _mousePosView;
    std::stack<State*>* _states;

private:
    static const bool debugged = Traits<State>::debugged && Tracer::debugActive;
    static const bool traced = Traits<State>::traced && Tracer::traceActive;
};

#endif