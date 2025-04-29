#ifndef PRICE_H
#define PRICE_H

struct Price {
    int grn;
    short int kop;

    void print() const;
    Price add(const Price& other) const;
    Price multiply(int quantity) const;
    void round();
};

#endif
