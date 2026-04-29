#include <herramientas.h>
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