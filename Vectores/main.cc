int main(){
  //Create a vector with {1,2,3,4}
  Vector v(4, 0);
  //initialize
  v.initialize();
  //print
  v.print();
  //push_back
  v.push_back(5);
  //print
  v.print();
  //empty?
  cout << v.empty() << endl;
  //push_front
  v.push_front(3);
  //print
  v.print();
    return 0;
}
