/**
 * @file Stock.cpp
 * @author Diego Gómez Sánchez and Emma Melero Reche
 * @brief Implementation of the Stock class.
 * @version 0.1
 * @date 2026-03-02
 * 
 * @copyright Copyright (c) 2026
 */
#include "Stock.h"

/**
 * @brief Default constructor.
 */
Stock::Stock(): id_paMed(0), num_stock(0), number(nullptr) {}

/**
 * @brief Constructor with medicine ID.
 * @param id_paMed ID of the medicine.
 */
Stock::Stock(int id_paMed): id_paMed(id_paMed), num_stock(0), number(nullptr) {}

/**
 * @brief Constructor with quantity and medicine pointer.
 * @param num_stock Quantity.
 * @param number Pointer to PaMedicamento.
 */
Stock::Stock(int num_stock, PaMedicamento *number)
: id_paMed(number->get_id_num()), num_stock(num_stock), number(number) {}

/**
 * @brief Copy constructor.
 * @param orig Stock to copy.
 */
Stock::Stock(const Stock &orig)
: id_paMed(orig.id_paMed), num_stock(orig.num_stock), number(orig.number) {}

/**
 * @brief Assignment operator.
 * @param orig Stock to copy.
 * @return Reference to current object.
 */
Stock &Stock::operator=(const Stock &orig) {
    if (this != &orig) {
        id_paMed = orig.id_paMed;
        num_stock = orig.num_stock;
        number = orig.number;
    }
    return *this;
}

/**
 * @brief Less than operator.
 * @param stock Other stock to compare.
 * @return true if this ID is less than other ID.
 */
bool Stock::operator<(const Stock &stock) const {
    return id_paMed < stock.id_paMed;
}

/**
 * @brief Increments stock.
 * @param n Quantity to add.
 */
void Stock::incrementa(int n) {
    num_stock += n;
}

/**
 * @brief Decrements stock.
 * @param n Quantity to remove.
 */
void Stock::decrementa(int n) {
    if (n <= 0) return;
    if (n >= num_stock) num_stock = 0;
    else num_stock -= n;
}

/**
 * @brief Get medicine ID.
 * @return int ID.
 */
int Stock::getid_pa_Med() const {
    return id_paMed;
}

/**
 * @brief Get stock quantity.
 * @return int Quantity.
 */
int Stock::getnum_stock() const {
    return num_stock;
}
