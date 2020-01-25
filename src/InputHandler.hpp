#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP

// #include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <list>
// #include <regex>
#include "VmStack.hpp"

class InputHandler
{
private:
	VmStack										*_vmStack;
	std::map<std::string, void (VmStack::*)()>	_cmnd;
	std::map<std::string, void (VmStack::*)(const IOperand *)>	_cmndWithArg;
	// std::map<std::string, eOperandType>		_types;

public:
	InputHandler(void);
	~InputHandler(void);
	InputHandler(InputHandler const &oth);
	InputHandler &operator=(InputHandler const &oth);

	void readFile(char *fname);
	void readStdin(void);
	void calcExpression(std::string const &cmnd);
	void calcExpression(std::string const &cmnd, IOperand const *rhs);
};

#endif