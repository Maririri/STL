// Контейнеры STL: 
//stack, queue, priority_queue
//set, multiset, map, multimap

//#include "stdafx.h"
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <clocale>

#include <functional>   // greater

#include "Point.h"

#include <iostream>
#include <Header4.h>

using namespace std;

#define stop __asm nop

template<typename T>
struct is_Q_or_Stack
{
	static const bool value = false;
};

template<typename T, typename Alloc>
struct is_Q_or_Stack<stack<T, Alloc>>
{
	static const bool value = true;
};

template<typename T, typename Alloc>
struct is_Q_or_Stack<queue<T, Alloc>>
{
	static const bool value = true;
};


template<typename T, typename Alloc>
struct is_Q_or_Stack<priority_queue<T, Alloc>>
{
	static const bool value = true;
};


/*template<typename T> 
  struct is_container : integral_constant<bool, has_const_iterator<T>::value && has_begin_end<T>::beg_value && has_begin_end<T>::end_value> 
  { };*/

template<typename V/*, typename C*/>
const V &getEl(queue<V/*,C*/> &t)
{
	return t.front();
}

template<typename T>
const typename T::value_type &getEl(T &t)
{
	return t.top();
}

template<typename T>
ostream &printThis(ostream &output, T &t)
{
	size_t elNum = 0;

	while(!t.empty())
	{
		output << getEl(t) << "\n";
		t.pop();
	}

	return output;
}




template<typename T>
ostream &operator<<(ostream &output, stack<T> t)
{
	return printThis<stack<T>>(output, t);
}

template<typename T>
ostream &operator<<(ostream &output, queue<T> t)
{
	return printThis<queue<T>>(output, t);
}

template<typename T>
ostream &operator<<(ostream &output, priority_queue<T> t)
{
	return printThis<priority_queue<T>>(output, t);
}

template<typename T, typename C, typename P>
ostream &operator<<(ostream &output, priority_queue<T, C, P> t)
{
	return printThis<priority_queue<T, C, P>>(output, t);
}

//template<typename T>
//ostream &printSet(ostream &output, const T &t)
//{
//	output << "\n\nThis is a set:\n";
//	for(auto elm : t)
//	{
//		output << elm << "\n";
//	}
//
//	return output;
//}


//template<typename T, typename C>
//ostream &operator<<(ostream &output, const set<T, C> &t)
//{
//	ostream &output1 = output;
//	output1 << "\n\nThis is a set:\n";
//	for(auto& elm : t)
//	{
//		output1 << elm << "\n";
//	}
//
//	return output1;
//}


template<typename T, typename C>
ostream &operator<<(ostream &output, const map<T, C> &t)
{
	output << "\n\nThis is a map:\n";
	for(auto elm : t)
	{
		output << "\n\t" << elm.first << " - " << elm.second;
	}

	return output;
}


template<typename T, typename C>
ostream &operator<<(ostream &output, const multimap<T, C> &t)
{
	output << "\n\nThis is a multimap:\n";

	for(auto elm : t)
	{
		output << "\n\t" << elm.first << " - " << elm.second;
	}

	return output;
}


ostream &operator<<(ostream &output, const char **str)
{
	output << *str;
	return output;
}

//template<typename T>
//ostream &operator<<(ostream &output, const vector<T> &v)
//{
//	output << "\n\nVector:\n\tsize: " << v.size() << "\n\tcap: " << v.capacity() << "\n\tmax size: " << v.max_size();
//
//	output << "\nElements: \n";
//	size_t   elNum = 0;
//	for(auto elm : v)
//	{
//		output << ++elNum << ". " << elm << "\n";
//	}
//
//	return output;
//}

template<typename T>
ostream &operator<<(ostream &output, const Point<T> *t)
{
	output << "\nPoint - \n\tx - " << t->GetX() << "\n\ty - " << t->GetY();

	return output;
}

template<typename T>
bool operator>(queue<T> t, /*typedef*/queue<T> t2)
{
	return t.size > t2.size;
}

class lingv
{
public:
	bool operator()(const char **str1, const char **str2)
	{
		const char *s1 = *str1;
		const char *s2 = *str2;

		while(*s1 != '\0' || s2 != '\0')
		{
			if(toupper(*s1) != toupper(*s2))
			{
				return toupper(*s1) > toupper(*s2) ? true : false;
			}

			s1++;
			s2++;
		}

		return false;
	}
};

