#include "state/state.h"

State::State(sf::RenderWindow* window, std::stack<State*>* states): _window(window), _states(states)
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("State<constructor>") : nullptr;
}

State::~State()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("State<destructor>") : nullptr;
}

void State::updateMousePositions() 
{
    _mousePosScreen = sf::Mouse::getPosition();
    _mousePosWindow = sf::Mouse::getPosition(*_window);
    _mousePosView = _window->mapPixelToCoords( sf::Mouse::getPosition() );
}

sf::RenderWindow* State::getWindow() { return _window; }