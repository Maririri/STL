//Стандартная библиотека шаблонов - STL 
//Контейнеры стандартной библиотеки - vector
//Итераторы

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <MyString.h>
//#include <Header4.h>
#include "Point.h"

void foo(int a) {
    printf("a - %d", a);}

#define MACRO foo(5);

#define      stop __asm nop
#pragma warning(disable: 4786)

using namespace std;

typedef vector<char>::iterator CharVectorIter;

template<typename U>
ostream &operator<<(ostream &output, const vector<U> &v)
{
	output << "\n\nVector:\n\tsize: " << v.size() << "\n\tcap: " << v.capacity() << "\n\tmax size: " << v.max_size();

	output << "\nElements: \n";
	size_t   elNum = 0;
	for(auto elm : v)
	{
		output << ++elNum << ". " << elm;

		if(elNum % 5 == 0)
			output << endl;
	}

	return output;
}


    template<typename T>
    ostream &operator<<(ostream &output, const vector<Point<T> *> &v)
    {
	output << "\n\nVector:\n\tsize: " << v.size() << "\n\tcap: " << v.capacity() << "\n\tmax size: " << v.max_size();

	output << "\nElements: \n";
	size_t   elNum = 0;
	for(auto elm : v)
	{
		if(elm)
		{
			output << ++elNum << ". x - " << elm->GetX() << ". y - " << elm->GetY() << "\n";
		}
	}

	return output;
}

//template<typename T>
//ostream &operator<<(ostream& output, const T& c)
//{
//	output << "\n\nVector:\n\tsize: " << c.size() << "\n\tcap: " << c.capacity() << "\n\tmax size: " << c.max_size();
//
//	output << "\nElements: \n";
//	size_t   elNum = 0;
//	for(auto elm : c)
//	{
//		output << ++elNum << ". " << elm << "\n";
//	}
//
//	return output;
//}

