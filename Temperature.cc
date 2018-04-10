#include "Temperature.h"

istream& operator >> (istream& stream, Temperature& Temp )
{
    setstate(ios_base:: goodbit);
    if(check(Temp) > 0)
    {
        setstate(ios_base:: failbit);
    }
    stream >> Temp.value;
    stream >> Temp.scale;
}


double convert( double input, char from, char to)
{
    if( from == to)
    {
        return input;
    }

    double Kelvins;

    switch(from) {
    case 'k': case 'K':
        Kelvins = input;
        break;
    case 'c': case 'C':
        Kelvins = input + 273, 15;
        break;
    case 'f': case 'F':
        Kelvins = ((5*(input - 32))/9) + 273,15;
        break;

    }

    switch(to)
    {
    case 'k':   case 'K': return Kelvins; break;
    case 'c':   case 'C': return Kelvins - 273,15; break;
    case 'f':   case 'F': return 1,8*(Kelvins - 273,15) + 32; break;

    }

}


bool operator < (const Temperature& lhs, const Temperature& rhs)
{
    return convert (lhs.value, lhs.scale, 'K') <  convert (rhs.value, rhs.scale, 'K');
}

Temperature operator - (const Temperature& lhs, const Temperature& rhs)
{
    Temperature ret_temp;
    ret_temp.value = convert (lhs.value, lhs.scale, 'K') -  convert (rhs.value, rhs
            .scale, 'K');
    ret_temp.scale = 'K';
    return ret_temp;
}

Temperature operator / (const Temperature& lhs, const Temperature& rhs)
{
    Temperature ret_temp;
    ret_temp.value = convert (lhs.value, lhs.scale, 'K') /  convert (rhs.value, rhs
            .scale, 'K');
    ret_temp.scale = 'K';
    return ret_temp;
}

Temperature operator * (const Temperature& lhs, const Temperature& rhs)
{
    Temperature ret_temp;
    ret_temp.value = convert (lhs.value, lhs.scale, 'K') *  convert (rhs.value, rhs
            .scale, 'K');
    ret_temp.scale = 'K';
    return ret_temp;
}

int check(const Temperature& Temp)
{
    if(Temp.scale != 'K' && Temp.scale != 'F' && Temp.scale != 'C')
    {
        cerr << "Wrong scale";
        return 1;
    }

    if(convert(Temp.value, Temp.scale, 'K') < 0)
    {
        cerr << "Kelvin < 0";
        return 2;
    }
    return 0;
}