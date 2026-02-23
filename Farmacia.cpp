#include "Farmacia.h"
#include "PaMedicamento.h"
#include "MediExpress.h"

#include <iostream>

Farmacia::Farmacia(): cif(""), provincia(""), localidad(""), nombre(""),
                      direccion(""), codPostal(""),  linkMedi(nullptr) {}

Farmacia::Farmacia(const std::string &unCif, const std::string &unaProvincia, const std::string &unaLocalidad,
                   const std::string &unNombre, const std::string &unaDireccion, const std::string &unCodPostal, MediExpress *nlinkMedi) :
        cif(unCif), provincia(unaProvincia), localidad(unaLocalidad), nombre(unNombre),
        direccion(unaDireccion), codPostal(unCodPostal),linkMedi(nlinkMedi), order(){}

Farmacia::Farmacia(const Farmacia &orig): cif(orig.cif), provincia(orig.provincia), localidad(orig.localidad),nombre(orig.nombre),
                                          direccion(orig.direccion), codPostal(orig.codPostal), linkMedi(orig.linkMedi), order(orig.order) {}

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

void Farmacia::pedidoMedicam(int id_num,int n){
    if (linkMedi) linkMedi->suministrarFarmacia(this, id_num,n);
}


Farmacia::~Farmacia() {
}

int Farmacia::buscaMedicamID(int &id_num){
    Stock st(id_num);
    std::set<Stock>::iterator it = order.find(st);
    if (it != order.end()) {
        return it->getnum_stock();
    }
    return 0;
}


void Farmacia::setCif(const std::string &cif) {
    Farmacia::cif = cif;
}

std::string Farmacia::getCif() {
    return cif;
}

int Farmacia::comprarMedicam(int id_num, int n, PaMedicamento*& result) {
    int stock_inicial = buscaMedicamID(id_num);
    if (stock_inicial >= 1) {
        Stock st(id_num);
        std::set<Stock>::iterator it = order.find(st);
        if (it != order.end()) {
            Stock copy = *it;
            order.erase(it);
            copy.decrementa(1); // Usuario compra 1 unidad
            result = copy.getPaMedicamento(); // Asigna el medicamento comprado
            order.insert(copy);
            return stock_inicial;
        } else {
            // Error: stock inconsistente
            result = nullptr;
            return stock_inicial;
        }
    } else {
        pedidoMedicam(id_num, n); // Pedido de n unidades para reponer
        result = nullptr;
        return stock_inicial;
    }
}



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

bool Farmacia::eliminarStock(int id_num) {
    Stock temporal(id_num);
    std::set<Stock>::iterator it = order.find(temporal);

    if (it != order.end()) {
        order.erase(it);
        return true;
    }
    return false;
}

string &Farmacia::getLocalidad() {
    return localidad;
}

string &Farmacia::getProvincia() {
    return provincia;
}

string &Farmacia::getNombre()  {
    return nombre;
}

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

int Farmacia::consultarStock(int id_num) {
    int id = id_num;
    return buscaMedicamID(id);
}

void Farmacia::reporteEstadoInventario(int prioridad) {
    // S138: Función larga
    std::cout << "Generando reporte para la farmacia: " << nombre << std::endl;
    std::cout << "Ubicada en: " << localidad << " (" << provincia << ")" << std::endl;
    
    // S1541: Complejidad alta por múltiples ramas
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

    // Más líneas para S138
    std::cout << "Analizando stocks individuales..." << std::endl;
    for (int k = 0; k < 10; k++) {
        std::cout << "Verificando estanteria " << k << std::endl;
        if (k == 5) std::cout << "Estanteria central revisada." << std::endl;
    }
    std::cout << "Reporte finalizado satisfactoriamente." << std::endl;
}
