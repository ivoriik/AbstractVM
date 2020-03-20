#ifndef TOKEN_HPP
#define TOKEN_HPP

# include <iostream>
# include <string>

enum eTokenType {Command, Value, Type, Comment};

class Token
{
private:
	std::string _value;
	eTokenType _type;

public:
	Token();
	Token(std::string const &s, eTokenType const &type);;
	~Token();

	Token(Token const &oth);
	Token &operator=(Token const &oth);

	std::string getValue() const;
	eTokenType getType() const;

	void setValue(std::string const &s);
	void setType(eTokenType const  &type);
};

#endif
