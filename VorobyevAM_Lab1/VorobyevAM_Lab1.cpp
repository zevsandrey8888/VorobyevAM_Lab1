#include <iostream>
#include <fstream>
#include <string>
using namespace std;

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

pipe cinpipe() {
    pipe p;
    cout << "\n add pipe \n";
    cout << "name:  ";
    cin >> p.name;
    cout << "length(double)  ";
    cin >> p.length;
    cout << "diametr(int)  ";
    cin >> p.diametr;
    cout << "station working? (1-YES, 0 - NO)  ";
    cin >> p.work;
    return p;
}

cs cincs() {
    cs c;
    cout << "\n add cs:\n";
    cout << "name:  ";
    cin >> c.name;
    cout << "number of stations(int):  ";
    cin >> c.workshop;
    cout << "number of workstations(int):  ";
    cin >> c.workshop_work;
    cout << "station class(char):  ";
    cin >> c.classcs;
    return c;
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
        cin >> p.work;
    }
    else {
        cout << "\nenter the pipe\n" << endl;
    }
}

void editcs(cs& c) {
    if (c.name != "") {
        cout << "\nchange in the number of operating stations" << "\nnumber of workstations(int):";
        cin >> c.workshop_work;
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
            fout << "Pipe:" << endl;
            fout << p.name << endl;
            fout << p.length << endl;
            fout << p.diametr << endl;
            fout << p.work << endl;
        }
        else {
            fout << "first, enter the pipe data" << endl;
        }

        if (c.name != "") {
            fout << "cs:" << endl;
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

pipe loadpipe() {
    pipe p;
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
    return p;
}

cs loadcs() {
    cs c;
    ifstream fin;
    fin.open("data.txt", ios::in);
    if (fin.is_open()) {
        string x;
        while (getline(fin, x)) {
            if (x == "cs:") {
                getline(fin, c.name);
                fin >> c.workshop;       fin.ignore();
                fin >> c.workshop_work;  fin.ignore();
                fin >> c.classcs;        fin.ignore();
                break;
            }
        }
        fin.close();
    }
    return c;
}

int main()
{
    string textmenu = "\n 1. add pipe\n 2. add cs\n 3. view all objects\n 4. edit pipe\n 5. edit cs\n 6. save\n 7. upload\n 0. exit\n";
    bool q = true;
    pipe p;
    cs c;
    while (q) {
        cout << textmenu;
        int y;
        cin >> y;
        switch (y) {
            case 1: {
                p = cinpipe();
                break;
            }
            case 2: {
                c = cincs();
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
                p = loadpipe();
                c = loadcs();
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

