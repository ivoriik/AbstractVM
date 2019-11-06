#include "Exceptions.hpp"

// unsigned int Exceptions::line = 1;

const char	*Exceptions::FileErrException::what(void) const throw() {
	return "Error: Impossible to open file";
}

const char	*Exceptions::SyntaxErrException::what(void) const throw() {
	return "Error: Syntax Error";
}

const char	*Exceptions::NoExitCommandException::what(void) const throw() {
	return "Error: No \"exit\" command";
}

const char	*Exceptions::OverflowException::what(void) const throw() {
	return "Error: ";
}

const char	*Exceptions::UnderflowException::what(void) const throw() {
	return "Error: ";
}

const char	*Exceptions::NotEnoughArgumentsException::what(void) const throw() {
	return "Error: Not enough arguments for operation";
}

const char	*Exceptions::AssertException::what(void) const throw() {
	return "Error: ";
}

const char	*Exceptions::EmptyStackException::what(void) const throw() {
	return "Error: ";
}

const char	*Exceptions::DivisionByZeroException::what(void) const throw() {
	return "Error: Division by zero!";
}

const char	*Exceptions::PrintCommandException::what(void) const throw() {
	return "Error: Invalid type for print";
}

const char	*Exceptions::MoreException::what(void) const throw() {
	return "Error: ";
}

const char	*Exceptions::LessException::what(void) const throw() {
	return "Error: ";
}

const char *Exceptions::ConversionException::what(void) const throw() {
	return "Error: Stream conversion failed";
}

const char *BadCmndException::what() const throw() {
	return "Error: Invalid command";
}
	
const char *BadTypeException::what() const throw() {
	return "Error: Invalid argument type";
}
	
const char *BadValueException::what() const throw() {
	return "Error: Invalid value";
}

const char *CmndAftExitException::what() const throw() {
	return "Error: \"exit\" is not the last command";
}