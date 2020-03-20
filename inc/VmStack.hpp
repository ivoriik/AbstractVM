#ifndef VM_STACK_HPP
#define VM_STACK_HPP

#include <sstream>
#include "IOperand.hpp"
#include <list>

class VmStack
{
private:
	std::list<const IOperand *> _stack;
	std::stringstream _resStr;
public:
	VmStack() = default;
	~VmStack();
	VmStack(VmStack const &oth);
	VmStack &operator=(VmStack const &oth);
	std::list<const IOperand *> getStack() const;

	void push(IOperand const *value);
	void pop();
	void dump();
	void assert(IOperand const *value);
	void add();
	void sub();
	void mul();
	void div();
	void mod();
	void print();
	void less(IOperand const *value);
	void more(IOperand const *value);

	void printResStr();

};

#endif