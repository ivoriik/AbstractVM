#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include <iostream>
#include <map>
#include <string>
#include <list>

class InputHandler
{
private:
	Parser									_parser;
	VmStack									*_vmStack;
	std::map<std::string, instructAddr>		_cmnd;
	// std::map<std::string, eOperandType>		_types;

public:
	InputHandler(void);
	~InputHandler(void);
	InputHandler(InputHandler const &oth);
	InputHandler &operator=(InputHandler const &oth);

	void readFile(char *fname);
	void readStdin(void);
	void calcExpression(std::cmatch const &_match);
}

#endif