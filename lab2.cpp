#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

class Field {

  double *first = new double;
  double *second = new double;

public:

  Field(){
    *first = 0;
    *second = 0;

    cout << "First = " << *first << endl;
    cout << "Second = " << *second << endl;
  };
  ~Field(){
    delete first;
    delete second;
  }

  bool Read(){};
  double distance();
  void Display();
};


double Field::distance(){
  cout << "Enter x value:" << endl;
  cin >> *first;
  cout << "Enter y value:" << endl;
  cin >> *second;
  return sqrt(*first * *first + *second * *second);
}

void Field::Display(){
  cout << *first << "x" << *second << "y. \n";
}

int main(){
  Field MyClass;

  double Distance = MyClass.distance();

  cout << "Distance = " << Distance << "\n";
}
