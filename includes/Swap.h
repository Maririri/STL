#include <utility>      // std::move (objects)

template <typename T>
void Swap(T& lhs, T& rhs)
{
	T tmp = std::move(lhs);
	lhs = std::move(rhs);
	rhs = std::move(tmp);
}