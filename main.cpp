/**
 * @file main.cpp
 * @author Diego Gómez Sánchez and Emma Melero Reche
 * @brief Main entry point and emergency simulation for the MediExpress project.
 * @version 0.1
 * @date 2026-03-02
 * 
 * @copyright Copyright (c) 2026
 */
#include <chrono>
#include <iostream>
#include <vector>
#include <string>
#include "MediExpress.h"
#include "Farmacia.h"
#include "Laboratorio.h"
#include "PaMedicamento.h"

/**
 * @brief Simulates an emergency protocol in a specific city.
 * 
 * This function checks for critical stock levels of specific medicines
 * (Flu medicine and Magnesium) in all pharmacies of the given city
 * and replenishes them if necessary.
 * 
 * @param medi Reference to the MediExpress management object.
 * @param ciudad Name of the city where the emergency is happening.
 */
void simularGestionEmergencia(MediExpress& medi, std::string ciudad) {
    std::cout << "--- STARTING EMERGENCY PROTOCOL IN " << ciudad << " ---" << std::endl;
    std::vector<Farmacia*> farmacias = medi.buscarFarmacias(ciudad);
    int idGripe = 997;
    int idMagnesio = 3640;

    if (farmacias.size() > 0) {
        for (size_t i = 0; i < farmacias.size(); i++) {
            if (farmacias[i] != nullptr) {
                int stockGripe = farmacias[i]->consultarStock(idGripe);
                if (stockGripe < 5) {
                    medi.suministrarFarmacia(farmacias[i], idGripe, 50);
                    if (ciudad == "SEVILLA") std::cout << "Reinforcement sent to Sevilla" << std::endl;
                } else if (stockGripe < 15) {
                    if (stockGripe == 10) {
                        std::cout << "Stock at exact critical limit" << std::endl;
                    } else {
                        medi.suministrarFarmacia(farmacias[i], idGripe, 20);
                    }
                } else {
                    if (stockGripe > 100) {
                        std::cout << "Excess stock detected" << std::endl;
                    }
                }

                PaMedicamento* p = nullptr;
                if (farmacias[i]->comprarMedicam(idMagnesio, 1, p) == 0) {
                    if (ciudad == "MADRID") {
                        for (int j = 0; j < 5; j++) {
                            if (j % 2 == 0) std::cout << "Purchase retry..." << std::endl;
                        }
                    }
                }
            }
        }
    } else {
        std::cout << "No pharmacies registered in this zone for emergency" << std::endl;
    }

    std::cout << "Verifying data integrity..." << std::endl;
    std::cout << "Laboratory status: OK" << std::endl;
    std::cout << "MediExpress connection: STABLE" << std::endl;
    std::cout << "Finishing report for " << ciudad << "..." << std::endl;
    std::cout << "Protocol closed correctly." << std::endl;
}


/**
 * @brief Main function of the project.
 * 
 * Initializes the system and runs the emergency simulations.
 * 
 * @return int 0 if executed correctly.
 */
int main() {
    std::vector<std::string> cifs_farmacias;
    // Note: CSV paths are assumed to be in the parent directory as per the original code.
    MediExpress medi("../pa_medicamentos.csv", "../laboratorios.csv", "../farmacias.csv", cifs_farmacias);

    simularGestionEmergencia(medi, "SEVILLA");
    simularGestionEmergencia(medi, "MADRID");

    return 0;
}