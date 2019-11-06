#include "VmStack.hpp"

VmStack() {}

/*Pop calls the removed element's destructor(?)*/
~VmStack() {
	while (!this->_stack.empty())
		this->_stack.pop();
}

VmStack(VmStack const &oth) {
	*this = oth;
}

VmStack &operator=(VmStack const &oth) {
	if (this != &oth)
		*this = oth;
	return *this;
}

std::stack<IOperand const *> getStack() const {
	return this->_stack;
}

void push(IOperand const *val) {
	this->_stack.push(val);
}
/*WORK ON IT*/
void pop() {
	if (this->_stack.empty())
		throw EmptyStackException();
	else {
		// delete this->_stack.top();
		this->_stack.pop();
	}
}

void dump() {
	// std::stack<IOperand const *> dumpedStack = getStack();
	IterableStack<IOperand const *> it = this->_stack.begin();
	IterableStack<IOperand const *> end = this->_stack.end();

	while (it != end)
		_resStr << it++ << std::endl;
}

void assert(IOperand const *val) {
	if (this->_stack.empty())
		throw EmptyStackException();
	else if (!(this->_stack.top()->toString() == val->toString())
			|| (this->_stack.top()->getType() != val->getType()))
		throw AssertException();
}

void add() {
	if (this->_stack.size() < 2)
		throw NotEnoughArgsException();
	else {
		IOperand const *op1 = this->_stack.top();
		this->_stack.pop();
		IOperand const *op2 = this->_stack.top();
		this->_stack.pop();

		try {
			push(*op1 + *op2);
		} catch (const OverflowException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const UnderflowException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
}

void sub() {
	if (this->_stack.size() < 2)
		throw NotEnoughArgsException();
	else {
		IOperand const *op1 = this->_stack.top();
		this->_stack.pop();
		IOperand const *op2 = this->_stack.top();
		this->_stack.pop();
		try {
			push(*op2 - *op1);
		} catch (const OverflowException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const UnderflowException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
}

void mul() {
	if (this->_stack.size() < 2)
		throw NotEnoughArgsException();
	else {
		IOperand const *op1 = this->_stack.top();
		this->_stack.pop();
		IOperand const *op2 = this->_stack.top();
		this->_stack.pop();

		try {
			push(*op1 * *op2);
		} catch (const OverflowException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const UnderflowException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
}

void div() {
	if (this->_stack.size() < 2)
		throw NotEnoughArgsException();
	else {
		IOperand const *op1 = this->_stack.top();
		this->_stack.pop();
		IOperand const *op2 = this->_stack.top();
		this->_stack.pop();

		try {
			push(*op2 / *op1);
		} catch (const OverflowException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const UnderflowException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const DivByZeroException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
}

void mod() {
	if (this->_stack.size() < 2)
		throw NotEnoughArgsException();
	else {
		IOperand const *op1 = this->_stack.top();
		this->_stack.pop();
		IOperand const *op2 = this->_stack.top();
		this->_stack.pop();

		try {
			push(*op2 % *op1);
		} catch (const OverflowException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const UnderflowException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const DivByZeroException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const ModOnFloatException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
}

void print() {
	if (this->_stack.empty())
		throw EmptyStackException();
	else {
		IOperand const *op = this->_stack.top();
		if (op->getType() != eOperandType::Int8)
			throw NotPrintableException();
		else
			_resStr << static_cast<char>(std::stoi(toString())) << std::endl;
	}
}