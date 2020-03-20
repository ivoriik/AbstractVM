#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <iostream>
#include <stack>
#include <regex>
#include "IOperand.hpp"
#include "FactoryClass.hpp"
#include "Lexer.hpp"
#include "VmStack.hpp"


class Parser
{
private:
    bool                    									_isExit;
	VmStack														*_vmStack;
	Lexer														_lexer;
	Token 														_cmnd;
	Token 														_type;
	Token 														_val;
 	std::map<std::string, eOperandType>         				_eType;
	std::map<std::string, void (VmStack::*)()>					_cmndFn;
	std::map<std::string, void (VmStack::*)(const IOperand *)>	_cmndWithArgFn;
public:
	Parser();
	~Parser();
	Parser(Parser const &oth) = default;
	Parser &operator=(Parser const &oth) = default;

	void processLine(std::string const &s);

	void isExit();
	void calcExpression(std::string const &cmnd);
	void calcExpression(std::string const &cmnd, IOperand const *rhs);
 	VmStack *getVmStack();
	
};

#endif