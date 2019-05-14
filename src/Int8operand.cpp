#include "Int8operand.h"
#include "OperandFactory.h"

Int8operand::Int8operand(std::string value) {
	_precision = 0;
	_type = INT8;
	_value = std::stoi(value);
}

int Int8operand::getPrecision() const {
	return (_precision);
}

eOperandType Int8operand::getType() const {
	return (_type);
}

int8_t	Int8operand::getValue() const {
	return (_value);
}

std::string const &Int8operand::toString() const{
	return (std::to_string(_value));
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
