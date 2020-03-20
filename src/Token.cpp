#include "Token.hpp"

Token::Token() {}

Token::Token(std::string const &s, eTokenType const &type) : _value(s), _type(type) {}

Token::~Token() {}

Token::Token(Token const &oth) {
	*this = oth;
}

Token &Token::operator=(Token const &oth) {

	if (this != &oth) {
		this->_value = oth.getValue();
		this->_type = oth.getType();
	}
	return *this;
}

std::string Token::getValue() const {
	return this->_value;
}

eTokenType Token::getType() const {
	return this->_type;
}

void Token::setValue(std::string const &s) {
	this->_value = s;
}

void Token::setType(eTokenType const &type) {
	this->_type = type;
}
