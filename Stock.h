<<<<<<< HEAD
/**
 * @file Stock.h
 * @author Diego Gómez Sánchez and Emma Melero Reche
 * @brief Header of the Stock class.
 * @version 0.1
 * @date 2026-03-02
 * 
 * @copyright Copyright (c) 2026
 */

=======
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
#ifndef EEDD_PRACTICAS_STOCK_H
#define EEDD_PRACTICAS_STOCK_H

#include "PaMedicamento.h"

/**
<<<<<<< HEAD
 * @brief Class that represents the stock of a medicine in a pharmacy.
 *
 * The Stock class manages the available quantity of a specific medicine,
 * identified by its ID, and maintains a reference to the corresponding PaMedicamento object.
 */
class Stock {
private:
    int id_paMed;          ///< ID of the medicine.
    int num_stock;         ///< Number of units in stock.
    PaMedicamento *number; ///< Pointer to the PaMedicamento object.

public:
    /**
     * @brief Default constructor for Stock.
=======
 * @brief Clase que representa el stock de un medicamento en una farmacia.
 *
 * La clase Stock gestiona la cantidad disponible de un medicamento específico,
 * identificado por su ID, y mantiene una referencia al objeto PaMedicamento correspondiente.
 */
class Stock {
    private:
    int id_paMed;          /// ID del medicamento.
    int num_stock;         /// Número de unidades en stock.
    PaMedicamento *number; /// Puntero al objeto PaMedicamento.

public:

    /**
     * @brief Constructor por defecto de Stock.
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
     */
    Stock();

    /**
<<<<<<< HEAD
     * @brief Constructor that initializes stock with a quantity and a pointer to PaMedicamento.
     * @param num_stock Initial number of units.
     * @param number Pointer to the PaMedicamento object.
     */
    Stock(int num_stock, PaMedicamento *number);

    /**
     * @brief Constructor that initializes stock with a medicine ID.
     * @param id_paMed ID of the medicine.
=======
     * @brief Constructor que inicializa el stock con una cantidad y un puntero a PaMedicamento.
     * @param num_stock Cantidad inicial de unidades.
     * @param number Puntero al objeto PaMedicamento.
     */
    Stock(int num_stock,PaMedicamento *number);

    /**
     * @brief Constructor que inicializa el stock con un ID de medicamento.
     * @param id_paMed ID del medicamento.
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
     */
    Stock(int id_paMed);

    /**
<<<<<<< HEAD
     * @brief Copy constructor for Stock.
     * @param orig Stock object to copy.
=======
     * @brief Constructor de copia de Stock.
     * @param orig Objeto Stock a copiar.
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
     */
    Stock(const Stock &orig);

    /**
<<<<<<< HEAD
     * @brief Assignment operator for Stock.
     * @param orig Stock object to assign.
     * @return Reference to the current object.
=======
     * @brief Operador de asignación para Stock.
     * @param orig Objeto Stock a asignar.
     * @return Referencia al objeto actual.
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
     */
    Stock& operator=(const Stock &orig);

    /**
<<<<<<< HEAD
     * @brief Less than comparison operator for ordering Stocks.
     * @param stock Stock object to compare.
     * @return true if this object's ID is less than the other.
=======
     * @brief Operador de comparación menor que para ordenar Stocks.
     * @param stock Objeto Stock a comparar.
     * @return true si este objeto es menor que el otro, false en caso contrario.
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
     */
    bool operator<(const Stock &stock) const;

    /**
<<<<<<< HEAD
     * @brief Increments the stock quantity by n units.
     * @param n Number of units to increase.
=======
     * @brief Incrementa la cantidad de stock en n unidades.
     * @param n Número de unidades a incrementar.
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
     */
    void incrementa(int n);

    /**
<<<<<<< HEAD
     * @brief Decrements the stock quantity by n units.
     * @param n Number of units to decrease.
=======
     * @brief Decrementa la cantidad de stock en n unidades.
     * @param n Número de unidades a decrementar.
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
     */
    void decrementa(int n);

    /**
<<<<<<< HEAD
     * @brief Get the numeric ID of the medicine.
     * @return ID of the medicine.
=======
     * @brief Obtiene el ID del medicamento.
     * @return ID del medicamento.
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
     */
    int getid_pa_Med() const;

    /**
<<<<<<< HEAD
     * @brief Get the pointer to the PaMedicamento object.
     * @return Pointer to PaMedicamento.
=======
     * @brief Obtiene el puntero al objeto PaMedicamento.
     * @return Puntero al PaMedicamento.
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
     */
    PaMedicamento* getPaMedicamento() const { return number; }

    /**
<<<<<<< HEAD
     * @brief Get the quantity of units in stock.
     * @return Number of units in stock.
=======
     * @brief Obtiene la cantidad de unidades en stock.
     * @return Número de unidades en stock.
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
     */
    int getnum_stock() const;

};

<<<<<<< HEAD
=======

>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
#endif //EEDD_PRACTICAS_STOCK_H