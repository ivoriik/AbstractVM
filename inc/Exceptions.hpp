#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <string>
#include <iostream>

namespace Exceptions
{
	 extern size_t line;

	class FileErrException: public std::exception
	{
	private:
		std::string _msg;
	public:
		FileErrException();
		virtual ~FileErrException() = default;
		FileErrException(FileErrException const &oth) = default;
		FileErrException &operator=(FileErrException const &oth) = default;

		const char	*what() const throw();
	};

	class SyntaxErrException: public std::exception
	{
	private:
		std::string _line;
		std::string _s;
		std::string _msg;
	public:
		SyntaxErrException(size_t ln, std::string const &s);
		virtual ~SyntaxErrException() = default;
		SyntaxErrException(SyntaxErrException const &oth) = default;
		SyntaxErrException &operator=(SyntaxErrException const &oth) = default;

		const char	*what() const throw();
	};
	
	class BadCmndException : public std::exception
	{
	private:
		std::string _line;
		std::string _s;
		std::string _msg;
	public:
		BadCmndException(size_t ln, std::string const &s);
		virtual ~BadCmndException() = default;
		BadCmndException(BadCmndException const &oth) = default;
		BadCmndException &operator=(BadCmndException const &oth) = default;
	    const char *what() const throw();
	};
	
	class BadTypeException : public std::exception
	{
	private:
		std::string _line;
		std::string _s;
		std::string _msg;
	public:
		BadTypeException(size_t ln, std::string const &s);
		virtual ~BadTypeException() = default;
		BadTypeException(BadTypeException const &oth) = default;
		BadTypeException &operator=(BadTypeException const &oth) = default;
		const char *what() const throw();
	};
	
	class BadValException : public std::exception
	{
	private:
		std::string _line;
		std::string _s;
		std::string _msg;
	public:
		BadValException(size_t ln, std::string const &s);
		virtual ~BadValException() = default;
		BadValException(BadValException const &oth) = default;
		BadValException &operator=(BadValException const &oth) = default;
	    const char *what() const throw();
	};

	class CmndAftExitException : public std::exception
	{
	private:
		std::string _line;
		std::string _msg;
	public:
		CmndAftExitException(size_t ln);
		virtual ~CmndAftExitException() = default;
		CmndAftExitException(CmndAftExitException const &oth) = default;
		CmndAftExitException &operator=(CmndAftExitException const &oth) = default;
	    const char *what() const throw();
	};

	class NoExitException: public std::exception
	{
	private:
		std::string _line;
		std::string _msg;
	public:
		NoExitException(size_t ln);
		virtual ~NoExitException() = default;
		NoExitException(NoExitException const &oth) = default;
		NoExitException &operator=(NoExitException const &oth) = default;
		const char	*what() const throw();
	};

	class OverflowException: public std::out_of_range
	{
	private:
		std::string _msg;
	public:
		OverflowException();
		virtual ~OverflowException() = default;
		OverflowException(OverflowException const &oth) = default;
		OverflowException &operator=(OverflowException const &oth) = default;
//		const char	*what() const throw() = default;
	};

	class UnderflowException: public std::out_of_range
	{
	private:
		std::string _msg;
	public:
		UnderflowException();
		virtual ~UnderflowException() = default;
		UnderflowException(UnderflowException const &oth) = default;
		UnderflowException &operator=(UnderflowException const &oth) = default;
	};

	class NotEnoughArgsException: public std::exception
	{
	private:
		std::string _msg;
	public:
		NotEnoughArgsException();
		virtual ~NotEnoughArgsException() = default;
		NotEnoughArgsException(NotEnoughArgsException const &oth) = default;
		NotEnoughArgsException &operator=(NotEnoughArgsException const &oth) = default;
		const char	*what() const throw();
	};

	class AssertException: public std::exception
	{
	private:
		std::string _msg;
	public:
		AssertException();
		virtual ~AssertException() = default;
		AssertException(AssertException const &oth) = default;
		AssertException &operator=(AssertException const &oth) = default;
		const char	*what() const throw();
	};

	class EmptyStackException: public std::exception
	{
	private:
		std::string _msg;
	public:
		EmptyStackException();
		virtual ~EmptyStackException() = default;
		EmptyStackException(EmptyStackException const &oth) = default;
		EmptyStackException &operator=(EmptyStackException const &oth) = default;
		const char	*what() const throw();
	};

	class DivByZeroException: public std::exception
	{
	private:
		std::string _msg;
	public:
		DivByZeroException();
		virtual ~DivByZeroException() = default;
		DivByZeroException(DivByZeroException const &oth) = default;
		DivByZeroException &operator=(DivByZeroException const &oth) = default;
		const char	*what() const throw();
	};

	class PrintCmndException: public std::exception
	{
	private:
		std::string _msg;
	public:
		PrintCmndException();
		virtual ~PrintCmndException() = default;
		PrintCmndException(PrintCmndException const &oth) = default;
		PrintCmndException &operator=(PrintCmndException const &oth) = default;
		const char	*what() const throw();
	};

	class ConversionErrException: public std::exception
	{
	private:
		std::string _msg;
	public:
		ConversionErrException();
		virtual ~ConversionErrException() = default;
		ConversionErrException(ConversionErrException const &oth) = default;
		ConversionErrException &operator=(ConversionErrException const &oth) = default;
		const char	*what() const throw();
	};

	class MoreAssertException: public std::exception
	{
	private:
		std::string _msg;
	public:
		MoreAssertException();
		virtual ~MoreAssertException() = default;
		MoreAssertException(MoreAssertException const &oth) = default;
		MoreAssertException &operator=(MoreAssertException const &oth) = default;
		const char	*what() const throw();
	};

	class LessAssertException: public std::exception
	{
	private:
		std::string _msg;
	public:
		LessAssertException();
		virtual ~LessAssertException() = default;
		LessAssertException(LessAssertException const &oth) = default;
		LessAssertException &operator=(LessAssertException const &oth) = default;
		const char	*what() const throw();
	};

class NonIntModException: public std::exception
	{
	private:
		std::string _msg;
	public:
		NonIntModException();
		virtual ~NonIntModException() = default;
		NonIntModException(NonIntModException const &oth) = default;
		NonIntModException &operator=(NonIntModException const &oth) = default;
		const char	*what() const throw();
	};
}

#endif
