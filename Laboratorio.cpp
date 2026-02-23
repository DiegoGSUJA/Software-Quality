#include "Laboratorio.h"

/**
 * @brief Constructor por defecto.
 */
Laboratorio::Laboratorio() : id(0), nombreLab(""), direccion(""), codPostal(""), localidad("") {}

/**
 * @brief Constructor parametrizado.
 */
Laboratorio::Laboratorio(int labId, const string &nom, const string &dir, const string &cp, const string &loc)
    : id(labId), nombreLab(nom), direccion(dir), codPostal(cp), localidad(loc) {}

/**
 * @brief Constructor de copia.
 */
Laboratorio::Laboratorio(const Laboratorio &orig)
    : id(orig.id), nombreLab(orig.nombreLab), direccion(orig.direccion), codPostal(orig.codPostal), localidad(orig.localidad) {}

/**
 * @brief Operador de asignación.
 * @param orig Objeto a copiar.
 * @return Referencia al objeto actual.
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
 * @brief Operador menor que.
 * @param otro Otro laboratorio.
 * @return true si el ID actual es menor que el otro.
 */
bool Laboratorio::operator<(const Laboratorio &otro) const {
    return id < otro.id;
}

/**
 * @brief Operador mayor que.
 * @param otro Otro laboratorio.
 * @return true si el ID actual es mayor que el otro.
 */
bool Laboratorio::operator>(const Laboratorio& otro) const {
    return id > otro.id;
}

/**
 * @brief Operador de igualdad.
 * @param otro Otro laboratorio.
 * @return true si el ID actual es igual que el otro.
 */
bool Laboratorio::operator==(const Laboratorio& otro) const {
    return id == otro.id;
}
