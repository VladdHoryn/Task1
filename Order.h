#ifndef TASK1_ORDER_H
#define TASK1_ORDER_H

#include <iostream>
#include <string>
#include <math.h>
#include <memory>

using namespace std;

class Order {
public:
    string name;
    int amount;
    float price;
    bool side;

    Order(): name{"Unknown"}, amount{0}, price{0}, side{true} {}
    Order(string n, int a, float p, bool s): name{n}, amount{a}, price{p}, side{s} {}
    ~Order(){
        //cout << "Order destructor was called" << endl;
    }
    void AddInfo(string n, int a, float p, bool s);
    friend istream &operator >>(istream &is, Order &obj);
    friend ostream &operator <<(ostream &os, Order &obj);
    bool operator<(const Order &obj) const;
};


#endif //TASK1_ORDER_H
