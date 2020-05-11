#ifndef _ENTITY_H
#define _ENTITY_H

#include <SFML/Graphics.hpp>
#include "location.h"
#include "Utilities/tracer.h"

/*
Description:
    This class is an abstract class, every character that's displayed on map
during game execution has to inherit Entity class.
TODO:
    Entities should be destroyed when leaving a map zone ?
    Define abstract methods: update render display move
*/
class Entity
{
public:
    /*
    Description:
        Entity class constructor sets its name, sprite, and location class.
        Classes that inhetits from it should handle it on their
    own way.
    */
    Entity( std::string, sf::Texture &, sf::Vector2f, Location::Direction );

    /*
    Description:
        Entity class destructor has to be virtual, in order to ensure
    that other inheritances are correctly destructed.
        Handle name and location destruction. Sprite is handled by AssetManager.
    */
    virtual ~Entity();
    
    std::string getName();
    Location * getLocation();
    sf::Sprite * getSprite();

    virtual void update(sf::Time &) = 0;
    virtual sf::Sprite render() = 0;

protected:
    /*
    Description:
        Entity class setters works in a basic way.
        Classes that inhetits from it should handle its exceptions.
    */
    void setName( std::string );
    void setLocation( Location * );
    void setSprite( sf::Texture & );

private:
    /* Entity name to be displayed during game execution */
    std::string _name;
    /* Entity current location */
    Location * _location;
    /* Entity pattern to be rendered. TODO: Make it a reference */
    sf::Sprite _sprite;

    /* Traits flag that allow debug */
    static const bool debugged = Traits<Entity>::debugged;
    /* Traits flag that allow tracing if debug and tracer is active */
    static const bool traced = debugged && Tracer::enable;
};

#endif