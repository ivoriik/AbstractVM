#include "InputHandler.hpp"

InputHandler::InputHandler(void) {
	this->_vmStack = new VmStack();
	// this->_types["int8"] = eOperandType::Int8;
	// this->_types["int16"] = eOperandType::Int16;
	// this->_types["int32"] = eOperandType::Int32;
	// this->_types["float"] = eOperandType::Float;
	// this->_types["double"] = eOperandType::Double;
	this->_cmnd["pop"] = &VmStack::pop;
	this->_cmnd["dump"] = &VmStack::dump;
	this->_cmnd["print"] = &VmStack::print;
	this->_cmnd["add"] = &VmStack::add;
	this->_cmnd["sub"] = &VmStack::sub;
	this->_cmnd["mul"] = &VmStack::mul;
	this->_cmnd["div"] = &VmStack::div;
	this->_cmnd["mod"] = &VmStack::mod;
	this->_cmnd["push"] = &VmStack::push;
	this->_cmnd["assert"] = &VmStack::assert;
}

InputHandler::~InputHandler(void) {}

InputHandler::InputHandler(InputHandler const &oth) {
	*this = oth;
}

InputHandler InputHandler::&operator=(InputHandler const &oth) {
	if (this != &oth) {
		*this = oth;
	}
	return oth;
}

void InputHandler::readFile(char *fname) {
    std::ifstream ifs;
    std::string s;
    std::list<std::string> content;
    Parser prs;

    ifs.open(fileName);
    if (!ifs.is_open()) {
    	throw(FileErrException());
    }

    while (std::getline(ifs, s)){
        content.push_back(s);
    }
    ifs.close();

    while (content.size()) {
    	try {
			prs.processLine(s);
		}
		// catch (const BadValueException &e) {
		// 	std::cerr << e.what() << std::endl; 
		// }
		// catch (const UnknownTypeException &e) {
		// 	std::cerr << e.what() << std::endl;
		// }
		// catch (const UnknownCommandException &e) {
		// 	std::cerr << e.what() << std::endl;
		// }
		catch (const SyntaxErrException &e) {
			std::cerr << e.what() << std::endl;
		}
		catch (const CommandAftExitException &e) {
			std::cerr << e.what() << std::endl;
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		if (prs._match[CMD_ID] != CMD_EXIT) {
			this->calcExpression(prs._match);
		}
    }
}

void InputHandler::readStdin(void) {
	std::string s;
	Parser prs;

	while(getline(std::cin, s) && s != ";;") {
		try {
			prs.processLine(s);
		}
		// catch (const BadValueException &e) {
		// 	std::cerr << e.what() << std::endl; 
		// }
		// catch (const UnknownTypeException &e) {
		// 	std::cerr << e.what() << std::endl;
		// }
		// catch (const UnknownCommandException &e) {
		// 	std::cerr << e.what() << std::endl;
		// }
		catch (const SyntaxErrException &e) {
			std::cerr << e.what() << std::endl;
		}
		catch (const CommandAftExitException &e) {
			std::cerr << e.what() << std::endl;
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		if (prs._match[CMD_ID] != CMD_EXIT) {
			this->calcExpression(prs._match);
		}
	}
}


void calcExpression(std::cmatch const &_match) {
	if (_match[CMD_ID] == "CMD_PUSH" || _match[CMD_ID] == "CMD_ASSERT") {
        IOperand const *op = _factory.createOperand(_match[TYP_ID], _match[VAL_ID]);
     	try {
        	_abstractStack->*(this->_cmnd[command.getContent()])(op);
     	}
	} else {
		try {
			this->_vmStack->*(_match[CMD_ID]);
		}
	}
    catch (const EmptyStackException& e) {
    	std::cerr << e.what() << std::endl; 
    }
    catch (const UnderFlowException& e) {
    	std::cerr << e.what() << std::endl; 
    }
    catch (const OverFlowException& e) {
    	std::cerr << e.what() << std::endl; 
    }
    catch (const AssertFailException& e) {
    	std::cerr << e.what() << std::endl; 
    }
    catch (const std::exception& e) {
    	std::cerr << e.what() << std::endl; 
    }
}
