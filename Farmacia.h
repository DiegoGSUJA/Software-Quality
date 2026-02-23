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
     */
    Farmacia();

    /**
     * @brief Constructor que inicializa una farmacia con todos sus datos.
     * @param unCif CIF de la farmacia.
     * @param unaProvincia Provincia de la farmacia.
     * @param unaLocalidad Localidad de la farmacia.
     * @param unNombre Nombre de la farmacia.
     * @param unaDireccion Dirección de la farmacia.
     * @param unCodPostal Código postal de la farmacia.
     * @param nlinkMedi Puntero al objeto MediExpress.
     */
    Farmacia(const std::string &unCif, const std::string &unaProvincia, const std::string &unaLocalidad,
             const std::string &unNombre, const std::string &unaDireccion, const std::string &unCodPostal, MediExpress *nlinkMedi);

    /**
     * @brief Constructor de copia de Farmacia.
     * @param orig Objeto Farmacia a copiar.
     */
    Farmacia(const Farmacia &orig);

    /**
     * @brief Operador de asignación para Farmacia.
     * @param orig Objeto Farmacia a asignar.
     * @return Referencia al objeto actual.
     */
    Farmacia& operator=(const Farmacia &orig);

    /**
     * @brief Destructor de Farmacia.
     */
    ~Farmacia();

    /**
     * @brief Operador de comparación menor que para ordenar Farmacias por CIF.
     * @param otro Objeto Farmacia a comparar.
     * @return true si este objeto es menor que el otro, false en caso contrario.
     */
    bool operator<(const Farmacia &otro) const {
        return cif < otro.cif;
    }

    /**
     * @brief Operador de comparación de igualdad para Farmacias por CIF.
     * @param otro Objeto Farmacia a comparar.
     * @return true si los CIF son iguales, false en caso contrario.
     */
    bool operator==(const Farmacia &otro) const {
        return cif == otro.cif;
    }

    /**
     * @brief Operador de comparación mayor que para Farmacias por CIF.
     * @param otro Objeto Farmacia a comparar.
     * @return true si este objeto es mayor que el otro, false en caso contrario.
     */
    bool operator>(const Farmacia &otro) const {
        return cif > otro.cif;
    }

    /**
     * @brief Establece el CIF de la farmacia.
     * @param cif Nuevo CIF de la farmacia.
     */
    void setCif(const std::string &cif);

    /**
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
     */
    std::string getCif();

    /**
     * @brief Permite comprar un medicamento, decrementando el stock si hay suficiente.
     * @param id_num ID del medicamento a comprar.
     * @param n Número de unidades a comprar (siempre 1 por usuario).
     * @param result Puntero al medicamento comprado, o nullptr si no se pudo comprar.
     * @return Número de unidades disponibles inicialmente.
     */
    int comprarMedicam(int id_num, int n, PaMedicamento*& result);

    /**
     * @brief Agrega nuevo stock de un medicamento a la farmacia.
     * @param p Puntero al medicamento.
     * @param n Número de unidades a agregar.
     */
    void nuevoStock(PaMedicamento *p, int n);

    /**
     * @brief Elimina el stock de un medicamento específico.
     * @param id_num ID del medicamento a eliminar.
     * @return true si se eliminó, false si no existía.
     */
    bool eliminarStock(int id_num);

    /**
     * @brief Consulta la cantidad de stock disponible de un medicamento.
     * @param id_num ID del medicamento.
     * @return Número de unidades en stock.
     */
    int consultarStock(int id_num);

    /**
     * @brief Busca medicamentos por nombre parcial.
     * @param nombreParcial Nombre parcial a buscar.
     * @return Vector de punteros a medicamentos encontrados.
     */
    std::vector<PaMedicamento*> buscarMedicamNombre(const std::string& nombreParcial);

private:
    /**
     * @brief Busca un medicamento por ID y devuelve el stock disponible.
     * @param id_num ID del medicamento.
     * @return Número de unidades disponibles.
     */
    int buscaMedicamID(int &id_num);

    /**
     * @brief Realiza un pedido de un medicamento para reponer stock.
     * @param id_num ID del medicamento.
     * @param n Número de unidades a pedir.
     */
    void pedidoMedicam(int id_num, int n);

    
    void reporteEstadoInventario(int prioridad);

    string getProvincia() const { return provincia; }
    string get_localidad() const { return localidad; }
    string get_nombre() const { return nombre; }

};

#endif //CMAKE_INSTALL_CMAKE_FARMACIA_H