class lingv2
{
public:
	bool operator()(const char **str1, const char **str2)
	{
		const char *s1 = *str1;
		const char *s2 = *str2;

		while(*s1 != '\0' || s2 != '\0')
		{
			if(toupper(*s1) != toupper(*s2))
			{
				return toupper(*s1) > toupper(*s2) ? true : false;
			}

			s1++;
			s2++;
		}

		return false;
	}
};

//blablabla
struct cmp
{
	bool operator()(const int &lhs, const int &rhs) const {return lhs > rhs;}
};


int main(int argc, char *argv[])
{
	setlocale(LC_CTYPE, "Russian");

	stack<int> s1;
	priority_queue<int> pq1;
	queue<int> q1;
	
	for(int i = 0; i<2; i++)
	{
		s1.push(11*i);
		pq1.push(100 + 11*i);
		q1.push(200 + 11*i);
	}

	cout << s1;
	cout << pq1;
	cout << q1;


	////////////////////////////////////////////////////////////////////////////////////
	//stack

	//Создайте стек таким образом, чтобы
	//а) элементы стека стали копиями элементов вектора
	//б) при выводе значений как вектора, так и стека порядок значений был одинаковым 

	//vector<int> v2(5, 33);

	int                          v2[] = {4, 3, 2, 5};
	vector<int>                  v3(begin(v2), end(v2));
	stack<int, vector<int>> s2(vector<int>(v3.rbegin(), v3.rend()));

	//Сравнение и копирование стеков
	//а) создайте стек и любым способом задайте значения элементов
	//б) создайте новый стек таким образом, чтобы он стал копией первого
	//в) сравните стеки на равенство
	//г) модифицируйте любой из стеком любым образом (push, pop, top)
	//д) проверьте, какой из стеков больше (подумайте, какой смысл вкладывается в такое сравнение)

	stack<int> s3, s4;
	for(int i = 0; i<2; i++)
	{
		s3.push(101 * i);
	}
	
	s4 = s3;

	cout << "\ns4 \n" << s4;
	cout << "\ns3\n" << s3;

	s3.push(77);

	cout << "\ns4 \n" << s4;
	cout << "\ns3\n" << s3;

	if(s4 > s3)
	{
		cout << "\ns4 is biger";
	}
	else
	{
		cout << "\ns3 is biger";
	}

	////////////////////////////////////////////////////////////////////////////////////
	//queue

	//Создайте очередь, которая содержит указатели на объекты типа Point,
	//при этом явно задайте базовый контейнер.
	//Измените значения первого и последнего элементов посредством front() и back()
	//Подумайте, что требуется сделать при уничтожении такой очереди?
	{
		queue<Point<int> *> my_q2;

		for(int i = 1; i<4; i++)
			my_q2.push(new Point<int>(1, i));

		cout << "\n\n\nQ before:\n" << my_q2;

		*my_q2.front() = Point<int>(6, 7);
		*my_q2.back()  = Point<int>(0, 9);

		cout << "\n\n\nQ after:\n" << my_q2;

		while(!my_q2.empty())
		{
			delete my_q2.front();
			my_q2.pop();
		}

	}
	////////////////////////////////////////////////////////////////////////////////////
	//priority_queue
	//а) создайте очередь с приоритетами, которая будет хранить адреса строковых литералов - const char*
	//б) проинициализируйте очередь при создании с помощью вспомогательного массива с элементами const char*
	//в) проверьте "упорядоченность" значений (с помощью pop() ) - если они оказываются не упорядоченными, подумайте:
	//		что сравнивается при вставке?


	{

		const char *c1 = "AbcAbcd";
		const char *c4 = "AbcAbce";
		const char *c3 = "Cde";
		const char *c2 = "Def";

		const char **initAr[] = {&c4, &c3, &c2, &c1};
		priority_queue<const char **> pq2(begin(initAr), end(initAr));
		cout << pq2;

		priority_queue<const char **, vector<const char **>, lingv> pq3(begin(initAr), end(initAr));
		cout << pq3;
	}


	////////////////////////////////////////////////////////////////////////////////////
	//set
	//a) создайте множество с элементами типа Point - подумайте, что необходимо определить
	//		в классе Point (и каким образом)
	//б) распечатайте значения элементов с помощью шаблона, реализованного в предыдущей лаб. работе
	//в) попробуйте изменить любое значение...
	//г) Создайте два множества, которые будут содержать одинаковые значения
	//		типа int, но занесенные в разном порядке
	//д) Вставьте в любое множество диапазон элементов из любого другого
	//	контейнера, например, элементов массива	(что происходит, если в массиве имеются дубли?)

	vector<Point<int>> vpPoint(4);

	for(int i = 0; i<5; i++)
		vpPoint[i] = Point<int>(1.1*i, 5*i);

	set<Point<int>> setP(vpPoint.begin(), vpPoint.end());
	cout << setP;

	int                ar[] = {11, 2, 4, 3, 5};
	set<int>      set1(begin(ar), end(ar));
	set<int, cmp> set2(begin(ar), end(ar));

	cout << set1;
	cout << set2;

	int ar2[] = {33, 33, 33, 4, 22, 22, 44, 44};
	set1.insert(begin(ar2), end(ar2));
	cout << set1;

	////////////////////////////////////////////////////////////////////////////////////
	//map	
	//а) создайте map, который хранит пары "фамилия, зарплата" - pair<const char*, int>,
	//	при этом строки задаются строковыми литералами
	//б) заполните контейнер значениями посредством operator[] и insert()
	//в) распечатайте содержимое

	//г) замените один из КЛЮЧЕЙ на новый (была "Иванова", вышла замуж => стала "Петрова")

	map<const char *, int> zpMap;

	zpMap["Ivanov"] = 20000;
	zpMap["Petrov"] = 21000;
	zpMap.insert(pair<const char *, int>("Sidorov", 25000));
	zpMap.insert(pair<const char *, int>("Sidorova", 26000));

	cout << zpMap;

	auto it = zpMap.find("Sidorova");
	int  zp = it->second;
	zpMap.erase(it);
	zpMap["Petrova"] = zp;

	cout << zpMap;

	//д) Сформируйте любым способом вектор с элементами типа string.
	//Создайте (и распечатайте для проверки) map<string, int>, который будет
	//содержать упорядоченные по алфавиту строки и
	//количество повторений каждой строки в векторе


	{
		string myStrs[6] = {string("str1bac"), string("str1baz"), string("str1bay"), string("str11"),
				string("str1b"), string("str1b")};

		map<string, int> strMap;

		for(int i = 0; i < 6; i++)
		{
			strMap[myStrs[i]]++;
		}

		cout << strMap;
	}


	////////////////////////////////////////////////////////////////////////////////////
	//multimap
	//а) создайте "англо-русский" словарь, где одному и тому же ключу будут соответствовать
	//		несколько русских значений - pair<string,string>, например: strange: чужой, странный...
	//б) Заполните словарь парами с помощью метода insert или проинициализируйте с помощью 
	//		вспомогательного массива пара (пары можно конструировать или создавать с помощью шаблона make_pair)
	//в) Выведите все содержимое словаря на экран
	//г) Выведите на экран только варианты "переводов" для заданного ключа. Подсказка: для нахождения диапазона
	//		итераторов можно использовать методы lower_bound() и upper_bound()

	{
		typedef multimap<string, string>::iterator MultimapIter;

		multimap<string, string> lingvo;

		lingvo.insert(pair<string, string>(string("strange"), string("чужой")));
		lingvo.insert(pair<string, string>(string("strange"), string("странный")));
		lingvo.insert(pair<string, string>(string("big"), string("бол")));
		lingvo.insert(pair<string, string>(string("big"), string("огр")));
		lingvo.insert(pair<string, string>(string("small"), string("мал")));
		lingvo.insert(pair<string, string>(string("small"), string("мел")));

		cout << lingvo;

		MultimapIter itlow = lingvo.lower_bound("strange");
		MultimapIter itup  = lingvo.upper_bound("strange");

		cout << "\n\nThis is the defs for 'strang': ";
		for(MultimapIter it = itlow; it != itup; ++it)
		{
			cout << "\n\t " << (*it).second << '\n';
		}
	}


	return 0;
}