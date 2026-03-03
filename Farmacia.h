<<<<<<< HEAD
/**
 * @file Farmacia.h
 * @author Emma Melero Reche and Diego Gómez Sánchez
 * @brief Header of the Farmacia class.
 * @version 0.1
 * @date 2026-03-02
 * 
 * @copyright Copyright (c) 2026
 */

=======
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
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
<<<<<<< HEAD
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
=======
 * @brief Clase que representa una farmacia.
 *
 * La clase Farmacia gestiona la información de una farmacia, incluyendo su CIF, ubicación,
 * nombre, dirección, código postal, y el stock de medicamentos disponibles.
 */
class Farmacia {
private:
    std::string cif;          /// CIF de la farmacia.
    std::string provincia;    /// Provincia donde se encuentra la farmacia.
    std::string localidad;    /// Localidad donde se encuentra la farmacia.
    std::string nombre;       /// Nombre de la farmacia.
    std::string direccion;    /// Dirección de la farmacia.
    std::string codPostal;    /// Código postal de la farmacia.
    MediExpress *linkMedi;    /// Asociación a la clase MediExpress para gestionar pedidos y suministros.
    std::set<Stock> order;    /// Conjunto de objetos Stock que representan el inventario de medicamentos.

public:
    /**
     * @brief Constructor por defecto de Farmacia.
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
     */
    Farmacia();

    /**
<<<<<<< HEAD
     * @brief Parameterized constructor.
     * @param unCif CIF identification.
     * @param unaProvincia Province name.
     * @param unaLocalidad City name.
     * @param unNombre Pharmacy name.
     * @param unaDireccion Street address.
     * @param unCodPostal Postal code.
     * @param nlinkMedi Pointer to the MediExpress interface.
=======
     * @brief Constructor que inicializa una farmacia con todos sus datos.
     * @param unCif CIF de la farmacia.
     * @param unaProvincia Provincia de la farmacia.
     * @param unaLocalidad Localidad de la farmacia.
     * @param unNombre Nombre de la farmacia.
     * @param unaDireccion Dirección de la farmacia.
     * @param unCodPostal Código postal de la farmacia.
     * @param nlinkMedi Puntero al objeto MediExpress.
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
     */
    Farmacia(const std::string &unCif, const std::string &unaProvincia, const std::string &unaLocalidad,
             const std::string &unNombre, const std::string &unaDireccion, const std::string &unCodPostal, MediExpress *nlinkMedi);

    /**
<<<<<<< HEAD
     * @brief Copy constructor.
     * @param orig Pharmacy object to copy.
=======
     * @brief Constructor de copia de Farmacia.
     * @param orig Objeto Farmacia a copiar.
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
     */
    Farmacia(const Farmacia &orig);

    /**
<<<<<<< HEAD
     * @brief Assignment operator.
     * @param orig Pharmacy object to assign.
     * @return Reference to the current object.
=======
     * @brief Operador de asignación para Farmacia.
     * @param orig Objeto Farmacia a asignar.
     * @return Referencia al objeto actual.
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
     */
    Farmacia& operator=(const Farmacia &orig);

    /**
<<<<<<< HEAD
     * @brief Destructor.
=======
     * @brief Destructor de Farmacia.
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
     */
    ~Farmacia();

    /**
<<<<<<< HEAD
     * @brief Less than operator for sorting by CIF.
     * @param otro Other pharmacy to compare with.
     * @return true if this CIF is less than the other.
=======
     * @brief Operador de comparación menor que para ordenar Farmacias por CIF.
     * @param otro Objeto Farmacia a comparar.
     * @return true si este objeto es menor que el otro, false en caso contrario.
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
     */
    bool operator<(const Farmacia &otro) const {
        return cif < otro.cif;
    }

    /**
<<<<<<< HEAD
     * @brief Equality operator based on CIF.
     * @param otro Other pharmacy to compare with.
     * @return true if CIFs are the same.
=======
     * @brief Operador de comparación de igualdad para Farmacias por CIF.
     * @param otro Objeto Farmacia a comparar.
     * @return true si los CIF son iguales, false en caso contrario.
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
     */
    bool operator==(const Farmacia &otro) const {
        return cif == otro.cif;
    }

