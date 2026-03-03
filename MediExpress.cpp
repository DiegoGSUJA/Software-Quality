/**
 * @file MediExpress.cpp
 * @author Diego Gómez Sánchez and Emma Melero Reche
 * @brief Implementation of the MediExpress class.
 * @version 0.1
 * @date 2026-03-02
 * 
 * @copyright Copyright (c) 2026
 */
#include "Farmacia.h"
#include "PaMedicamento.h"
#include "MediExpress.h"

#include <chrono>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

/**
 * @brief Reads pharmacy data from a CSV file.
 * @param ph Vector to store pharmacies.
 * @param filename CSV file path.
 * @param cifs_farmacias Vector to store CIFs.
 */
void MediExpress::lecturaFarmacias(std::vector<Farmacia> &ph, const std::string &filename, std::vector<std::string> &cifs_farmacias) {
    std::ifstream is;
    std::stringstream columnas;
    std::string fila;
    int leidos = 0;
    std::string cif, provincia, localidad, nombre, direccion, codPostal;

    std::cout << "\nAttempting to open: " << filename << std::endl;
    is.open(filename);
    if (!is.good()) {
        std::cout << "\nError opening pharmacy file: " << filename << std::endl;
        return;
    }

    auto t_ini = std::chrono::high_resolution_clock::now();
    while (std::getline(is, fila)) {
        if (fila == "") continue;

        columnas.clear();
        columnas.str("");
        columnas.str(fila);

        std::getline(columnas, cif, ';');
        std::getline(columnas, provincia, ';');
        std::getline(columnas, localidad, ';');
        std::getline(columnas, nombre, ';');
        std::getline(columnas, direccion, ';');
        std::getline(columnas, codPostal);

        if (cif == "") continue;
        Farmacia f(cif, provincia, localidad, nombre, direccion, codPostal, this);
        ph.push_back(f);
        leidos++;
        if (leidos < 500)
            cifs_farmacias.push_back(cif);
    }
    auto t_fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = t_fin - t_ini;
    is.close();

    std::cout << "Pharmacy read time (std::vector): "
              << std::fixed << std::setprecision(15)
              << duracion.count() << " secs." << std::endl;
    std::cout << "Pharmacies read: " << leidos << std::endl;
}

/**
 * @brief Reads medicine data from a CSV file.
 * @param v Map to store medicines.
 * @param filename CSV file path.
 */
void MediExpress::lecturaMedicamentos(std::map<int, PaMedicamento> &v, const std::string &filename) {
    std::ifstream is;
    std::stringstream columnas;
    std::string fila;
    int leidos = 0;
    std::string id_number, id_alpha, nombre;

    std::cout << "\nAttempting to open: " << filename << std::endl;
    is.open(filename);
    if (!is.good()) {
        std::cout << "\nError opening medicine file: " << filename << std::endl;
        return;
    }

    auto t_ini = std::chrono::high_resolution_clock::now();
    while (std::getline(is, fila)) {
        if (fila == "") continue;
        columnas.clear();
        columnas.str(fila);

        getline(columnas, id_number, ';');
        getline(columnas, id_alpha, ';');
        getline(columnas, nombre, ';');

        try {
            int id = std::stoi(id_number);
            v.insert(std::pair<int, PaMedicamento>(id, PaMedicamento(id, id_alpha, nombre)));
            leidos++;
        } catch (...) {
            // Skip invalid IDs
        }
    }
    auto t_fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = t_fin - t_ini;
    is.close();

    std::cout << "Medicine read time (std::map): "
              << std::fixed << std::setprecision(15)
              << duracion.count() << " secs." << std::endl;
    std::cout << "Medicines read: " << leidos << std::endl;
}

/**
 * @brief Reads laboratory data from a CSV file.
 * @param l List to store laboratories.
 * @param filename CSV file path.
 */
