#include "Int16operand.h"
#include "OperandFactory.h"

Int16operand::Int16operand(std::string value) {
	_precision = 0;
	_type = INT16;
	if (std::stod(value) < INT16_MIN)
		throw Int16Exception("Underflow value");
	else if (std::stod(value) > INT16_MAX)
		throw Int16Exception("Overflow value");
	_value = std::stoi(value);
	_stringValue = value;
}

int Int16operand::getPrecision() const {
	return (_precision);
}

eOperandType Int16operand::getType() const {
	return (_type);
}

std::string const &Int16operand::toString() const {
	return (_stringValue);
}

IOperand const *Int16operand::operator+(IOperand const &rhs) const {
	OperandFactory create;
	eOperandType type = rhs.getType() >= _type ? rhs.getType() : _type;

	return (create.createOperand(type, std::to_string(_value + stoi(rhs.toString()))));
}

IOperand const *Int16operand::operator-(IOperand const &rhs) const {
	OperandFactory create;
	eOperandType type = rhs.getType() >= _type ? rhs.getType() : _type;

	return (create.createOperand(type, std::to_string(_value - stoi(rhs.toString()))));
}

IOperand const *Int16operand::operator*(IOperand const &rhs) const {
	OperandFactory create;
	eOperandType type = rhs.getType() >= _type ? rhs.getType() : _type;

	return (create.createOperand(type, std::to_string(_value * stoi(rhs.toString()))));
}

IOperand const *Int16operand::operator/(IOperand const &rhs) const {
	OperandFactory create;
	eOperandType type = rhs.getType() >= _type ? rhs.getType() : _type;

	return (create.createOperand(type, std::to_string(_value / stoi(rhs.toString()))));
}

IOperand const *Int16operand::operator%(IOperand const &rhs) const {
	OperandFactory create;
	eOperandType type = rhs.getType() >= _type ? rhs.getType() : _type;

	return (create.createOperand(type, std::to_string(_value % stoi(rhs.toString()))));
}
