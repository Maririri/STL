#include "math.h"
#include <vector>
#include <map>

template <typename T>
std::ostream& printSet(std::ostream& output, const T& t)
{
	output << "\n\nThis is a set:\n";
	for(auto& elm : t)
	{
		output << elm << "\n";
	}

	return output;
}

template <typename T, typename C>
std::ostream& operator<< (std::ostream& output, const std::set<T, C>& t)
{
	return printSet(output, t);
}


template <typename T>
std::ostream& operator<< (std::ostream& output, const std::vector<T>& v)
{
	output<< "\n\nVector:\n\tsize: " << v.size() << "\n\tcap: " << v.capacity() << "\n\tmax size: " << v.max_size();

	output<< "\nElements: \n";
	size_t elNum = 0;
	for(auto& elm : v)
	{
		output<< ++elNum << ". " << elm << "\n";
	}

	return output;
}

template <typename T>
void output(const T& elm)
{
	std::cout << elm << "\n";
}

template <typename T>
class PointChanger
{
	T m_chngX;
	T m_chngY;
public:
	PointChanger(T x = T(), T y = T()) : m_chngX(x), m_chngY(y){}
	 void operator() (Point<T>& p) { p.SetX(m_chngX); p.SetY(m_chngY);}
};



template <typename T>
class PointFindIf_er
{
	T m_n;
	T m_m;
public:
	PointFindIf_er(T n = T(), T m = T()) : m_n(n), m_m(m){}
	 bool operator() (Point<T>& p) { return (p.GetX() >= -m_n)?((p.GetX()<= m_m)?((p.GetY() >= -m_n)?((p.GetY()<= m_m)?1:0):0):0):0;}
};


using namespace std;

struct Rect
{

	int x;
	uint32_t y;
    vector<uint32_t> m_v;
    typedef  map<size_t, std::vector<uint32_t>>   MyMap;
    typedef const MyMap MyConstMap;
    MyMap myMap;


    typedef const unsigned int* myT;

    vector<myT> m_vp;

    MyConstMap myCMap;

    myT pT;





};



std::ostream& operator<< (std::ostream& output,const Rect& r)
{
		output << " x - " << r.x << "; y - " << r.y << ";\n";

		return output;
}

double dist(Rect r)
{
	return sqrt(pow(r.x, 2) + pow(r.y, 2));
}