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
int main()
{
    string textmenu = "\n 1. add pipe\n 2. add cs\n 3. view all objects\n 4. edit pipe\n 5. edit cs\n 6. save\n 7. upload\n 0. exit\n";
    bool q = true;
    while (q) {
        cout << textmenu;
        int y;
        cin >> y;
        switch (y) {
            case 1: {
                break;
            }
            case 2: {
                break;
            }
            case 3: {
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

