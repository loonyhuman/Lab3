//
// Created by u211-05 on 10.04.2018.
//

#ifndef UNTITLED_TEMPERATURE_H
#define UNTITLED_TEMPERATURE_H
#include <iostream>
#include <cassert>
#include <sstream>
using namespace std;

struct Temperature
{
    double value;
    char scale;
} ;
istream& operator >> (istream& stream, Temperature& Temp );


double convert( double input, char from, char to);

bool operator < (const Temperature& lhs, const Temperature& rhs);

Temperature operator - (const Temperature& lhs, const Temperature& rhs);

Temperature operator / (const Temperature& lhs, const Temperature& rhs);

Temperature operator * (const Temperature& lhs, const Temperature& rhs);

int check(const Temperature& Temp);



#endif //UNTITLED_TEMPERATURE_H
