//
// Created by martin machajewski on 19.02.20.
//

#ifndef UNTITELED1_RANDOM_NUMBER_H
#define UNTITELED1_RANDOM_NUMBER_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>


////////////////////this c++ file contains code provided by/////////////
// @author:Ivan Prodanov
// reference: Stackoverflow
//URL: https://stackoverflow.com/a/686376/7091177
/////////////////////////////////////////////////////////////////////////
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
        return static_cast<int>(((b - a) * ((float)std::rand() / RAND_MAX)) + a);
    }

};


////////////////////this c++ file contains code provided by/////////////
//@author:Michael MKlimenko
//reference: Github
//URL: https://mklimenko.github.io/english/2018/06/04/constexpr-random/
/////////////////////////////////////////////////////////////////////////

constexpr int lce_a = 4096;
constexpr int lce_c = 150889;
constexpr int lce_m = 714025;

constexpr static auto time_from_string(const char* str, int offset) {
    return static_cast<std::uint32_t>(str[offset] - '0') * 10 +
           static_cast<std::uint32_t>(str[offset + 1] - '0');
}

constexpr static auto get_seed_constexpr() {
    auto t = __TIME__;
    return time_from_string(t, 0) * 60 * 60 + time_from_string(t, 3) * 60 + time_from_string(t, 6);
}

constexpr static std::uint32_t uniform_distribution(std::uint32_t &previous) {
    previous = ((lce_a * previous + lce_c) % lce_m);
    return previous;
}

constexpr static double uniform_distribution_n(std::uint32_t &previous) {
    auto dst = uniform_distribution(previous);
    return static_cast<double>(dst) / lce_m;
}

template <typename T, std::size_t sz>
constexpr static auto uniform_distribution(T min, T max) {
    std::array<T, sz> dst{};
    auto previous = get_seed_constexpr();
    for (auto &el : dst)
        el = static_cast<T>(uniform_distribution_n(previous) * (max - min) + min);

    return dst;
}


template <typename T>
constexpr static T uniform_distribution(T min, T max) {

    auto previous = get_seed_constexpr();
    return static_cast<T>(uniform_distribution_n(previous) * (max - min) + min);
}



 #endif //UNTITELED1_RANDOM_NUMBER_H
