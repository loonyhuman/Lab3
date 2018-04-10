#include "Temperature.h"

void test_temperature_input()
{
    Temperature Temp;
    istringstream iss("10K");
    iss >> Temp;
    assert (Temp.value == 10);
    assert (Temp.scale == 'K');

    istringstream iss1("-42C");
    iss1 >> Temp;
    assert (Temp.value == -42);
    assert (Temp.scale == 'C');

    istringstream iss2("451F");
    iss2 >> Temp;
    assert (Temp.value == 451);
    assert (Temp.scale == 'F');

    istringstream iss3("ABC");
    iss3 >> Temp;
    assert (iss3.fail());
}