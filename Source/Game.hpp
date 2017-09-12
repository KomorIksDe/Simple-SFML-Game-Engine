#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <stack>
#include <memory>

#include "States/DebugState.hpp"

class Game {
    private:
        sf::RenderWindow m_window;
        std::stack<std::unique_ptr<BaseState>> m_states;

    public:
        Game();

        void run();
        void pushState(std::unique_ptr<BaseState> state);
        void popState();
        void changeState(std::unique_ptr<BaseState> state);

        const sf::RenderWindow& getWindow() const;

    private:
        void handleEvents();
};

#endif // GAME_HPP_INCLUDED
