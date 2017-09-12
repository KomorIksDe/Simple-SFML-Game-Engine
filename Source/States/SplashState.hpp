#ifndef SPLASHSTATE_HPP_INCLUDED
#define SPLASHSTATE_HPP_INCLUDED

#include "BaseState.hpp"

#include <SFML/Audio.hpp>
#include <queue>

class SplashState : public BaseState {
    class Splash {
        private:
            float              m_time;
            bool               m_hasSound;
            sf::Clock          m_timer;
            sf::Sound          m_sound;
            sf::RectangleShape m_sprite;
            sf::Text           m_text;

        public:
            Splash(const sf::Texture& texture, const std::string& text, float time);
            Splash(const sf::Texture& texture, const std::string& text, const sf::SoundBuffer& buffer, float time);

            bool isOver() const;
            void start();
            void draw(sf::RenderTarget& renderer);

        private:
            void prepareText(const std::string& text);
    };

    private:
        std::queue<Splash> m_splashes;

    public:
        SplashState(Game& game);

        void handleEvents(sf::Event event)      override;
        void handleInput()                      override;
        void update(float deltaTime)            override;
        void render(sf::RenderTarget& renderer) override;
};

#endif // SPLASHSTATE_HPP_INCLUDED
