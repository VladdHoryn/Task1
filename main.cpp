#include <iostream>
#include "Order.h"
//#include "Order.cpp"
#include <queue>

using namespace std;

priority_queue<Order> sell;
priority_queue<Order> buy;

int main() {
    Order a("vlad", 100, 0.1, false);
    Order b;
    sell.push(a);
    b = sell.top();
    cout << b;

    return 0;
}

