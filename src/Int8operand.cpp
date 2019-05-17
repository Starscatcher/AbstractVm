#include "../inc/Int8operand.h"
#include "../inc/OperandFactory.h"

Int8operand::Int8operand(std::string value) {
	_precision = 0;
	_type = INT8;
	if (stold(value) < std::numeric_limits<int8_t>::lowest())
		throw Int8Exception("Underflow int8");
	else if (stold(value) > std::numeric_limits<int8_t>::max())
		throw Int8Exception("Overflow int8");
	_value = std::stoi(value);
	_stringValue = std::to_string(_value);
}

Int8operand::~Int8operand() {}

Int8operand      &Int8operand::operator=(Int8operand const &src) {
	if (this == &src)
		return (*this);
	_value = src._value;
	_precision = src._precision;
	_stringValue = src._stringValue;
	_type = src._type;
	return (*this);
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

	return (create.createOperand(type, std::to_string(_value + stod(rhs.toString()))));
}

IOperand const *Int8operand::operator-(IOperand const &rhs) const {
	OperandFactory create;
	eOperandType type = rhs.getType() >= _type ? rhs.getType() : _type;

	return (create.createOperand(type, std::to_string(_value - stod(rhs.toString()))));
}

IOperand const *Int8operand::operator*(IOperand const &rhs) const {
	OperandFactory create;
	eOperandType type = rhs.getType() >= _type ? rhs.getType() : _type;

	return (create.createOperand(type, std::to_string(_value * stod(rhs.toString()))));
}

IOperand const *Int8operand::operator/(IOperand const &rhs) const {
	OperandFactory create;
	eOperandType type = rhs.getType() >= _type ? rhs.getType() : _type;

	return (create.createOperand(type, std::to_string(_value / stod(rhs.toString()))));
}

IOperand const *Int8operand::operator%(IOperand const &rhs) const {
	OperandFactory create;
	eOperandType type = rhs.getType() >= _type ? rhs.getType() : _type;

	return (create.createOperand(type, std::to_string(fmod(_value, stod(rhs.toString())))));
}

IOperand const *Int8operand::operator&(IOperand const &rhs) const {
	OperandFactory	create;
	eOperandType	type = rhs.getType() > _type ? rhs.getType() : _type;

	if (_type > INT32 || rhs.getType() > INT32)
		throw Int8Exception("Binary operation can be only with INT8 INT16 INT32");
	return (create.createOperand(type, std::to_string(_value & stoi(rhs.toString()))));
}

IOperand const * Int8operand::operator|(IOperand const &rhs) const {
	OperandFactory	create;
	eOperandType	type = rhs.getType() > _type ? rhs.getType() : _type;

	if (_type > INT32 || rhs.getType() > INT32)
		throw Int8Exception("Binary operation can be only with INT8 INT16 INT32");
	return (create.createOperand(type, std::to_string(_value | stoi(rhs.toString()))));
}

IOperand const * Int8operand::operator^(IOperand const &rhs) const {
	OperandFactory	create;
	eOperandType	type = rhs.getType() > _type ? rhs.getType() : _type;

	if (_type > INT32 || rhs.getType() > INT32)
		throw Int8Exception("Binary operation can be only with INT8 INT16 INT32");
	return (create.createOperand(type, std::to_string(_value ^ stoi(rhs.toString()))));
}


Int8operand::Int8Exception::Int8Exception() {
	_message = nullptr;
}

Int8operand::Int8Exception::Int8Exception(std::string message) {
	_message = message;
}

Int8operand::Int8Exception::~Int8Exception() noexcept {}

Int8operand::Int8Exception::Int8Exception(Int8Exception const &src) {
	_message = src._message;
}

const char *Int8operand::Int8Exception::what() const noexcept {
	return (_message.c_str());
}

Int8operand::Int8Exception &Int8operand::Int8Exception::operator=(const Int8operand::Int8Exception &src) {
	_message = src._message;
	return (*this);
}