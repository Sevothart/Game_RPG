#ifndef _SETTINGS_STATE_H
#define _SETTINGS_STATE_H

#include "state/state.h"

class SettingsMenuState: public State
{
public:
    /*! @brief
        Initializes the current Render and data display.
    Setting font, position, color, outline, etc.
    */
    SettingsMenuState(sf::RenderWindow* window);

    ~SettingsMenuState();

    void initWindow();
    void initFPS();
    
    /*! @brief
        Updates data showed on the screen corner.
    */
    void update(sf::Time& dt);

    void updateInput();
    void updateFPS(sf::Time& dt);

    /*! @brief
        Should be called every frame to render Entities alive on game.
    @param target   Where the entities are going to be draw.
    */
    void render(sf::RenderTarget* target = nullptr);

private:
    /*! @property 
    Data used to provide information about the game state to the user. */
    sf::Font _font;
    sf::Text _showFPS;
    std::ostringstream _fps;

    /*! @property
    Traits flag that allow debug if class debug and tracer debug are active. */
    static const bool debugged = Traits<SettingsMenuState>::debugged && Tracer::debugActive;

    /*! @property
    Traits flag that allow tracing if class tracing and tracer are active. */
    static const bool traced = Traits<SettingsMenuState>::traced && Tracer::traceActive;
};

#endif