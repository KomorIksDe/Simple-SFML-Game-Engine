#ifndef RESOURCEHOLDER_HPP_INCLUDED
#define RESOURCEHOLDER_HPP_INCLUDED

#include "ResourceManager.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class ResourceHolder {
    public:
        ResourceManager<sf::Texture>     textures;
        ResourceManager<sf::Font>        fonts;
        ResourceManager<sf::SoundBuffer> sounds;

    public:
        static ResourceHolder& get();

    private:
        ResourceHolder();
};

#endif // RESOURCEHOLDER_HPP_INCLUDED
