#include <iostream>

#include <cstdlib>

#include <ctime>

typedef double ETYPE;

using namespace std;

//Объекты типа elem можно упорядочить с помощью указателя next.
struct elem {

  ETYPE data; //Назовем data информационным элементом. У нас он типа int, но
              //может быть любогонеобходимого нам типа.

  elem* next; //Указатель next указывает на объект типа elem.

  elem (ETYPE e, elem* n) {

    data = e;
    next = n;

  }

};

class list {

  elem* h;

  elem* l;

public:

  list(){
    h = NULL;
    l = NULL;
  }

  void push_front(ETYPE e) { //Функция заполнения списка (с 0 элемента)

    if (h == NULL) {
      l = new elem(e, NULL);
      h = l;
    } else {
      h = new elem(e, h);
    }

  }

  void push_back(ETYPE e) { //Функция заполнения списка (с последнего элемента)

    if (h == NULL) {

      h = new elem(e, h); l = h;

    } else {

      l->next = new elem(e, NULL);

      l = l->next;

    }

  }

  void push(elem* e, ETYPE sum) { //Функция добавления элемента на определенное n место

    elem* el;

    el = new elem(sum, e->next);

    e->next = el;

  }

  friend class iter;

};

class iter { //Инициализация дружественного класса

  elem* current;

public:

  iter(list& l) {

    current = l.h;

  }

  elem* operator++();

};

elem* iter::operator++() { //Основная функция дружественного класса, которая позволит

  if (current) {             //нам «пробежаться» по всем элементам списка

    elem* tmp = current;

    current = current->next;

    return tmp;

  }

  return NULL;

}

int main() {


  list ls;

  cout << "Enter amount of elements." << endl;

  int n;

  cin >> n;

  srand(time(0));

  for (int i = 0; i < n; i++) { //Заполнение списка случайными числами

    ls.push_back(rand() % 99);

  }

  iter it(ls);

  elem* p;

  cout << "List from " << n << " random integers: " << endl;

  while ((p = ++it) != NULL) { //Выводим список через iter
    cout << p->data << ' ';
  }

  cout << endl;

  it = ls;

  while ((p = ++it) != NULL) { //Изменяем список по условию через iter

  if (p->next == NULL) ls.push_back(p->data); else

    if (int(p->data) % 2 == 1) {

      ls.push(p, (p->data + p->next->data) / 2);

    }

  }

  it = ls;

  cout << "Changed list:" << endl;

  while ((p = ++it) != NULL) {

  cout << p->data << ' ';

  }

  cout << endl;

  system("pause");

}
