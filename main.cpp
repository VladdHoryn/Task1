#include <iostream>
#include "Order.h"
//#include "Order.cpp"
#include <queue>

using namespace std;

bool Compare(Order &sell, Order &buy) {
    int x;
    if(abs(sell.price) <= abs(buy.price)){
        x = min(sell.amount, buy.amount);
        sell.amount -= x;
        buy.amount -= x;
        cout << sell.name << " " << -x << " UAH" << endl;
        cout << buy.name << " " << x << " UAH" << endl;
        return true;
    }
    return false;
}

int main() {
    priority_queue<Order> sell;
    priority_queue<Order> buy;
    int k = 0;
    Order a, seller, buyer;
    while (k != 1){
        cout << "Enter 0 to add order" << endl;
        cout << "Enter 1 if there are no more orders" << endl;
        cin >> k;
        if(k == 0){
            cin >> a;
            if(a.side == 1)
                sell.push(a);
            else
                buy.push(a);
        }
    }

    if(!sell.empty() && !buy.empty()) {
        seller = sell.top();
        sell.pop();
        buyer = buy.top();
        buy.pop();
        while (true) {
//            cout << "seller : " << seller;
//            cout << "buyer : " << buyer;
            if(Compare(seller, buyer))
            {
                if(seller.amount == 0 && sell.size() > 0)
                {
                    seller = sell.top();
                    sell.pop();
                }
                else if(seller.amount == 0)
                    break;

                if(buyer.amount == 0 && buy.size() > 0)
                {
                    buyer = buy.top();
                    buy.pop();
                }
                else if(buyer.amount == 0)
                    break;

            }
            else
                break;

        }
    }

    return 0;
}

