#include <iostream>
#include "queue_sorted.h"
#include "queue_sorted.cpp"

using namespace std;

int main() {
    queue_sorted<int> a;
    a.Enqueue(100);
    a.Enqueue(15);
    a.Enqueue(-1);
    a.Enqueue(-10);
    a.Enqueue(-3);
    a.Print();
    return 0;
}
