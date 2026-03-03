/**
 * @file MediExpress.h
 * @author Emma Melero Reche and Diego Gómez Sánchez
 * @brief Header of the MediExpress class.
 * @version 0.1
 * @date 2026-03-02
 * 
 * @copyright Copyright (c) 2026
 */

#ifndef EEDD_PRACTICAS_MEDIEXPRESS_H
#define EEDD_PRACTICAS_MEDIEXPRESS_H

#include <vector>
#include <list>
#include <map>
#include "PaMedicamento.h"
#include "Laboratorio.h"

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
     */
    MediExpress(const std::string &medicamentos, const std::string &laboratorios, const std::string &farmacias, std::vector<std::string> &cifs_farmacias);

    /**
     * @brief Reads medicine data from a CSV file.
     * @param v Reference to the map to store data.
     * @param filename Path to the CSV file.
     */
    void lecturaMedicamentos(std::map<int, PaMedicamento> &v, const std::string &filename);

    /**
     * @brief Reads laboratory data from a CSV file.
     * @param l Reference to the list to store data.
     * @param filename Path to the CSV file.
     */
    void lecturaLaboratorios(std::list<Laboratorio> &l, const std::string &filename);

    /**
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
     */
    void suministrarMed(PaMedicamento *pa, Laboratorio *lab);

    /**
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
     */
    PaMedicamento* buscarCompuesto(int &id_num);

    /**
     * @brief Gets a list of medicines that have no assigned laboratory.
     * @return Vector of pointers to medicines.
     */
    std::vector<PaMedicamento*> getMedicamentoSinlab();

    /**
     * @brief Destructor.
     */
    ~MediExpress();

    /**
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
     */
    void suministrarFarmacia(Farmacia *f, int id_num, int n);

    /**
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
     */
    void enlaza_Farmacia_medicamento(std::vector<std::string>& cifs_farmacias);

    /**
     * @brief Removes a medicine from the system and all pharmacies.
     * @param id_num ID of the medicine to remove.
     * @return true if removed, false otherwise.
     */
    bool eliminarMedicamento(int id_num);

    /**
     * @brief Getter for the pharmacy vector.
     * @return Vector of pharmacies.
     */
    std::vector<Farmacia>& getpharmacy();

    /**
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
