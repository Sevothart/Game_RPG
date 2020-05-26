#include "state/main_menu_state.h"

MainMenuState::MainMenuState(sf::RenderWindow* window, std::stack<State*>* states): State(window, states)
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("MainMenuState<constructor>") : nullptr;

    _window->setMouseCursorVisible(true);
    _background.setSize(sf::Vector2f( getWindow()->getSize().x, getWindow()->getSize().y ));
    _background.setFillColor( sf::Color(249, 219, 210)  );

    initButtons();
}

MainMenuState::~MainMenuState()
{
    std::unique_ptr<Tracer> tmp = (traced) ? std::make_unique<Tracer>("MainMenuState<destructor>") : nullptr;
    delete _playButton;
    delete _settingsButton;
    delete _saveButton;
}

void MainMenuState::initButtons()
{
    sf::Vector2i buttonSize = sf::Vector2i(256, 256);

    sf::Vector2f playButtonPos = sf::Vector2f(
        getWindow()->getSize().x/2.f - buttonSize.x/2.f - buttonSize.x*3/2.f,
        getWindow()->getSize().y/2.f - buttonSize.y/2.f
    );

    sf::Vector2f settingsButtonPos = sf::Vector2f(
        getWindow()->getSize().x/2.f - buttonSize.x/2.f + buttonSize.x*3/2.f,
        getWindow()->getSize().y/2.f - buttonSize.y/2.f
    );

    sf::Vector2f saveButtonPos = sf::Vector2f(
        getWindow()->getSize().x/2.f - buttonSize.x/2.f,
        getWindow()->getSize().y/2.f - buttonSize.y/2.f
    );

    _playButton = new Button("play", AssetManager::getTexture(ICON_PATH(movie)), playButtonPos, buttonSize);
    _settingsButton = new Button("settings", AssetManager::getTexture(ICON_PATH(settings)), settingsButtonPos, buttonSize);
    _saveButton = new Button("save", AssetManager::getTexture(ICON_PATH(diskette)), saveButtonPos, buttonSize);
}

void MainMenuState::update(sf::Time& dt){

    updateMousePositions();

    /* Update buttons state */
    _playButton->update(dt, _mousePosView);
    _settingsButton->update(dt, _mousePosView);
    _saveButton->update(dt, _mousePosView);
}

void MainMenuState::render(sf::RenderTarget* target){

    if(!target)
        target = getWindow();
    
    target->draw( _background );
    _playButton->render(target);
    _settingsButton->render(target);
    _saveButton->render(target);

}

void MainMenuState::onNotify(sf::Event& event)
{
    if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
    {
        delete _states->top();
        _states->pop();
    }

    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Button::Left)
    {
        if( _playButton->getSprite().getGlobalBounds().contains(_mousePosView) )
        {
            _states->push( new GameState(_window, _states) );
        }
        else if( _settingsButton->getSprite().getGlobalBounds().contains(_mousePosView) )
        {
            _states->push( new SettingsMenuState(_window, _states) );
        }
    }
}