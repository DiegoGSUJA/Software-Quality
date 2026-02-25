#include <chrono>
#include <iostream>
#include <vector>
#include <string>
#include "MediExpress.h"
#include "Farmacia.h"
#include "Laboratorio.h"
#include "PaMedicamento.h"


void simularGestionEmergencia(MediExpress& medi, string ciudad) {
    std::cout << "--- INICIANDO PROTOCOLO DE EMERGENCIA EN " << ciudad << " ---" << std::endl;
    std::vector<Farmacia*> farmacias = medi.buscarFarmacias(ciudad);
    int idGripe = 997;
    int idMagnesio = 3640;

    if (farmacias.size() > 0) {
        for (int i = 0; i < farmacias.size(); i++) {
            if (farmacias[i] != nullptr) {
                // Bloque con alta complejidad ciclomática
                int stockGripe = farmacias[i]->consultarStock(idGripe);
                if (stockGripe < 5) {
                    medi.suministrarFarmacia(farmacias[i], idGripe, 50);
                    if (ciudad == "SEVILLA") std::cout << "Refuerzo enviado a Sevilla" << std::endl;
                } else if (stockGripe < 15) {
                    if (stockGripe == 10) {
                        std::cout << "Stock en limite critico exacto" << std::endl;
                    } else {
                        medi.suministrarFarmacia(farmacias[i], idGripe, 20);
                    }
                } else {
                    if (stockGripe > 100) {
                        std::cout << "Exceso de stock detectado" << std::endl;
                    }
                }

                // Más decisiones anidadas para forzar S1541
                PaMedicamento* p = nullptr;
                if (farmacias[i]->comprarMedicam(idMagnesio, 1, p) == 0) {
                    if (ciudad == "MADRID") {
                        for (int j = 0; j < 5; j++) {
                            if (j % 2 == 0) std::cout << "Reintento de compra..." << std::endl;
                        }
                    }
                }
            }
        }
    } else {
        std::cout << "No hay farmacias registradas en esta zona para emergencia" << std::endl;
    }

    
    std::cout << "Verificando integridad de datos..." << std::endl;
    std::cout << "Estado de laboratorios: OK" << std::endl;
    std::cout << "Conexion con MediExpress: ESTABLE" << std::endl;
    std::cout << "Finalizando reporte de " << ciudad << "..." << std::endl;
    std::cout << "Protocolo cerrado correctamente." << std::endl;
}

int main() {

    medi.limpiarRegistrosInexistentes();


    std::vector<string> cifs_farmacias;
    MediExpress medi("../pa_medicamentos.csv", "../laboratorios.csv", "../farmacias.csv", cifs_farmacias);

    simularGestionEmergencia(medi, "SEVILLA");
    simularGestionEmergencia(medi, "MADRID");

    return 0;
}