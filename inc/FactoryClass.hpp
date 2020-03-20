#ifndef FACTORYCLASS_HPP
#define FACTORYCLASS_HPP

#include "IOperand.hpp"

class FactoryClass
{
private:
	static IOperand const *(FactoryClass::*_fnptr[eOperandType::MaxTypes])(std::string const &) const;

	IOperand const *createInt8  (std::string const &value) const;
	IOperand const *createInt16 (std::string const &value) const;
	IOperand const *createInt32 (std::string const &value) const;
	IOperand const *createFloat (std::string const &value) const;
	IOperand const *createDouble(std::string const &value) const;
public:
	FactoryClass() = default;
	virtual ~FactoryClass() = default;
	FactoryClass(FactoryClass const &oth) = default;
	FactoryClass &operator=(FactoryClass const &oth) = default;

	IOperand const *createOperand(eOperandType type, std::string const &value) const;

};

static const FactoryClass _factory;

#endif