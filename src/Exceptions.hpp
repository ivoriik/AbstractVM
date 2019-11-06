#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <string>
#include <iostream>

/*CANONICAL FORM*/

namespace Exceptions
{
	// extern unsigned int line;

	class FileErrException: public std::exception
	{
	public:
		const char	*what(void) const throw();
	};

	class SyntaxErrException: public std::exception
	{
	public:
		const char	*what(void) const throw();
	};
	
	class NotValidCmndException : public std::exception
	{
	public :
	    char *what() const throw();
	};
	
	class NotValidTypeException : public std::exception
	{
	public:
		const char *what() const throw();
	};
	
	class BadValueException : public std::exception
	{
	public :
	    const char *what() const throw();
	};

	class CmndAftExitException : public std::exception
	{
	public:
	    const char *what() const throw();
	};

	class NoExitCmndException: public std::exception
	{
	public:
		const char	*what(void) const throw();
	};

	class OverflowException: public std::exception
	{
	public:
		const char	*what(void) const throw();
	};

	class UnderflowException: public std::exception
	{
	public:
		const char	*what(void) const throw();
	};

	class NotEnoughArgsException: public std::exception
	{
	public:
		const char	*what(void) const throw();
	};

	class AssertException: public std::exception
	{
	public:
		const char	*what(void) const throw();
	};

	class EmptyStackException: public std::exception
	{
	public:
		const char	*what(void) const throw();
	};

	class DivByZeroException: public std::exception
	{
	public:
		const char	*what(void) const throw();
	};

	class PrintCmndException: public std::exception
	{
	public:
		const char	*what(void) const throw();
	};

	class ConversionErrException: public std::exception
	{
	public:
		const char	*what(void) const throw();
	};

/* ??? */
	class MoreException: public std::exception
	{
	public:
		const char	*what(void) const throw();
	};

	class LessException: public std::exception
	{
	public:
		const char	*what(void) const throw();
	};

#endif
