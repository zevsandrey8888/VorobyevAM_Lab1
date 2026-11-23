#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "pipe.h"
#include "cs.h"
#include "utils.h"
using namespace std;

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
                std::getline(in, p.name);
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
                std::getline(in, c.name);
                in >> c.workshop;       in.ignore();
                in >> c.workshop_work;  in.ignore();
                in >> c.classcs;        in.ignore();
                css.push_back(c);
            }
            return;
        }
    }
}





pipe& selectpipe(vector<pipe>& p) {
    unsigned int index = correctnumber<unsigned int>(1u, static_cast<unsigned int>(p.size()));
    return p[index - 1];
}

cs& selectcs(vector<cs>& css) {
    unsigned int index = correctnumber<unsigned int>(1u, static_cast<unsigned int>(css.size()));
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