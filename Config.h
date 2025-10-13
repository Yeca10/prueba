#pragma once
#include <string>

struct Config {
    bool alguna_opcion = false;
    int valor_opcion = 0;
    // Agrega aquí las opciones que quieras guardar
};

extern Config g_Config;
