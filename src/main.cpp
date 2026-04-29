#include "herramientas.h"
#include <iostream>


using namespace std;

int main(){

    int n;

    cout << "Ingrese una opcion";

    cin >>n;
    switch(n){
        case 1: void guardar_log();
        break;
        case 2: cout << "Sample1";
        break;
        default: cout << "Opcion no valida";
    }

    return 0;
}