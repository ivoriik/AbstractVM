#ifndef FACTORY_CLASS_HPP
#define FEACTORY_CLASS_HPP

#include "IOperand.hpp"
#include <vector>

class FactoryClass
{
private:
	typedef IOperand const * (FactoryClass::*fnptr_t)(std::string const &) const;
	static const fnptr_t _fnptr[MaxOperandTypes];
	// typedef std::vector<IOperand const *(FactoryClass::*)(std::string const &value) const> fnptr_t;
	// fnptr_t _fnptr;

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

static const FactoryClass factory;

#endif