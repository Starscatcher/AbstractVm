#include <cfloat>
#include "DoubleOperand.h"
#include "OperandFactory.h"
#include "math.h"

DoubleOperand::DoubleOperand(std::string value) {
	_precision = 15;
	_type = DOUBLE;
	if (std::stold(value) < DBL_MIN)
		throw DoubleException("Underflow value");
	else if (std::stold(value) > DBL_MAX)
		throw DoubleException("Overflow value");
	_value = std::stod(value);
	_stringValue = value;
}

int DoubleOperand::getPrecision() const {
	return (_precision);
}

eOperandType DoubleOperand::getType() const {
	return (_type);
}

std::string const &DoubleOperand::toString() const {
	return (_stringValue);
}

IOperand const *DoubleOperand::operator+(IOperand const &rhs) const {
	OperandFactory create;
	eOperandType type = rhs.getType() >= _type ? rhs.getType() : _type;

	return (create.createOperand(type, std::to_string(_value + stod(rhs.toString()))));
}

IOperand const *DoubleOperand::operator-(IOperand const &rhs) const {
	OperandFactory create;
	eOperandType type = rhs.getType() >= _type ? rhs.getType() : _type;

	return (create.createOperand(type, std::to_string(_value - stod(rhs.toString()))));
}

IOperand const *DoubleOperand::operator*(IOperand const &rhs) const {
	OperandFactory create;
	eOperandType type = rhs.getType() >= _type ? rhs.getType() : _type;

	return (create.createOperand(type, std::to_string(_value * stod(rhs.toString()))));
}

IOperand const *DoubleOperand::operator/(IOperand const &rhs) const {
	OperandFactory create;
	eOperandType type = rhs.getType() >= _type ? rhs.getType() : _type;

	return (create.createOperand(type, std::to_string(_value / stod(rhs.toString()))));
}

IOperand const *DoubleOperand::operator%(IOperand const &rhs) const {
	OperandFactory create;
	eOperandType type = rhs.getType() >= _type ? rhs.getType() : _type;

	return (create.createOperand(type, std::to_string(fmod(_value, stof(rhs.toString())))));
}
