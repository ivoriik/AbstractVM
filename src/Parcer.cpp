#include "Parser.hpp"
#include "Exceptions.hpp"
#include "IOperand.hpp"

Parser::Parser(): _isExit(false), _vmStack(new VmStack()) {
	_eType.emplace("int8", eOperandType::Int8);
	_eType.emplace("int16", eOperandType::Int16);
	_eType.emplace("int32", eOperandType::Int32);
	_eType.emplace("float", eOperandType::Float);
	_eType.emplace("double", eOperandType::Double);
	_cmndFn.emplace("pop", &VmStack::pop);
	_cmndFn.emplace("dump", &VmStack::dump);
	_cmndFn.emplace("print", &VmStack::print);
	_cmndFn.emplace("add", &VmStack::add);
	_cmndFn.emplace("sub", &VmStack::sub);
	_cmndFn.emplace("mul", &VmStack::mul);
	_cmndFn.emplace("div", &VmStack::div);
	_cmndFn.emplace("mod", &VmStack::mod);
	_cmndWithArgFn.emplace("push", &VmStack::push);
	_cmndWithArgFn.emplace("assert", &VmStack::assert);
	_cmndWithArgFn.emplace("less", &VmStack::less);
	_cmndWithArgFn.emplace("more", &VmStack::more);
}

Parser::~Parser() {
	try {
		isExit();
		this->getVmStack()->printResStr();
	}
	catch (const Exceptions::NoExitException &e) {
		std::cerr << e.what() << std::endl;
	}
}

void Parser::processLine(std::string const &s) {

	++Exceptions::line;
	if (s.empty() || std::all_of(s.begin(), s.end(), isspace) ||
		_lexer.isComment(s))
		return ;
	if (_isExit)
		throw Exceptions::CmndAftExitException(Exceptions::line);
	this->_cmnd = this->_lexer.setCmnd(s);
	if (_cmnd.getValue() == "push" ||
		_cmnd.getValue() == "assert" ||
		_cmnd.getValue() == "less" ||
		_cmnd.getValue() == "more") {
		this->_type = _lexer.setType(s);
		this->_val = _lexer.setVal(s);
		this->_lexer.checkCmndWithVal(s);
		this->calcExpression(this->_cmnd.getValue(),
				_factory.createOperand(this->_eType[this->_type.getValue()],
				this->_val.getValue()));
	} else {
			_lexer.checkCmnd(s);
		if (this->_cmnd.getValue() == "exit") {
			this->_isExit = true;
			return ;
		}
		this->calcExpression(this->_cmnd.getValue());
	}
}

void Parser::isExit() {
    if (!this->_isExit)
        throw Exceptions::NoExitException(Exceptions::line);
}

void Parser::calcExpression(std::string const &cmnd) {
	try {
		(this->_vmStack->*_cmndFn[cmnd])();
	} catch (const Exceptions::EmptyStackException& e) {
		std::cerr << e.what() << std::endl;
	} catch (const Exceptions::UnderflowException& e) {
		std::cerr << e.what() << std::endl;
	} catch (const Exceptions::OverflowException& e) {
		std::cerr << e.what() << std::endl;
	} catch (const Exceptions::AssertException& e) {
		std::cerr << e.what() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

void Parser::calcExpression(std::string const &cmnd, IOperand const *op) {
	try {
		(this->_vmStack->*_cmndWithArgFn[cmnd])(op);
	} catch (const Exceptions::EmptyStackException& e) {
		std::cerr << e.what() << std::endl;
	} catch (const Exceptions::UnderflowException& e) {
		std::cerr << e.what() << std::endl;
	} catch (const Exceptions::OverflowException& e) {
		std::cerr << e.what() << std::endl;
	} catch (const Exceptions::AssertException& e) {
		std::cerr << e.what() << std::endl;
	} catch (const std::out_of_range &e) {
		std::cerr << "Out of range: " << e.what() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Out of range: " << e.what() << std::endl;
	}
}

VmStack * Parser::getVmStack() {
	return this->_vmStack;
}
