#include "MenuState.hpp"
#include "../ResourceManagers/ResourceHolder.hpp"
#include "../Game.hpp"

#include <iostream>
#include <windows.h>

MenuState::MenuState(Game& game)
:   BaseState   (game)
,   m_background({1280, 720})
,   m_logo      ({500, 150})
,   m_button    (GUI::ButtonSize::Wide)
,   m_button2   (GUI::ButtonSize::Wide) {

    m_background.setFillColor(sf::Color(33, 33, 33));

    m_logo.setTexture(&ResourceHolder::get().textures.get("Logo"));
    m_logo.setOrigin(500 / 2, 150 / 2);
    m_logo.setPosition(1280 / 2, 720 / 4);

    m_button.setText("No dawaj :)))");
    m_button.setPosition({1280 / 2, 3 * 720 / 5});
    m_button.setFunction([](){
        std::cout<<"Button works!"<<std::endl;
    });

    m_button2.setText("Wyjdz sb");
    m_button2.setPosition({1280 / 2, 4 * 720 / 5});
    m_button2.setFunction([](){
        exit(0);
    });

    m_bottomCredits.setString("Version 0.1, by Pawel Kupczak on 12.09.2017");
    m_bottomCredits.setCharacterSize(20);
    m_bottomCredits.setFont(ResourceHolder::get().fonts.get("JosefinSans"));
    m_bottomCredits.setOrigin(0,
                              m_bottomCredits.getLocalBounds().height);
    m_bottomCredits.setPosition(0, 720);
}

void MenuState::handleEvents(sf::Event event) {
    m_button.handleEvents(event, m_p_game->getWindow());
    m_button2.handleEvents(event, m_p_game->getWindow());
}

void MenuState::handleInput() {

}

void MenuState::update(float deltaTime) {

}

void MenuState::render(sf::RenderTarget& renderer) {
    renderer.draw(m_background);
    renderer.draw(m_logo);
    m_button.render(renderer);
    m_button2.render(renderer);
    renderer.draw(m_bottomCredits);
}
