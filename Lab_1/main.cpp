#include <iostream>
#include <fstream>
#include "Price.h"

using namespace std;

int main() {
    ifstream file("input.txt");
    if (!file) {
        cout << "Файл input.txt не знайдено!" << endl;
        return 1;
    }

    Price total = {0, 0};

    int grn, kop, quantity;
    while (file >> grn >> kop >> quantity) {
        Price item = {grn, kop};
        Price itemTotal = item.multiply(quantity);
        total = total.add(itemTotal);
    }

    cout << "Загальна сума: ";
    total.print();

    total.round();
    cout << "Сума до оплати (після заокруглення): ";
    total.print();

    return 0;
}
