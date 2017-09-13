#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include "../ResourceManagers/ResourceHolder.hpp"

namespace GUI {
    class Widget {
        protected:
            class Rectangle : public sf::RectangleShape {
                public:
                    bool isRolledOn (const sf::RenderWindow& window) const;
                    bool isClickedOn(const sf::RenderWindow& window, sf::Event event);
            };

            class Text : public sf::Text {
                public:
                    Text();
            };

        public:
            virtual void handleEvents(sf::Event event, const sf::RenderWindow& window) = 0;
            virtual void render(sf::RenderTarget& renderer)                            = 0;
            virtual void setPosition(const sf::Vector2f& pos)                          = 0;
            virtual sf::Vector2f getSize() const                                       = 0;
    };
}

#endif // WIDGET_HPP_INCLUDED
