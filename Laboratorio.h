#ifndef EEDD_PRACTICAS_LABORATORIO_H
#define EEDD_PRACTICAS_LABORATORIO_H

#include <string>

using namespace std;


class Laboratorio {
    private:
    int id;
    string nombreLab;
    string direccion;
    string codPostal;
    string localidad;

    public:
    /**
     * @brief Constructor por defecto.
     */
    Laboratorio();

    /**
     * @brief Constructor parametrizado.
     * @param labId Identificador numérico del laboratorio.
     * @param nom Nombre del laboratorio.
     * @param dir Dirección completa.
     * @param cp Código postal.
     * @param loc Localidad.
     */
    Laboratorio(int labId, const string &nom, const string &dir, const string &cp, const string &loc);

    /**
     * @brief Constructor de copia.
     * @param orig Objeto a copiar.
     */
    Laboratorio(const Laboratorio &orig);

    /**
     * @brief Operador de asignación.
     * @param orig Objeto a copiar.
     * @return Referencia al objeto actual.
     */
    Laboratorio& operator=(const Laboratorio &orig);

    // Getters
    int get_id() const { return id; }
    string &get_nombreLab() { return nombreLab; }
    string get_direccion() const { return direccion; }
    string get_codPostal() const { return codPostal; }
    string get_localidad() const { return localidad; }

    // Setters
    void set_id(int labId) { id = labId; }
    void set_nombreLab(const string &nom) { nombreLab = nom; }
    void set_direccion(const string &dir) { direccion = dir; }
    void set_codPostal(const string &cp) { codPostal = cp; }
    void set_localidad(const string &loc) { localidad = loc; }

    /**
     * @brief Operador menor que.
     * @param otro Otro laboratorio.
     * @return true si el ID actual es menor que el otro.
     */
    bool operator<(const Laboratorio &otro) const;

    /**
     * @brief Operador mayor que.
     * @param otro Otro laboratorio.
     * @return true si el ID actual es mayor que el otro.
     */
    bool operator>(const Laboratorio& otro) const;

    /**
     * @brief Operador de igualdad.
     * @param otro Otro laboratorio.
     * @return true si el ID actual es igual que el otro.
     */
    bool operator==(const Laboratorio& otro) const;
};


#endif //EEDD_PRACTICAS_LABORATORIO_H