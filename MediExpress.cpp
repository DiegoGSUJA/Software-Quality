<<<<<<< HEAD
/**
 * @file MediExpress.cpp
 * @author Diego Gómez Sánchez and Emma Melero Reche
 * @brief Implementation of the MediExpress class.
 * @version 0.1
 * @date 2026-03-02
 * 
 * @copyright Copyright (c) 2026
 */
=======
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
#include "Farmacia.h"
#include "PaMedicamento.h"
#include "MediExpress.h"

#include <chrono>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

<<<<<<< HEAD
/**
 * @brief Reads pharmacy data from a CSV file.
 * @param ph Vector to store pharmacies.
 * @param filename CSV file path.
 * @param cifs_farmacias Vector to store CIFs.
 */
void MediExpress::lecturaFarmacias(std::vector<Farmacia> &ph, const std::string &filename, std::vector<std::string> &cifs_farmacias) {
=======
void MediExpress::lecturaFarmacias(std::vector<Farmacia> &ph, const std::string &filename, std::vector<string> &cifs_farmacias) {
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
    std::ifstream is;
    std::stringstream columnas;
    std::string fila;
    int leidos = 0;
    std::string cif, provincia, localidad, nombre, direccion, codPostal;

<<<<<<< HEAD
    std::cout << "\nAttempting to open: " << filename << std::endl;
    is.open(filename);
    if (!is.good()) {
        std::cout << "\nError opening pharmacy file: " << filename << std::endl;
        return;
    }

    auto t_ini = std::chrono::high_resolution_clock::now();
=======
    std::cout << "\nIntentando abrir: " << filename << std::endl;
    is.open(filename);
    if (!is.good()) {
        std::cout << "\nError de apertura en archivo de farmacias: " << filename << std::endl;
        return;
    }

    std::chrono::high_resolution_clock::time_point t_ini = std::chrono::high_resolution_clock::now();
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
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
<<<<<<< HEAD
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
=======
        Farmacia f(cif, provincia, localidad, nombre, direccion, codPostal,this);
        ph.push_back(f);
        leidos++;
        if (leidos<500)
        cifs_farmacias.push_back(cif);

    }
    std::chrono::high_resolution_clock::time_point t_fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = t_fin - t_ini;
    is.close();

    std::cout << "Tiempo de lectura de farmacias (std::vector): "
              << std::fixed << std::setprecision(15)
              << duracion.count() << " segs." << std::endl;
    std::cout << "Farmacias leidas: " << leidos << std::endl;
}

void MediExpress::lecturaMedicamentos(std::map<int,PaMedicamento> &v, const std::string &filename) {
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
    std::ifstream is;
    std::stringstream columnas;
    std::string fila;
    int leidos = 0;
    std::string id_number, id_alpha, nombre;

<<<<<<< HEAD
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
=======
    std::cout << "\nIntentando abrir: " << filename << std::endl;
    is.open(filename);
    if (!is.good()) {
        std::cout << "\nError de apertura en archivo de medicamentos: " << filename << std::endl;
        return;
    }

    std::chrono::high_resolution_clock::time_point t_ini = std::chrono::high_resolution_clock::now();
    while (std::getline(is, fila)) {
        if (fila == "") continue;
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
        columnas.str(fila);

        getline(columnas, id_number, ';');
        getline(columnas, id_alpha, ';');
        getline(columnas, nombre, ';');

        try {
            int id = std::stoi(id_number);
<<<<<<< HEAD
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
=======
            v.insert(std::pair<int,PaMedicamento> (id ,PaMedicamento(id, id_alpha, nombre)));
            leidos++;
        } catch (...) {
            // Ignora líneas con IDs no numéricos o vacíos
        }
        columnas.clear();
    }
    std::chrono::high_resolution_clock::time_point t_fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = t_fin - t_ini;
    is.close();

    std::cout << "Tiempo de lectura de medicamentos (std::map): "
              << std::fixed << std::setprecision(15)
              << duracion.count() << " segs." << std::endl;
    std::cout << "Medicamentos leidos: " << leidos << std::endl;
}