void MediExpress::lecturaLaboratorios(std::list<Laboratorio> &l, const std::string &filename) {
    std::ifstream is(filename, std::ios::binary);
    std::string content = "";
    std::string fila;
    int leidos = 0;

    std::cout << "\nAttempting to open: " << filename << std::endl;
    if (!is.is_open()) {
        std::cout << "\nError opening laboratory file: " << filename << std::endl;
        return;
    }

    content.assign(std::istreambuf_iterator<char>(is), std::istreambuf_iterator<char>());
    is.close();

    size_t pos = 0;
    while ((pos = content.find("\r\n", pos)) != std::string::npos) {
        content.replace(pos, 2, "\n");
    }
    pos = 0;
    while ((pos = content.find('\r', pos)) != std::string::npos) {
        content[pos] = '\n';
        ++pos;
    }

    std::istringstream ss(content);
    auto t_ini = std::chrono::high_resolution_clock::now();
    while (std::getline(ss, fila)) {
        if (fila == "") continue;
        std::stringstream columnas(fila);
        std::string id_str, nombreLab, direccion, codPostal, localidad;

        std::getline(columnas, id_str, ';');
        std::getline(columnas, nombreLab, ';');
        std::getline(columnas, direccion, ';');
        std::getline(columnas, codPostal, ';');
        std::getline(columnas, localidad);

        if (id_str == "") continue;
        int id = 0;
        try {
            id = std::stoi(id_str);
        } catch (...) {
            continue;
        }
        l.push_back(Laboratorio(id, nombreLab, direccion, codPostal, localidad));
        leidos++;
    }
    auto t_fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = t_fin - t_ini;

    std::cout << "Laboratory read time (std::list): "
              << std::fixed << std::setprecision(15)
              << duracion.count() << " secs." << std::endl;
    std::cout << "Laboratories read: " << leidos << std::endl;
}

/**
 * @brief Automatically links medicines to laboratories.
 * @param v Medicine map.
 * @param l Laboratory list.
 */
void MediExpress::enlazaAutomatizado(std::map<int, PaMedicamento> &v, std::list<Laboratorio> &l) {
    int lim = 0;
    auto it = l.begin();
    auto it2 = v.begin();
    while (it2 != v.end() && it != l.end()) {
        it2->second.servidoPor(&(*it));
        ++it2;
        lim++;
        if (lim == 2) {
            lim = 0;
            ++it;
        }
    }
}

/**
 * @brief Randomly populates pharmacies with initial stock.
 * @param cifs_farmacias Loaded CIFs.
 */
void MediExpress::enlaza_Farmacia_medicamento(std::vector<std::string>& cifs_farmacias) {
    int numCIFs = static_cast<int>(cifs_farmacias.size());
    int numMedicamentos = static_cast<int>(medication.size());
    const int medicamentosPorFarmacia = 100;

    std::vector<int> claves_medicamentos;
    for (auto const& [key, val] : medication) {
        claves_medicamentos.push_back(key);
    }

    for (int i = 0; i < numCIFs; i++) {
        Farmacia* farmacia = buscarFarmacia(cifs_farmacias[i]);
        if (farmacia == nullptr) continue;

        for (int j = 0; j < medicamentosPorFarmacia; j++) {
            int indice_medicamento = (i * medicamentosPorFarmacia + j) % numMedicamentos;
            int id_medicamento = claves_medicamentos[indice_medicamento];
            int id_medic = medication[id_medicamento].get_id_num();
            suministrarFarmacia(farmacia, id_medic, 10);
        }
    }
    std::cout << "Cyclic medicine assignment completed." << std::endl;
}

/**
 * @brief Constructor for MediExpress.
 */
MediExpress::MediExpress(const std::string &medicamentos, const std::string &laboratorios, const std::string &farmacias, std::vector<std::string> &cifs_farmacias) {
    lecturaMedicamentos(medication, medicamentos);
    lecturaLaboratorios(labs, laboratorios);
    lecturaFarmacias(pharmacy, farmacias, cifs_farmacias);
    enlazaAutomatizado(medication, labs);
    enlaza_Farmacia_medicamento(cifs_farmacias);

    std::vector<PaMedicamento*> medsSinLab = getMedicamentoSinlab();
    std::cout << "Medicines without lab after link: " << medsSinLab.size() << std::endl;
}

/**
 * @brief Link a medicine to a laboratory.
 */
void MediExpress::suministrarMed(PaMedicamento *pa, Laboratorio *lab) {
    pa->servidoPor(lab);
}

/**
 * @brief Find laboratory by name.
 */
Laboratorio* MediExpress::buscarLab(std::string &nombreLab) {
    for (auto& lab : labs) {
        if (lab.get_nombreLab() == nombreLab) return &lab;
    }
    return nullptr;
}

/**
 * @brief Find laboratories in a city.
 */
std::list<Laboratorio*> MediExpress::buscarLabCiudad(std::string &nombreCiudad) {
    std::list<Laboratorio*> resultado;
    for (auto& lab : labs) {
        if (lab.get_localidad().find(nombreCiudad) != std::string::npos) {
            resultado.push_back(&lab);
        }
    }
    return resultado;
}

/**
 * @brief Find medicines by name.
 */
std::vector<PaMedicamento*> MediExpress::buscarCompuesto(std::string &nombrePA) {
    std::vector<PaMedicamento*> resultado;
    for (auto& [id, med] : medication) {
        if (med.get_nombre() == nombrePA) resultado.push_back(&med);
    }
    return resultado;
}

/**
 * @brief Find medicine by ID.
 */
