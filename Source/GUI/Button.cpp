#include "Button.hpp"

GUI::Button::Button(ButtonSize s) {
    switch(s) {
        case ButtonSize::Small:
            m_button.setSize({512, 128});
            break;
        case ButtonSize::Wide:
            m_button.setSize({256, 64});
            break;
    }

    m_button.setFillColor({52, 152, 219});
    m_button.setOrigin(m_button.getSize().x / 2, m_button.getSize().y / 2);
    updateText();
}

void GUI::Button::setFunction(std::function<void(void)>func) {
    m_function = func;
}

void GUI::Button::setText(const std::string& text) {
    m_text.setString(text);
    updateText();
}

void GUI::Button::setTexture(const sf::Texture& texture) {
    m_button.setTexture(&texture);
}

void GUI::Button::handleEvents(sf::Event event, const sf::RenderWindow& window) {
    auto pos = sf::Mouse::getPosition(window);

    if(m_button.getGlobalBounds().contains(pos.x, pos.y)) {
        if(event.type == sf::Event::MouseButtonPressed) {
            if(event.mouseButton.button == sf::Mouse::Left)
                m_function();
        }
    }
}

void GUI::Button::render(sf::RenderTarget& renderer) {
    renderer.draw(m_button);
    renderer.draw(m_text);
}

void GUI::Button::setPosition(const sf::Vector2f& pos) {
    m_position = pos;

    m_button.setPosition(m_position);
    m_text.setPosition  (m_position);

    updateText();
}

sf::Vector2f GUI::Button::getSize() const {
    return m_button.getSize();
}

void GUI::Button::updateText() {
    m_text.setOrigin(m_text.getGlobalBounds().width  / 2,
                     m_text.getGlobalBounds().height / 2);
}
