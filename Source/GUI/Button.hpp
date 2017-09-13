#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

#include "Widget.hpp"

#include <functional>

namespace GUI {
    enum class ButtonSize {
        Small,
        Wide
    };

    class Button : public GUI::Widget {
        private:
            sf::Vector2f m_position;
            Rectangle    m_button;
            Text         m_text;

            std::function<void(void)> m_function = [](){};

        private:
            void updateText();

        public:
            Button(ButtonSize s = ButtonSize::Wide);

            void setFunction(std::function<void(void)> func);
            void setText    (const std::string& text);
            void setTexture (const sf::Texture& texture);

            void handleEvents   (sf::Event event, const sf::RenderWindow& window) override;
            void render         (sf::RenderTarget& renderer)                      override;
            void setPosition    (const sf::Vector2f& pos)                         override;
            sf::Vector2f getSize() const                                          override;
    };
}

#endif // BUTTON_HPP_INCLUDED
