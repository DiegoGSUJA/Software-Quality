/**
 * @file Stock.h
 * @author Diego Gómez Sánchez and Emma Melero Reche
 * @brief Header of the Stock class.
 * @version 0.1
 * @date 2026-03-02
 * 
 * @copyright Copyright (c) 2026
 */

#ifndef EEDD_PRACTICAS_STOCK_H
#define EEDD_PRACTICAS_STOCK_H

#include "PaMedicamento.h"

/**
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
     */
    Stock();

    /**
     * @brief Constructor that initializes stock with a quantity and a pointer to PaMedicamento.
     * @param num_stock Initial number of units.
     * @param number Pointer to the PaMedicamento object.
     */
    Stock(int num_stock, PaMedicamento *number);

    /**
     * @brief Constructor that initializes stock with a medicine ID.
     * @param id_paMed ID of the medicine.
     */
    Stock(int id_paMed);

    /**
     * @brief Copy constructor for Stock.
     * @param orig Stock object to copy.
     */
    Stock(const Stock &orig);

    /**
     * @brief Assignment operator for Stock.
     * @param orig Stock object to assign.
     * @return Reference to the current object.
     */
    Stock& operator=(const Stock &orig);

    /**
     * @brief Less than comparison operator for ordering Stocks.
     * @param stock Stock object to compare.
     * @return true if this object's ID is less than the other.
     */
    bool operator<(const Stock &stock) const;

    /**
     * @brief Increments the stock quantity by n units.
     * @param n Number of units to increase.
     */
    void incrementa(int n);

    /**
     * @brief Decrements the stock quantity by n units.
     * @param n Number of units to decrease.
     */
    void decrementa(int n);

    /**
     * @brief Get the numeric ID of the medicine.
     * @return ID of the medicine.
     */
    int getid_pa_Med() const;

    /**
     * @brief Get the pointer to the PaMedicamento object.
     * @return Pointer to PaMedicamento.
     */
    PaMedicamento* getPaMedicamento() const { return number; }

    /**
     * @brief Get the quantity of units in stock.
     * @return Number of units in stock.
     */
    int getnum_stock() const;

};

#endif //EEDD_PRACTICAS_STOCK_H