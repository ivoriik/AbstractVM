#include "Exceptions.hpp"

// unsigned int Exceptions::line = 1;

const char	*Exceptions::FileErrException::what(void) const throw() {
	return "Error: Impossible to open file";
}

const char	*Exceptions::SyntaxErrException::what(void) const throw() {
	return "Error: Syntax Error";
}

const char	*Exceptions::NoExitException::what(void) const throw() {
	return "Error: No \"exit\" command";
}

const char	*Exceptions::OverflowException::what(void) const throw() {
	return "Error: ";
}

const char	*Exceptions::UnderflowException::what(void) const throw() {
	return "Error: ";
}

const char	*Exceptions::NotEnoughArgsException::what(void) const throw() {
	return "Error: Not enough arguments for operation";
}

const char	*Exceptions::AssertException::what(void) const throw() {
	return "Error: ";
}

const char	*Exceptions::EmptyStackException::what(void) const throw() {
	return "Error: ";
}

const char	*Exceptions::DivByZeroException::what(void) const throw() {
	return "Error: Division by zero!";
}

const char	*Exceptions::PrintCmndException::what(void) const throw() {
	return "Error: Invalid type for print";
}

const char	*Exceptions::MoreException::what(void) const throw() {
	return "Error: ";
}

const char	*Exceptions::LessException::what(void) const throw() {
	return "Error: ";
}

const char *Exceptions::ConversionErrException::what(void) const throw() {
	return "Error: Stream conversion failed";
}

const char *Exceptions::BadCmndException::what() const throw() {
	return "Error: Invalid command";
}
	
const char *Exceptions::BadTypeException::what() const throw() {
	return "Error: Invalid argument type";
}
	
const char *Exceptions::BadValException::what() const throw() {
	return "Error: Invalid value";
}

const char *Exceptions::CmndAftExitException::what() const throw() {
	return "Error: \"exit\" is not the last command";
}