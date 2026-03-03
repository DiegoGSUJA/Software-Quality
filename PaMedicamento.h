/**
 * @file PaMedicamento.h
 * @author Diego Gómez Sánchez and Emma Melero Reche
 * @brief Header of the PaMedicamento class.
 * @version 0.1
 * @date 2026-03-02
 * 
 * @copyright Copyright (c) 2026
 */

#ifndef EEDD_PRACTICAS_PAMEDICAMENTO_H
#define EEDD_PRACTICAS_PAMEDICAMENTO_H

#include <string>
#include "Laboratorio.h"

/**
 * @brief Class that represents a medicine with numeric and alphanumeric IDs.
 */
class PaMedicamento {
private:
    int id_num;          ///< Numeric identifier of the medicine.
    std::string id_alpha; ///< Alphanumeric identifier of the medicine.
    std::string nombre;   ///< Name of the medicine.
    Laboratorio *serve;   ///< Pointer to the Laboratory that supplies this medicine.

public:
    /**
     * @brief Default constructor.
     */
    PaMedicamento();

    /**
     * @brief Parameterized constructor.
     * @param idN Numeric identifier.
     * @param idA Alphanumeric identifier.
     * @param nom Name of the medicine.
     */
    PaMedicamento(int idN, const std::string &idA, const std::string &nom);

    /**
     * @brief Copy constructor.
     * @param orig Object to be copied.
     */
    PaMedicamento(const PaMedicamento &orig);

    /**
     * @brief Assignment operator.
     * @param orig Object to be copied.
     * @return Reference to the current object.
     */
    PaMedicamento& operator=(const PaMedicamento &orig);

    /**
     * @brief Get the numeric ID.
     * @return Numeric ID.
     */
    int get_id_num() const { return id_num; }

    /**
     * @brief Get the alphanumeric ID.
     * @return Alphanumeric ID.
     */
    std::string get_id_alpha() const { return id_alpha; }

    /**
     * @brief Get the name of the medicine.
     * @return Medicine name.
     */
    std::string get_nombre() const { return nombre; }

    /**
     * @brief Get the supplying laboratory.
     * @return Pointer to the Laboratory.
     */
    Laboratorio* get_serve() const { return serve; }

    /**
     * @brief Less than operator based on numeric ID.
     * @param otro Another medicine to compare with.
     * @return true if this numeric ID is less than the other.
     */
    bool operator<(const PaMedicamento &otro) const;

    /**
     * @brief Greater than operator based on numeric ID.
     * @param otro Another medicine to compare with.
     * @return true if this numeric ID is greater than the other.
     */
    bool operator>(const PaMedicamento& otro) const;

    /**
     * @brief Associates a laboratory that supplies the medicine.
     * @param lab Pointer to the laboratory.
     */
    void servidoPor(Laboratorio *lab);

};

#endif //EEDD_PRACTICAS_PAMEDICAMENTO_H
