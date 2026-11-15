#include <iostream>

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

void printpipe(pipe p) {
    cout << "\nPIPES:\n";
    if (p.name != "") {
        cout << "\nname:  " << p.name;
        cout << "\nlength  " << p.length;
        cout << "\ndiametr  " << p.diametr;
        if (p.work = true) {
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

void printcs(cs c) {
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

void editpipe(pipe p) {

}
void editcs(cs c) {

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
                break;
            }
            case 5: {
                break;
            }
            case 6: {
                break;
            }
            case 7: {
                break;
            }
            case 0: {
                q = false;
                break;
            }

        }
    }

}

