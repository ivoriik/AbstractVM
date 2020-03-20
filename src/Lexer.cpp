#include "Lexer.hpp"
#include "Token.hpp"
#include "Exceptions.hpp"

bool Lexer::isComment(std::string const &s) {

	return std::regex_search(s, std::regex(RGX_COMMENT));
}

Token Lexer::setCmnd(std::string const &s) {

	if (!(std::regex_search(s, _match, std::regex(RGX_CMND))) ) {
		throw Exceptions::BadCmndException(Exceptions::line, s);
	}
	return Token(_match[0], eTokenType::Command);
}

Token Lexer::setType(std::string const &s) {

	if (!(std::regex_search(s, _match, std::regex(RGX_TYPE))))
		throw Exceptions::BadTypeException(Exceptions::line, s);
	return Token(_match[0], eTokenType::Type);
}

Token Lexer::setVal(std::string const &s) {

	if (!(std::regex_search(s, _match, std::regex(RGX_NUM))))
		throw Exceptions::BadValException(Exceptions::line, s);
	return Token(_match[1], eTokenType::Value);
}

void Lexer::checkCmnd(std::string const &s) {
	if (!(std::regex_search(s, std::regex(RGX_SYNT_CMND))))
		throw Exceptions::SyntaxErrException(Exceptions::line, s);
}

void Lexer::checkCmndWithVal(std::string const &s) {
	if (!(std::regex_match(s, _match, std::regex(RGX_SYNT_CMND_WITH_VAL))))
		throw Exceptions::SyntaxErrException(Exceptions::line, s);
}
