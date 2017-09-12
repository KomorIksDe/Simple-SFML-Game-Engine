#include "SplashState.hpp"
#include "MenuState.hpp"
#include "../Game.hpp"
#include "../ResourceManagers/ResourceHolder.hpp"

SplashState::SplashState(Game& game)
:   BaseState(game) {

    m_splashes.emplace(ResourceHolder::get().textures.get("Splash"),
                       "Komor g4m3s",
                       ResourceHolder::get().sounds.get("splashNoise"),
                       2.0f);

    m_splashes.emplace(ResourceHolder::get().textures.get("Splash"),
                       "Good luck xdDxdXxddDDDxXD",
                       ResourceHolder::get().sounds.get("splashNoise"),
                       2.0f);

    m_splashes.front().start();
}

void SplashState::handleEvents(sf::Event event) {
    if(event.type == sf::Event::KeyPressed)
        handleInput();
}

void SplashState::handleInput() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        m_p_game->changeState(std::make_unique<MenuState>(*m_p_game));
}

void SplashState::update(float deltaTime) {
    if(!m_splashes.empty()) {
        if(m_splashes.front().isOver()) {
            m_splashes.pop();

            if(!m_splashes.empty())
                m_splashes.front().start();
        }
    }
    else
        m_p_game->changeState(std::make_unique<MenuState>(*m_p_game));
}

void SplashState::render(sf::RenderTarget& renderer){
    if(!m_splashes.empty())
        m_splashes.front().draw(renderer);
}

SplashState::Splash::Splash(const sf::Texture& texture, const std::string& text, float time)
:   m_sprite  ({1280, 720})
,   m_time    (time)
,   m_hasSound(false) {

    prepareText(text);
    m_sprite.setTexture(&texture);
}

SplashState::Splash::Splash(const sf::Texture& texture, const std::string& text, const sf::SoundBuffer& buffer, float time)
:   m_sprite  ({1280, 720})
,   m_time    (time)
,   m_hasSound(true)
,   m_sound   (buffer) {

    prepareText(text);
    m_sprite.setTexture(&texture);
}

bool SplashState::Splash::isOver() const {
    return m_timer.getElapsedTime().asSeconds() >= m_time;
}

void SplashState::Splash::start() {
    if(m_hasSound)
        m_sound.play();

    m_timer.restart();
}

void SplashState::Splash::draw(sf::RenderTarget& renderer) {
    renderer.draw(m_sprite);
    renderer.draw(m_text);
}

void SplashState::Splash::prepareText(const std::string& text) {
    m_text.setString(text);
    m_text.setFont(ResourceHolder::get().fonts.get("JosefinSans"));
    m_text.setCharacterSize(40);
    m_text.setOrigin(m_text.getLocalBounds().width / 2,
                     m_text.getLocalBounds().height / 2);
    m_text.setPosition(1280 / 2, 720 / 2);
}
