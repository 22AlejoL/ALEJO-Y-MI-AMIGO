
int main() {
    Vector v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    v.push_back(10);
    cout << "Front: " << v.front() << endl; // Imprime 1
    cout << "Back: " << v.back() << endl;   // Imprime 3
    cout << "Elemento en la posición 1: " << v.at(1) << endl; // Imprime 2
    v.pop_back();
    cout << "Back después de pop_back(): " << v.back() << endl; // Imprime 2
    v.pop_front();
    cout << "Front después de pop_front(): " << v.front() << endl; // Imprime 2
    v.push_front(5);
    cout << "Front después de push_front(5): " << v.front() << endl; // Imprime 5
    return 0;
}
