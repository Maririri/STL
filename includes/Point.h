#include <iostream>

template<typename T>
class Point
{
	T m_x;
	T m_y;
public:


    Point(T m_x) : m_x(m_x) {
    }

    Point(const T &x, const T &y)
			: m_x(x)
			  , m_y(y) {};

    Point() {
    }

    T GetX() const {return m_x;}

	void SetX(T m_x) { Point::m_x = m_x; }

	T GetY() const { return m_y; }

	void SetY(T m_y) { Point::m_y = m_y; }

	T &operator=(T &&other);

	bool operator<(const Point<T> &p) const {return m_x < p.m_x /*|| m_y < p.m_y*/;}

	bool operator==(const Point<T> &p) {return m_x == p.m_x || m_y == p.m_y;}

	bool operator==(Point<T> &p) {return m_x == p.m_x || m_y == m_y;}

	struct is_negativ
	{
		bool operator()(const Point<T> &p) {return p.m_x < 0 || p.m_y < 0;}
	};

	friend std::ostream &operator<<(std::ostream &output, const Point<T> &p)
	{
		output << ". x - " << p.m_x << ". y - " << p.m_y << "\n";

		return output;
	}

	/*friend bool operator==(Point<T>& p1, Point<T>& p2)
	{
		return p1.m_x == p2.m_x || p1.m_y == p2.m_y;
	}*/
};


template<typename T>
T &Point<T>::operator=(T &&other)
{
	if(this != &other)
	{


		m_x = other.m_x;
		m_y = other.m_y;
	}

	return *this;
}
/*public:
	Point():m_x(T()), m_y(T()){};
	Point(const T& x, const T& y):m_x(x), m_y(y){};

	Point()

	T& operator=(const T& other);
	T& operator=(T&& other);

private:*/