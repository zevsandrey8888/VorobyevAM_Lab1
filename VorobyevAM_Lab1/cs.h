#pragma once
#include <iostream>
#include <string>
#include <vector>

class cs
{
public:
    std::string name;
    int workshop;
    int workshop_work;
    char classcs;


    //cs();

    friend std::istream& operator >> (std::istream& in, cs& c);
    friend std::ostream& operator << (std::ostream& out, const cs& c);

};

