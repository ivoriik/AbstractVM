#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <iostream>
#include <stack>
#include <regex>
#include "Ioperadn.hpp"

class Parser
{
private:
    bool                    _isExit;
	std::cmatch				_match;
	const std::regex		_comment;
	const std::regex		_cmd;
	const std::regex		_cmdVal;

	// OperandFactory const                        _factory;
 //    std::map<std::string, instructAddr>         _instructs;
 //    std::map<std::string, instructAddrWithArgs> _instructsWithArgs;
 //    std::map<std::string, eOperandType>         _types;
public:
	Parser(void);
	~Parser(void);
	Parser(Parser const &oth);
	Parser &operator=(Parser const &oth);

	void processLine(std::string s);

	void isExit();
	// void executeTokens(Token command);
 //    void executeTokens(Token command, Token type, Token value);
	
};

#endif