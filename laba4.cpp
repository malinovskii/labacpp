#include <iostream>
#include <cmath>
using namespace std;

class Triangle {
	private:
		float angle1, angle2, angle3, side1, side2, side3;
	public:
		// Ввод сторон треугольника
		void set_sides()
		{
			cin >> side1 >> side2 >> side3;
		}

		// Ввод углов треугольника
		void set_angles()
		{
			cin >> angle1 >> angle2 >> angle3;
		}

		// Вычисление площади
		float square (void)
		{
        float square, p;
		    p = (side1+side2+side3) / 2;
		    square = sqrt(p*(p-side1)*(p-side2)*(p-side3));
		    if (square = 0) cout << "Triangle doesn't exist" << endl;
		    cout << "square = " << square << endl;

		}
		// Вычисление периметра
		float perimeter (void)
		{
        float perimeter;
		    perimeter = side1 + side2 + side3;
		    cout << "perimeter = " << perimeter << endl;
		}
		// Вычисление высот
		void height (void)
		{
      float h1, h2, h3, p;
		  p = (side1+side2+side3) / 2;
		  h1 = sqrt(4*p*((p-side1)*(p-side2)*(p-side3))/(side1*side1));
      h2 = sqrt(4*p*((p-side1)*(p-side2)*(p-side3))/(side2*side2));
      h3 = sqrt(4*p*((p-side1)*(p-side2)*(p-side3))/(side3*side3));
      cout << "h1= " << h1 << endl << "h2= "<< h2 << endl << "h3= " << h3 <<endl;
		}
		// Определение вида треугольника
		void kind_of_triangle (void)
		{
      if (side1 == side2 && side2 == side3){
        cout << "Equilateral triangle" << endl; // Равносторонний треугольнинк
      }
      else{
         if ((side1 == side2) || (side2 == side3) || (side3 == side1)){
              cout << "Isosceles triangle"<< endl; // Равнобедренный треугольник
         }
         else
         {
           if ((angle1 == 90) || (angle2 == 90) || (angle3 == 90)){
             cout << "Right triangle"<< endl; // Прямоугольный треугольник
           }

         }
	    }
	   }

};

int main()
{
	Triangle T; // Создаем экземпляр класса Triangle
	cout <<"Enter sides of triangle"<<endl;
	T.set_sides();
	cout << "Enter angles of triangle"<<endl;
  T.set_angles();
	T.square(); // Вывод площади
	T.perimeter(); // Вывод периметра
	T.height(); // Вывод всех высот
	T.kind_of_triangle(); // Вывод типа треугольника
	return 0;
}