PaMedicamento* MediExpress::buscarCompuesto(int &id_num) {
    auto it = medication.find(id_num);
    if (it != medication.end()) return &it->second;
    return nullptr;
}

/**
 * @brief Get medicines without an assigned lab.
 */
std::vector<PaMedicamento*> MediExpress::getMedicamentoSinlab() {
    std::vector<PaMedicamento*> resultado;
    for (auto& [id, med] : medication) {
        if (med.get_serve() == nullptr) resultado.push_back(&med);
    }
    return resultado;
}

/**
 * @brief Supply stock to a pharmacy.
 */
void MediExpress::suministrarFarmacia(Farmacia *f, int id_num, int n) {
    PaMedicamento *med = buscarCompuesto(id_num);
    if (med != nullptr) f->nuevoStock(med, n);
}

/**
 * @brief Find pharmacy by CIF.
 */
Farmacia* MediExpress::buscarFarmacia(std::string &cif) {
    for (size_t i = 0; i < pharmacy.size(); i++) {
        if (cif == pharmacy[i].getCif()) return &pharmacy[i];
    }
    return nullptr;
}

/**
 * @brief Find laboratories for a specific medicine name.
 */
std::vector<Laboratorio*> MediExpress::buscarLabs(const std::string &nombrePA) {
    std::vector<Laboratorio*> resultado;
    for (auto& [id, med] : medication) {
        if (med.get_nombre().find(nombrePA) != std::string::npos) {
            Laboratorio* lab = med.get_serve();
            if (lab != nullptr) {
                bool exists = false;
                for (auto* r : resultado) {
                    if (r == lab) { exists = true; break; }
                }
                if (!exists) resultado.push_back(lab);
            }
        }
    }
    return resultado;
}

/**
 * @brief Destructor.
 */
MediExpress::~MediExpress() {}

/**
 * @brief Remove laboratories in a city.
 */
int MediExpress::eliminarLaboratoriosCiudad(const std::string &ciudad) {
    int eliminados = 0;
    auto it = labs.begin();
    while (it != labs.end()) {
        if (it->get_localidad().find(ciudad) != std::string::npos) {
            Laboratorio *lab_buscado = &(*it);
            for (auto& [id, med] : medication) {
                if (med.get_serve() == lab_buscado) med.servidoPor(nullptr);
            }
            it = labs.erase(it);
            eliminados++;
        } else {
            ++it;
        }
    }
    return eliminados;
}

/**
 * @brief Getter for pharmacies.
 */
std::vector<Farmacia>& MediExpress::getpharmacy() {
    return pharmacy;
}

/**
 * @brief Getter for laboratories.
 */
std::list<Laboratorio> &MediExpress::getlabs() {
    return labs;
}

/**
 * @brief Find pharmacies by province.
 */
std::vector<Farmacia*> MediExpress::buscarFarmacias(std::string &provincia) {
    std::vector<Farmacia*> resultado;
    for (size_t i = 0; i < pharmacy.size(); i++) {
        if (pharmacy[i].getProvincia() == provincia) resultado.push_back(&pharmacy[i]);
    }
    return resultado;
}

/**
 * @brief Remove a medicine.
 */
bool MediExpress::eliminarMedicamento(int id_num) {
    PaMedicamento *pa = buscarCompuesto(id_num);
    if (!pa) return false;

    for (size_t i = 0; i < pharmacy.size(); i++) {
        pharmacy[i].eliminarStock(id_num);
    }

    auto it = medication.find(id_num);
    if (it != medication.end()) {
        medication.erase(it);
        return true;
    }
    return false;
}

/**
 * @brief Redistribute stock between pharmacies.
 */
void MediExpress::redistribuirStockUrgente(std::string medicamento, std::string origen, std::string destino) {
    std::cout << "Starting redistribution for: " << medicamento << std::endl;
    auto vOrigen = buscarFarmacias(origen);
    auto vDestino = buscarFarmacias(destino);

    for (auto* fOrg : vOrigen) {
        if (fOrg != nullptr) {
            for (auto* fDest : vDestino) {
                if (fDest != nullptr && fOrg != fDest) {
                    int stockActual = fOrg->consultarStock(999); 
                    if (stockActual > 100) {
                        if (fDest->getProvincia() == fOrg->getProvincia()) {
                            if (stockActual > 500) std::cout << "Massive transfer allowed" << std::endl;
                            else std::cout << "Standard transfer" << std::endl;
                        } else if (fDest->getProvincia() == "MADRID") {
                            std::cout << "National priority detected" << std::endl;
                        }
                    } else {
                        std::cout << "Insufficient stock at source: " << fOrg->getNombre() << std::endl;
                    }
                }
            }
        }
    }
}
