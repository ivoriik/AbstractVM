#include "InputHandler.hpp"
#include "Exceptions.hpp"
#include <iomanip>
#include "VmStack.hpp"

bool vmHelp() {
    std::cout << std::endl << std::setiosflags(std::ios::left)
        << "| command  | " << std::setw(15) << "parameter"     << std::setw(100) << "| description" << '|' << std::endl
        << "|==========|=====================================================================================================================" << std::endl
		<< "| push     | " << std::setw(15) << "type(value)"   << std::setw(100) << "| Pushes value at the top of the stack. Format: int8(n), int16(n), int32(n), float(n), double(n)" << '|' << std::endl
		<< "| pop      | " << std::setw(15) << ""              << std::setw(100) << "| Unstacks value from the top of the stack" << '|' << std::endl
		<< "| dump     | " << std::setw(15) << ""              << std::setw(100) << "| Displays each value of the stack, from the recent one to the oldest one" << '|' << std::endl
		<< "| assert   | " << std::setw(15) << "expression"    << std::setw(100) << "| Asserts that the value at the top of the stack is equal to the one passed as parameter" << '|' << std::endl
		<< "| add      | " << std::setw(15) << ""              << std::setw(100) << "| Unstacks the first two values on the stack, adds them, then stacks the result" << '|' << std::endl
		<< "| sub      | " << std::setw(15) << ""              << std::setw(100) << "| Unstacks the first two values on the stack, subtracts them, then stacks the result" << '|' << std::endl
		<< "| mul      | " << std::setw(15) << ""              << std::setw(100) << "| Unstacks the first two values on the stack, multiplies them, then stacks the result" << '|' << std::endl
		<< "| div      | " << std::setw(15) << ""              << std::setw(100) << "| Unstacks the first two values on the stack, divides them, then stacks the result" << '|' << std::endl
		<< "| mod      | " << std::setw(15) << ""              << std::setw(100) << "| Unstacks the first two values on the stack, calculates the modulus, then stacks the result" << '|' << std::endl
		<< "| print    | " << std::setw(15) << ""              << std::setw(100) << "| Asserts that the value at the top of the stack is an 8-bit integer" << '|' << std::endl
		<< "| more     | " << std::setw(15) << "expression"    << std::setw(100) << "| Asserts that the value at the top of the stack is greater than one passed as parameter" << '|' << std::endl
		<< "| less     | " << std::setw(15) << "expression"    << std::setw(100) << "| Asserts that the value at the top of the stack is less than one passed as parameter" << '|' << std::endl
		<< "| exit     | " << std::setw(15) << ""              << std::setw(100) << "| Terminate the execution of the current program" << '|' << std::endl
        << "| ;        | " << std::setw(15) << ""              << std::setw(100) << "| Comments start with a ’;’ and finish with a newline" << '|' << std::endl;
	return (0);
}

int main(int argc, char **argv)
{
	InputHandler handler;

	try {
		if (argc == 1) {
			handler.readStdin();
		} else if (argc == 2) {
			if (static_cast<std::string>(argv[1]) == static_cast<std::string>("--help")) {
				vmHelp();
			} else {
				handler.readFile(argv[1]);
			}
		} else {
			std::cout << "Usage: abstractVM [FILE]" << std::endl
				<< "Try 'abstractVM --help' for more information." << std::endl;
		}
	} catch (Exceptions::FileErrException &e) {
		std::cerr << e.what() << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
