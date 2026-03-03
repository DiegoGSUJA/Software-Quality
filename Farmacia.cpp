<<<<<<< HEAD
/**
 * @file Farmacia.cpp
 * @author Diego Gómez Sánchez and Emma Melero Reche
 * @brief Implementation of the Farmacia class.
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

#include <iostream>

<<<<<<< HEAD
/**
 * @brief Default constructor.
 */
Farmacia::Farmacia(): cif(""), provincia(""), localidad(""), nombre(""),
                      direccion(""), codPostal(""),  linkMedi(nullptr) {}

/**
 * @brief Parameterized constructor.
 * @param unCif CIF identification.
 * @param unaProvincia Province name.
 * @param unaLocalidad City name.
 * @param unNombre Pharmacy name.
 * @param unaDireccion Street address.
 * @param unCodPostal Postal code.
 * @param nlinkMedi Pointer to the MediExpress interface.
 */
=======
Farmacia::Farmacia(): cif(""), provincia(""), localidad(""), nombre(""),
                      direccion(""), codPostal(""),  linkMedi(nullptr) {}

>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
Farmacia::Farmacia(const std::string &unCif, const std::string &unaProvincia, const std::string &unaLocalidad,
                   const std::string &unNombre, const std::string &unaDireccion, const std::string &unCodPostal, MediExpress *nlinkMedi) :
        cif(unCif), provincia(unaProvincia), localidad(unaLocalidad), nombre(unNombre),
        direccion(unaDireccion), codPostal(unCodPostal),linkMedi(nlinkMedi), order(){}

<<<<<<< HEAD
/**
 * @brief Copy constructor.
 * @param orig Pharmacy object to copy.
 */
Farmacia::Farmacia(const Farmacia &orig): cif(orig.cif), provincia(orig.provincia), localidad(orig.localidad),nombre(orig.nombre),
                                          direccion(orig.direccion), codPostal(orig.codPostal), linkMedi(orig.linkMedi), order(orig.order) {}

/**
 * @brief Assignment operator.
 * @param orig Pharmacy object to copy.
 * @return Reference to the current object.
 */
=======
Farmacia::Farmacia(const Farmacia &orig): cif(orig.cif), provincia(orig.provincia), localidad(orig.localidad),nombre(orig.nombre),
                                          direccion(orig.direccion), codPostal(orig.codPostal), linkMedi(orig.linkMedi), order(orig.order) {}

>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
Farmacia& Farmacia::operator=(const Farmacia &orig){
    if(this != &orig){
        cif = orig.cif;
        provincia = orig.provincia;
        localidad = orig.localidad;
        nombre = orig.nombre;
        direccion = orig.direccion;
        codPostal = orig.codPostal;
        linkMedi = orig.linkMedi;
        order = orig.order;
    }
    return *this;
}

<<<<<<< HEAD
/**
 * @brief Places a restock order to MediExpress.
 * @param id_num ID of the medicine.
 * @param n Number of units to order.
 */
=======
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
void Farmacia::pedidoMedicam(int id_num,int n){
    if (linkMedi) linkMedi->suministrarFarmacia(this, id_num,n);
}

<<<<<<< HEAD
/**
 * @brief Destructor.
 */
Farmacia::~Farmacia() {
}

/**
 * @brief Internal method to find stock by medicine ID.
 * @param id_num ID of the medicine.
 * @return Number of units in stock.
 */
=======

Farmacia::~Farmacia() {
}

>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
int Farmacia::buscaMedicamID(int &id_num){
    Stock st(id_num);
    std::set<Stock>::iterator it = order.find(st);
    if (it != order.end()) {
        return it->getnum_stock();
    }
    return 0;
}

<<<<<<< HEAD
/**
 * @brief Set the CIF of the pharmacy.
 * @param cif New CIF.
 */
=======

>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
void Farmacia::setCif(const std::string &cif) {
    Farmacia::cif = cif;
}

<<<<<<< HEAD
/**
 * @brief Get the CIF.
 * @return std::string the CIF.
 */
=======
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
std::string Farmacia::getCif() {
    return cif;
}

<<<<<<< HEAD
/**
 * @brief Sells a medicine to a customer.
 *
 * If stock is available, it decrements by one unit.
 * If not, it requests a restock from MediExpress.
 *
 * @param id_num  Numeric ID of the medicine.
 * @param n       Units to request if out of stock.
 * @param result  Output pointer to the purchased PaMedicamento.
 * @return Stock level before the attempt.
 */
=======
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
int Farmacia::comprarMedicam(int id_num, int n, PaMedicamento*& result) {
    int stock_inicial = buscaMedicamID(id_num);
    if (stock_inicial >= 1) {
        Stock st(id_num);
        std::set<Stock>::iterator it = order.find(st);
        if (it != order.end()) {
            Stock copy = *it;
            order.erase(it);
<<<<<<< HEAD
            copy.decrementa(1); // User buys 1 unit
            result = copy.getPaMedicamento();
            order.insert(copy);
            return stock_inicial;
        } else {
=======
            copy.decrementa(1); // Usuario compra 1 unidad
            result = copy.getPaMedicamento(); // Asigna el medicamento comprado
            order.insert(copy);
            return stock_inicial;
        } else {
            // Error: stock inconsistente
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
            result = nullptr;
            return stock_inicial;
        }
    } else {
<<<<<<< HEAD
        pedidoMedicam(id_num, n); // Request replenishment
=======
        pedidoMedicam(id_num, n); // Pedido de n unidades para reponer
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
        result = nullptr;
        return stock_inicial;
    }
}

