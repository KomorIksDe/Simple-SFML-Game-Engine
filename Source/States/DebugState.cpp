#include "DebugState.hpp"
#include "../Game.hpp"

DebugState::DebugState(Game& game)
:   BaseState(game)
,   m_shape({500.0f, 250.0f}) {

    m_shape.setFillColor(sf::Color::Red);
}

void DebugState::handleEvents(sf::Event event) {
    auto pos = sf::Mouse::getPosition(m_p_game->getWindow());

    if(m_shape.getGlobalBounds().contains(pos.x, pos.y)) {
        if(event.type == sf::Event::MouseButtonPressed)
            m_shape.setFillColor(sf::Color::Blue);
    }
}

void DebugState::handleInput() {

}

void DebugState::update(float deltaTime) {

}

void DebugState::render(sf::RenderTarget& renderer) {
    renderer.draw(m_shape);
}
