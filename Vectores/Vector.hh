#include<iostream>
//For vectors
#include<vector>

//define red
#define RED "\033[31m"
#define RESET "\033[0m"


//for std
using namespace std;


class Vector
{
private:
  unsigned int size;
  unsigned int capacity;
  int *data;
public:

  //make the constructor
  Vector(unsigned int size)
  {
    this->capacity = size;
    this->data = new int[size];//the nwe is for the size of the vector and does not have to be the same as the capacity
  }

  //print the vector
  void print()
  {
    for (int i = 0; i < size; i++)
    {
      cout << data[i] << " ";
    }
    cout << endl;
  }

    //-------------------------------------
  //Requeriments
  //Empty
  bool empty()
  {
    return size == 0;
  }

  //int size
  unsigned int sizeWidth()
  {
    return size;
  }

  //pushback function
  void push_back(int value)
  {
    if (size == capacity)
    {
      resize();
      data[size] = value;
      size++;
    }
    else{
      data[size] = value;
      size++;
    }
  }

  //resize function
  void resize()
  {
    int *temp = new int[capacity * 2];
    for ( unsigned int i = 0; i < size; i++)
    {
      temp[i] = data[i];
    }
    delete[] data;
    data = temp;
    capacity *= 2;
  }

  //push_front function
  void push_front(int nuevoValor)
  {
    if (size == capacity)
    {
      resize();
    }
    int *temp = new int[capacity];
    temp[0]=nuevoValor;
    for ( unsigned int i = 0; i < size; i++)
    {
      temp[i+1] = data[i];
    }
    size++;
    delete[] data;
    data = temp;
  }
  //Returns the last term in the vector
  int& back()
  {
    return data[size-1];
  }

  //int& front
  int& front()
  {
    return data[0];
  }

  //int& position p
  int& at(unsigned int p)
  {
    return data[p];
  }

  //pop_back function
  void pop_back()
  {
    size--;
  }

  //pop_front function
  void pop_front()
  {
    int *temp = new int[capacity];
    for ( unsigned int i = 0; i < size; i++)
    {
      temp[i] = data[i+1];
    }
    delete[] data;
    data = temp;
    size--;
  }

};


