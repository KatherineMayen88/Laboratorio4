#include "Header.h"
#include <iostream>
#include <string>

using namespace std;
using namespace System;

string* llenarliebre(string pistaL[], int n) {

    for (size_t i = 0; i < 70; i++)
    {
        if (pistaL[i] == "[L]") {
            if (n < 0 && i < 12) {

            }
            else {
                pistaL[i] = "[ ]";
                pistaL[i + n] = "[L]";
                i = 69;
            }
        }
    }
    return pistaL;
}

string* llenartortuga(string pistaT[], int n) {

    for (size_t i = 0; i < 70; i++)
    {
        if (pistaT[i] == "[T]") {
            if (n < 0 && i < 6) {

            }
            else {
                pistaT[i] = "[ ]";
                pistaT[i + n] = "[T]";
                i = 69;
            }
        }
    }
    return pistaT;
}

string* moverliebre(string pistaL[], int l) {
    pistaL = llenarliebre(pistaL, l);
    return pistaL;
}

string* movertortuga(string pistaT[], int t) {
    pistaT = llenartortuga(pistaT, t);
    return pistaT;
}


int liebre(int random) {
    if (random <= 20) {
        return 0;
    }
    else if (random > 20 && random <= 40) {
        return 9;
    }
    else if (random > 40 && random <= 50) {
        return -12;
    }
    else if (random > 50 && random <= 80) {
        return 1;
    }
    else if (random > 80 && random <= 100) {
        return -2;
    }
}

int tortuga(int random) {
    if (random <= 50) {
        return 5;
    }
    else if (random > 50 && random <= 70) {
        return -6;
    }
    else if (random > 70 && random <= 100) {
        return 1;
    }
}

//MAIN
int main()
{

    cout << "¡BANG! " << endl;
    cout << "¡Y ARRANCAN!" << endl;
    cout << endl;

    string pistaL[70];
    string* punteropistaL;

    string pistaT[70];
    string* punteropistaT;

    bool ganar = false;

    for (size_t i = 0; i < 69; i++)
    {
        pistaL[i] = "[ ]";
        pistaT[i] = "[ ]";
    }

    pistaL[0] = "[L]";
    pistaT[0] = "[T]";
    while (ganar == false) {

        System::Threading::Thread::Sleep(1000);
        int random = 1 + rand() % 101;
        int rl = liebre(random);
        int rt = tortuga(random);
        punteropistaL = moverliebre(pistaL, rl);
        punteropistaT = movertortuga(pistaT, rt);

        for (size_t i = 0; i < 69; i++)
        {
            cout << pistaL[i] << ' ';
            if (pistaL[69] == "[L]") {
                ganar = true;
                cout << "LA LIEBRE GANA, NI HABLAR" << endl;
                cout << endl;
                i = 69;
            }
        }
        cout << endl;
        cout << endl;
        for (size_t i = 0; i < 69; i++)
        {
            cout << pistaT[i] << ' ';
            if (pistaT[69] == "[T]") {
                ganar = true;
                cout << "TORTUGA GANAAAA!!" << endl;
                cout << endl;
                i = 69;
            }
        }
        cout << endl;


        for (size_t i = 0; i < 69; i++)
        {
            if (pistaT[i] == "[T]" && pistaL[i] == "[L]") {
                cout << "OUCH!! TORTUGA MORDIDA" << endl;
            }
        }
        cout << endl;
    }

    std::cin.get();

}