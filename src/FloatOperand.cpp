#include "FloatOperand.h"
#include "OperandFactory.h"
#include "math.h"

FloatOperand::FloatOperand(std::string value) {
	_precision = 7;
	_type = FLOAT;
	_value = std::stoi(value);
}

int FloatOperand::getPrecision() const {
	return (_precision);
}

eOperandType FloatOperand::getType() const {
	return (_type);
}

float	FloatOperand::getValue() const {
	return (_value);
}

std::string const &FloatOperand::toString() const {
	return (std::to_string(_value));
}

IOperand const *FloatOperand::operator+(IOperand const &rhs) const {
	OperandFactory create;
	eOperandType type = rhs.getType() >= _type ? rhs.getType() : _type;

	return (create.createOperand(type, std::to_string(_value + stof(rhs.toString()))));
}

IOperand const *FloatOperand::operator-(IOperand const &rhs) const {
	OperandFactory create;
	eOperandType type = rhs.getType() >= _type ? rhs.getType() : _type;

	return (create.createOperand(type, std::to_string(_value - stof(rhs.toString()))));
}

IOperand const *FloatOperand::operator*(IOperand const &rhs) const {
	OperandFactory create;
	eOperandType type = rhs.getType() >= _type ? rhs.getType() : _type;

	return (create.createOperand(type, std::to_string(_value * stof(rhs.toString()))));
}

IOperand const *FloatOperand::operator/(IOperand const &rhs) const {
	OperandFactory create;
	eOperandType type = rhs.getType() >= _type ? rhs.getType() : _type;

	return (create.createOperand(type, std::to_string(_value / stof(rhs.toString()))));
}

IOperand const *FloatOperand::operator%(IOperand const &rhs) const {
	OperandFactory create;
	eOperandType type = rhs.getType() >= _type ? rhs.getType() : _type;

	return (create.createOperand(type, std::to_string(fmodf(_value, stof(rhs.toString())))));
}
