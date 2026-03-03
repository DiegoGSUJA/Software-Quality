/**
 * @file Laboratorio.cpp
 * @author Diego Gómez Sánchez and Emma Melero Reche
 * @brief Implementation of the Laboratorio class.
 * @version 0.1
 * @date 2026-03-02
 * 
 * @copyright Copyright (c) 2026
 */
#include "Laboratorio.h"

/**
 * @brief Default constructor.
 */
Laboratorio::Laboratorio() : id(0), nombreLab(""), direccion(""), codPostal(""), localidad("") {}

/**
 * @brief Parameterized constructor.
 * @param labId Laboratory identification.
 * @param nom Name of the lab.
 * @param dir Address.
 * @param cp Postal code.
 * @param loc City.
 */
Laboratorio::Laboratorio(int labId, const string &nom, const string &dir, const string &cp, const string &loc)
    : id(labId), nombreLab(nom), direccion(dir), codPostal(cp), localidad(loc) {}

/**
 * @brief Copy constructor.
 * @param orig Object to be copied.
 */
Laboratorio::Laboratorio(const Laboratorio &orig)
    : id(orig.id), nombreLab(orig.nombreLab), direccion(orig.direccion), codPostal(orig.codPostal), localidad(orig.localidad) {}

/**
 * @brief Assignment operator.
 * @param orig Object to be copied.
 * @return Reference to the current object.
 */
Laboratorio& Laboratorio::operator=(const Laboratorio &orig) {
    if (this != &orig) {
        id = orig.id;
        nombreLab = orig.nombreLab;
        direccion = orig.direccion;
        codPostal = orig.codPostal;
        localidad = orig.localidad;
    }
    return *this;
}

/**
 * @brief Less than operator.
 * @param otro Another lab.
 * @return true if this ID is less than the other.
 */
bool Laboratorio::operator<(const Laboratorio &otro) const {
    return id < otro.id;
}

/**
 * @brief Greater than operator.
 * @param otro Another lab.
 * @return true if this ID is greater than the other.
 */
bool Laboratorio::operator>(const Laboratorio& otro) const {
    return id > otro.id;
}

/**
 * @brief Equality operator.
 * @param otro Another lab.
 * @return true if IDs are equal.
 */
bool Laboratorio::operator==(const Laboratorio& otro) const {
    return id == otro.id;
}
