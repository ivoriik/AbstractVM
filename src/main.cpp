#include "InputHandler.hpp"
#include "Exceptions.cpp"

bool vmHelp(void) const {
    std::cout << std::endl << std::setiosflags(std::ios::left)
        << "| command  | " << std::setw(14) << "parameter"     << std::setw(95) << ": description" << '|' << std::endl
        << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
        << "| exit     | " << std::setw(14) << ' '             << std::setw(95) << ": Stop to execute command queue and exit from AVM (necessary at the end of command queue);" << '|' << std::endl
        << "| print    | " << std::setw(14) << ' '             << std::setw(95) << ": Asserts that the value at the top of the stack is an 8-bit integer;" << '|' << std::endl
        << "| assert   | " << std::setw(14) << "@expression"   << std::setw(95) << ": check if @expression is true or not;" << '|' << std::endl
        << "| push     | " << std::setw(14) << "@type(@value)" << std::setw(95) << ": valid @type is int8, int16, int32, float, double; Pushes the @value at the top of the stack;" << '|' << std::endl
        << "| pop      | " << std::setw(14) << ' '             << std::setw(95) << ": Unstacks the value from the top of the stack;" << '|' << std::endl
        << "| add      | " << std::setw(14) << ' '             << std::setw(95) << ": Unstacks the first two values on the stack, adds them, then stacks the result;" << '|' << std::endl
        << "| sub      | " << std::setw(14) << ' '             << std::setw(95) << ": Unstacks the first two values on the stack, subtracts them, then stacks the result;" << '|' << std::endl
        << "| mul      | " << std::setw(14) << ' '             << std::setw(95) << ": Unstacks the first two values on the stack, multiplies them, then stacks the result;" << '|' << std::endl
        << "| div      | " << std::setw(14) << ' '             << std::setw(95) << ": Unstacks the first two values on the stack, divides them, then stacks the result;" << '|' << std::endl
        << "| mod      | " << std::setw(14) << ' '             << std::setw(95) << ": Unstacks the first two values on the stack, calculates the modulus, then stacks the result;" << '|' << std::endl
        << "| ;        | " << std::setw(14) << ' '             << std::setw(95) << ": All comments start with ';';" << '|' << std::endl
        << "| " INVERT ";;       " WHITE " | " << std::setw(14) << ' '             << std::setw(95) << ": Stops waiting for any input and execute AVM;" << '|' << std::endl
        << "| " INVERT "help/h   " WHITE " | " << std::setw(14) << ' '             << std::setw(95) << ": Print this help info;" << '|' << std::endl << std::endl;
}

int main(int argc, char **argv)
{
	InputHandler handler;

	try {
		if (argc == 1) {
			handler.readStdin();
		} else if (argc == 2) {
			if (static_cast<std::string>(argv[1]) == static_cast<std::string>("--help"))
				vmHelp();
			else
				handler.readFile(fname);
		} else {
			std::cout << "Usage: abstractVM [FILE]" << std::endl;
			std::cout << "Try 'abstractVM --help' for more information." << std::endl;
		}
	} catch (const Exceptions::FileErrException &e) {
		std::cerr << e.what() << std::endl;
	} catch (const std::Exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
