#ifndef EEDD_PRACTICAS_MEDIEXPRESS_H
#define EEDD_PRACTICAS_MEDIEXPRESS_H

#include <vector>
#include <list>
#include <map>
#include "PaMedicamento.h"
#include "Laboratorio.h"


class Farmacia;
/**
 * @brief Clase principal que gestiona la base de datos de medicamentos y laboratorios.
 *
 * MediExpress se encarga de almacenar y gestionar la relacion de suministro
 * entre los medicamentos (PaMedicamento) y los laboratorios (Laboratorio)
 * utilizando estructuras dinamicas como VDinamic y ListaEnlazada.
 */
class MediExpress {
private:
    std::map<int,PaMedicamento> medication;    /// Mapa para almacenar los medicamentos con id_num como clave.
    std::list<Laboratorio> labs;               /// Lista enlazada para almacenar los laboratorios.
    std::vector<Farmacia> pharmacy;            /// Vector dinamico para almacenar las farmacias.


public:

    /**
     * @brief Constructor por defecto de MediExpress.
     * * Es responsable de inicializar la aplicacion, lo que generalmente incluye
     * * la lectura y carga de los datos iniciales de medicamentos y laboratorios.
     */
    MediExpress(const std::string &medicamentos, const std::string &laboratorios, const std::string &farmacias, std::vector<std::string> &cifs_farmacias);

    /**
     * @brief Lee los datos de medicamentos desde un archivo y los carga en un contenedor.
     * @param v Referencia al contenedor dinamico donde se cargaran los objetos PaMedicamento.
     * @param filename El nombre del archivo CSV (o similar) con los datos de medicamentos.
     */
    void lecturaMedicamentos(std::map<int,PaMedicamento> &v, const std::string &filename);

    /**
     * @brief Lee los datos de laboratorios desde un archivo y los carga en una lista.
     * @param l Referencia a la lista enlazada donde se cargaran los objetos Laboratorio.
     * @param filename El nombre del archivo CSV (o similar) con los datos de laboratorios.
     */
    void lecturaLaboratorios(std::list<Laboratorio> &l, const std::string &filename);

    /**
     * @brief Lee los datos de laboratorios desde un archivo y los carga en una lista.
     * @param l Referencia a la lista enlazada donde se cargaran los objetos Laboratorio.
     * @param filename El nombre del archivo CSV (o similar) con los datos de laboratorios.
     */
    void lecturaFarmacias(std::vector<Farmacia> &ph, const std::string &filename, std::vector<string> &cifs_farmacias);

    /**
     * @brief Lee los datos de farmacias desde un archivo y los carga en un vector dinamico.
     * @param vec Referencia al contenedor dinamico donde se cargaran los objetos Farmacia.
     * @param filename El nombre del archivo CSV (o similar) con los datos de farmacias.
     */
    void lecturaFarmaciasVector(std::vector<Farmacia> &vec, const std::string &filename);


    /**
     * @brief Realiza la vinculacion automatica inicial entre medicamentos y laboratorios.
     * * Esta funcion utiliza la informacion cargada para establecer la relacion de suministro
     * * de forma masiva (p.ej., basandose en IDs o nombres preestablecidos en los datos de entrada).
     * @param v Referencia al contenedor de medicamentos.
     * @param l Referencia a la lista de laboratorios.
     */
    void enlazaAutomatizado(std::map<int,PaMedicamento> &v, std::list<Laboratorio> &l);

    /**
     * @brief Asigna un laboratorio especifico como suministrador de un medicamento.
     * @param pa Puntero al objeto PaMedicamento que se va a suministrar.
     * @param lab Puntero al objeto Laboratorio que sera el suministrador.
     */
    void suministrarMed(PaMedicamento *pa, Laboratorio *lab);

    /**
     * @brief Busca un laboratorio por su nombre.
     * @param nombreLab Nombre del laboratorio a buscar.
     * @return Laboratorio* Puntero al objeto Laboratorio encontrado, o `nullptr` si no existe.
     */
    Laboratorio* buscarLab(string &nombreLab);

    /**
     * @brief Busca y recupera todos los laboratorios ubicados en una ciudad especifica.
     * @param nombreCiudad Nombre de la ciudad o localidad a buscar.
     * @return ListaEnlazada<Laboratorio*> Una lista enlazada de punteros a los laboratorios encontrados.
     */
    std::list<Laboratorio*> buscarLabCiudad(string &nombreCiudad);

