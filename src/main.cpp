#include "herra.h"
#include <iostream>


using namespace std;

int main(){

    int n;

    cout << "Ingrese una opcion";
    cin >>n;
    cout << n;
    switch(n){
        case 1:guardar_log();
        break;
        case 2:leer_archivo();
        break;
        case 3: cout << "Sample1";
        break;
        default: cout << "Opcion no valida";
    }

    return 0;
}