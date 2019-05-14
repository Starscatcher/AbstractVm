#include <cfloat>
#include "FloatOperand.h"
#include "OperandFactory.h"

FloatOperand::FloatOperand(std::string value) {
	_precision = 7;
	_type = FLOAT;
	if (std::stod(value) < FLT_MIN)
		throw FloatException("Underflow value");
	else if (std::stod(value) > FLT_MAX)
		throw FloatException("Overflow value");
	_value = std::stof(value);
	_stringValue = value;
}

int FloatOperand::getPrecision() const {
	return (_precision);
}

eOperandType FloatOperand::getType() const {
	return (_type);
}

std::string const &FloatOperand::toString() const {
	return (_stringValue);
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

FloatOperand::FloatException::~FloatException() noexcept {}