<<<<<<< HEAD
/**
 * @brief Adds or updates stock for a medicine.
 * @param p Pointer to the medicine.
 * @param n Number of units to add.
 */
=======


>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
void Farmacia::nuevoStock(PaMedicamento *p, int n) {
    Stock nuevo(n,p);
    std::set<Stock>::iterator it = order.find(nuevo);
    if (it != order.end()) {
            Stock copy = *it;
            order.erase(it);
            copy.incrementa(n);
            order.insert(copy);
    } else {
        order.insert(nuevo);
    }
}

<<<<<<< HEAD
/**
 * @brief Removes a medicine from the inventory.
 * @param id_num ID of the medicine.
 * @return true if removed, false if not found.
 */
=======
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
bool Farmacia::eliminarStock(int id_num) {
    Stock temporal(id_num);
    std::set<Stock>::iterator it = order.find(temporal);

    if (it != order.end()) {
        order.erase(it);
        return true;
    }
    return false;
}

<<<<<<< HEAD
/**
 * @brief Get the City (localidad).
 * @return string& reference to the city.
 */
std::string &Farmacia::getLocalidad() {
    return localidad;
}

/**
 * @brief Get the Province.
 * @return string& reference to the province.
 */
std::string &Farmacia::getProvincia() {
    return provincia;
}

/**
 * @brief Get the Name of the pharmacy.
 * @return string& reference to the name.
 */
std::string &Farmacia::getNombre()  {
    return nombre;
}

/**
 * @brief Searches for medicines by partial name.
 * @param nombreParcial Part of the name to search for.
 * @return Vector of pointers to matching medicines.
 */
=======
string &Farmacia::getLocalidad() {
    return localidad;
}

string &Farmacia::getProvincia() {
    return provincia;
}

string &Farmacia::getNombre()  {
    return nombre;
}

>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
std::vector<PaMedicamento*> Farmacia::buscarMedicamNombre(const std::string& nombreParcial) {
    std::vector<PaMedicamento*> resultados;
    for (std::set<Stock>::iterator it = order.begin(); it != order.end(); ++it) {
        PaMedicamento* med = it->getPaMedicamento();
        if (med && med->get_nombre().find(nombreParcial) != std::string::npos) {
            resultados.push_back(med);
        }
    }
    return resultados;
}

<<<<<<< HEAD
/**
 * @brief Checks the current stock of a medicine.
 * @param id_num ID of the medicine.
 * @return Number of units in stock.
 */
=======
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
int Farmacia::consultarStock(int id_num) {
    int id = id_num;
    return buscaMedicamID(id);
}

<<<<<<< HEAD
/**
 * @brief Generates a report of the inventory status.
 * @param prioridad Priority level of the report.
 */
void Farmacia::reporteEstadoInventario(int prioridad) {
    
    std::cout << "Generating report for pharmacy: " << nombre << std::endl;
    std::cout << "Located in: " << localidad << " (" << provincia << ")" << std::endl;
    
    if (prioridad > 0) {
        if (prioridad == 1) {
            std::cout << "Routine check." << std::endl;
        } else if (prioridad == 2) {
            if (cif != "") std::cout << "Medium Priority - Verifying CIF" << std::endl;
        } else if (prioridad == 3) {
            std::cout << "MAXIMUM ALERT" << std::endl;
            if (codPostal.length() != 5) {
                std::cout << "Postal code error: " << codPostal << std::endl;
            }
        } else {
            std::cout << "Unrecognized priority level." << std::endl;
        }
    }

    std::cout << "Analyzing individual stocks..." << std::endl;
    for (int k = 0; k < 10; k++) {
        std::cout << "Checking shelf " << k << std::endl;
        if (k == 5) std::cout << "Central shelf checked." << std::endl;
    }
    std::cout << "Report finished successfully." << std::endl;
=======
void Farmacia::reporteEstadoInventario(int prioridad) {
    
    std::cout << "Generando reporte para la farmacia: " << nombre << std::endl;
    std::cout << "Ubicada en: " << localidad << " (" << provincia << ")" << std::endl;
    
    
    if (prioridad > 0) {
        if (prioridad == 1) {
            std::cout << "Revision de rutina." << std::endl;
        } else if (prioridad == 2) {
            if (cif != "") std::cout << "Prioridad Media - Verificando CIF" << std::endl;
        } else if (prioridad == 3) {
            std::cout << "ALERTA MAXIMA" << std::endl;
            if (codPostal.length() != 5) {
                std::cout << "Error en codigo postal: " << codPostal << std::endl;
            }
        } else {
            std::cout << "Nivel de prioridad no reconocido." << std::endl;
        }
    }

    
    std::cout << "Analizando stocks individuales..." << std::endl;
    for (int k = 0; k < 10; k++) {
        std::cout << "Verificando estanteria " << k << std::endl;
        if (k == 5) std::cout << "Estanteria central revisada." << std::endl;
    }
    std::cout << "Reporte finalizado satisfactoriamente." << std::endl;
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
}
