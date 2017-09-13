#ifndef MANUSTATE_HPP_INCLUDED
#define MANUSTATE_HPP_INCLUDED

#include "BaseState.hpp"
#include "../GUI/Button.hpp"

class MenuState : public BaseState {
    private:
        sf::RectangleShape m_background;
        sf::RectangleShape m_logo;
        sf::Text           m_bottomCredits;
        GUI::Button        m_button;
        GUI::Button        m_button2;

    public:
        MenuState(Game& game);

        void handleEvents(sf::Event event)      override;
        void handleInput()                      override;
        void update(float deltaTime)            override;
        void render(sf::RenderTarget& renderer) override;
};

#endif // MANUSTATE_HPP_INCLUDED
