#include "cs.h"
#include "utils.h"
using namespace std;

istream& operator >> (istream& in, cs& c) {
    cout << "\n add cs:\n";
    cout << "name:  ";
    std::getline(cin >> ws, c.name);
    cout << "number of stations(int):  ";
    c.workshop = correctnumber<int>(0, 10000);
    cout << "number of workstations(int):  ";
    c.workshop_work = correctnumber<int>(0, c.workshop);
    cout << "station class(char):  ";
    c.classcs = correctnumber<char>(0, 10000);
    return in;
}



ostream& operator << (ostream& out, const cs& c) {
    if (c.name != "") {
        out << "\nname:  " << c.name;
        out << "\nnumber of stations:  " << c.workshop;
        out << "\nnumber of workstations:  " << c.workshop_work;
        out << "\nstation class(char):  " << c.classcs << endl;
    }
    else {
        out << "\nenter the cs\n" << endl;
    }
    return out;
}
