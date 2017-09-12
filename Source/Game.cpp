#include "Game.hpp"
#include "ResourceManagers/ResourceHolder.hpp"
#include "States/SplashState.hpp"

Game::Game()
:   m_window(sf::VideoMode(1280, 720), "BGE v2.0") {

    pushState(std::make_unique<SplashState>(*this));
}

void Game::run() {
    while (m_window.isOpen()) {
        handleEvents();

        m_window.clear();

        m_states.top()->handleInput();
        m_states.top()->update(0.0f);
        m_states.top()->render(m_window);

        m_window.display();
    }
}

const sf::RenderWindow& Game::getWindow() const {
    return m_window;
}

void Game::handleEvents() {
    sf::Event event;

    while(m_window.pollEvent(event)) {
        m_states.top()->handleEvents(event);

        switch(event.type) {
            case sf::Event::Closed:
                m_window.close();
                break;

            default:
                break;
        }
    }
}


void Game::pushState(std::unique_ptr<BaseState> state) {
    m_states.push(std::move(state));
}

void Game::popState() {
    if(!m_states.empty())
        m_states.pop();
}

void Game::changeState(std::unique_ptr<BaseState> state) {
    popState();
    m_states.push(std::move(state));
}
