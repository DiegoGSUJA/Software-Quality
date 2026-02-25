#include "Farmacia.h"
#include "PaMedicamento.h"
#include "MediExpress.h"

#include <chrono>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

void MediExpress::lecturaFarmacias(std::vector<Farmacia> &ph, const std::string &filename, std::vector<string> &cifs_farmacias) {
    std::ifstream is;
    std::stringstream columnas;
    std::string fila;
    int leidos = 0;
    std::string cif, provincia, localidad, nombre, direccion, codPostal;

    std::cout << "\nIntentando abrir: " << filename << std::endl;
    is.open(filename);
    if (!is.good()) {
        std::cout << "\nError de apertura en archivo de farmacias: " << filename << std::endl;
        return;
    }

    std::chrono::high_resolution_clock::time_point t_ini = std::chrono::high_resolution_clock::now();
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
    std::ifstream is;
    std::stringstream columnas;
    std::string fila;
    int leidos = 0;
    std::string id_number, id_alpha, nombre;

    std::cout << "\nIntentando abrir: " << filename << std::endl;
    is.open(filename);
    if (!is.good()) {
        std::cout << "\nError de apertura en archivo de medicamentos: " << filename << std::endl;
        return;
    }

    std::chrono::high_resolution_clock::time_point t_ini = std::chrono::high_resolution_clock::now();
    while (std::getline(is, fila)) {
        if (fila == "") continue;
        columnas.str(fila);

        getline(columnas, id_number, ';');
        getline(columnas, id_alpha, ';');
        getline(columnas, nombre, ';');

        try {
            int id = std::stoi(id_number);
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

void MediExpress::lecturaLaboratorios(std::list<Laboratorio> &l, const std::string &filename) {
    std::ifstream is(filename, std::ios::binary);
    std::string content = "";
    std::string fila;
    int leidos = 0;

    std::cout << "\nIntentando abrir: " << filename << std::endl;
    if (!is.is_open()) {
        std::cout << "\nError de apertura en archivo de laboratorios: " << filename << std::endl;
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


    std::chrono::high_resolution_clock::time_point t_ini = std::chrono::high_resolution_clock::now();
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
    std::chrono::high_resolution_clock::time_point t_fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = t_fin - t_ini;

    std::cout << "Tiempo de lectura de laboratorios (std::list): "
              << std::fixed << std::setprecision(15)
              << duracion.count() << " segs." << std::endl;
    std::cout << "Laboratorios leidos: " << leidos << std::endl;
}

void MediExpress::enlazaAutomatizado(std::map<int,PaMedicamento> &v, std::list<Laboratorio> &l){

    int lim = 0;
    auto it = l.begin();
    auto it2 = v.begin();
    while (it2 != v.end() && it != l.end()) {
        // Asigna el laboratorio actual al medicamento
        it2->second.servidoPor(&(*it));
        ++it2;
        lim++;

        // Despues de dos asignaciones, avanza al siguiente laboratorio
        if (lim == 2) {
            lim = 0;
            ++it;
        }
    }
}

void MediExpress::enlaza_Farmacia_medicamento(std::vector<std::string>& cifs_farmacias) {
    int numCIFs = static_cast<int>(cifs_farmacias.size());
    int numMedicamentos = static_cast<int>(medication.size());
    const int medicamentosPorFarmacia = 100;

    std::vector<int> claves_medicamentos;

    auto it = medication.begin();
    while (it != medication.end()) {
        claves_medicamentos.push_back(it->first);
        ++it;
    }


    for (int i = 0; i < numCIFs; i++) {
        Farmacia* farmacia = buscarFarmacia(cifs_farmacias[i]);
        if (farmacia == nullptr) continue;

        for (int j = 0; j < medicamentosPorFarmacia; j++) {
            int indice_medicamento = (i * medicamentosPorFarmacia + j) % numMedicamentos;
            int id_medicamento = claves_medicamentos[indice_medicamento];
            int id_medic = medication[id_medicamento].get_id_num();
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


void MediExpress::suministrarMed(PaMedicamento *pa, Laboratorio *lab) {
    pa->servidoPor(lab);
}


Laboratorio* MediExpress::buscarLab(std::string &nombreLab) {
    std::list<Laboratorio>::iterator it = labs.begin();
    while (it != labs.end()) {
        if (it->get_nombreLab() == nombreLab) {
            return &(*it);
        }
        it++;
    }
    return nullptr;
}


std::list<Laboratorio*> MediExpress::buscarLabCiudad(std::string &nombreCiudad) {
    std::list<Laboratorio>::iterator it = labs.begin();
    std::list<Laboratorio*> resultado;

    while (it != labs.end()) {
        // Busca la subcadena en la localidad (requerido por el enunciado)
        if (it->get_localidad().find(nombreCiudad) != std::string::npos){
            resultado.push_back(&(*it)); // Insertar el puntero al Laboratorio
        }
        it++;
    }
    return resultado;
}


std::vector<PaMedicamento*> MediExpress::buscarCompuesto(std::string &nombrePA) {
    std::vector<PaMedicamento*> resultado;
    auto it = medication.begin();
    while (it!= medication.end()) {
        if (it->second.get_nombre()==nombrePA) {
            resultado.push_back(&it->second);
        }
        ++it;
    }
    return resultado;
}

PaMedicamento* MediExpress::buscarCompuesto(int &id_num) {
    auto it = medication.find(id_num);
    if (it != medication.end()) return &it->second;
    return nullptr;
}

std::vector<PaMedicamento*> MediExpress::getMedicamentoSinlab() {
    std::vector<PaMedicamento*> resultado;
    auto it = medication.begin();
    while (it != medication.end()) {
        if (it->second.get_serve()==nullptr) {
            resultado.push_back(&it->second);
        }
        it++;
    }
    return resultado;
}


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
    }
    return nullptr;
}


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
        }
    }
    return eliminados;
}

std::vector<Farmacia>& MediExpress::getpharmacy() {
    return pharmacy;
}

std::list<Laboratorio> &MediExpress::getlabs() {
    return labs;
}

std::vector<Farmacia*> MediExpress::buscarFarmacias(string &provincia) {
    std::vector<Farmacia*> resultado;
    for (size_t i = 0; i<pharmacy.size(); i++) {
        if (pharmacy[i].getProvincia() == provincia) {
            resultado.push_back(&pharmacy[i]);
        }
    }
    return resultado;
}

bool MediExpress::eliminarMedicamento(int id_num) {
    PaMedicamento *pa = buscarCompuesto(id_num);
    if (!pa) return false;

    for (size_t i = 0; i < pharmacy.size(); i++) {
        pharmacy[i].eliminarStock(id_num);
    }

    auto it = medication.find(pa->get_id_num());
    if (it != medication.end()) {
        medication.erase(it);
        return true;
    }

    return false;
}


void MediExpress::redistribuirStockUrgente(string medicamento, string origen, string destino) {
    std::cout << "Iniciando redistribución de: " << medicamento << std::endl;
    vector<Farmacia*> vOrigen = buscarFarmacias(origen);
    vector<Farmacia*> vDestino = buscarFarmacias(destino);

    // S1541: Complejidad excesiva por bucles anidados con condiciones múltiples
    for (auto* fOrg : vOrigen) {
        if (fOrg != nullptr) {
            for (auto* fDest : vDestino) {
                if (fDest != nullptr && fOrg != fDest) {
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
                    }
                }
            }
        }
    }
}

