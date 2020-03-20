#include "Exceptions.hpp"

size_t Exceptions::line = 0;

Exceptions::FileErrException::FileErrException() {
	this->_msg = "Error: Impossible to open file!";
}
const char	*Exceptions::FileErrException::what() const throw() {
	return this->_msg.c_str();
}

Exceptions::SyntaxErrException::SyntaxErrException(size_t ln, std::string const &s): _line(std::to_string(ln)), _s(s) {
	this->_msg = "Line " + _line + ": " + _s + "\nError: Syntax Error!";
}
const char	*Exceptions::SyntaxErrException::what() const throw() {
	return this->_msg.c_str();
}

Exceptions::NoExitException::NoExitException(size_t ln): _line(std::to_string(ln)) {
	this->_msg = "Line " + _line + ". Error: No \"exit\" command!";
}
const char	*Exceptions::NoExitException::what() const throw() {
	return this->_msg.c_str();
}

Exceptions::OverflowException::OverflowException(): std::out_of_range("Error: Overflow on a value")
{}

Exceptions::UnderflowException::UnderflowException(): std::out_of_range("Error: Underflow on a value")
{}

Exceptions::NotEnoughArgsException::NotEnoughArgsException() {
	this->_msg = "Error: Not enough arguments for operation!";
}
const char	*Exceptions::NotEnoughArgsException::what() const throw() {
	return this->_msg.c_str();
}

Exceptions::AssertException::AssertException() {
	this->_msg = "Assertion failed!";
}
const char	*Exceptions::AssertException::what() const throw() {
	return this->_msg.c_str();
}

Exceptions::EmptyStackException::EmptyStackException() {
	this->_msg = "Error: Instruction on an empty stack!";
}
const char	*Exceptions::EmptyStackException::what() const throw() {
	return this->_msg.c_str();
}

Exceptions::DivByZeroException::DivByZeroException() {
	this->_msg = "Error: Division by zero!";
}
const char	*Exceptions::DivByZeroException::what() const throw() {
	return this->_msg.c_str();
}

Exceptions::PrintCmndException::PrintCmndException() {
	this->_msg = "Error: Type is not printable!";
}
const char	*Exceptions::PrintCmndException::what() const throw() {
	return this->_msg.c_str();
}

Exceptions::MoreAssertException::MoreAssertException() {
	this->_msg = "More assertion failed!";
}
const char	*Exceptions::MoreAssertException::what() const throw() {
	return this->_msg.c_str();
}

Exceptions::LessAssertException::LessAssertException() {
	this->_msg = "Less assertion failed!";
}
const char	*Exceptions::LessAssertException::what() const throw() {
	return this->_msg.c_str();
}

Exceptions::ConversionErrException::ConversionErrException() {
	this->_msg = "Error: Stream conversion failed!";
}
const char *Exceptions::ConversionErrException::what() const throw() {
	return this->_msg.c_str();
}

Exceptions::BadCmndException::BadCmndException(size_t ln, std::string const &s): _line(std::to_string(ln)), _s(s) {
	this->_msg = "Line " + _line + ": " + _s + "\nError: Instruction is unknown!";
}
const char *Exceptions::BadCmndException::what() const throw() {
	return this->_msg.c_str();
}

Exceptions::BadTypeException::BadTypeException(size_t ln, std::string const &s): _line(std::to_string(ln)), _s(s) {
	this->_msg = "Line " + _line + ": " + _s + "\nError: Invalid argument type!";
}
const char *Exceptions::BadTypeException::what() const throw() {
	return this->_msg.c_str();
}

Exceptions::BadValException::BadValException(size_t ln, std::string const &s): _line(std::to_string(ln)), _s(s) {
	this->_msg = "Line " + _line + ": " + _s + "\nError: Invalid value!";
}
const char *Exceptions::BadValException::what() const throw() {
	return this->_msg.c_str();
}

Exceptions::CmndAftExitException::CmndAftExitException(size_t ln): _line(std::to_string(ln)) {
	this->_msg = "Line " + _line + "\nError: \"exit\" is not the last command!";
}
const char *Exceptions::CmndAftExitException::what() const throw() {
	return this->_msg.c_str();
}

Exceptions::NonIntModException::NonIntModException() {
	this->_msg = "Invalid operands of non integer types to binary operator %!";
}
const char *Exceptions::NonIntModException::what() const throw() {
	return this->_msg.c_str();
}