    /**
     * @brief Busca y recupera todos los medicamentos que contienen un principio activo (compuesto) dado.
     * @param nombrePA Nombre del principio activo a buscar.
     * @return VDinámico<PaMedicamento*> Un vector dinamico de punteros a los medicamentos encontrados.
     */
    std::vector<PaMedicamento*> buscarCompuesto(string &nombrePA);

    /**
     * @brief Busca un medicamento por su ID numérico.
     * @param id_num ID numérico del medicamento a buscar.
     * @return PaMedicamento* Puntero al objeto PaMedicamento encontrado, o `nullptr` si no existe.
     */
    PaMedicamento* buscarCompuesto(int &id_num);

    /**
     * @brief Obtiene una lista de todos los medicamentos que actualmente no tienen un laboratorio suministrador asignado.
     * @return VDinámico<PaMedicamento*> Un vector dinamico de punteros a los medicamentos sin laboratorio.
     */
    std::vector<PaMedicamento*> getMedicamentoSinlab();

    /**
     * @brief Destructor de MediExpress.
     * Es responsable de liberar cualquier recurso o memoria dinamica gestionada por la clase,
     * aunque gran parte de la limpieza la realizan los destructores de sus atributos (vector, ListaEnlazada).
     */
    ~MediExpress();

    /**
     * @brief Elimina todos los laboratorios que se encuentran en la ciudad especificada.
     * * Los medicamentos que tuvieran como suministrador a uno de estos laboratorios
     * * deben actualizar su puntero a suministrador a `nullptr`.
     * @param ciudad Nombre de la ciudad de la que se eliminaran los laboratorios.
     * @return int El numero de laboratorios que fueron eliminados.
     */
    int eliminarLaboratoriosCiudad(const std::string &ciudad);


    /**
     * @brief Suministra un medicamento especifico a una farmacia determinada.
     * @param f Puntero a la farmacia que recibira el suministro.
     * @param id_num ID numerico del medicamento a suministrar.
     * @param n Cantidad de unidades a suministrar.
     */
    void suministrarFarmacia(Farmacia *f, int id_num, int n);

    /**
     * @brief Busca una farmacia por su CIF.
     * @param cif CIF de la farmacia a buscar.
     * @return Farmacia* Puntero al objeto Farmacia encontrado, o `nullptr` si no existe.
     */
    Farmacia* buscarFarmacia(string &cif);

    /**
     * @brief Busca y recupera todas las farmacias ubicadas en una provincia especifica.
     * @param provincia Nombre de la provincia a buscar.
     * @return VDinámico<Farmacia*> Un vector dinamico de punteros a las farmacias encontradas.
     */
    std::vector<Farmacia*> buscarFarmacias(string &provincia);

    /**
     * @brief Busca y recupera todos los laboratorios que suministran un principio activo (compuesto) dado.
     * @param nombrePA Nombre del principio activo a buscar.
     * @return VDinámico<Laboratorio*> Un vector dinamico de punteros a los laboratorios encontrados.
     */
    std::vector<Laboratorio*> buscarLabs(const string &nombrePA);

    /**
     * @brief Realiza la vinculacion entre farmacias y medicamentos.
     * * Esta funcion utiliza la informacion cargada para establecer la relacion de suministro
     * * entre farmacias y medicamentos.
     * @param cifs_farmacias Referencia al contenedor de CIFs de farmacias.
     */
    void enlaza_Farmacia_medicamento(std::vector<std::string>& cifs_farmacias);

    /**
     * @brief Elimina un medicamento especifico de todas las farmacias.
     * @param id_num ID numerico del medicamento a eliminar.
     * @return bool `true` si el medicamento fue eliminado de al menos una farmacia, `false` si no se encontro en ninguna.
     */
    bool eliminarMedicamento(int id_num);

    /**
     * @brief Obtiene el vector dinamico de farmacias gestionadas por MediExpress.
     * @return VDinámico<Farmacia>& Referencia al vector dinamico de farmacias.
     */
    std::vector<Farmacia>& getpharmacy();

    /**
     * @brief Obtiene la lista enlazada de laboratorios gestionados por MediExpress.
     * @return ListaEnlazada<Laboratorio>& Referencia a la lista enlazada de laboratorios.
     */
    std::list<Laboratorio>& getlabs();

    void redistribuirStockUrgente(string medicamento, string origen, string destino);


};


#endif //EEDD_PRACTICAS_MEDIEXPRESS_H

