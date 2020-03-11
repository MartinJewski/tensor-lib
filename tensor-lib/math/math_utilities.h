//
// Created by martin on 10.03.20.
//

#ifndef UNTITELED1_MATH_UTILITIES_H
#define UNTITELED1_MATH_UTILITIES_H


#include <math.h>
#include <vector>

//https://stackoverflow.com/questions/33268513/calculating-standard-deviation-variance-in-c

double StandardDeviation(std::vector<double>);
double Variance(std::vector<double>);

double StandardDeviation(std::vector<double> samples)
{
    return sqrt(Variance(samples));
}

double Variance(std::vector<double> samples)
{
    int size = samples.size();

    double variance = 0;
    double t = samples[0];
    for (int i = 1; i < size; i++)
    {
        t += samples[i];
        double diff = ((i + 1) * samples[i]) - t;
        variance += (diff * diff) / ((i + 1.0) *i);
    }

    return variance / (size - 1);
}


#endif //UNTITELED1_MATH_UTILITIES_H
