//
// Created by martin on 19.02.20.
//

#ifndef UNTITELED1_RANDOM_NUMBER_H
#define UNTITELED1_RANDOM_NUMBER_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>

struct random_number{

    static double rand_DoubleRange(double a, double b)
    {
        return ((b - a) * ((double)std::rand() / RAND_MAX)) + a;
    }

    static float rand_FloatRange(float a, float b)
    {
        return ((b - a) * ((float)std::rand() / RAND_MAX)) + a;
    }

    static int rand_IntRange(int a, int b)
    {
        return std::rand() % (b + a);
    }

};



#endif //UNTITELED1_RANDOM_NUMBER_H
