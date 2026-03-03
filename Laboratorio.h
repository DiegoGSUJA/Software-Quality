<<<<<<< HEAD
/**
 * @file Laboratorio.h
 * @author Diego Gómez Sánchez and Emma Melero Reche
 * @brief Header of the Laboratorio class.
 * @version 0.1
 * @date 2026-03-02
 * 
 * @copyright Copyright (c) 2026
 */

=======
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
#ifndef EEDD_PRACTICAS_LABORATORIO_H
#define EEDD_PRACTICAS_LABORATORIO_H

#include <string>

using namespace std;

<<<<<<< HEAD
/**
 * @brief Class that simulates a laboratory.
 */
class Laboratorio {
private:
    int id;               ///< Laboratory identifier.
    string nombreLab;     ///< Name of the laboratory.
    string direccion;     ///< Address of the laboratory.
    string codPostal;     ///< Postal code of the laboratory.
    string localidad;     ///< City where the laboratory is located.

public:
    /**
     * @brief Default constructor.
=======

class Laboratorio {
    private:
    int id;
    string nombreLab;
    string direccion;
    string codPostal;
    string localidad;

    public:
    /**
     * @brief Constructor por defecto.
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
     */
    Laboratorio();

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
     * @param labId Identificador numérico del laboratorio.
     * @param nom Nombre del laboratorio.
     * @param dir Dirección completa.
     * @param cp Código postal.
     * @param loc Localidad.
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
     */
    Laboratorio(int labId, const string &nom, const string &dir, const string &cp, const string &loc);

    /**
<<<<<<< HEAD
     * @brief Copy constructor.
     * @param orig Object to be copied.
=======
     * @brief Constructor de copia.
     * @param orig Objeto a copiar.
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
     */
    Laboratorio(const Laboratorio &orig);

    /**
<<<<<<< HEAD
     * @brief Assignment operator.
     * @param orig Object to be copied.
     * @return Reference to the current object.
     */
    Laboratorio& operator=(const Laboratorio &orig);

    /**
     * @brief Get the ID of the laboratory.
     * @return int ID.
     */
    int get_id() const { return id; }

    /**
     * @brief Get the name of the laboratory.
     * @return string& Name reference.
     */
    string &get_nombreLab() { return nombreLab; }

    /**
     * @brief Get the address of the laboratory.
     * @return string Address.
     */
    string get_direccion() const { return direccion; }

    /**
     * @brief Get the postal code of the laboratory.
     * @return string Postal code.
     */
    string get_codPostal() const { return codPostal; }

    /**
     * @brief Get the city of the laboratory.
     * @return string City.
     */
    string get_localidad() const { return localidad; }

    /**
     * @brief Set the ID of the laboratory.
     * @param labId New ID.
     */
    void set_id(int labId) { id = labId; }

    /**
     * @brief Set the name of the laboratory.
     * @param nom New name.
     */
    void set_nombreLab(const string &nom) { nombreLab = nom; }

    /**
     * @brief Set the address of the laboratory.
     * @param dir New address.
     */
    void set_direccion(const string &dir) { direccion = dir; }

    /**
     * @brief Set the postal code of the laboratory.
     * @param cp New postal code.
     */
    void set_codPostal(const string &cp) { codPostal = cp; }

    /**
     * @brief Set the city of the laboratory.
     * @param loc New city.
     */
    void set_localidad(const string &loc) { localidad = loc; }

    /**
     * @brief Less than operator.
     * @param otro Another laboratory to compare with.
     * @return true if this ID is less than the other.
=======
     * @brief Operador de asignación.
     * @param orig Objeto a copiar.
     * @return Referencia al objeto actual.
     */
    Laboratorio& operator=(const Laboratorio &orig);

    // Getters
    int get_id() const { return id; }
    string &get_nombreLab() { return nombreLab; }
    string get_direccion() const { return direccion; }
    string get_codPostal() const { return codPostal; }
    string get_localidad() const { return localidad; }

    // Setters
    void set_id(int labId) { id = labId; }
    void set_nombreLab(const string &nom) { nombreLab = nom; }
    void set_direccion(const string &dir) { direccion = dir; }
    void set_codPostal(const string &cp) { codPostal = cp; }
    void set_localidad(const string &loc) { localidad = loc; }

    /**
     * @brief Operador menor que.
     * @param otro Otro laboratorio.
     * @return true si el ID actual es menor que el otro.
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
     */
    bool operator<(const Laboratorio &otro) const;

    /**
<<<<<<< HEAD
     * @brief Greater than operator.
     * @param otro Another laboratory to compare with.
     * @return true if this ID is greater than the other.
=======
     * @brief Operador mayor que.
     * @param otro Otro laboratorio.
     * @return true si el ID actual es mayor que el otro.
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
     */
    bool operator>(const Laboratorio& otro) const;

    /**
<<<<<<< HEAD
     * @brief Equality operator.
     * @param otro Another laboratory to compare with.
     * @return true if both IDs are the same.
=======
     * @brief Operador de igualdad.
     * @param otro Otro laboratorio.
     * @return true si el ID actual es igual que el otro.
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
     */
    bool operator==(const Laboratorio& otro) const;
};

<<<<<<< HEAD
=======

>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
#endif //EEDD_PRACTICAS_LABORATORIO_H