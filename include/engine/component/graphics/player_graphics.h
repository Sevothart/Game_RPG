#ifndef _PLAYER_GRAPHICS_H
#define _PLAYER_GRAPHICS_H

#include "entities/player.h"

class PlayerGraphicsComponent: public GraphicsComponent
{
public:
    PlayerGraphicsComponent(sf::Texture &texture, sf::Vector2f startPos, sf::Vector2i spriteSize);
    ~PlayerGraphicsComponent();

    void update(GameObject& GameObject, float& dt);

private:
    void initAnimations();
    void initStates();

    void setStandingAnimation(PlayerState::Direction dir);
    void setWalkingAnimation(PlayerState::Direction dir);
    void setSprintingAnimation(PlayerState::Direction dir);

    void chooseAnimation(std::string name);

    // std::map<PlayerState, std::string> _stateToAnimation;
};

#endif