>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
void MediExpress::lecturaLaboratorios(std::list<Laboratorio> &l, const std::string &filename) {
    std::ifstream is(filename, std::ios::binary);
    std::string content = "";
    std::string fila;
    int leidos = 0;

<<<<<<< HEAD
    std::cout << "\nAttempting to open: " << filename << std::endl;
    if (!is.is_open()) {
        std::cout << "\nError opening laboratory file: " << filename << std::endl;
=======
    std::cout << "\nIntentando abrir: " << filename << std::endl;
    if (!is.is_open()) {
        std::cout << "\nError de apertura en archivo de laboratorios: " << filename << std::endl;
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
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
<<<<<<< HEAD
    auto t_ini = std::chrono::high_resolution_clock::now();
=======


    std::chrono::high_resolution_clock::time_point t_ini = std::chrono::high_resolution_clock::now();
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
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
<<<<<<< HEAD
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
=======
    std::chrono::high_resolution_clock::time_point t_fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = t_fin - t_ini;

    std::cout << "Tiempo de lectura de laboratorios (std::list): "
              << std::fixed << std::setprecision(15)
              << duracion.count() << " segs." << std::endl;
    std::cout << "Laboratorios leidos: " << leidos << std::endl;
}

void MediExpress::enlazaAutomatizado(std::map<int,PaMedicamento> &v, std::list<Laboratorio> &l){

>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
    int lim = 0;
    auto it = l.begin();
    auto it2 = v.begin();
    while (it2 != v.end() && it != l.end()) {
<<<<<<< HEAD
        it2->second.servidoPor(&(*it));
        ++it2;
        lim++;
=======
        // Asigna el laboratorio actual al medicamento
        it2->second.servidoPor(&(*it));
        ++it2;
        lim++;

        // Despues de dos asignaciones, avanza al siguiente laboratorio
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
        if (lim == 2) {
            lim = 0;
            ++it;
        }
    }
}

<<<<<<< HEAD
/**
 * @brief Randomly populates pharmacies with initial stock.
 * @param cifs_farmacias Loaded CIFs.
 */
=======
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
void MediExpress::enlaza_Farmacia_medicamento(std::vector<std::string>& cifs_farmacias) {
    int numCIFs = static_cast<int>(cifs_farmacias.size());
    int numMedicamentos = static_cast<int>(medication.size());
    const int medicamentosPorFarmacia = 100;

    std::vector<int> claves_medicamentos;
<<<<<<< HEAD
    for (auto const& [key, val] : medication) {
        claves_medicamentos.push_back(key);
    }

=======

    auto it = medication.begin();
    while (it != medication.end()) {
        claves_medicamentos.push_back(it->first);
        ++it;
    }


>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
    for (int i = 0; i < numCIFs; i++) {
        Farmacia* farmacia = buscarFarmacia(cifs_farmacias[i]);
        if (farmacia == nullptr) continue;

        for (int j = 0; j < medicamentosPorFarmacia; j++) {
            int indice_medicamento = (i * medicamentosPorFarmacia + j) % numMedicamentos;
            int id_medicamento = claves_medicamentos[indice_medicamento];
            int id_medic = medication[id_medicamento].get_id_num();
<<<<<<< HEAD
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
=======
            suministrarFarmacia(farmacia, id_medic,10);
        }
    }
    std::cout << "Asignacion ciclica de medicamentos completada." << std::endl;
}




MediExpress::MediExpress(const std::string &medicamentos, const std::string &laboratorios, const std::string &farmacias, std::vector<string> &cifs_farmacias) {

    lecturaMedicamentos(medication, medicamentos);
    lecturaLaboratorios(labs, laboratorios);
    lecturaFarmacias(pharmacy, farmacias,cifs_farmacias);


    // Establecer las relaciones
    enlazaAutomatizado(medication, labs);
    enlaza_Farmacia_medicamento(cifs_farmacias);

    // Verificar el resultado del enlace
    std::vector<PaMedicamento*> medsSinLab = getMedicamentoSinlab();
    std::cout << "Medicamentos sin laboratorio asignado despues del enlace: " << medsSinLab.size() << std::endl;
}


>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
void MediExpress::suministrarMed(PaMedicamento *pa, Laboratorio *lab) {
    pa->servidoPor(lab);
}

<<<<<<< HEAD
/**
 * @brief Find laboratory by name.
 */
Laboratorio* MediExpress::buscarLab(std::string &nombreLab) {
    for (auto& lab : labs) {
        if (lab.get_nombreLab() == nombreLab) return &lab;
=======

Laboratorio* MediExpress::buscarLab(std::string &nombreLab) {
    std::list<Laboratorio>::iterator it = labs.begin();
    while (it != labs.end()) {
        if (it->get_nombreLab() == nombreLab) {
            return &(*it);
        }
        it++;
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
    }
    return nullptr;
}

<<<<<<< HEAD
/**
 * @brief Find laboratories in a city.
 */
std::list<Laboratorio*> MediExpress::buscarLabCiudad(std::string &nombreCiudad) {
    std::list<Laboratorio*> resultado;
    for (auto& lab : labs) {
        if (lab.get_localidad().find(nombreCiudad) != std::string::npos) {
            resultado.push_back(&lab);
        }
=======

std::list<Laboratorio*> MediExpress::buscarLabCiudad(std::string &nombreCiudad) {
    std::list<Laboratorio>::iterator it = labs.begin();
    std::list<Laboratorio*> resultado;

    while (it != labs.end()) {
        // Busca la subcadena en la localidad (requerido por el enunciado)
        if (it->get_localidad().find(nombreCiudad) != std::string::npos){
            resultado.push_back(&(*it)); // Insertar el puntero al Laboratorio
        }
        it++;
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
    }
    return resultado;
}

<<<<<<< HEAD
/**
 * @brief Find medicines by name.
 */
std::vector<PaMedicamento*> MediExpress::buscarCompuesto(std::string &nombrePA) {
    std::vector<PaMedicamento*> resultado;
    for (auto& [id, med] : medication) {
        if (med.get_nombre() == nombrePA) resultado.push_back(&med);
=======

std::vector<PaMedicamento*> MediExpress::buscarCompuesto(std::string &nombrePA) {
    std::vector<PaMedicamento*> resultado;
    auto it = medication.begin();
    while (it!= medication.end()) {
        if (it->second.get_nombre()==nombrePA) {
            resultado.push_back(&it->second);
        }
        ++it;
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
    }
    return resultado;
}

<<<<<<< HEAD
/**
 * @brief Find medicine by ID.
 */
=======
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
PaMedicamento* MediExpress::buscarCompuesto(int &id_num) {
    auto it = medication.find(id_num);
    if (it != medication.end()) return &it->second;
    return nullptr;
}

<<<<<<< HEAD
/**
 * @brief Get medicines without an assigned lab.
 */
std::vector<PaMedicamento*> MediExpress::getMedicamentoSinlab() {
    std::vector<PaMedicamento*> resultado;
    for (auto& [id, med] : medication) {
        if (med.get_serve() == nullptr) resultado.push_back(&med);
=======
std::vector<PaMedicamento*> MediExpress::getMedicamentoSinlab() {
    std::vector<PaMedicamento*> resultado;
    auto it = medication.begin();
    while (it != medication.end()) {
        if (it->second.get_serve()==nullptr) {
            resultado.push_back(&it->second);
        }
        it++;
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
    }
    return resultado;
}

<<<<<<< HEAD
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
=======

void MediExpress::suministrarFarmacia(Farmacia *f, int id_num, int n) {
    PaMedicamento *med = buscarCompuesto(id_num);
    if (med != nullptr) {
        f->nuevoStock(med,n);
    }
}

Farmacia* MediExpress::buscarFarmacia(std::string &cif){
    for (size_t i=0;i<pharmacy.size();i++) {
        if (cif == pharmacy[i].getCif()) {
            return &pharmacy[i];
        }
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
    }
    return nullptr;
}

<<<<<<< HEAD
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
=======

std::vector<Laboratorio*> MediExpress::buscarLabs(const std::string &nombrePA) {
    std::vector<Laboratorio*> resultado;

    for (auto it = medication.begin();
         it != medication.end();
         ++it)
    {

        const PaMedicamento& pa = it->second;


        if (pa.get_nombre().find(nombrePA) != std::string::npos) {


            Laboratorio* lab = pa.get_serve();


            if (lab != nullptr) {


                bool existe = false;


                for (size_t j = 0; j < resultado.size(); ++j) {
                    if (resultado[j] == lab) {
                        existe = true;
                        break;
                    }
                }

                if (!existe) {
                    resultado.push_back(lab);
                }
            }
        }
    }

    return resultado;
}




MediExpress::~MediExpress() {
    // vector<PaMedicamento> medication; y ListaEnlazada<Laboratorio> labs;
    // liberan su propia memoria automaticamente.
}


int MediExpress::eliminarLaboratoriosCiudad(const std::string &ciudad) {
    int eliminados = 0;
    std::list<Laboratorio>::iterator it = labs.begin();
    while (it != labs.end()) {
        if (it->get_localidad().find(ciudad) != std::string::npos) {
            Laboratorio *lab_buscado = &(*it);
            auto it2 = medication.begin();
            while (it2 != medication.end()) {
                if (it2->second.get_serve() == lab_buscado) {
                    it2->second.servidoPor(nullptr);
                }
                ++it2;
            }
            it = labs.erase(it);
            eliminados++;
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
        }
    }
    return eliminados;
}

<<<<<<< HEAD
/**
 * @brief Getter for pharmacies.
 */
=======
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
std::vector<Farmacia>& MediExpress::getpharmacy() {
    return pharmacy;
}

<<<<<<< HEAD
/**
 * @brief Getter for laboratories.
 */
=======
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
std::list<Laboratorio> &MediExpress::getlabs() {
    return labs;
}

<<<<<<< HEAD
/**
 * @brief Find pharmacies by province.
 */
std::vector<Farmacia*> MediExpress::buscarFarmacias(std::string &provincia) {
    std::vector<Farmacia*> resultado;
    for (size_t i = 0; i < pharmacy.size(); i++) {
        if (pharmacy[i].getProvincia() == provincia) resultado.push_back(&pharmacy[i]);
=======
std::vector<Farmacia*> MediExpress::buscarFarmacias(string &provincia) {
    std::vector<Farmacia*> resultado;
    for (size_t i = 0; i<pharmacy.size(); i++) {
        if (pharmacy[i].getProvincia() == provincia) {
            resultado.push_back(&pharmacy[i]);
        }
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
    }
    return resultado;
}

<<<<<<< HEAD
/**
 * @brief Remove a medicine.
 */
=======
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
bool MediExpress::eliminarMedicamento(int id_num) {
    PaMedicamento *pa = buscarCompuesto(id_num);
    if (!pa) return false;

    for (size_t i = 0; i < pharmacy.size(); i++) {
        pharmacy[i].eliminarStock(id_num);
    }

<<<<<<< HEAD
    auto it = medication.find(id_num);
=======
    auto it = medication.find(pa->get_id_num());
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
    if (it != medication.end()) {
        medication.erase(it);
        return true;
    }
<<<<<<< HEAD
    return false;
}

/**
 * @brief Redistribute stock between pharmacies.
 */
void MediExpress::redistribuirStockUrgente(std::string medicamento, std::string origen, std::string destino) {
    std::cout << "Starting redistribution for: " << medicamento << std::endl;
    auto vOrigen = buscarFarmacias(origen);
    auto vDestino = buscarFarmacias(destino);

=======

    return false;
}


void MediExpress::redistribuirStockUrgente(string medicamento, string origen, string destino) {
    std::cout << "Iniciando redistribución de: " << medicamento << std::endl;
    vector<Farmacia*> vOrigen = buscarFarmacias(origen);
    vector<Farmacia*> vDestino = buscarFarmacias(destino);

    // S1541: Complejidad excesiva por bucles anidados con condiciones múltiples
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
    for (auto* fOrg : vOrigen) {
        if (fOrg != nullptr) {
            for (auto* fDest : vDestino) {
                if (fDest != nullptr && fOrg != fDest) {
<<<<<<< HEAD
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
=======
                    int stockActual = fOrg->consultarStock(999); // ID genérico
                    if (stockActual > 100) {
                        if (fDest->getProvincia() == fOrg->getProvincia()) {
                            if (stockActual > 500) {
                                std::cout << "Transferencia masiva permitida" << std::endl;
                            } else {
                                std::cout << "Transferencia estándar" << std::endl;
                            }
                        } else if (fDest->getProvincia() == "MADRID") {
                            std::cout << "Prioridad nacional detectada" << std::endl;
                        }
                    } else {
                        
                        std::cout << "Stock insuficiente en origen: " << fOrg->getNombre() << std::endl;
                        std::cout << "Cancelando operación para este nodo..." << std::endl;
                        std::cout << "Reintentando con siguiente nodo disponible en " << destino << std::endl;
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
                    }
                }
            }
        }
    }
}
<<<<<<< HEAD
=======

>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
