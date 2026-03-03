/**
 * @file Farmacia.h
 * @author Emma Melero Reche and Diego Gómez Sánchez
 * @brief Header of the Farmacia class.
 * @version 0.1
 * @date 2026-03-02
 * 
 * @copyright Copyright (c) 2026
 */

#ifndef CMAKE_INSTALL_CMAKE_FARMACIA_H
#define CMAKE_INSTALL_CMAKE_FARMACIA_H

#include "Laboratorio.h"
#include "Stock.h"
#include <vector>
#include <string>
#include <set>

class MediExpress;
class PaMedicamento;

/**
 * @brief Class that simulates a pharmacy.
 */
class Farmacia {
private:
    std::string cif;           ///< Pharmacy identification number (CIF).
    std::string provincia;     ///< Province where the pharmacy is located.
    std::string localidad;     ///< City where the pharmacy is located.
    std::string nombre;        ///< Name of the pharmacy.
    std::string direccion;     ///< Street address of the pharmacy.
    std::string codPostal;     ///< Postal code of the pharmacy.
    MediExpress *linkMedi;     ///< Pointer to MediExpress for supply management.
    std::set<Stock> order;     ///< Set of Stock objects representing the inventory.

public:
    /**
     * @brief Default constructor.
     */
    Farmacia();

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
    Farmacia(const std::string &unCif, const std::string &unaProvincia, const std::string &unaLocalidad,
             const std::string &unNombre, const std::string &unaDireccion, const std::string &unCodPostal, MediExpress *nlinkMedi);

    /**
     * @brief Copy constructor.
     * @param orig Pharmacy object to copy.
     */
    Farmacia(const Farmacia &orig);

    /**
     * @brief Assignment operator.
     * @param orig Pharmacy object to assign.
     * @return Reference to the current object.
     */
    Farmacia& operator=(const Farmacia &orig);

    /**
     * @brief Destructor.
     */
    ~Farmacia();

    /**
     * @brief Less than operator for sorting by CIF.
     * @param otro Other pharmacy to compare with.
     * @return true if this CIF is less than the other.
     */
    bool operator<(const Farmacia &otro) const {
        return cif < otro.cif;
    }

    /**
     * @brief Equality operator based on CIF.
     * @param otro Other pharmacy to compare with.
     * @return true if CIFs are the same.
     */
    bool operator==(const Farmacia &otro) const {
        return cif == otro.cif;
    }

    /**
     * @brief Greater than operator for sorting by CIF.
     * @param otro Other pharmacy to compare with.
     * @return true if this CIF is greater than the other.
     */
    bool operator>(const Farmacia &otro) const {
        return cif > otro.cif;
    }

    /**
     * @brief Set the CIF of the pharmacy.
     * @param cif New CIF.
     */
    void setCif(const std::string &cif);

    /**
     * @brief Get the City (localidad).
     * @return string& reference to the city.
     */
    std::string& getLocalidad();

    /**
     * @brief Get the Province.
     * @return string& reference to the province.
     */
    std::string& getProvincia();

    /**
     * @brief Get the Name of the pharmacy.
     * @return string& reference to the name.
     */
    std::string& getNombre();

    /**
     * @brief Get the CIF.
     * @return std::string the CIF.
     */
    std::string getCif();

    /**
     * @brief Sells a medicine to a customer.
     * @param id_num ID of the medicine.
     * @param n Units to restock if stock is empty.
     * @param result Output pointer to the purchased medicine.
     * @return Previous stock level.
     */
    int comprarMedicam(int id_num, int n, PaMedicamento*& result);

    /**
     * @brief Adds or updates stock for a medicine.
     * @param p Pointer to the medicine.
     * @param n Number of units to add.
     */
    void nuevoStock(PaMedicamento *p, int n);

    /**
     * @brief Removes a medicine from the inventory.
     * @param id_num ID of the medicine.
     * @return true if removed, false if not found.
     */
    bool eliminarStock(int id_num);

    /**
     * @brief Checks the current stock of a medicine.
     * @param id_num ID of the medicine.
     * @return Number of units in stock.
     */
    int consultarStock(int id_num);

    /**
     * @brief Searches for medicines by partial name.
     * @param nombreParcial Part of the name to search for.
     * @return Vector of pointers to matching medicines.
     */
    std::vector<PaMedicamento*> buscarMedicamNombre(const std::string& nombreParcial);

private:
    /**
     * @brief Internal method to find stock by medicine ID.
     * @param id_num ID of the medicine.
     * @return Number of units in stock.
     */
    int buscaMedicamID(int &id_num);

    /**
     * @brief Places a restock order to MediExpress.
     * @param id_num ID of the medicine.
     * @param n Number of units to order.
     */
    void pedidoMedicam(int id_num, int n);

    /**
     * @brief Generates a report of the inventory status.
     * @param prioridad Priority level of the report.
     */
    void reporteEstadoInventario(int prioridad);

    /**
     * @brief Get the Province (const version).
     * @return string Province name.
     */
    std::string getProvincia() const { return provincia; }

    /**
     * @brief Get the City (const version).
     * @return string City name.
     */
    std::string get_localidad() const { return localidad; }

    /**
     * @brief Get the Name (const version).
     * @return string Pharmacy name.
     */
    std::string get_nombre() const { return nombre; }

};

#endif //CMAKE_INSTALL_CMAKE_FARMACIA_H
