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

}

void InputHandler::readStdin(void) {
	std::string s;

	while(getline(std::cin, s) && s != ";;") {
		try {
			this->_parser.processLine(s);
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
		if (_match[CMD_ID] != "CMD_EXIT") {
			this->calcExpression(_parser._match);
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
