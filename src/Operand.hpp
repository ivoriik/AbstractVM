#ifndef OPERAND_HPP
#define OPERAND_HPP

#include "IOperand.hpp"
#include "FactoryClass.hpp"
#include "Exceptions.hpp"
#include <cmath>


template<typename T>
class Operand : public IOperand
{
private:
	T				_value;
	eOperandType	_type;
	std::string		_str;
	int32_t			_precision;
public:
	Operand<T>(T const &value, eOperandType const &type, std::string const &str):
			_value(value), _type(type), _str(str) {};
	virtual ~Operand<T>();
	Operand<T>(Operand<T> const &oth) {
		*this = oth;
	};
	Operand<T> &operator=(Operand<T> const &oth) {
		if (this != &oth)
			*this = oth;
	};

	int getPrecision(void) const {
		int precision = 0;

		if (_type == Float)
			precision = 7;
		else if (_type == Double)
			precision = 14;
		return precision;
	};
	
	eOperandType getType(void) const {
		return _type;
	};

	std::string const &toString(void) const {
		return _str;
	};

	IOperand const *baseOperators(IOperand const &rhs, char const newType) const;

	IOperand const *operator+(IOperand const &rhs) const;
	IOperand const *operator-(IOperand const &rhs) const;
	IOperand const *operator*(IOperand const &rhs) const;
	IOperand const *operator/(IOperand const &rhs) const;
	IOperand const *operator%(IOperand const &rhs) const;
	bool operator==(IOperand const &rhs) const;
	bool operator>(IOperand const &rhs) const;
	bool operator<(IOperand const &rhs) const;
};

#define HIGHER_PRECISION_TYPE(a, b) ((a).getPrecision() >= (b).getPrecision() ? (a).getType() : (b).getType())
template<typename T>
IOperand const *Operand<T>::operator+(IOperand const &rhs) const {
		long double rhsVal = std::stold(rhs.toString());
		eOperandType newType = HIGHER_PRECISION_TYPE(*this, rhs);

		return (_factory.createOperand(newType, std::to_string(static_cast<long double>(_value)
				+ rhsVal)));
}

template<typename T>
IOperand const *Operand<T>::operator-(IOperand const &rhs) const {
		long double rhsVal = std::stold(rhs.toString());
		eOperandType newType = HIGHER_PRECISION_TYPE(*this, rhs);

		return (_factory.createOperand(newType, std::to_string(static_cast<long double>(_value)
				- rhsVal)));
}

template<typename T>
IOperand const *Operand<T>::operator*(IOperand const &rhs) const {
		long double rhsVal = std::stold(rhs.toString());
		eOperandType newType = HIGHER_PRECISION_TYPE(*this, rhs);

		return (_factory.createOperand(newType, std::to_string(static_cast<long double>(_value)
				* rhsVal)));
}

template<typename T>
IOperand const *Operand<T>::operator/(IOperand const &rhs) const {
		long double rhsVal = std::stold(rhs.toString());
		if (rhsVal == 0)
			throw Exceptions::DivByZeroException();

		eOperandType newType = HIGHER_PRECISION_TYPE(*this, rhs);

		return (_factory.createOperand(newType, std::to_string(static_cast<long double>(_value)
				/ rhsVal)));
}

template<typename T>
IOperand const *Operand<T>::operator%(IOperand const &rhs) const {
		long double rhsVal = std::stold(rhs.toString());
		if (rhsVal == 0)
			throw Exceptions::DivByZeroException();

		eOperandType newType = HIGHER_PRECISION_TYPE(*this, rhs);

		return (_factory.createOperand(newType, std::to_string(fmod(static_cast<long double>(_value),
				rhsVal))));
}

// ------------------------- Comparison Operators -------------------------
// CHECK + ADD NEW

template<typename T>
bool	Operand<T>::operator==(IOperand const &rhs) const {
		long double rhsVal = std::stold(rhs.toString());

		return static_cast<long double>(_value) == rhsVal;
}

template<typename T>
bool	Operand<T>::operator>(IOperand const &rhs) const {
		long double rhsVal = std::stold(rhs.toString());

		return static_cast<long double>(_value) > rhsVal;
}

template<typename T>
bool	Operand<T>::operator<(IOperand const &rhs) const {
		long double rhsVal = std::stold(rhs.toString());

		return static_cast<long double>(_value) < rhsVal;
}

#endif