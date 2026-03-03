<<<<<<< HEAD
/**
 * @file MediExpress.h
 * @author Emma Melero Reche and Diego Gómez Sánchez
 * @brief Header of the MediExpress class.
 * @version 0.1
 * @date 2026-03-02
 * 
 * @copyright Copyright (c) 2026
 */

=======
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
#ifndef EEDD_PRACTICAS_MEDIEXPRESS_H
#define EEDD_PRACTICAS_MEDIEXPRESS_H

#include <vector>
#include <list>
#include <map>
#include "PaMedicamento.h"
#include "Laboratorio.h"

<<<<<<< HEAD
class Farmacia;

/**
 * @brief Class that manages the system, linking pharmacies, laboratories, and medicines.
 */
class MediExpress {
private:
    std::map<int, PaMedicamento> medication; ///< Map to store medicines with their ID as key.
    std::list<Laboratorio> labs;             ///< List of laboratories.
    std::vector<Farmacia> pharmacy;         ///< Vector of pharmacies.

public:
    /**
     * @brief Constructor for MediExpress.
     * @param medicamentos Filename for medicines CSV.
     * @param laboratorios Filename for laboratories CSV.
     * @param farmacias Filename for pharmacies CSV.
     * @param cifs_farmacias Vector to store CIFs of loaded pharmacies.
=======

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
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
     */
    MediExpress(const std::string &medicamentos, const std::string &laboratorios, const std::string &farmacias, std::vector<std::string> &cifs_farmacias);

    /**
<<<<<<< HEAD
     * @brief Reads medicine data from a CSV file.
     * @param v Reference to the map to store data.
     * @param filename Path to the CSV file.
     */
    void lecturaMedicamentos(std::map<int, PaMedicamento> &v, const std::string &filename);

    /**
     * @brief Reads laboratory data from a CSV file.
     * @param l Reference to the list to store data.
     * @param filename Path to the CSV file.
=======
     * @brief Lee los datos de medicamentos desde un archivo y los carga en un contenedor.
     * @param v Referencia al contenedor dinamico donde se cargaran los objetos PaMedicamento.
     * @param filename El nombre del archivo CSV (o similar) con los datos de medicamentos.
     */
    void lecturaMedicamentos(std::map<int,PaMedicamento> &v, const std::string &filename);

    /**
     * @brief Lee los datos de laboratorios desde un archivo y los carga en una lista.
     * @param l Referencia a la lista enlazada donde se cargaran los objetos Laboratorio.
     * @param filename El nombre del archivo CSV (o similar) con los datos de laboratorios.
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
     */
    void lecturaLaboratorios(std::list<Laboratorio> &l, const std::string &filename);

    /**
<<<<<<< HEAD
     * @brief Reads pharmacy data from a CSV file and populates initial CIFs.
     * @param ph Reference to the vector to store data.
     * @param filename Path to the CSV file.
     * @param cifs_farmacias Reference to the vector of CIFs.
     */
    void lecturaFarmacias(std::vector<Farmacia> &ph, const std::string &filename, std::vector<std::string> &cifs_farmacias);

    /**
     * @brief Reads pharmacy data into a vector.
     * @param vec Reference to the vector to store data.
     * @param filename Path to the CSV file.
     */
    void lecturaFarmaciasVector(std::vector<Farmacia> &vec, const std::string &filename);

    /**
     * @brief Automatically links medicines to laboratories.
     * @param v Reference to the map of medicines.
     * @param l Reference to the list of labs.
     */
    void enlazaAutomatizado(std::map<int, PaMedicamento> &v, std::list<Laboratorio> &l);

    /**
     * @brief Manually links a medicine to a laboratory.
     * @param pa Pointer to the medicine.
     * @param lab Pointer to the laboratory.
=======
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
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
     */
    void suministrarMed(PaMedicamento *pa, Laboratorio *lab);

    /**
<<<<<<< HEAD
     * @brief Searches for a laboratory by name.
     * @param nombreLab Name of the laboratory.
     * @return Pointer to the laboratory or nullptr if not found.
     */
    Laboratorio* buscarLab(std::string &nombreLab);

    /**
     * @brief Searches for laboratories in a specific city.
     * @param nombreCiudad Name of the city.
     * @return List of pointers to matching laboratories.
     */
    std::list<Laboratorio*> buscarLabCiudad(std::string &nombreCiudad);

    /**
     * @brief Searches for medicines by name.
     * @param nombrePA Name of the medicine.
     * @return Vector of pointers to matching medicines.
     */
    std::vector<PaMedicamento*> buscarCompuesto(std::string &nombrePA);

