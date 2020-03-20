#include "VmStack.hpp"
#include "Exceptions.hpp"

VmStack::~VmStack() {
	while (!this->_stack.empty())
		this->_stack.pop_front();
}

VmStack::VmStack(VmStack const &oth) {
	*this = oth;
}

VmStack &VmStack::operator=(VmStack const &oth) {
	if (this == &oth)
		return *this;
	for (auto i = oth._stack.begin(); i != oth._stack.end(); ++i) {
		this->_stack.push_back(*i);
	}
	return *this;
}

std::list<const IOperand *> VmStack::getStack() const {
	return this->_stack;
}

void VmStack::push(IOperand const *val) {
	if (val)
		this->_stack.push_front(val);
}

void VmStack::pop() {
	if (this->_stack.empty())
		throw Exceptions::EmptyStackException();
	else
		this->_stack.pop_front();
}

void VmStack::dump() {

	for (auto i = _stack.begin(); i != _stack.end(); ++i) {
		_resStr << (*i)->toString() << std::endl;
	}
}

void VmStack::assert(IOperand const *op) {
	if (this->_stack.empty())
		throw Exceptions::EmptyStackException();
	else if (*this->_stack.front() == *op)
		return ;
	throw Exceptions::AssertException();
}

void VmStack::less(IOperand const *op) {
	std::cout << __func__ << std::endl;
	if (this->_stack.empty())
		throw Exceptions::EmptyStackException();
	else if (!(*this->_stack.front() < *op)) {
		throw Exceptions::LessAssertException();
	}
}

void VmStack::more(IOperand const *op) {
	std::cout << __func__ << std::endl;
	if (this->_stack.empty())
		throw Exceptions::EmptyStackException();
	else if (!(*this->_stack.front() > *op)) {
		throw Exceptions::MoreAssertException();
	}
}

void VmStack::add() {
	if (this->_stack.size() < 2)
		throw Exceptions::NotEnoughArgsException();
	else {
		IOperand const *op1 = this->_stack.front();
		this->_stack.pop_front();
		IOperand const *op2 = this->_stack.front();
		this->_stack.pop_front();

		try {
			push(*op1 + *op2);
		} catch (const Exceptions::OverflowException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const Exceptions::UnderflowException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const std::out_of_range &e) {
			std::cerr << e.what() << std::endl;
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
}

void VmStack::sub() {
//	std::cout << __func__ << std::endl;
	if (this->_stack.size() < 2)
		throw Exceptions::NotEnoughArgsException();
	else {
		IOperand const *op1 = this->_stack.front();
		this->_stack.pop_front();
		IOperand const *op2 = this->_stack.front();
		this->_stack.pop_front();
		try {
			push(*op2 - *op1);
		} catch (const Exceptions::OverflowException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const Exceptions::UnderflowException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const std::out_of_range &e) {
			std::cerr << e.what() << std::endl;
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
}

void VmStack::mul() {
//	std::cout << __func__ << std::endl;
	if (this->_stack.size() < 2)
		throw Exceptions::NotEnoughArgsException();
	else {
		IOperand const *op1 = this->_stack.front();
		this->_stack.pop_front();
		IOperand const *op2 = this->_stack.front();
		this->_stack.pop_front();

		try {
			push(*op1 * *op2);
		} catch (const Exceptions::OverflowException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const Exceptions::UnderflowException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const std::out_of_range &e) {
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
		IOperand const *op1 = this->_stack.front();
		this->_stack.pop_front();
		IOperand const *op2 = this->_stack.front();
		this->_stack.pop_front();

		try {
			push(*op2 / *op1);
		} catch (const Exceptions::OverflowException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const Exceptions::UnderflowException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const Exceptions::DivByZeroException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const std::out_of_range &e) {
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
		IOperand const *op1 = this->_stack.front();
		this->_stack.pop_front();
		IOperand const *op2 = this->_stack.front();
		this->_stack.pop_front();

		try {
			push(*op2 % *op1);
		} catch (const Exceptions::OverflowException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const Exceptions::UnderflowException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const Exceptions::DivByZeroException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const Exceptions::NonIntModException &e) {
		 	std::cerr << e.what() << std::endl;
		} catch (const std::out_of_range &e) {
			std::cerr << e.what() << std::endl;
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
}

void VmStack::print() {
	if (this->_stack.empty())
		throw Exceptions::EmptyStackException();
	else {
		IOperand const *op = this->_stack.front();
		if (op->getType() != eOperandType::Int8)
			throw Exceptions::PrintCmndException();
		else
			_resStr << static_cast<char>(std::stoi(op->toString())) << std::endl;
	}
}

void VmStack::printResStr() {
	std::cout << this->_resStr.str();
}