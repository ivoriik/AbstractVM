#ifndef OPERAND_HPP
#define OPERAND_HPP

#include "IOperand.hpp"
#include "FactoryClass.hpp"
#include "Exceptions.hpp"
#include <cmath>
#include <iomanip>
#include <sstream>
#include <limits>

template<typename T>
class Operand: public IOperand
{
private:
	T					_value;
	eOperandType		_type;
	int32_t				_precision;
	std::string		 	_str;
public:
	Operand<T>(T const &value, eOperandType const &type):
			_value(value), _type(type), _precision(static_cast<int>(_type)), _str(getString()) {

	};
	virtual ~Operand<T>() {};
	Operand<T>(Operand<T> const &oth):
	        _value(oth._value), _type(oth._type), _precision(oth._precision), _str(oth._str) {};
	Operand<T> &operator=(Operand<T> const &oth) {
		if (this != &oth) {
			_value = oth._value;
			_type = oth._type;
			_str = oth._str;
		}
		return *this;
	};

	int getPrecision() const {
		return this->_precision;
	};
	
	eOperandType getType() const {
		return _type;
	};

	std::string const &toString() const {
		return _str;
	};

	std::string getString() {
		if (_type < eOperandType::Float)
			return(std::to_string(_value));
		else {
			std::stringstream s(std::stringstream::out);
			s << std::setprecision(std::numeric_limits<T>::digits10 + 1) << _value;
			return s.str();
		}
	}

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
		long long rhsVal = std::stoll(rhs.toString());

		if (getType() > eOperandType::Int32 || rhs.getType() > eOperandType::Int32)
			throw Exceptions::NonIntModException();

		if (rhsVal == 0)
			throw Exceptions::DivByZeroException();

		eOperandType newType = HIGHER_PRECISION_TYPE(*this, rhs);

		return (_factory.createOperand(newType, std::to_string(fmod(static_cast<long long>(_value),
				rhsVal))));
}

// ------------------------- Comparison Operators -------------------------

template<typename T>
bool	Operand<T>::operator==(IOperand const &rhs) const {

		return rhs.toString() == this->toString() &&
				this->getType() == rhs.getType();
}

template<typename T>
bool	Operand<T>::operator>(IOperand const &rhs) const {
		long double rhsVal = std::stold(rhs.toString());

		return static_cast<long double>(this->_value) > rhsVal &&
			   this->getType() == rhs.getType();
}

template<typename T>
bool	Operand<T>::operator<(IOperand const &rhs) const {
		long double rhsVal = std::stold(rhs.toString());

		return static_cast<long double>(this->_value) < rhsVal &&
			   this->getType() == rhs.getType();
}

#endif