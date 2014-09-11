#include <stddef.h>

template <typename T>
class MyVector
{
public:

	class iterator
	{
	public:
		iterator();
		~iterator();

	private:
		T* p;
	};

	iterator::iterator()
	{
	}

	iterator::~iterator()
	{
	}


	MyVector(): m_n(0), m_cap(0), m_p(nullptr){}
	
	MyVector(size_t n): m_n(0), m_cap(n), m_p(nullptr)
	{
		m_p = new T[m_cap];

		for (size_t i = 0; i < m_cap; i++)
		{
			m_p[i] = T();
		}
	}

	//template <typename T>
	MyVector(size_t n,const T& t): m_n(n), m_cap(n), m_p(nullptr)
	{
		m_p = new T[m_cap];

		for (size_t i = 0; i < m_cap; i++)
		{
			m_p[i] = t;
		}
	}

    MyVector(size_t m_n, T* m_p) : m_n(m_n), m_p(m_p) {
    }

    ~MyVector();

	T& front() 
	{ 
		if(m_n) return m_p[0];
		//throw std::lengtherr ("Reached stak element cap");
		throw std::out_of_range("Reached stak element cap");
	}
	T& back() { return m_p[m_n-1];}
	
	template<typename A> void push_back(A&& a)
	{
		if (m_n == m_cap)
		{
			m_cap *=1.5;

			T* p = new T[m_cap];

			for (int i = 0; i < m_n; i++)
			{
				p[i] = std::move(m_p[i]);
			}

			delete []m_p;

			m_p = p;
		}

		m_p[m_n] = a;
	}
private:
	T* m_p;
	size_t m_n;
	size_t m_cap;
};


MyVector::~MyVector()
{
}