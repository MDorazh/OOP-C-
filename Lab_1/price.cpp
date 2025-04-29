#include <iostream>
#include "Price.h"

using namespace std;

void Price::print() const {
    cout << grn << " грн " << kop << " коп" << endl;
}

Price Price::add(const Price& other) const {
    Price result;
    result.grn = grn + other.grn;
    result.kop = kop + other.kop;

    if (result.kop >= 100) {  
        result.grn += result.kop / 100; 
        result.kop %= 100;
    }

    return result;
}

Price Price::multiply(int quantity) const {
    int totalKop = (grn * 100 + kop) * quantity;

    Price result;
    result.grn = totalKop / 100;
    result.kop = totalKop % 100;

    return result;
}

void Price::round() {
    int totalKop = grn * 100 + kop;
    int remainder = totalKop % 10;

    if (remainder < 5) {
        totalKop -= remainder;
    } else {
        totalKop += (10 - remainder);
    }

    grn = totalKop / 100;
    kop = totalKop % 100;
}
