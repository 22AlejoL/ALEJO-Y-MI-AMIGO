#include <iostream>
#include "listc.hh"

using namespace std;

int main() {
    cout << "hola" << endl;
    List<int> l;
    l.print();
    l.push_back(10);
    l.print();
    l.push_front(-12);
    l.print();
    return 0;
}
