#include "Stock.h"

Stock::Stock(): id_paMed(0), num_stock(0), number(nullptr) {}

Stock::Stock(int id_paMed): id_paMed(id_paMed), num_stock(0), number(nullptr) {}

Stock::Stock(int num_stock, PaMedicamento *number)
: id_paMed(number->get_id_num()), num_stock(num_stock), number(number) {}

Stock::Stock(const Stock &orig)
: id_paMed(orig.id_paMed), num_stock(orig.num_stock), number(orig.number) {}

Stock &Stock::operator=(const Stock &orig) {
    if (this != &orig) {
        id_paMed = orig.id_paMed;
        num_stock = orig.num_stock;
        number = orig.number;
    }
    return *this;
}

bool Stock::operator<(const Stock &stock) const {
    return id_paMed < stock.id_paMed;
}


void Stock::incrementa(int n) {
    num_stock += n;
}

void Stock::decrementa(int n) {
    if (n <= 0) return;
    if (n >= num_stock) num_stock = 0;
    else num_stock -= n;

}

int Stock::getid_pa_Med() const {
    return id_paMed;
}

int Stock::getnum_stock() const {
    return num_stock;
}
