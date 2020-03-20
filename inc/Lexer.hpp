#ifndef LEXER_HPP
#define LEXER_HPP

#include "Token.hpp"
#include <regex>

#define RGX_COMMENT "^;.*"
#define RGX_NUM "[(](([-]?|[+]?)([\\d]+|[\\d]+.[\\d]+))[)]"
#define RGX_TYPE "(int8|int16|int32|float|double)"
#define RGX_CMND "(push|assert|pop|dump|print|add|sub|mul|div|mod|exit|less|more)"

#define RGX_SYNT_CMND "[\\s]*"\
	"(pop|dump|add|sub|mul|div|mod|print|exit)"\
	"[\\s]*"\
	"(;.*|[]{0,0})$"

#define RGX_SYNT_CMND_WITH_VAL "[\\s]*"\
	"(push|assert|less|more)"\
	"[\\s]+"\
	RGX_TYPE\
	RGX_NUM\
	"[\\s]*"\
	"(;.*|[]{0,0})$"

class Lexer
{
private:
	std::smatch _match;

public:
	Lexer() = default;
	~Lexer() = default;

	Lexer(Lexer const &oth) = default;
	Lexer &operator=(Lexer const &oth) = default;

	bool isComment(std::string const &s);
	void checkCmnd(std::string const &s);
	void checkCmndWithVal(std::string const &s);
	Token setCmnd(std::string const &s);
	Token setType(std::string const &s);
	Token setVal(std::string const &s);
};

#endif
