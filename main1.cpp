#include "Swap.h"
#include "Point.h"
#include "MyString.h"
#include "MyStack.h"
#include "Q.h"

#include <algorithm>

#include <boost/container/vector.hpp>
#include <vector>

using namespace std;


template<typename T>
ostream &operator<<(ostream &output, const vector<T> &v)
{
	output << "\n\nVector:\n\tsize: " << v.size() << "\n\tcap: " << v.capacity() << "\n\tmax size: " << v.max_size();

	output << "\nElements: \n";
	size_t   elNum = 0;
	for(auto elm : v)
	{
		output << ++elNum << ". " << elm << "\n";
	}

	return output;
}

int main(int argc, char *argv[])
{

	//It's time for boost!
	boost::container::vector<int> bVec;
	bVec.push_back(11);
	cout << "bVec[0] = " <<bVec[0] <<endl;


	//<editor-fold desc="Swap">
	int iX = 1, iY = -1;
	Swap(iX, iY);

	double dX = 0.5, dY = -5.5;
	Swap(dX, dY);

	Point<int> pt1(1, 2);
	Point<int> pt2(-3, -4);
    //1

	Swap(pt1, pt2);

	MyString str1("One"), str2("Two");
	Swap(str1, str2);
	//</editor-fold>

    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << str1 << endl;

	MyStack<MyString, 3> iStack;

	try
	{
		iStack.Push(str1);
		iStack.Push(move(str2));
	}
	catch(out_of_range &e)
	{
		cerr << "Out of range Push(): " << e.what() << "\n";
	}

	try
	{
		auto i = iStack[1];
		i = iStack[2];
	}
	catch(out_of_range &e)
	{
		cerr << "Out of range []: " << e.what() << "\n";
	}

	cout << iStack;

	//<editor-fold desc="MyQ">
	MyQ<int> qt(3);

	try
	{
		for(auto i = 0; i < 3; i++)
			qt.Push(i);
	}
	catch(out_of_range &e)
	{
		cerr << "Out of range: " << e.what() << "\n";
	}

	cout << qt;

	try
	{
		int res;

		for(auto i = 0; i < 3; i++)
			res = qt.Pop();
	}
	catch(out_of_range &e)
	{
		cerr << "Out of range: " << e.what() << "\n";
	}

	cout << qt;

	for(auto i = 0; i < 2; i++)
		qt.Push(10*i + i);

	int              ar[] = {1, 3, 5};
	vector<int> v(begin(ar), end(ar));

	qt.Push(move(v[1]));

	cout << qt;

	for(auto i = 0; i < 2; i++)
		qt.Pop();

	cout << qt;

	for(auto i = 6; i < 8; i++)
		qt.Push(10*i + i);

	cout << qt;

	qt.Push(777);

	cout << qt;
	//</editor-fold>

	return 0;
}
