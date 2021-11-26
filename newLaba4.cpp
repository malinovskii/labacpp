// #include <vcl>
#include <iostream>
// #include <stdio>
// #include <conio>
#include <string.h>
using namespace std;
class Timee
{
	int hour, min, sec;

public:
	Timee(int a, int b, int c) { hour = a; min = b; sec = c; }

	Timee(int a) { hour = (a / 3600); min = (a - hour * 3600) / 60; sec = a - hour * 3600 - min * 60; }
  
	Timee(const char *str)
	{
		string a; int n = 0, ob[3];
		for (int i = 0; i<(strlen(str) + 1); i++)
			if (str[i] != ':' && i != strlen(str))
				a += str[i];
			else
			{

				ob[n] = atoi(a.c_str());

				n++;
				a = "";
			}
		hour = ob[0];
		min = ob[1];
		sec = ob[2];
	}

	ShowTime()

	{
		cout << hour << ":" << min << ":" << sec;
	}

	void operator +(Timee obj)
	{
		this->sec += obj.sec;
		if (this->sec >= 60)
		{
			this->min++; this->sec -= 60;
		}

		this->min = this->min + obj.min;
		if (this->min >= 60)
		{
			this->hour++; this->min -= 60;
		}

		this->hour = this->hour + obj.hour;
	}

	void operator +(int a)
	{
		this->sec += a;

		if (this->sec >= 60)
		{
			this->min++; this->sec -= 60;
		}

		if (this->min >= 60)
		{
			this->hour++; this->min -= 60;
		}
	}

	void operator -(int a)
	{
		this->sec -= a;


		while (this->sec < 0)
		{
			this->min--; this->sec += 60;
		}

		while (this->min < 0)
		{
			this->hour--; this->min += 60;
		}

		while (this->hour < 0)
			this->hour++;
	}

	bool operator ==(Timee obj)
	{
		if (this->hour == obj.hour)
		{
			if (this->min == obj.min)
			{
				if (this->sec == obj.sec)
					return true;
				else
					return false;
			}
			else return false;
		}
		else return false;
	}

	bool operator !=(Timee obj)
	{
		if (this->hour == obj.hour)
		{
			if (this->min == obj.min)
			{
				if (this->sec == obj.sec)
					return false;
				else
					return true;
			}
			else return true;
		}
		else return true;
	}

	int ToSec()
	{
		return (hour * 3600 + min * 60 + sec);
	}

	int ToMin()
	{
		return (hour * 60 + min);
	}
};

int main()
{
	char str[80]; int a; int hour, min, sec;
	cout << "Enter Time in Hour:Min:Sec format: ";
	cin >> str;
	Timee ob(str);
	ob.ShowTime();


	cout << "\nEnter Time in Sec format: ";
	cin >> a;
	Timee ob1(a);
	ob1.ShowTime();


	cout << "\nEnter Time in Hour Min Sec format: \n";
	cin >> hour >> min >> sec;
	Timee ob2(hour, min, sec);
	ob2.ShowTime();

  cout << '\n';

  cout << "Sum of first and second" <<endl;
	ob + ob1;
	ob.ShowTime();

  cout << '\n';

  cout << "Sum + 60 seconds" <<endl;
	ob + 60;
	ob.ShowTime();

  cout << '\n';

	cout << "Sum - 120 seconds" <<endl;
	ob - 120;
	ob.ShowTime();

  cout << '\n';

	if(ob==ob2)
	cout<<"ob==ob2 \n";
	if(ob!=ob1)
	cout<<"ob!=ob1 \n";
	cout << "Converting sum to minutes \n" << ob.ToMin() << endl << "Converting sum to seconds\n" << ob.ToSec() << endl;
	system("pause");

  return 0;
}
