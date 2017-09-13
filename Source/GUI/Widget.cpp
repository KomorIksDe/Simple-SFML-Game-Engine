#include "Widget.hpp"

GUI::Widget::Text::Text() {
    setCharacterSize(30);
    setFillColor    (sf::Color::White);
    setOutlineColor (sf::Color::Black);
    setFont         (ResourceHolder::get().fonts.get("JosefinSans"));
}

bool GUI::Widget::Rectangle::isRolledOn(const sf::RenderWindow& window) const {
    auto pos = sf::Mouse::getPosition(window);

    return getGlobalBounds().contains(pos.x, pos.y);
}

bool GUI::Widget::Rectangle::isClickedOn(const sf::RenderWindow& window, sf::Event event) {
    if(isRolledOn(window)) {
        if(event.type == sf::Event::MouseButtonPressed)
            return event.mouseButton.button == sf::Mouse::Left;
    }

    return false;
}
