#include "DoubleOperand.h"
#include "OperandFactory.h"
#include "math.h"

DoubleOperand::DoubleOperand(std::string value) {
	_precision = 15;
	_type = DOUBLE;
	_value = std::stoi(value);
}

int DoubleOperand::getPrecision() const {
	return (_precision);
}

eOperandType DoubleOperand::getType() const {
	return (_type);
}

double	DoubleOperand::getValue() const {
	return (_value);
}

std::string const &DoubleOperand::toString() const {
	return (std::to_string(_value));
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