int main()
{
	// Контейнер стандартной библиотеки vector 

	//////////////////////////////////////////////////////////////////////
	//Создание векторов. 

	//Создайте следующие вектора:
	//---------------------------
	//пустой вектор целых чисел - vInt и проверьте с помощью функции size(),
	//что его размер нулевой.


	vector<int> v;

	if(!v.size())
	{
		cout << "The vector is empty!";
	}

	v.resize(1);
	v.front() = 1;


	for (int i = 0; i < 9; i++)
	{
		v.push_back(i+33);

		cout << v;
	}

	vector<double> vd(12);
	cout << vd;

	vector<MyString> vS(5,MyString("A"));
	cout << vS;

	vS.at(0) = "B";
	vS[1] = "C";


    try {
        throw 1;
    } catch (int a) {
        cerr << "qqqqqq";
    }

	try
	{
		vS.at(26) = "Z";
	}
	catch (out_of_range& e) {
		cerr << "Out of range: " << e.what() << "\n";
	}
	catch (exception& e) {
		cerr << "Some other exception: " << e.what() << "\n";
	}

	cout << vS;



	double dMas[] = {33, 55, 6, 33, 22, 11};
	size_t dMSize = sizeof(dMas)/sizeof(double);

	vector<double> vD2(begin(dMas), begin(dMas) + 4);
	cout << vD2;

	vector<double> vD3(vD2.begin() + 2, vD2.begin() + 4 );
	cout << vD3;

	//вектор элементов типа Point - vPoint1 а) с начальным размером 3. Какой конструктор
	//будет вызван для каждого элемента?
	//b) vPoint2 с начальным размером 5 и проинициализируйте каждый элемент координатами (1,1).

	int tmp = 0;

	vector<Point<double>> vPoint1(3);
	vector<Point<int>>    vPoint2(5, Point<int>(1, 1));


	//вектор указателей на Point - vpPoint с начальным размером 5
	//Подумайте: как корректно заставить эти указатели "указывать" на объекты Point
	{

		//Подсказка: для вывода на печать значений скорее всего Вам понадобится
		//а) специализация Вашей шаблонной функции
		//б) или перегрузка operator<< для Point*

	}//Какие дополнительные действия нужно предпринять для такого вектора?

	Point<int> p1(3.3, 3.9);
	Point<int> p2(3, 9);

	vector<Point<int> *> vpPoint(5);

	vpPoint[0] = &p1;
	vpPoint[1] = &p2;

	cout << vpPoint;


	///////////////////////////////////////////////////////////////////////
	//Резервирование памяти.
	//Подумайте, всегда ли верны приведенные ниже проверки?

	{
		size_t      n = 200;
		vector<int> v(n);
		v.resize(n / 2);
		cout << v;
		if(v.capacity() == n)
			cout << "true";
		else
		{
			cout << "false";
		}
	}

	{
		size_t      n = 5;
		size_t      m = 20;
		vector<int> v(n);
		v.reserve(m);
		cout << v;
		if(v.capacity() == m)
			cout << "true";
		else
		{
			cout << "false";
		}
	}

	//Создайте два "пустых" вектора с элементами
	//любого (но одного и того же типа) типа. 
	//В первом векторе зарезервируйте память под 5 элементов, а потом заполните
	//его значениями с помощью push_back.
	//Второй вектор просто заполните значениями посредством push_back.
	//
	//Сравните размер, емкость векторов и значения элементов

	{
		vector<int> v(5);
		vector<int> v2;

		for(int i = 0; i < 5; i++)
		{
			v.push_back(i);
			v2.push_back(i);
		}

		cout << v;
		cout << v2;
	}

	//!!! shrink_to_fit - Уменьшение емкости вектора.
	//Для любого вектора из предыдущего задания требуется уменьшить емкость
	//до size.

	{
		vector<int> v(3);

		for(int i = 0; i < 3; i++)
			v.push_back(i);

		cout << v;

		v.shrink_to_fit();
		cout << v;
	}

	//Создание "двухмерного вектора" - вектора векторов
	//Задан одномерный массив int ar[] = {11,2,4,3,5};
	//Создайте вектор векторов следующим образом:
	//вектор vv[0] - содержит 11 элементов со значением 11
	//vv[1] - содержит 2,2
	//vv[2] - содержит 4,4,4,4
	//...
	//Распечатайте содержимое такого двухмерного вектора по строкам
	{
		int 	ar[]   = {11, 2, 4, 3, 5};
		size_t 	sizeAr = sizeof(ar) / sizeof(int);
		vector<vector<int>> vv(sizeAr);

		for(int i = 0; i < sizeAr; i++)
		{
			vv[i] = vector<int>(ar[i], ar[i]);
		}

		cout << vv;
	}

	vector<char> vChar2(5, 'a');
	char tmpC = 'z';

	for (int i = 0; i < 3; i++)
	{
		
		//cin >> tmpC;

		//auto res = ;

		if (find(vChar2.begin(), vChar2.end(), tmpC) != vChar2.end())
		{
			vChar2.insert(vChar2.begin(), tmpC);
		}
	}



	cout << vChar2;

		//Вставьте перед каждым элементом вектора vChar2 букву 'W'
	vector<char>::iterator i = vChar2.begin();
	vector<char>::iterator e = vChar2.end();
	for (; i != e; ++i)
	{
		i = vChar2.insert(i, 'W');
		++i;
		e = vChar2.end();
	}

	cout << vChar2;
	///////////////////////////////////////////////////////////////////
	//Напишите функцию, которая должна удалять только повторяющиеся последовательности.
	//Например: было - "qwerrrrty122223", стало - "qwety13"

	char              chAr[] = "qwerrrrty122223";
	vector<char> vChar3(begin(chAr), end(chAr) - 1);

	cout << vChar3;

	CharVectorIter vChar3Begin = vChar3.begin();
	CharVectorIter vChar3End = vChar3.end();

	char p = '\0';
	for(; vChar3Begin != vChar3End;)
	{
		if(*vChar3Begin == p)
		{
			vChar3Begin = vChar3.erase(vChar3Begin);
			//++i;
			vChar3End = vChar3.end();
		}
		else
		{
			p = *vChar3Begin;
			++vChar3Begin;
		}
	}


///////////////////////////////////////////////////////////////////

//Удаление элемента последовательности erase()
//Напишите функцию удаления из любого вектора всех дублей 


// change char to typename T and enclose all of that in a function


///////////////////////////////////////////////////////////////////
//Создайте новый вектор таким образом, чтобы его элементы стали
//копиями элементов любого из созданных ранее векторов, но расположены
//были бы в обратном порядке

	vector<char> va(vChar3.rbegin(), vChar3.rend());

	cout << va;

///////////////////////////////////////////////////////////////////
//Создайте вектор с элементами string. Заполните его значениями
//любым способом.
//"Разбейте" созданный вектор на отдельные вектора, в которых будут "собраны"
//строки, начинающиеся с одной и той же буквы.
//Например: "Abba" "Alfa" "Beta" "Beauty" ...
//1. "Abba" "Alfa"
//2. "Beta" "Beauty" ...
//...
//при этом исходный вектор должен стать пустым
	{
		string strs[] = {string("Abba"), string("Alfa"), string("Beta"),
				string("Beauty")};
		vector<string> strStart(begin(strs), end(strs));

		typedef vector<vector<string>> myStrVec;

		myStrVec strAr;

		char p = '\0';
		bool found;

		for(int i = 0; i < strStart.size(); i++)
		{
			p = strStart[i][0];

			found = false;
			for(int j = 0; j < strAr.size(); j++)
			{
				if(strAr[j][0][0] == p)
				{
					strAr[j].push_back(move(strStart[i]));
					found = 1;
					break;
				}
			}

			if(!found)
			{
				vector<string> tmp;
				tmp.push_back(move(strStart[i]));
				strAr.push_back(move(tmp));
			}

		}

	}



///////////////////////////////////////////////////////////////////

//Задание 1. Списки. Операции, характерные для списков.
//Создайте пустой список из элементов Point - ptList1 и наполните
//его значениями с помощью методов push_back(),
//push_front, insert()

	list<Point<int>> lp;
	lp.push_back(Point<int>(1, 1));
	lp.push_front(Point<int>(2, 2));
	lp.insert(lp.begin()++, Point<int>(1, 1));

//Напишите шаблон функции, которая будет выводить элементы
//ЛЮБОГО КОНТЕЙНЕРА на печать. Проверьте работу шаблона на контейнерах
//vector и list. Подсказка - хотелось бы увидеть тип контейнера.


//Сделайте любой из списков "реверсивным" - reverse()


//Создайте список ptList2 из элементов Point таким образом, чтобы он стал 
//копией вектора элементов типа Point, но значения элементов списка располагались
//бы в обратном порядке 



//Отсортируйте списки  ptList1 и ptList2 - методом класса list - sort()
//по возрастанию.
//Подумайте: что должно быть перегружено в классе Point для того, чтобы
//работала сортировка




//Объедините отсортированные списки - merge(). Посмотрите: что
//при этом происходит с каждым списком.


//Исключение элемента из списка - remove()
//Исключите из списка элемент с определенным значением.
//Подумайте: что должно быть перегружено в классе Point?


//Исключение элемента из списка, удовлетворяющего заданному условию:
//любая из координат отрицательна - remove_if(). 


//Исключение из списка подряд расположенных дублей - unique(). 



///////////////////////////////////////////////////////////////////
//Задание 2.Очередь с двумя концами - контейнер deque

//Создайте пустой deque с элементами типа Point. С помощью
//assign заполните deque копиями элементов вектора. С помощью
//разработанного Вами в предыдущем задании универсального шаблона
//выведите значения элементов на печать



//Создайте deque с элементами типа MyString. Заполните его значениями
//с помощью push_back(), push_front(), insert()
//С помощью erase удалите из deque все элементы, в которых строчки
//начинаются с 'A' или 'a'

    cout << "END OF PROGRAMM" << endl;


	getchar();

	return 0;
}