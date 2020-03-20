#include "InputHandler.hpp"
#include "Exceptions.hpp"
#include "Parser.hpp"

void InputHandler::readFile(char *fname) {
    std::ifstream ifs;
    std::string s;
    std::list<std::string> content;

    ifs.open(fname);
    if (!ifs.is_open()) {
    	throw(Exceptions::FileErrException());
    }

	while (std::getline(ifs, s)){
        content.push_back(s);
    }
    ifs.close();

	Parser prs;

	for (auto i = content.begin(); i != content.end(); ++i) {

    	try {
			prs.processLine(*i);
		} catch (const Exceptions::BadCmndException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const Exceptions::CmndAftExitException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const Exceptions::BadTypeException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const Exceptions::BadValException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const Exceptions::SyntaxErrException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
    }
}

void InputHandler::readStdin() {
	std::string s;
	Parser prs;

	while(true) {
		std::cout << ">> ";
		if (!getline(std::cin, s) || s == ";;")
			break;
		try {
			prs.processLine(s);
		} catch (const Exceptions::BadCmndException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const Exceptions::CmndAftExitException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const Exceptions::BadTypeException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const Exceptions::BadValException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const Exceptions::SyntaxErrException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
}
