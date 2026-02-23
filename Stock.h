#ifndef EEDD_PRACTICAS_STOCK_H
#define EEDD_PRACTICAS_STOCK_H

#include "PaMedicamento.h"

/**
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
     */
    Stock();

    /**
     * @brief Constructor que inicializa el stock con una cantidad y un puntero a PaMedicamento.
     * @param num_stock Cantidad inicial de unidades.
     * @param number Puntero al objeto PaMedicamento.
     */
    Stock(int num_stock,PaMedicamento *number);

    /**
     * @brief Constructor que inicializa el stock con un ID de medicamento.
     * @param id_paMed ID del medicamento.
     */
    Stock(int id_paMed);

    /**
     * @brief Constructor de copia de Stock.
     * @param orig Objeto Stock a copiar.
     */
    Stock(const Stock &orig);

    /**
     * @brief Operador de asignación para Stock.
     * @param orig Objeto Stock a asignar.
     * @return Referencia al objeto actual.
     */
    Stock& operator=(const Stock &orig);

    /**
     * @brief Operador de comparación menor que para ordenar Stocks.
     * @param stock Objeto Stock a comparar.
     * @return true si este objeto es menor que el otro, false en caso contrario.
     */
    bool operator<(const Stock &stock) const;

    /**
     * @brief Incrementa la cantidad de stock en n unidades.
     * @param n Número de unidades a incrementar.
     */
    void incrementa(int n);

    /**
     * @brief Decrementa la cantidad de stock en n unidades.
     * @param n Número de unidades a decrementar.
     */
    void decrementa(int n);

    /**
     * @brief Obtiene el ID del medicamento.
     * @return ID del medicamento.
     */
    int getid_pa_Med() const;

    /**
     * @brief Obtiene el puntero al objeto PaMedicamento.
     * @return Puntero al PaMedicamento.
     */
    PaMedicamento* getPaMedicamento() const { return number; }

    /**
     * @brief Obtiene la cantidad de unidades en stock.
     * @return Número de unidades en stock.
     */
    int getnum_stock() const;

};


#endif //EEDD_PRACTICAS_STOCK_H