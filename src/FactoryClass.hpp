#ifndef FACTORYCLASS_HPP
#define FACTORYCLASS_HPP

#include "IOperand.hpp"
#include <vector>

class FactoryClass
{
private:
	// typedef IOperand const * (FactoryClass::*fnPtrCreateOp)(std::string const &s) const;
	// static const fnPtrCreateOp _fnptr[MaxTypes];
	static IOperand const *(FactoryClass::*_fnptr[MaxTypes])(std::string const &) const;

	IOperand const *createInt8  (std::string const &value) const;
	IOperand const *createInt16 (std::string const &value) const;
	IOperand const *createInt32 (std::string const &value) const;
	IOperand const *createFloat (std::string const &value) const;
	IOperand const *createDouble(std::string const &value) const;
public:
	FactoryClass();
	virtual ~FactoryClass();
	FactoryClass(FactoryClass const &oth);
	FactoryClass &operator=(FactoryClass const &oth);

	IOperand const *createOperand(eOperandType type, std::string const &value) const;

};

static const FactoryClass _factory;

#endif