#pragma once
#include <iostream>
#include <string>
#include <vector>
class pipe
{
public:
    std::string name;
    double length;
    int diametr;
    bool work;

    //pipe();
    //std::string GetName() const;



    friend std::ostream& operator << (std::ostream& out, const pipe& p);
    friend std::istream& operator >> (std::istream& in, pipe& p);

};

