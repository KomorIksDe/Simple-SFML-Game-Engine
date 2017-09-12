#ifndef MANUSTATE_HPP_INCLUDED
#define MANUSTATE_HPP_INCLUDED

#include "BaseState.hpp"

class MenuState : public BaseState {
    private:
        sf::RectangleShape m_background;
        sf::RectangleShape m_logo;
        sf::RectangleShape m_button;
        sf::Text           m_buttonText;
        sf::Text           m_bottomCredits;

    public:
        MenuState(Game& game);

        void handleEvents(sf::Event event)      override;
        void handleInput()                      override;
        void update(float deltaTime)            override;
        void render(sf::RenderTarget& renderer) override;
};

#endif // MANUSTATE_HPP_INCLUDED
