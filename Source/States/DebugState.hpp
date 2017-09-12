#ifndef DEBUGSTATE_HPP_INCLUDED
#define DEBUGSTATE_HPP_INCLUDED

#include "BaseState.hpp"

class DebugState : public BaseState {
    private:
        sf::RectangleShape m_shape;

    public:
        DebugState(Game& game);

        void handleEvents(sf::Event event)      override;
        void handleInput()                      override;
        void update(float deltaTime)            override;
        void render(sf::RenderTarget& renderer) override;
};

#endif // DEBUGSTATE_HPP_INCLUDED
