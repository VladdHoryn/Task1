#include "Order.h"

#include <utility>

using namespace std;

void Order::AddInfo(std::string n, int a, float p, bool s) {
    name = std::move(n);
    amount = a;
    price = p;
    side = s;
    //std::cout << name << " " << amount << " " << price << " " << side << endl;
}

istream &operator>>(istream &is, Order &obj){
    cout << "Enter 0 if you want to buy, 1 if you want to sell: ";
    is >> obj.side;
    cout << "Enter name if the User: ";
    is >> obj.name;
    cout << "Enter amount of UAH: ";
    is >> obj.amount;
    cout << "Enter price for 1 UAH in USD: ";
    is >> obj.price;
    if(obj.side == 1)
        obj.price = -obj.price;


    return is;
}

ostream  &operator<<(ostream &os, Order &obj){
    os << obj.name << " " << obj.amount << " " << obj.price << " " << obj.side << endl;
    return os;
}

bool Order::operator<(const Order &obj) const {
    return this->price < obj.price;
}