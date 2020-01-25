#include "VmStack.hpp"

VmStack::VmStack() {}

/*Pop calls the removed element's destructor(?)*/
VmStack::~VmStack() {
	while (!this->_stack.empty())
		this->_stack.pop();
}

VmStack::VmStack(VmStack const &oth) {
	*this = oth;
}

VmStack &VmStack::operator=(VmStack const &oth) {
	if (this != &oth)
		*this = oth;
	return *this;
}

IterableStack<IOperand const *> VmStack::getStack() const {
	return this->_stack;
}

void VmStack::push(IOperand const *val) {
	this->_stack.push(val);
}
/*WORK ON IT*/
void VmStack::pop() {
	if (this->_stack.empty())
		throw Exceptions::EmptyStackException();
	else {
		// delete this->_stack.top();
		this->_stack.pop();
	}
}

void VmStack::dump() {
	// std::stack<IOperand const *> dumpedStack = getStack();
/*
** REPLAYS TO FOR / DIFFERENT STACK
*/
	IterableStack<IOperand const *>::iterator it = this->_stack.begin();
	IterableStack<IOperand const *>::iterator end = this->_stack.end();

	while (it != end) {
		_resStr << (*it)->toString() << std::endl;
		it++;
	}
}

void VmStack::assert(IOperand const *val) {
	if (this->_stack.empty())
		throw Exceptions::EmptyStackException();
	else if (!(this->_stack.top()->toString() == val->toString())
			|| (this->_stack.top()->getType() != val->getType()))
		throw Exceptions::AssertException();
}

void VmStack::add() {
	if (this->_stack.size() < 2)
		throw Exceptions::NotEnoughArgsException();
	else {
		IOperand const *op1 = this->_stack.top();
		this->_stack.pop();
		IOperand const *op2 = this->_stack.top();
		this->_stack.pop();

		try {
			push(*op1 + *op2);
		} catch (const Exceptions::OverflowException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const Exceptions::UnderflowException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
}

void VmStack::sub() {
	if (this->_stack.size() < 2)
		throw Exceptions::NotEnoughArgsException();
	else {
		IOperand const *op1 = this->_stack.top();
		this->_stack.pop();
		IOperand const *op2 = this->_stack.top();
		this->_stack.pop();
		try {
			push(*op2 - *op1);
		} catch (const Exceptions::OverflowException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const Exceptions::UnderflowException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
}

void VmStack::mul() {
	if (this->_stack.size() < 2)
		throw Exceptions::NotEnoughArgsException();
	else {
		IOperand const *op1 = this->_stack.top();
		this->_stack.pop();
		IOperand const *op2 = this->_stack.top();
		this->_stack.pop();

		try {
			push(*op1 * *op2);
		} catch (const Exceptions::OverflowException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const Exceptions::UnderflowException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
}

void VmStack::div() {
	if (this->_stack.size() < 2)
		throw Exceptions::NotEnoughArgsException();
	else {
		IOperand const *op1 = this->_stack.top();
		this->_stack.pop();
		IOperand const *op2 = this->_stack.top();
		this->_stack.pop();

		try {
			push(*op2 / *op1);
		} catch (const Exceptions::OverflowException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const Exceptions::UnderflowException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const Exceptions::DivByZeroException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
}

void VmStack::mod() {
	if (this->_stack.size() < 2)
		throw Exceptions::NotEnoughArgsException();
	else {
		IOperand const *op1 = this->_stack.top();
		this->_stack.pop();
		IOperand const *op2 = this->_stack.top();
		this->_stack.pop();

		try {
			push(*op2 % *op1);
		} catch (const Exceptions::OverflowException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const Exceptions::UnderflowException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const Exceptions::DivByZeroException &e) {
			std::cerr << e.what() << std::endl;
		// } catch (const Exceptions::ModOnFloatException &e) {
		// 	std::cerr << e.what() << std::endl;
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
}

void VmStack::print() {
	if (this->_stack.empty())
		throw Exceptions::EmptyStackException();
	else {
		IOperand const *op = this->_stack.top();
		if (op->getType() != eOperandType::Int8)
			throw Exceptions::PrintCmndException();
		else
			_resStr << static_cast<char>(std::stoi(op->toString())) << std::endl;
	}
}