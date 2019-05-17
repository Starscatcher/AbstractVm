#include <cfloat>
#include "../inc/FloatOperand.h"
#include "../inc/OperandFactory.h"

FloatOperand::FloatOperand(std::string value) {
	_precision = 7;
	_type = FLOAT;

	if (stold(value) < std::numeric_limits<float>::lowest())
		throw FloatException("Underflow float");
	else if (stold(value) > std::numeric_limits<float>::max())
		throw FloatException("Overflow float");
	_value = stof(value);
	_stringValue = std::to_string(_value);
}

FloatOperand::~FloatOperand() {}

FloatOperand      &FloatOperand::operator=(FloatOperand const &src) {
	if (this == &src)
		return (*this);
	_value = src._value;
	_precision = src._precision;
	_stringValue = src._stringValue;
	_type = src._type;
	return (*this);
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

	return (create.createOperand(type, std::to_string(_value + stod(rhs.toString()))));
}

IOperand const *FloatOperand::operator-(IOperand const &rhs) const {
	OperandFactory create;
	eOperandType type = rhs.getType() >= _type ? rhs.getType() : _type;

	return (create.createOperand(type, std::to_string(_value - stod(rhs.toString()))));
}

IOperand const *FloatOperand::operator*(IOperand const &rhs) const {
	OperandFactory create;
	eOperandType type = rhs.getType() >= _type ? rhs.getType() : _type;

	return (create.createOperand(type, std::to_string(_value * stod(rhs.toString()))));
}

IOperand const *FloatOperand::operator/(IOperand const &rhs) const {
	OperandFactory create;
	eOperandType type = rhs.getType() >= _type ? rhs.getType() : _type;

	return (create.createOperand(type, std::to_string(_value / stod(rhs.toString()))));
}

IOperand const *FloatOperand::operator%(IOperand const &rhs) const {
	OperandFactory create;
	eOperandType type = rhs.getType() >= _type ? rhs.getType() : _type;

	return (create.createOperand(type, std::to_string(fmod(_value, stod(rhs.toString())))));
}

IOperand const *FloatOperand::operator&(IOperand const &rhs) const {
	rhs.getType();
	throw FloatOperand("Binary operation can be only with INT8 INT16 INT32");
}

IOperand const *FloatOperand::operator|(IOperand const &rhs) const {
	rhs.getType();
	throw FloatOperand("Binary operation can be only with INT8 INT16 INT32");
}

IOperand const *FloatOperand::operator^(IOperand const &rhs) const {
	rhs.getType();
	throw FloatOperand("Binary operation can be only with INT8 INT16 INT32");
}


FloatOperand::FloatException::FloatException() {
	_message = nullptr;
}

FloatOperand::FloatException::FloatException(std::string message) {
	_message = message;
}

FloatOperand::FloatException::~FloatException() noexcept {}

FloatOperand::FloatException::FloatException(FloatException const &src) {
	_message = src._message;
}

const char *FloatOperand::FloatException::what() const noexcept {
	return (_message.c_str());
}

FloatOperand::FloatException &FloatOperand::FloatException::operator=(const FloatOperand::FloatException &src) {
	_message = src._message;
	return (*this);
}

