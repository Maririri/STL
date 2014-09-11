#include <stdexcept>

template <typename T, size_t size> class MyStack
{
	T* m_data;
	size_t m_topOfStack;
	size_t m_size;

public:
	MyStack();


	~MyStack(){ delete[] m_data;}

	void Push(const T&);
	void Push(T&&);
	const T Pop();

	const T& operator[](size_t);

	friend std::ostream& operator<<(std::ostream& output, const MyStack<T, size>& ms)
	{
		T* p = ms.m_data;

		for (size_t i = 0; i < ms.m_topOfStack; i++)
		{
			output << (*p++) << "\n";
		}

		return output;
	}	

};

template <typename T, size_t size>
MyStack<T, size>::MyStack() : m_data(nullptr), m_topOfStack(0)
{
	m_size = size;
	m_data = new T[m_size];
}

 
template <typename T, size_t size>
void MyStack<T, size>::Push(const T& t)
{
	if (m_topOfStack != m_size)
	{
		m_data[m_topOfStack++] = t;
		return;
	}

	throw std::out_of_range("Reached stak element cap");
}

template <typename T, size_t size>
void MyStack<T, size>::Push(T&& t)
{
	if (m_topOfStack != m_size)
	{
		m_data[m_topOfStack++] = std::move(t);
		return;
	}

	throw std::out_of_range("Reached stak element cap");
}

template <typename T, size_t size>
const T MyStack<T, size>::Pop()
{
	if (m_topOfStack)
	{
		return m_data[--m_topOfStack];
	}

	throw std::out_of_range("The stack is empty");
}


template <typename T, size_t size>
const T& MyStack<T, size>::operator[](size_t index)
{
	if (index > (m_topOfStack - 1) || index < 0)
	{
		throw std::out_of_range("Can't access this element");
	}

	return m_data[index];
}

/*template <typename T, size_t size>
std::ostream& operator<<(std::ostream& output, const MyStack<T, size>& ms)
{
	T* p = m_data;

	for (size_t i = 0; i < m_topOfStack; i++)
	{
		output << (p++) << "\n";
	}

	reteun output;
}
*/
/*template <typename T, size_t size>
T& MyStack<T, size>::operator=(MyStack<T, size>&& other)
{
if (this != &other)
{
delete[] data;

data = other.data;
m_size = other.m_size;

other.data = std::nullptr;
other.m_size = 0;
}

return *this;
}*/