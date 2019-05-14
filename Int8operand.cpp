#include "Int8operand.h"
#include "OperandFactory.h"

Int8operand::Int8operand(std::string value) {
	_precision = 0;
	_type = INT8;
	if (std::stod(value) < INT8_MIN)
		throw Int8Exception("Underflow INT8 value");
	else if (std::stod(value) > INT8_MAX)
		throw Int8Exception("Overflow value");
	_value = std::stoi(value);
	_stringValue = value;
}

int Int8operand::getPrecision() const {
	return (_precision);
}

eOperandType Int8operand::getType() const {
	return (_type);
}

std::string const &Int8operand::toString() const {
	return (_stringValue);
}

IOperand const *Int8operand::operator+(IOperand const &rhs) const {
	OperandFactory create;
	eOperandType type = rhs.getType() >= _type ? rhs.getType() : _type;

	return (create.createOperand(type, std::to_string(_value + stoi(rhs.toString()))));
}

IOperand const *Int8operand::operator-(IOperand const &rhs) const {
	OperandFactory create;
	eOperandType type = rhs.getType() >= _type ? rhs.getType() : _type;

	return (create.createOperand(type, std::to_string(_value - stoi(rhs.toString()))));
}

IOperand const *Int8operand::operator*(IOperand const &rhs) const {
	OperandFactory create;
	eOperandType type = rhs.getType() >= _type ? rhs.getType() : _type;

	return (create.createOperand(type, std::to_string(_value * stoi(rhs.toString()))));
}

IOperand const *Int8operand::operator/(IOperand const &rhs) const {
	OperandFactory create;
	eOperandType type = rhs.getType() >= _type ? rhs.getType() : _type;

	return (create.createOperand(type, std::to_string(_value / stoi(rhs.toString()))));
}

IOperand const *Int8operand::operator%(IOperand const &rhs) const {
	OperandFactory create;
	eOperandType type = rhs.getType() >= _type ? rhs.getType() : _type;

	return (create.createOperand(type, std::to_string(_value % stoi(rhs.toString()))));
}
