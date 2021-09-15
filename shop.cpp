#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Struct for Products
struct Product{
  string name;
  string price;
  string date_arrived;
  string amount;
};


int File(string file_name, int action)
{

    ifstream file;
    file.open(file_name);


    // Creating list of structures with Product type
    int amountOfProducts = 0;

    string line;

    while(getline(file, line)){
      ++amountOfProducts;
    }


    Product Products[amountOfProducts] = {};

    for(int i = 0; i < amountOfProducts; i++)
    {
        // Setting values to struct array
        getline(file, Products[i].name, ',');
        getline(file, Products[i].price, ',');
        getline(file, Products[i].date_arrived, ',');
        getline(file, Products[i].amount, '\n');
    }

    // Find Element by name
    string search_name;

    if(action == 1){

      cout << "Enter product name: ";
      cin >> search_name;

      for(int i = 0; i < amountOfProducts; i++){

        if(Products[i].name == search_name){
            cout << Products[i].name << " " << Products[i].price << " " << Products[i].date_arrived << " " << Products[i].amount << "\n";
        }

      }

      exit(2);
    }

    // Change element by name
    if(action == 2){

      cout << "Enter product name: ";
      cin >> search_name;

      string new_name;
      string new_price;
      string new_date_arrived;
      string new_amount;

      for(int i = 0; i < amountOfProducts; i++){

        if(Products[i].name == search_name){

          cout << Products[i].name << " " << Products[i].price << " " << Products[i].date_arrived << " " << Products[i].amount << "\n";

          cout << "Enter new name:";
          cin >> new_name;
          cout << "Enter new price:";
          cin >> new_price;
          cout << "Enter new date arrived:";
          cin >> new_date_arrived;
          cout << "Enter new amount:";
          cin >> new_amount;

          Products[i].name = new_name;
          Products[i].price = new_price;
          Products[i].date_arrived = new_date_arrived;
          Products[i].amount = new_amount;
        }
      }

      ofstream fout;

      fout.open(file_name);

      for(int i = 0; i < amountOfProducts; i++)
      {
          fout << Products[i].name << "," << Products[i].price << "," << Products[i].date_arrived << "," << Products[i].amount << "\n";
      }

      fout.close();
    }

    file.close();

    return 0;

}

int main(){

    int action;
    cout << "Choose an action 1 is find element by name, 2 is change element by name";
    cin >> action;

    File("shop.txt", action);

    return 0;
}
