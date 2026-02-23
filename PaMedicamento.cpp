#include "PaMedicamento.h"


PaMedicamento::PaMedicamento(): id_num(0), id_alpha(""), nombre("") {}

PaMedicamento::PaMedicamento(int idN, const std::string &idA, const std::string &nom):
        id_num(idN), id_alpha(idA), nombre(nom){}

PaMedicamento::PaMedicamento(const PaMedicamento &orig)
        : id_num(orig.id_num), id_alpha(orig.id_alpha), nombre(orig.nombre) {}

PaMedicamento& PaMedicamento::operator=(const PaMedicamento &orig) {
    if (this != &orig) {
        id_num = orig.id_num;
        id_alpha = orig.id_alpha;
        nombre = orig.nombre;
    }
    return *this;
}

bool PaMedicamento::operator<(const PaMedicamento& otro) const {
    return id_num < otro.id_num;
}

bool PaMedicamento::operator>(const PaMedicamento& otro) const {
    return id_num > otro.id_num;
}

void PaMedicamento::servidoPor(Laboratorio *lab) {serve = lab;}