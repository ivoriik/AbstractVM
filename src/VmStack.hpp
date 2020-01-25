#ifndef VM_STACK_HPP
#define VM_STACK_HPP

#include "Operand.hpp"
#include "Exceptions.hpp"
#include <sstream>
#include "IterableStack.hpp"
// #include <stack>
// #include <cstdlib>

#define CMD_POP "pop"
#define CMD_DUMP "dump"
#define CMD_ADD "add"
#define CMD_SUB "sub"
#define CMD_MUL "mul"
#define CMD_DIV "div"
#define CMD_MOD "mod"
#define CMD_PRINT "print"
#define CMD_EXIT "exit"

// #define CMD_ID 

// #define CM_MORE "more"
// #define CM_LESS "less"
// #define CM_MAX "max"
// #define CM_MIN "min"

class VmStack
{
private:
/*
** REPLAYS TO DIFFERENT STACK
*/
	IterableStack<IOperand const *> _stack;
	std::stringstream _resStr;
public:
	VmStack();
	~VmStack();
	VmStack(VmStack const &oth);
	VmStack &operator=(VmStack const &oth);
	IterableStack<IOperand const *> getStack() const;
	// std::stack<IOperand const *> getStack() const;

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
};

#endif