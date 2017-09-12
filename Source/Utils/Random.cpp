#include "Random.hpp"

Random::Random() {
    gen.seed(std::time(nullptr));
}

Random& Random::get() {
    static Random ran;

    return ran;
}

int Random::intInRange(int low, int high) {
    std::uniform_int_distribution<int> dist(low, high);

    return dist(gen);
}

float Random::floatInRange(float low, float high) {
    std::uniform_real_distribution<float> dist(low, high);

    return dist(gen);
}
