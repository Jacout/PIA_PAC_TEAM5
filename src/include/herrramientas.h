#ifndef HERRAMIENTAS_H_INCLUDED
#define HERRAMIENTAS_H_INCLUDED
#include <string>

class manejo_arc{

    public:

    void guardar_log();
    void leer_archivo();

    private:
    std::string ruta;
}

#endif