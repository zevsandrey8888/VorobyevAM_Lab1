#include "pipe.h"
#include "utils.h"
using namespace std;

//std::string pipe::GetName() const
//{
//    return name;
//}

istream& operator >> (istream& in, pipe& p) {
    cout << "\n add pipe: \n";
    cout << "name:  ";
    std::getline(cin >> ws, p.name);
    cout << "length(double)  ";
    p.length = correctnumber<double>(0, 10000);
    cout << "diametr(int)  ";
    p.diametr = correctnumber<int>(0, 10000);
    cout << "station working? (1-YES, 0 - NO)  ";
    p.work = correctnumber<bool>(0, 1);
    return in;
}

ostream& operator << (ostream& out, const pipe& p) {
    if (p.name != "") {
        out << "\nname:  " << p.name;
        out << "\nlength:  " << p.length;
        out << "\ndiametr:  " << p.diametr;
        out << "\npipe: " << (p.work ? "work" : "dont work") << endl;
    }
    else {
        out << "\nenter the pipe\n  ";
    }
    return out;
}