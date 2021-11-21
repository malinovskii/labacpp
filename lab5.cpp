#include <iostream>
#include <windows.h>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename T, typename T2>

class Massiv
{

	T2 size;
	T* mas;

	public:

	Massiv(){}

	Massiv(T2 size_mass = 0, T* get = 0){

		size = size_mass;

		mas = new T[size];

		for (int i = 0; i < size; i++)

		{

		mas[i] = get[i];

		}

		cout << "Constructor with parameters finished\n";

	}

	Massiv(const Massiv& object){

		this->size = object.size;

		this->mas = new T[object.size];

		for (int i = 0; i < size; i++){
			this->mas[i] = object.mas[i];
		}

		cout << "Copying constructor finished\n";

	}

	void Action(){

		cout << "Changed string output: ";

    int min = mas[0];
    for(int i = 0; i < 4; ++i)
    {
        if(mas[i] < min)
        {
            min = mas[i];
        }
    }

		for (int i = 0; i < size; i++){

			cout << min* mas[i] << " ";

		}

		cout << endl;

	}

	~Massiv(){

	cout << "Destructor has been called" << '\n';

	delete[]mas;

	}

};

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}


int main(){

  srand(time(NULL));

	string s_get = to_string(getRandomNumber(1,20)) + "," + to_string(getRandomNumber(1,20)) + "," + to_string(getRandomNumber(1,20)) + "," + to_string(getRandomNumber(1,20)) ;

	cout << s_get << '\n';

	string help_string;

	int count_numbers = 0;

	int count = 0;

	for (int i = 0; i < s_get.length(); i++){

		if (s_get[i] == ','){
			count_numbers += 1;
		}

	}

	count_numbers++;

	int* need = new int[count_numbers];

	for (int i = 0; i < s_get.length(); i++){

		if (s_get[i] == ','){

			need[count] = atoi(help_string.c_str()); // Converting from string to int and write to list

			count++;

			help_string = "";

		} else {

			help_string += s_get[i];

		}

	}

	need[count] = atoi(help_string.c_str()); // Writing last number to array

	Massiv <int, int> help(count_numbers, need);

	help.Action();

	Massiv <int, int> Copying(help); // Copying constructor demo

  Copying.Action();

	Massiv <int, long> Sample_func(count_numbers, need); // Sample function  demo

	Sample_func.Action();

	delete[]need;

}
