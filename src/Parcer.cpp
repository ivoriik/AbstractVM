#include "Parser.hpp"

Parser(void) {


     this->_isExit = false;
}

~Parser(void) {
	try {
		checkExit()
	}
	catch (const MissingExitException &e) {
		std::cerr << e.what() << std::endl;
	}
	delete this->_vmStack;
}

Parser(Parser const &oth) {
	*this = oth;
}

Parser &operator=(Parser const &oth) {
	if (this != &oth) {
		delete this->_vmStack;
		*this = oth;
	}
	return *this;
}

void processLine(std::string s) {
	if (s.empty() || std::all_of(s.begin(), s.end(), isspace) ||
		(std::regex_match(s.c_str(), _comment))
		return ;
	if (_isExit == true)
		throw Exceptions::CmndAftExitException();
	if (std::regex_match(s.c_str(), _match, _cmd))
	{
		if (_match[REGEX_CMD_INDEX] == "exit")
			_isExit = true;
		return ;
	}
	else 
		std::regex_match(s.c_str(), _cmdValue))
		return ;
	else
		throw Exceptions::SyntaxErrException();
}

void Parser::checkExit() {
    if (!this->_exitBool)
        throw MissingExitException();
}