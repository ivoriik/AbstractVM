#ifndef ITERABLESTACK_HPP
#define ITERABLESTACK_HPP

#include <iterator>
#include <stack>

template <typename T>
class ItarbleStack : public std::stack<T> {
	public:
		ItarbleStack(): std::stack<T>() {}
		ItarbleStack(std::stack<T> const &oth): std::stack<T>(oth) {}
		ItarbleStack(ItarbleStack const &oth): std::stack<T>(oth) {}
		virtual ~ItarbleStack() {}
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
