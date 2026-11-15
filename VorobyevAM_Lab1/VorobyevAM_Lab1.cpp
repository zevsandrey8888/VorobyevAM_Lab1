#include <iostream>
#include <fstream>
#include <string>
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

void cinpipe(pipe& p){
    cout << "\n add pipe \n";
    cout << "name:  ";
    getline(cin >> ws, p.name);
    cout << "length(double)  ";
    p.length = correctnumber<double>(0, 10000);;
    cout << "diametr(int)  ";
    p.diametr = correctnumber<int>(0, 10000);;
    cout << "station working? (1-YES, 0 - NO)  ";
    p.work = correctnumber<bool>(0, 10000);;
}

void cincs(cs& c) {
    cout << "\n add cs:\n";
    cout << "name:  ";
    getline(cin >> ws, c.name);
    cout << "number of stations(int):  ";
    c.workshop = correctnumber<int>(0, 10000);
    cout << "number of workstations(int):  ";
    c.workshop_work = correctnumber<int>(0, c.workshop);;
    cout << "station class(char):  ";
    c.classcs = correctnumber<char>(0, 10000);;
}

void printpipe(const pipe& p) {
    cout << "\nPIPES:\n";
    if (p.name != "") {
        cout << "\nname:  " << p.name;
        cout << "\nlength  " << p.length;
        cout << "\ndiametr  " << p.diametr;
        if (p.work == true) {
            cout << "\npipe work\n  ";
        }
        else {
            cout << "\npipe dont work\n  ";
        }
    }
    else {
        cout << "\nenter the pipe\n  ";
    }

}


void printcs(const cs& c) {
    cout << "\nCSS:\n";
    if (c.name != "") {
        cout << "\nname:  " << c.name;
        cout << "\nnumber of stations:  " << c.workshop;
        cout << "\nnumber of workstations:  " << c.workshop_work;
        cout << "\nstation class(char):  " << c.classcs;
    }
    else {
        cout << "\nenter the cs\n"<<endl;
    }
    
}

void editpipe(pipe& p) {
    if (p.name != "") {
        cout << "\nchange in the operating condition of the pipe:" << "\nenter whether the pipe is working(1-yes, 0-no):";
        p.work = correctnumber<bool>(0,1);
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

void saveobj(const pipe& p, const cs& c) {
    ofstream fout;
    fout.open("data.txt", ios::out);
    if (fout.is_open()) {

        if (p.name != "") {
            fout << "Pipe:" << endl << p.name << endl
            << p.length <<endl << p.diametr << endl << p.work << endl;
        }
        else {
            fout << "first, enter the pipe data" << endl;
        }

        if (c.name != "") {
            fout << "Cs:" << endl;
            fout << c.name << endl;
            fout << c.workshop << endl;
            fout << c.workshop_work << endl;
            fout << c.classcs << endl;
        }
        else {
            fout << "first, enter the cs data" << endl;
        }

        fout.close();
        cout << "\nsaved\n";
    }
    else {
        cout << "\ncan not open file\n";
    }
}

void loadpipe(pipe& p) {
    ifstream fin;
    fin.open("data.txt", ios::in);
    if (fin.is_open()) {
        string x;
        while (getline(fin, x)) {
            if (x == "Pipe:") {
                getline(fin, p.name);
                fin >> p.length;     fin.ignore();
                fin >> p.diametr;    fin.ignore();
                fin >> p.work;       fin.ignore();
                break;
            }
        }
        fin.close();
    }
}

void loadcs(cs& c) {
    ifstream fin;
    fin.open("data.txt", ios::in);
    if (fin.is_open()) {
        string x;
        while (getline(fin, x)) {
            if (x == "Cs:") {
                getline(fin, c.name);
                fin >> c.workshop;       fin.ignore();
                fin >> c.workshop_work;  fin.ignore();
                fin >> c.classcs;        fin.ignore();
                break;
            }
        }
        fin.close();
    }
}

int main()
{
    bool q = true;
    pipe p;
    cs c;
    while (q) {
        cout << "\n 1. add pipe\n 2. add cs\n 3. view all objects\n 4. edit pipe\n 5. edit cs\n 6. save\n 7. upload\n 0. exit\n";
        int y = correctnumber<int>(0, 7);
        switch (y) {
            case 1: {
                cinpipe(p);
                break;
            }
            case 2: {
                cincs(c);
                break;
            }
            case 3: {
                cout << "\nALL OBJECTS:";
                printpipe(p);
                printcs(c);
                break;
            }
            case 4: {
                editpipe(p);
                break;
            }
            case 5: {
                editcs(c);
                break;
            }
            case 6: {
                saveobj(p,c);
                break;
            }
            case 7: {
                loadpipe(p);
                loadcs(c);
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

