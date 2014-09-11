// Iter_Alg.cpp : Defines the entry point for the console application.
//
//Итераторы. Стандартные алгоритмы. Предикаты.

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>
//#include <string>

#include "Point.h"
#include "Header4.h"

using namespace std;
#define      stop __asm nop


int main(int argc, char *argv[])
{

///////////////////////////////////////////////////////////////////

	//Задание 1. Итераторы

	//Реверсивные итераторы. Сформируйте set<Point>. Подумайте, что
	//нужно перегрузить в классе Point. Создайте вектор, элементы которого 
	//являются копиями элементов set, но упорядочены по убыванию

	Point<int>              p1(3.3, 3.9);
	Point<int>              p2(17, 9);
	Point<int>              p3(15, -4);
	Point<int>              p4(8, -7);
	vector<Point<int>> vpPoint(4);

	vpPoint[0] = p1;
	vpPoint[1] = p2;
	vpPoint[2] = p3;
	vpPoint[3] = p4;

	set<Point<int>> setP(vpPoint.begin(), vpPoint.end());

	vector<Point<int>> vpPointbw(setP.rbegin(), setP.rend());


	//Потоковые итераторы. С помощью ostream_iterator выведите содержимое
	//vector и set из предыдущего задания на экран.

	ostream_iterator<Point<int>> it(cout, "\n\t * ");
	cout << "\n\nOutputing the set:\n";
	copy(setP.begin(), setP.end(), it);

	cout << "\n\nOutputing the vector:\n";
	copy(vpPointbw.begin(), vpPointbw.end(), it);

	//Итераторы вставки. С помощью возвращаемых функциями:
	//back_inserter()
	//front_inserter()
	//inserter()
	//итераторов вставки добавьте элементы в любой из созданных контейнеров. Подумайте:
	//какие из итераторов вставки можно использовать с каждым контейнером.



	copy(setP.begin(), setP.end(), back_inserter(vpPointbw));

	cout << "\n\nOutputing the vector:\n";
	copy(vpPointbw.begin(), vpPointbw.end(), it);

///////////////////////////////////////////////////////////////////

	//Задание 2. Обобщенные алгоритмы (заголовочный файл <algorithm>). Предикаты.

	// алгоритм for_each() - вызов заданной функции для каждого элемента любой последовательности
	//(массив, vector, list...)
	//С помощью алгоритма for_each в любой последовательности с элементами любого типа
	//распечатайте значения элементов
	//Подсказка : неплохо вызываемую функцию определить как шаблон

	cout << "\n\nfor_each\n";
	for_each(vpPointbw.begin(), vpPointbw.end(), output<Point<int>>);


	//С помощью алгоритма for_each в любой последовательности с элементами типа Point
	//измените "координаты" на указанное значение (такой предикат тоже стоит реализовать
	//как шаблон) и выведите результат с помощью предыдущего предиката

	{
		cout << "\n\nfor_each mod\n";
		for_each(vpPointbw.begin(), vpPointbw.end(), PointChanger<int>(1, 1));
		for_each(vpPointbw.begin(), vpPointbw.end(), output<Point<int>>);
		cout << "\n\nfor_each mod T()\n";
		for_each(vpPointbw.begin(), vpPointbw.end(), PointChanger<int>());
		for_each(vpPointbw.begin(), vpPointbw.end(), output<Point<int>>);
	}

	//С помощью алгоритма find() найдите в любой последовательности элементов Point
	//все итераторы на элемент Point с указанным значением.
	{
		vector<Point<int>> vpPointbw3(setP.rbegin(), setP.rend());

		auto it = vpPointbw3.begin();

		while(it != vpPointbw3.end())
		{
			it = find(it, vpPointbw3.end(), Point<int>(15, -4));
			if(it == vpPointbw3.end())
				break;
			cout << *it;
			it++;
		}
	}

	//С помощью алгоритма sort() отсортируйте любую последовательность элементов Point.
	//По умолчанию алгоритм сортирует последовательность по возрастанию.
	//Что должно быть определено в классе Point?

	vector<Point<int>> vpPointbw2(setP.rbegin(), setP.rend());
	cout << "\n\nSort\n";
	sort(vpPointbw2.begin(), vpPointbw2.end());
	for_each(vpPointbw2.begin(), vpPointbw2.end(), output<Point<int>>);

	//Отсортируйте массив double по убыванию абсолютного значения. Сформируйте критерий сортировки
	//посредством лямбда-функции

	cout << "\n\n double sorter\n";
	double ar[] = {-1.4, -1.4, -7.4, 1.6, 1.4, -1.3, 1.2, 1.9};

	sort(begin(ar), end(ar), [](double a, double b) {return abs(a) > abs(b);});

	for_each(begin(ar), end(ar), output<double>);


	//С помощью алгоритма find_if() найдите в любой последовательности элементов Point
	//итератор на элемент Point, удовлетворяющий условию: координаты x и y лежат в промежутке
	//[-n, +m].

	{

		cout << "\n\nSPointFindIf_er\n";
		vector<Point<int>> vpPointbw3(setP.rbegin(), setP.rend());

		auto it = vpPointbw3.begin();

		while(it != vpPointbw3.end())
		{
			it = find_if(it, vpPointbw3.end(), PointFindIf_er<int>(15, 15));
			if(it == vpPointbw3.end())
				break;
			cout << *it;
			it++;
		}
	}

	//С помощью алгоритма sort() отсортируйте любую последовательность элементов Rect,
	//располагая прямоугольники по удалению центра от начала координат.

	//region sort() for Rect
	cout << "\n\nRect sort\n";
	Rect arR[] = {{11, 15}, {3, 25}, {14, 2}, {3, 17}, {2, 2}};
	for_each(begin(arR), end(arR), output<Rect>);

	sort(begin(arR),
			end(arR),
			[](Rect a, Rect b) {return dist(a) < dist(b);}
	);
	cout << "\n\nRect sorted\n";
	for_each(begin(arR), end(arR), output<Rect>);
	//endregion

	//Напишите функцию, которая с помощью алгоритма transform переводит
	//содержимое объекта string в нижний регистр.
	//Подсказка: класс string - это "почти" контейнер, поэтому для него
	// определены методы begin() и end()

	string str("hello");
	transform(str.begin(), str.end(), str.begin(), static_cast<int (*)(int)>(toupper));
	cout << str;

	//Заполните list объектами string. С помощью алгоритма transform сформируте
	//значения "пустого" set, конвертируя строки в нижний регистр

	list<string> lStr;
	lStr.push_back("HAY");
	lStr.push_back("HOW");
	lStr.push_back("ARE");
	lStr.push_back("YOU");

	set<string>  sStr;
	list<string> lStr2;
	insert_iterator<set<string>> b_it(sStr, sStr.begin());

	transform(lStr.begin(), lStr.end(), b_it, [](string &s) -> string {
		transform(s.begin(), s.end(), s.begin(), static_cast<int (*)(int)>(tolower));
		return s;
	});


	for_each(begin(sStr), end(sStr), output<string>);

	return 0;
}

