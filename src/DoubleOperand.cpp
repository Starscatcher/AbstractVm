#include <cfloat>
#include "../inc/DoubleOperand.h"
#include "../inc/OperandFactory.h"
#include "math.h"

DoubleOperand::DoubleOperand(std::string value) {
	_precision = 15;
	_type = DOUBLE;
	if (stold(value) < std::numeric_limits<double>::lowest())
		throw DoubleException("Underflow double");
	else if (stold(value) > std::numeric_limits<double>::max())
		throw DoubleException("Overflow double");
	_value = stod(value);
	_stringValue = std::to_string(_value);
}

DoubleOperand::~DoubleOperand() {
}

DoubleOperand      &DoubleOperand::operator=(DoubleOperand const &src) {
	if (this == &src)
		return (*this);
	_value = src._value;
	_precision = src._precision;
	_stringValue = src._stringValue;
	_type = src._type;
	return (*this);
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

	return (create.createOperand(type, std::to_string(fmod(_value, stod(rhs.toString())))));
}

IOperand const *DoubleOperand::operator&(IOperand const &rhs) const {
	rhs.getType();
	throw DoubleOperand("Binary operation can be only with INT8 INT16 INT32");
}

IOperand const *DoubleOperand::operator|(IOperand const &rhs) const {
	rhs.getType();
	throw DoubleOperand("Binary operation can be only with INT8 INT16 INT32");
}

IOperand const *DoubleOperand::operator^(IOperand const &rhs) const {
	rhs.getType();
	throw DoubleOperand("Binary operation can be only with INT8 INT16 INT32");
}


DoubleOperand::DoubleException::DoubleException() {
	_message = nullptr;
}

DoubleOperand::DoubleException::DoubleException(std::string message) {
	_message = message;
}

DoubleOperand::DoubleException::~DoubleException() noexcept {}

DoubleOperand::DoubleException::DoubleException(DoubleException const &src) {
	_message = src._message;
}

const char *DoubleOperand::DoubleException::what() const noexcept {
	return (_message.c_str());
}

DoubleOperand::DoubleException &DoubleOperand::DoubleException::operator=(const DoubleOperand::DoubleException &src) {
	_message = src._message;
	return (*this);
}