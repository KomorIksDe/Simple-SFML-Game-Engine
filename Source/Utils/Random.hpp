#ifndef RANDOM_HPP_INCLUDED
#define RANDOM_HPP_INCLUDED

#include <ctime>
#include <random>

class Random {
    private:
        std::minstd_rand gen;

    public:
        Random();

        static Random& get();

        int intInRange(int low, int high);
        float floatInRange(float low, float high);
};

#endif // RANDOM_HPP_INCLUDED
