#include "FactoryClass.hpp"
#include "Operand.hpp"
#include "Exceptions.hpp"
#include <sstream>
#include <float.h>

IOperand const *(FactoryClass::*(FactoryClass::_fnptr[eOperandType::MaxTypes]))(std::string const &) const =
{
	&FactoryClass::createInt8,
	&FactoryClass::createInt16,
	&FactoryClass::createInt32,
	&FactoryClass::createFloat,
	&FactoryClass::createDouble
};

IOperand const *FactoryClass::createOperand(eOperandType type, std::string const &val) const {

	return (this->*_fnptr[type])(val);
}

IOperand const *FactoryClass::createInt8(std::string const &val) const {
	long double num = std::stold(val);

	if (num > INT8_MAX || num < INT8_MIN)
		throw Exceptions::OverflowException();
	else
		return new Operand<int8_t>(static_cast<int8_t>(num), eOperandType::Int8);
}

IOperand const *FactoryClass::createInt16(std::string const &val) const {
	long double num = std::stold(val);

	if (num < INT16_MIN || num > INT16_MAX)
		throw Exceptions::OverflowException();
	else
		return new Operand<int16_t>(static_cast<int16_t>(num), eOperandType::Int16);
}

IOperand const *FactoryClass::createInt32(std::string const &val) const {
	long double num = std::stold(val);

	if (num < INT32_MIN || num > INT32_MAX)
		throw Exceptions::OverflowException();
	else
		return new Operand<int32_t>(static_cast<int32_t>(num), eOperandType::Int32);
}

IOperand const *FactoryClass::createFloat(std::string const &val) const {
	long double num = std::stold(val);

	if (num < -FLT_MAX || num > FLT_MAX)
		throw Exceptions::OverflowException();
	else if (num > 0 && num < FLT_MIN)
		throw Exceptions::UnderflowException();
	else
		return new Operand<float>(static_cast<float>(num), eOperandType::Float);
}

IOperand const *FactoryClass::createDouble(std::string const &val) const {
	long double num = std::stold(val);

	if (num < -DBL_MAX || num > DBL_MAX)
		throw Exceptions::OverflowException();
	else if (num > 0 && num < DBL_MIN)
		throw Exceptions::UnderflowException();
	else
		return new Operand<double>(static_cast<double>(num), eOperandType::Double);
}