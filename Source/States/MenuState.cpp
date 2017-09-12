#include "MenuState.hpp"
#include "../ResourceManagers/ResourceHolder.hpp"
#include "../Game.hpp"

#include <iostream>

MenuState::MenuState(Game& game)
:   BaseState(game)
,   m_background({1280, 720})
,   m_logo      ({500, 150})
,   m_button    ({300, 75}) {

    m_background.setFillColor(sf::Color(33, 33, 33));

    m_logo.setTexture(&ResourceHolder::get().textures.get("Logo"));
    m_logo.setOrigin(500 / 2, 150 / 2);
    m_logo.setPosition(1280 / 2, 720 / 4);

    m_button.setFillColor(sf::Color(55, 55, 55));
    m_button.setOrigin(300 / 2, 75 / 2);
    m_button.setPosition(1280 / 2, 2 * 720 / 4);

    m_buttonText.setString("Kliknij no :)");
    m_buttonText.setFont(ResourceHolder::get().fonts.get("JosefinSans"));
    m_buttonText.setOrigin(m_buttonText.getLocalBounds().width / 2,
                           m_buttonText.getLocalBounds().height / 2);
    m_buttonText.setPosition(m_button.getPosition().x,
                             m_button.getPosition().y);

    m_bottomCredits.setString("Version 0.1, by Pawel Kupczak on 12.09.2017");
    m_bottomCredits.setCharacterSize(20);
    m_bottomCredits.setFont(ResourceHolder::get().fonts.get("JosefinSans"));
    m_bottomCredits.setOrigin(0,
                              m_bottomCredits.getLocalBounds().height);
    m_bottomCredits.setPosition(0, 720);
}

void MenuState::handleEvents(sf::Event event) {
    if(event.type == sf::Event::MouseButtonPressed) {
        auto pos = sf::Mouse::getPosition(m_p_game->getWindow());

        if(m_button.getGlobalBounds().contains(pos.x, pos.y)) {
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                std::cout<<"xD";
        }
    }
}

void MenuState::handleInput() {
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

    }
}

void MenuState::update(float deltaTime) {

}

void MenuState::render(sf::RenderTarget& renderer) {
    renderer.draw(m_background);
    renderer.draw(m_logo);
    renderer.draw(m_button);
    renderer.draw(m_buttonText);
    renderer.draw(m_bottomCredits);
}
