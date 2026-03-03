<<<<<<< HEAD
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
=======
#include "Stock.h"

Stock::Stock(): id_paMed(0), num_stock(0), number(nullptr) {}

Stock::Stock(int id_paMed): id_paMed(id_paMed), num_stock(0), number(nullptr) {}

Stock::Stock(int num_stock, PaMedicamento *number)
: id_paMed(number->get_id_num()), num_stock(num_stock), number(number) {}

Stock::Stock(const Stock &orig)
: id_paMed(orig.id_paMed), num_stock(orig.num_stock), number(orig.number) {}

>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
Stock &Stock::operator=(const Stock &orig) {
    if (this != &orig) {
        id_paMed = orig.id_paMed;
        num_stock = orig.num_stock;
        number = orig.number;
    }
    return *this;
}

<<<<<<< HEAD
/**
 * @brief Less than operator.
 * @param stock Other stock to compare.
 * @return true if this ID is less than other ID.
 */
=======
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
bool Stock::operator<(const Stock &stock) const {
    return id_paMed < stock.id_paMed;
}

<<<<<<< HEAD
/**
 * @brief Increments stock.
 * @param n Quantity to add.
 */
=======

>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
void Stock::incrementa(int n) {
    num_stock += n;
}

<<<<<<< HEAD
/**
 * @brief Decrements stock.
 * @param n Quantity to remove.
 */
=======
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
void Stock::decrementa(int n) {
    if (n <= 0) return;
    if (n >= num_stock) num_stock = 0;
    else num_stock -= n;
<<<<<<< HEAD
}

/**
 * @brief Get medicine ID.
 * @return int ID.
 */
=======

}

>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
int Stock::getid_pa_Med() const {
    return id_paMed;
}

<<<<<<< HEAD
/**
 * @brief Get stock quantity.
 * @return int Quantity.
 */
=======
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
int Stock::getnum_stock() const {
    return num_stock;
}
