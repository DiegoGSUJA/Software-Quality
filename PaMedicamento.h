
#ifndef EEDD_PRACTICAS_PAMEDICAMENTO_H
#define EEDD_PRACTICAS_PAMEDICAMENTO_H


#include <string>
#include "Laboratorio.h"

class PaMedicamento {
private:
    int id_num;
    std::string id_alpha;
    std::string nombre;
    Laboratorio *serve;
public:
    /**
     * @brief Constructor por defecto.
     */
    PaMedicamento();

    /**
     * @brief Constructor parametrizado.
     * @param idN Identificador numérico.
     * @param idA Identificador alfanumérico.
     * @param nom Nombre del medicamento.
     */
    PaMedicamento(int idN, const std::string &idA, const std::string &nom);

    /**
     * @brief Constructor de copia.
     * @param orig Objeto a copiar.
     */
    PaMedicamento(const PaMedicamento &orig);

    /**
     * @brief Operador de asignación.
     * @param orig Objeto a copiar.
     * @return Referencia al objeto actual.
     */
    PaMedicamento& operator=(const PaMedicamento &orig);

    // Getters
    int get_id_num() const { return id_num; }
    std::string get_id_alpha() const { return id_alpha; }
    std::string get_nombre() const { return nombre; }
    Laboratorio* get_serve() const{return serve;}

    /**
     * @brief Operador menor que.
     * @param otro Otro medicamento.
     * @return true si es menor, false en caso contrario.
     */
    bool operator<(const PaMedicamento &otro) const;
    /**
     * @brief Operador mayor que.
     * @param otro Otro medicamento.
     * @return true si es mayor, false en caso contrario.
     * Ambos operadores necesarios para la busqueda binaria
     */
    bool operator>(const PaMedicamento& otro) const;

    /**
     * @brief Asocia un laboratorio que suministra el medicamento.
     * @param lab Puntero al laboratorio.
     */
    void servidoPor(Laboratorio *lab);

};


#endif //EEDD_PRACTICAS_PAMEDICAMENTO_H