    /**
<<<<<<< HEAD
     * @brief Greater than operator for sorting by CIF.
     * @param otro Other pharmacy to compare with.
     * @return true if this CIF is greater than the other.
=======
     * @brief Operador de comparación mayor que para Farmacias por CIF.
     * @param otro Objeto Farmacia a comparar.
     * @return true si este objeto es mayor que el otro, false en caso contrario.
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
     */
    bool operator>(const Farmacia &otro) const {
        return cif > otro.cif;
    }

    /**
<<<<<<< HEAD
     * @brief Set the CIF of the pharmacy.
     * @param cif New CIF.
=======
     * @brief Establece el CIF de la farmacia.
     * @param cif Nuevo CIF de la farmacia.
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
     */
    void setCif(const std::string &cif);

    /**
<<<<<<< HEAD
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
=======
     * @brief Obtiene la localidad de la farmacia.
     * @return Referencia a la localidad.
     */
    string& getLocalidad();

    /**
     * @brief Obtiene la provincia de la farmacia.
     * @return Referencia a la provincia.
     */
    string& getProvincia();

    /**
     * @brief Obtiene el nombre de la farmacia.
     * @return Referencia al nombre.
     */
    string &getNombre();

    /**
     * @brief Obtiene el CIF de la farmacia.
     * @return CIF de la farmacia.
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
     */
    std::string getCif();

    /**
<<<<<<< HEAD
     * @brief Sells a medicine to a customer.
     * @param id_num ID of the medicine.
     * @param n Units to restock if stock is empty.
     * @param result Output pointer to the purchased medicine.
     * @return Previous stock level.
=======
     * @brief Permite comprar un medicamento, decrementando el stock si hay suficiente.
     * @param id_num ID del medicamento a comprar.
     * @param n Número de unidades a comprar (siempre 1 por usuario).
     * @param result Puntero al medicamento comprado, o nullptr si no se pudo comprar.
     * @return Número de unidades disponibles inicialmente.
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
     */
    int comprarMedicam(int id_num, int n, PaMedicamento*& result);

    /**
<<<<<<< HEAD
     * @brief Adds or updates stock for a medicine.
     * @param p Pointer to the medicine.
     * @param n Number of units to add.
=======
     * @brief Agrega nuevo stock de un medicamento a la farmacia.
     * @param p Puntero al medicamento.
     * @param n Número de unidades a agregar.
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
     */
    void nuevoStock(PaMedicamento *p, int n);

    /**
<<<<<<< HEAD
     * @brief Removes a medicine from the inventory.
     * @param id_num ID of the medicine.
     * @return true if removed, false if not found.
=======
     * @brief Elimina el stock de un medicamento específico.
     * @param id_num ID del medicamento a eliminar.
     * @return true si se eliminó, false si no existía.
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
     */
    bool eliminarStock(int id_num);

    /**
<<<<<<< HEAD
     * @brief Checks the current stock of a medicine.
     * @param id_num ID of the medicine.
     * @return Number of units in stock.
=======
     * @brief Consulta la cantidad de stock disponible de un medicamento.
     * @param id_num ID del medicamento.
     * @return Número de unidades en stock.
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
     */
    int consultarStock(int id_num);

    /**
<<<<<<< HEAD
     * @brief Searches for medicines by partial name.
     * @param nombreParcial Part of the name to search for.
     * @return Vector of pointers to matching medicines.
=======
     * @brief Busca medicamentos por nombre parcial.
     * @param nombreParcial Nombre parcial a buscar.
     * @return Vector de punteros a medicamentos encontrados.
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
     */
    std::vector<PaMedicamento*> buscarMedicamNombre(const std::string& nombreParcial);

private:
    /**
<<<<<<< HEAD
     * @brief Internal method to find stock by medicine ID.
     * @param id_num ID of the medicine.
     * @return Number of units in stock.
=======
     * @brief Busca un medicamento por ID y devuelve el stock disponible.
     * @param id_num ID del medicamento.
     * @return Número de unidades disponibles.
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
     */
    int buscaMedicamID(int &id_num);

    /**
<<<<<<< HEAD
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
=======
     * @brief Realiza un pedido de un medicamento para reponer stock.
     * @param id_num ID del medicamento.
     * @param n Número de unidades a pedir.
     */
    void pedidoMedicam(int id_num, int n);

    
    void reporteEstadoInventario(int prioridad);

    string getProvincia() const { return provincia; }
    string get_localidad() const { return localidad; }
    string get_nombre() const { return nombre; }
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4

};

#endif //CMAKE_INSTALL_CMAKE_FARMACIA_H
