#ifndef ITERABLESTACK_HPP
#define ITERABLESTACK_HPP

#include <iterator>
#include <stack>

template <typename T>
class IterableStack : public std::stack<T> {
	public:
		IterableStack(): std::stack<T>() {}
		IterableStack(std::stack<T> const &oth): std::stack<T>(oth) {}
		IterableStack(IterableStack const &oth): std::stack<T>(oth) {}
		virtual ~IterableStack() {}
		using std::stack<T>::operator=;
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin() {
			return std::begin(std::stack<T>::c);
		}
		iterator end() {
			return std::end(std::stack<T>::c);
		}
};

#endif
