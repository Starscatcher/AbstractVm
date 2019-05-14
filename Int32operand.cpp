#include "Int32operand.h"
#include "OperandFactory.h"

Int32operand::Int32operand(std::string value) {
	_precision = 0;
	_type = INT32;
	if (std::stod(value) < INT32_MIN)
		throw Int32Exception("Underflow value");
	else if (std::stod(value) > INT32_MAX)
		throw Int32Exception("Overflow value");
	_value = std::stoi(value);
	_stringValue = value;
}

int Int32operand::getPrecision() const {
	return (_precision);
}

eOperandType Int32operand::getType() const {
	return (_type);
}

std::string const&Int32operand::toString() const {
	return (_stringValue);
}

IOperand const *Int32operand::operator+(IOperand const &rhs) const {
	OperandFactory create;
	eOperandType type = rhs.getType() >= _type ? rhs.getType() : _type;

	return (create.createOperand(type, std::to_string(_value + stoi(rhs.toString()))));
}

IOperand const *Int32operand::operator-(IOperand const &rhs) const {
	OperandFactory create;
	eOperandType type = rhs.getType() >= _type ? rhs.getType() : _type;

	return (create.createOperand(type, std::to_string(_value - stoi(rhs.toString()))));
}

IOperand const *Int32operand::operator*(IOperand const &rhs) const {
	OperandFactory create;
	eOperandType type = rhs.getType() >= _type ? rhs.getType() : _type;

	return (create.createOperand(type, std::to_string(_value * stoi(rhs.toString()))));
}

IOperand const *Int32operand::operator/(IOperand const &rhs) const {
	OperandFactory create;
	eOperandType type = rhs.getType() >= _type ? rhs.getType() : _type;

	return (create.createOperand(type, std::to_string(_value / stoi(rhs.toString()))));
}

IOperand const *Int32operand::operator%(IOperand const &rhs) const {
	OperandFactory create;
	eOperandType type = rhs.getType() >= _type ? rhs.getType() : _type;

	return (create.createOperand(type, std::to_string(_value % stoi(rhs.toString()))));
}
