#ifndef BASESTATE_HPP_INCLUDED
#define BASESTATE_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class Game;

class BaseState {
    protected:
        Game* m_p_game;

    public:
        BaseState(Game& game)
        :   m_p_game(&game)
        { }

        virtual ~BaseState() = default;

        virtual void handleEvents(sf::Event event)      = 0;
        virtual void handleInput()                      = 0;
        virtual void update(float deltaTime)            = 0;
        virtual void render(sf::RenderTarget& renderer) = 0;
};

#endif // BASESTATE_HPP_INCLUDED
