/**
 * @file Laboratorio.h
 * @author Diego Gómez Sánchez and Emma Melero Reche
 * @brief Header of the Laboratorio class.
 * @version 0.1
 * @date 2026-03-02
 * 
 * @copyright Copyright (c) 2026
 */

#ifndef EEDD_PRACTICAS_LABORATORIO_H
#define EEDD_PRACTICAS_LABORATORIO_H

#include <string>

using namespace std;

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
     */
    Laboratorio();

    /**
     * @brief Parameterized constructor.
     * @param labId Laboratory identification.
     * @param nom Name of the lab.
     * @param dir Address.
     * @param cp Postal code.
     * @param loc City.
     */
    Laboratorio(int labId, const string &nom, const string &dir, const string &cp, const string &loc);

    /**
     * @brief Copy constructor.
     * @param orig Object to be copied.
     */
    Laboratorio(const Laboratorio &orig);

    /**
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
     */
    bool operator<(const Laboratorio &otro) const;

    /**
     * @brief Greater than operator.
     * @param otro Another laboratory to compare with.
     * @return true if this ID is greater than the other.
     */
    bool operator>(const Laboratorio& otro) const;

    /**
     * @brief Equality operator.
     * @param otro Another laboratory to compare with.
     * @return true if both IDs are the same.
     */
    bool operator==(const Laboratorio& otro) const;
};

#endif //EEDD_PRACTICAS_LABORATORIO_H