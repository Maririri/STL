#include <stdexcept>
#include <iostream>

template <typename T> class MyQ
{
	T* m_pointerToData;
	T* m_pBegin;
	T* m_pEnd;
	size_t m_cap;
	size_t m_numberOfElm;

	void MoveDataPointerAndCheckIfOutOfRang(T*& dataPointer);
	void Realloc();

	void PushData(T&&);
	void PushData(const T&);

public:
	MyQ(size_t);
//	MyQ(const MyQ&);

	~MyQ(){ delete[] m_pointerToData;}

	void Push(T); 

	const T Pop();

	friend std::ostream& operator<< (std::ostream& output, MyQ<T>& q)
	{
		if(q.m_numberOfElm)
		{
			T* p = q.m_pBegin;

			output << "\n\n\nHere are the elements:";

			for (size_t i = 0; i < q.m_numberOfElm; i++)
			{
				output << "\n\t" << *p ;

				q.MoveDataPointerAndCheckIfOutOfRang(p);

			}
		}

		return output;
	}
};


template <typename T>
MyQ<T>::MyQ(size_t cap): m_numberOfElm(0), m_cap(cap)
{
	m_pBegin = m_pEnd = m_pointerToData = new T[m_cap];
}

//template <typename T>
//MyQ<T>::MyQ(const MyQ& otherQ)
//{
//	delete[] m_pointerToData;
//
//	otherQ
//
//}


/*template <typename T>
void MyQ<T>::PushData(T&& t)
{
	*m_pEnd = t;
}

template <typename T>
void MyQ<T>::PushData(const T& t)
{
	*m_pEnd = std::forward<T>(t);
}*/



template <typename T>
void MyQ<T>::Push(T t)
{
	if (m_numberOfElm >= m_cap)
	{
		Realloc();
	}

	*m_pEnd = std::forward<T>(t);//PushData(t);

	MoveDataPointerAndCheckIfOutOfRang(m_pEnd);

	m_numberOfElm++;

	/*Debug output*/
	std::cout<< "\nm_pointerToData -" << m_pointerToData << " m_pBegin - " << m_pBegin << " m_pEnd - " << m_pEnd;
}

template <typename T>
void MyQ<T>::Realloc()
{
	size_t newSize = m_cap*1.5;
	T* newDataLoc = new T[newSize];
	
	size_t i;
	for ( i = 0; i < m_cap; i++)
	{
		newDataLoc[i] = *m_pBegin;

		MoveDataPointerAndCheckIfOutOfRang(m_pBegin);
	}

	delete[] m_pointerToData;
	m_pointerToData = m_pBegin = newDataLoc;
	m_pEnd = &newDataLoc[i];
	m_cap = newSize;

}

template <typename T>
const T MyQ<T>::Pop()
{
	if (m_numberOfElm)
	{
		T* res = m_pBegin;

		MoveDataPointerAndCheckIfOutOfRang(m_pBegin);

		m_numberOfElm--;
		if (m_numberOfElm == 0)
		{
			m_pBegin = m_pEnd = m_pointerToData;
		}

		std::cout<< "\nm_pointerToData -" << m_pointerToData << " m_pBegin - " << m_pBegin << " m_pEnd - " << m_pEnd;
		return *res;
	}

	throw std::out_of_range("The Q is empty");
}

template <typename T> 
void MyQ<T>::MoveDataPointerAndCheckIfOutOfRang(T*& dataPointer)
{
	dataPointer++;

	if (dataPointer >=(m_pointerToData + m_cap))
	{
		dataPointer = m_pointerToData;
	}
}


// copy conster
// operator=
/*
template <typename T>
std::ostream& operator<< (std::ostream& output, const MyQ<T>& q)
{
	T* p = m_pBegin;

	for (size_t i = 0; i < m_cap; i++)
	{
		output << (p++) << "\n";

		if (p >(m_pointerToData + m_cap))
		{
			p = m_pointerToData;
		}
	}
}*/