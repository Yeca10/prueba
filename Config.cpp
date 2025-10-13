#include "Config.h"
#include <fstream>
#include "json.hpp"      // Asegúrate de que json.hpp esté en el proyecto
using json = nlohmann::json;

// Definición de la variable global
Config g_Config;

void GuardarConfig() {
    try {
        json j;
        j["alguna_opcion"] = g_Config.alguna_opcion;
        j["valor_opcion"] = g_Config.valor_opcion;

        std::ofstream ofs("config.json");
        if (ofs.is_open()) {
            ofs << j.dump(4); // 4 = indentación para que quede legible
            ofs.close();
        }
    }
    catch (...) {
        // Si falla el guardado, simplemente no hacemos nada
    }
}

void CargarConfig() {
    try {
        std::ifstream ifs("config.json");
        if (!ifs.is_open()) return;

        json j;
        ifs >> j;

        g_Config.alguna_opcion = j.value("alguna_opcion", false);
        g_Config.valor_opcion = j.value("valor_opcion", 0);
        ifs.close();
    }
    catch (...) {
        // Si falla la carga, se mantienen valores por defecto
    }
}
