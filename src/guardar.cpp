#include "herra.h"
#include <iostream>
#include <fstream>


using namespace std;
void guardar_log(){
    ofstream ofs("registro.txt", ios::out);

    ofs << "Evento: acceso no autorizado\n";
    int codigo = 403;
    ofs << "Código: " << codigo << endl;
    ofs.close();
    cout << "Registro creado exitosamente." << endl;
}

void leer_archivo(){

    string ruta;

    cout << "Ingrese la ruta del archivo a revisar" << "\n";
    cin >> ruta;
    ifstream ifs(ruta);
    
    string linea;
    
    while (getline(ifs, linea)){
        cout << linea << endl;

    }
    ifs.close();
}