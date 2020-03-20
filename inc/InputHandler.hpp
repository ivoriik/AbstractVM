#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP

#include <fstream>

class InputHandler
{
public:
	InputHandler() = default;
	~InputHandler() = default;
	InputHandler(InputHandler const &oth) = default;
	InputHandler &operator=(InputHandler const &oth) = default;

	void readFile(char *fname);
	void readStdin();
};

#endif