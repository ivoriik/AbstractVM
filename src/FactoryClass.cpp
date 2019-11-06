#include "FactoryClass.hpp"
#include "Operand.hpp"
#include "Exceptions.hpp"

FactoryClass::FactoryClass() {
	// _fnptr = fnptr_t(MaxTypes);
	_fnptr[Int8] = &FactoryClass::createInt8;
	_fnptr[Int16] = &FactoryClass::createInt16;
	_fnptr[Int32] = &FactoryClass::createInt32;
	_fnptr[Float] = &FactoryClass::createFloat;
	_fnptr[Double] = &FactoryClass::createDouble;
}
FactoryClass::~FactoryClass() {}
FactoryClass::FactoryClass(FactoryClass const &oth) {
	*this = oth;
}

FactoryClass &FactoryClass::operator=(FactoryClass const &oth) {
	if (this != &oth)
		*this = oth;
	return *this;
}

IOperand const *FactoryClass::createOperand(eOperandType type, std::string const &val) const {
	/*Maybe I should add check for valid TYPE val*/
	IOperand *op;

	try {
		op = (this->*_fnptr[type])(val);
	} catch (const ConversionError &e) {
		std::cerr << e.what() << std::endl;
	} catch (const OverflowError &e) {
		std::cerr << e.what() << std::endl;
	} catch (const UnderflovError &e) {
		std::cerr << e.what() << std::endl;
	}
	return op;
}

IOperand const *FactoryClass::createInt8(std::string const &val) const {
	int64_t num;

	std::istringstream ss(val);
	ss >> num;
	if (ss.fail())
		throw Exceptions::ConversionError();
	if (num > INT8_MAX || num < INT8_MIN)
		throw Exceptions::OverflowError("int8");
	else
		return new Operand<int8_t>(static_cast<int8_t>(num), Int8, std::string(val));
}

IOperand const *FactoryClass::createInt16(std::string const &val) const {
	int64_t num;

	std::istringstream ss(val);
	ss >> num;
	if (ss.fail())
		throw Exceptions::ConversionError();
	if (num < INT16_MIN || num > INT16_MAX)
		throw Exceptions::OverflowError("int16");
	else
		return new Operand<int16_t>(static_cast<int16_t>(num), Int16, std::string(val));
}

IOperand const *FactoryClass::createInt32(std::string const &val) const {
	int64_t num;

	std::istringstream ss(val);
	ss >> num;
	if (ss.fail())
		throw Exceptions::ConversionError();
	if (num < INT32_MIN || num > INT32_MAX)
		throw Exceptions::OverflowError("int32");
	else
		return new Operand<int32_t>(static_cast<int32_t>(num), Int32, std::string(val));
}

IOperand const *FactoryClass::createFloat(std::string const &val) const {
	long double num;

	std::istringstream ss(val);
	ss >> num;
	if (ss.fail())
		throw Exceptions::ConversionError();
	if (num < -FLT_MAX || num > FLT_MAX)
		throw Exceptions::OverflowError("float");
	else if (num > 0 && num < FLT_MIN)
		throw Exceptions::UnderflowError("float");
	else
		return new Operand<float>(static_cast<float>(num), Float, std::string(val));
}

IOperand const *FactoryClass::createDouble(std::string const &val) const {
	long double num;

	std::istringstream ss(val);
	ss >> num;
	if (ss.fail())
		throw Exceptions::ConversionError();
	if (num < -DBL_MAX || num > DBL_MAX)
		throw Exceptions::OverflowError("double");
	else if (num > 0 && num < DBL_MIN)
		throw Exceptions::UnderflowError("double");
	else
		return new Operand<double>(static_cast<double>(num), Double, std::string(val));
}