    /**
     * @brief Searches for a medicine by numeric ID.
     * @param id_num Numeric ID.
     * @return Pointer to the medicine or nullptr if not found.
=======
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
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
     */
    PaMedicamento* buscarCompuesto(int &id_num);

    /**
<<<<<<< HEAD
     * @brief Gets a list of medicines that have no assigned laboratory.
     * @return Vector of pointers to medicines.
=======
     * @brief Obtiene una lista de todos los medicamentos que actualmente no tienen un laboratorio suministrador asignado.
     * @return VDinámico<PaMedicamento*> Un vector dinamico de punteros a los medicamentos sin laboratorio.
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
     */
    std::vector<PaMedicamento*> getMedicamentoSinlab();

    /**
<<<<<<< HEAD
     * @brief Destructor.
=======
     * @brief Destructor de MediExpress.
     * Es responsable de liberar cualquier recurso o memoria dinamica gestionada por la clase,
     * aunque gran parte de la limpieza la realizan los destructores de sus atributos (vector, ListaEnlazada).
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
     */
    ~MediExpress();

    /**
<<<<<<< HEAD
     * @brief Deletes all laboratories in a given city.
     * @param ciudad name of the city.
     * @return Number of laboratories removed.
     */
    int eliminarLaboratoriosCiudad(const std::string &ciudad);

    /**
     * @brief Replenishes stock for a specific pharmacy.
     * @param f Pointer to the pharmacy.
     * @param id_num ID of the medicine.
     * @param n Quantity to supply.
=======
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
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
     */
    void suministrarFarmacia(Farmacia *f, int id_num, int n);

    /**
<<<<<<< HEAD
     * @brief Searches for a pharmacy by CIF.
     * @param cif CIF of the pharmacy.
     * @return Pointer to the pharmacy or nullptr if not found.
     */
    Farmacia* buscarFarmacia(std::string &cif);

    /**
     * @brief Searches for pharmacies in a specific province.
     * @param provincia Name of the province.
     * @return Vector of pointers to pharmacies.
     */
    std::vector<Farmacia*> buscarFarmacias(std::string &provincia);

    /**
     * @brief Searches for laboratories that supply a specific medicine.
     * @param nombrePA Name of the medicine.
     * @return Vector of pointers to laboratories.
     */
    std::vector<Laboratorio*> buscarLabs(const std::string &nombrePA);

    /**
     * @brief Randomly links initial stock to pharmacies.
     * @param cifs_farmacias CIFs of the pharmacies to populate.
=======
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
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
     */
    void enlaza_Farmacia_medicamento(std::vector<std::string>& cifs_farmacias);

    /**
<<<<<<< HEAD
     * @brief Removes a medicine from the system and all pharmacies.
     * @param id_num ID of the medicine to remove.
     * @return true if removed, false otherwise.
=======
     * @brief Elimina un medicamento especifico de todas las farmacias.
     * @param id_num ID numerico del medicamento a eliminar.
     * @return bool `true` si el medicamento fue eliminado de al menos una farmacia, `false` si no se encontro en ninguna.
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
     */
    bool eliminarMedicamento(int id_num);

    /**
<<<<<<< HEAD
     * @brief Getter for the pharmacy vector.
     * @return Vector of pharmacies.
=======
     * @brief Obtiene el vector dinamico de farmacias gestionadas por MediExpress.
     * @return VDinámico<Farmacia>& Referencia al vector dinamico de farmacias.
>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
     */
    std::vector<Farmacia>& getpharmacy();

    /**
<<<<<<< HEAD
     * @brief Getter for the laboratory list.
     * @return List of laboratories.
     */
    std::list<Laboratorio>& getlabs();

    /**
     * @brief Handles urgent stock redistribution between provinces.
     * @param medicamento Name of the medicine.
     * @param origen Source province.
     * @param destino Destination province.
     */
    void redistribuirStockUrgente(std::string medicamento, std::string origen, std::string destino);

};

#endif // EEDD_PRACTICAS_MEDIEXPRESS_H
=======
     * @brief Obtiene la lista enlazada de laboratorios gestionados por MediExpress.
     * @return ListaEnlazada<Laboratorio>& Referencia a la lista enlazada de laboratorios.
     */
    std::list<Laboratorio>& getlabs();

    void redistribuirStockUrgente(string medicamento, string origen, string destino);


};


#endif //EEDD_PRACTICAS_MEDIEXPRESS_H

>>>>>>> 999b9a08297f7ad8d51f2d1403d58432c37d04d4
