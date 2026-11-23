#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
T correctnumber(double min, double max) {
    T tipe;
    while (cin.peek() == '+' || !(cin >> tipe) || cin.peek() != '\n' || tipe < min || tipe > max) {
        cout << "enter the correct value:";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return tipe;
}

struct pipe
{
    string name;
    double length;
    int diametr;
    bool work;
};

struct cs {
    string name;
    int workshop;
    int workshop_work;
    char classcs;
};

void editpipe(pipe& p) {
    if (p.name != "") {
        cout << "\nchange in the operating condition of the pipe:" << "\nenter whether the pipe is working(1-yes, 0-no):";
        p.work = correctnumber<bool>(0, 1);
    }
    else {
        cout << "\nenter the pipe\n" << endl;
    }
}

void editcs(cs& c) {
    if (c.name != "") {
        cout << "\nchange in the number of operating stations" << "\nnumber of workstations(int):";
        c.workshop_work = correctnumber<int>(0, c.workshop);
    }
    else {
        cout << "\nenter the cs\n" << endl;
    }
}

void saveobj(ostream& out, const vector<pipe>& pipes, const vector<cs>& css) {
    out << "Pipes:" << endl;
    out << pipes.size() << endl;
    for (const auto& p : pipes) {
        out << p.name << endl
            << p.length << endl
            << p.diametr << endl
            << p.work << endl;
    }

    out << "Cs:" << endl;
    out << css.size() << endl;
    for (const auto& c : css) {
        out << c.name << endl
            << c.workshop << endl
            << c.workshop_work << endl
            << c.classcs << endl;
    }
}

void loadpipes(istream& in, vector<pipe>& pipes) {
    string x;
    while (getline(in, x)) {
        if (x == "Pipes:") {
            size_t count = 0;
            in >> count;
            in.ignore();

            pipes.clear();
            pipes.reserve(count);

            for (size_t i = 0; i < count; ++i) {
                pipe p;
                getline(in, p.name);
                in >> p.length;   in.ignore();
                in >> p.diametr;  in.ignore();
                in >> p.work;     in.ignore();
                pipes.push_back(p);
            }
            return;
        }
    }
}

void loadcss(istream& in, vector<cs>& css) {
    string x;
    while (getline(in, x)) {
        if (x == "Cs:") {
            size_t count = 0;
            in >> count;
            in.ignore();

            css.clear();
            css.reserve(count);

            for (size_t i = 0; i < count; ++i) {
                cs c;
                getline(in, c.name);
                in >> c.workshop;       in.ignore();
                in >> c.workshop_work;  in.ignore();
                in >> c.classcs;        in.ignore();
                css.push_back(c);
            }
            return;
        }
    }
}

istream& operator >> (istream& in, pipe& p) {
    cout << "\n add pipe: \n";
    cout << "name:  ";
    getline(cin >> ws, p.name);
    cout << "length(double)  ";
    p.length = correctnumber<double>(0, 10000);
    cout << "diametr(int)  ";
    p.diametr = correctnumber<int>(0, 10000);
    cout << "station working? (1-YES, 0 - NO)  ";
    p.work = correctnumber<bool>(0, 1);
    return in;
}

istream& operator >> (istream& in, cs& c) {
    cout << "\n add cs:\n";
    cout << "name:  ";
    getline(cin >> ws, c.name);
    cout << "number of stations(int):  ";
    c.workshop = correctnumber<int>(0, 10000);
    cout << "number of workstations(int):  ";
    c.workshop_work = correctnumber<int>(0, c.workshop);
    cout << "station class(char):  ";
    c.classcs = correctnumber<char>(0, 10000);
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

ostream& operator << (ostream& out, const cs& c) {
    if (c.name != "") {
        out << "\nname:  " << c.name;
        out << "\nnumber of stations:  " << c.workshop;
        out << "\nnumber of workstations:  " << c.workshop_work;
        out << "\nstation class(char):  " << c.classcs <<endl;
    }
    else {
        out << "\nenter the cs\n" << endl;
    }
    return out;
}

pipe& selectpipe(vector<pipe>& p) {
    unsigned int index = correctnumber<unsigned int>(1u, p.size());
    return p[index - 1];
}

cs& selectcs(vector<cs>& css) {
    unsigned int index = correctnumber<unsigned int>(1u, css.size());
    return css[index - 1];
}

int main()
{
    bool q = true;
    vector<pipe> pipes;
    vector<cs> css;

    while (q) {
        cout << "\n 1. add pipe\n 2. add cs\n 3. view all objects\n 4. edit pipe\n 5. edit cs\n 6. save\n 7. upload\n 0. exit\n";

        switch (correctnumber<int>(0, 7)) {
        case 1: {
            pipe p;
            cin >> p;
            pipes.push_back(p);
            break;
        }
        case 2: {
            cs c;
            cin >> c;
            css.push_back(c);
            break;
        }
        case 3: {
            cout << "\nALL OBJECTS:";

            if (pipes.empty()) {
                cout << "\nno pipes\n";
            }
            else {
                cout << "\nPIPES:\n";
                for (const auto& p : pipes) {
                    cout << p;
                }
            }

            if (css.empty()) {
                cout << "\nno cs\n";
            }
            else {
                cout << "\nCSS:\n";
                for (const auto& c : css) {
                    cout << c;
                }
            }
            break;
        }
        case 4: {
            if (pipes.empty()) {
                cout << "\nno pipes\n";
                break;
            }
            editpipe(selectpipe(pipes));
            break;
        }
        case 5: {
            if (css.empty()) {
                cout << "\nno cs\n";
                break;
            }
            editcs(selectcs(css));
            break;
        }
        case 6: {
            ofstream fout;
            fout.open("data.txt", ios::out);
            if (!fout.is_open()) {
                cout << "\ncan not open file for writing\n";
                break;
            }
            saveobj(fout, pipes, css);
            fout.close();
            cout << "\nsaved\n";
            break;
        }
        case 7: {
            ifstream fin;
            fin.open("data.txt", ios::in);
            if (!fin.is_open()) {
                cout << "\ncan not open file for reading\n";
                break;
            }
            loadpipes(fin, pipes);
            loadcss(fin, css);
            fin.close();
            cout << "\nloaded\n";
            break;
        }
        case 0: {
            q = false;
            break;
        }
        }
    }
}