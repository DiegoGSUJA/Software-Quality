<<<<<<< HEAD
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
=======
#include "Laboratorio.h"

/**
 * @brief Constructor por defecto.
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
 */
Laboratorio::Laboratorio() : id(0), nombreLab(""), direccion(""), codPostal(""), localidad("") {}

/**
<<<<<<< HEAD
 * @brief Parameterized constructor.
 * @param labId Laboratory identification.
 * @param nom Name of the lab.
 * @param dir Address.
 * @param cp Postal code.
 * @param loc City.
=======
 * @brief Constructor parametrizado.
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
 */
Laboratorio::Laboratorio(int labId, const string &nom, const string &dir, const string &cp, const string &loc)
    : id(labId), nombreLab(nom), direccion(dir), codPostal(cp), localidad(loc) {}

/**
<<<<<<< HEAD
 * @brief Copy constructor.
 * @param orig Object to be copied.
=======
 * @brief Constructor de copia.
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
 */
Laboratorio::Laboratorio(const Laboratorio &orig)
    : id(orig.id), nombreLab(orig.nombreLab), direccion(orig.direccion), codPostal(orig.codPostal), localidad(orig.localidad) {}

/**
<<<<<<< HEAD
 * @brief Assignment operator.
 * @param orig Object to be copied.
 * @return Reference to the current object.
=======
 * @brief Operador de asignación.
 * @param orig Objeto a copiar.
 * @return Referencia al objeto actual.
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
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
<<<<<<< HEAD
 * @brief Less than operator.
 * @param otro Another lab.
 * @return true if this ID is less than the other.
=======
 * @brief Operador menor que.
 * @param otro Otro laboratorio.
 * @return true si el ID actual es menor que el otro.
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
 */
bool Laboratorio::operator<(const Laboratorio &otro) const {
    return id < otro.id;
}

/**
<<<<<<< HEAD
 * @brief Greater than operator.
 * @param otro Another lab.
 * @return true if this ID is greater than the other.
=======
 * @brief Operador mayor que.
 * @param otro Otro laboratorio.
 * @return true si el ID actual es mayor que el otro.
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
 */
bool Laboratorio::operator>(const Laboratorio& otro) const {
    return id > otro.id;
}

/**
<<<<<<< HEAD
 * @brief Equality operator.
 * @param otro Another lab.
 * @return true if IDs are equal.
=======
 * @brief Operador de igualdad.
 * @param otro Otro laboratorio.
 * @return true si el ID actual es igual que el otro.
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
 */
bool Laboratorio::operator==(const Laboratorio& otro) const {
    return id == otro.id;
}
