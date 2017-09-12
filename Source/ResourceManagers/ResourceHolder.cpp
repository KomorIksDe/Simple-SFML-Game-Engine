#include "ResourceHolder.hpp"

ResourceHolder& ResourceHolder::get() {
    static ResourceHolder holder;

    return holder;
}

ResourceHolder::ResourceHolder()
:   textures("Textures", "png")
,   fonts   ("Fonts", "ttf")
,   sounds  ("SFX", "ogg") {

    textures.addResource("Logo");
    textures.addResource("Splash");

    fonts.addResource("JosefinSans");

    sounds.addResource("splashNoise");
}
