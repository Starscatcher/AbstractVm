#include "../inc/Int16operand.h"
#include "../inc/OperandFactory.h"

Int16operand::Int16operand(std::string value) {
	_precision = 0;
	_type = INT16;
	if (stold(value) < std::numeric_limits<int16_t>::lowest())
		throw Int16Exception("Underflow int16");
	else if (stold(value) > std::numeric_limits<int16_t>::max())
		throw Int16Exception("Overflow int16");
	_value = std::stoi(value);
	_stringValue = std::to_string(_value);
}

Int16operand::~Int16operand() {}

Int16operand      &Int16operand::operator=(Int16operand const &src) {
	if (this == &src)
		return (*this);
	_value = src._value;
	_precision = src._precision;
	_stringValue = src._stringValue;
	_type = src._type;
	return (*this);
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

	return (create.createOperand(type, std::to_string(_value + stod(rhs.toString()))));
}

IOperand const *Int16operand::operator-(IOperand const &rhs) const {
	OperandFactory create;
	eOperandType type = rhs.getType() >= _type ? rhs.getType() : _type;

	return (create.createOperand(type, std::to_string(_value - stod(rhs.toString()))));
}

IOperand const *Int16operand::operator*(IOperand const &rhs) const {
	OperandFactory create;
	eOperandType type = rhs.getType() >= _type ? rhs.getType() : _type;

	return (create.createOperand(type, std::to_string(_value * stod(rhs.toString()))));
}

IOperand const *Int16operand::operator/(IOperand const &rhs) const {
	OperandFactory create;
	eOperandType type = rhs.getType() >= _type ? rhs.getType() : _type;

	return (create.createOperand(type, std::to_string(_value / stod(rhs.toString()))));
}

IOperand const *Int16operand::operator%(IOperand const &rhs) const {
	OperandFactory create;
	eOperandType type = rhs.getType() >= _type ? rhs.getType() : _type;

	return (create.createOperand(type, std::to_string(fmod(_value, stod(rhs.toString())))));
}

IOperand const *Int16operand::operator&(IOperand const &rhs) const {
	OperandFactory	create;
	eOperandType	type = rhs.getType() > _type ? rhs.getType() : _type;

	if (_type > INT32 || rhs.getType() > INT32)
		throw Int16Exception("Binary operation can be only with INT8 INT16 INT32");
	return (create.createOperand(type, std::to_string(_value & stoi(rhs.toString()))));
}

IOperand const * Int16operand::operator|(IOperand const &rhs) const {
	OperandFactory	create;
	eOperandType	type = rhs.getType() > _type ? rhs.getType() : _type;

	if (_type > INT32 || rhs.getType() > INT32)
		throw Int16Exception("Binary operation can be only with INT8 INT16 INT32");
	return (create.createOperand(type, std::to_string(_value | stoi(rhs.toString()))));
}

IOperand const * Int16operand::operator^(IOperand const &rhs) const {
	OperandFactory	create;
	eOperandType	type = rhs.getType() > _type ? rhs.getType() : _type;

	if (_type > INT32 || rhs.getType() > INT32)
		throw Int16Exception("Binary operation can be only with INT8 INT16 INT32");
	return (create.createOperand(type, std::to_string(_value ^ stoi(rhs.toString()))));
}


Int16operand::Int16Exception::Int16Exception() {
	_message = nullptr;
}

Int16operand::Int16Exception::Int16Exception(std::string message) {
	_message = message;
}

Int16operand::Int16Exception::~Int16Exception() noexcept {}

Int16operand::Int16Exception::Int16Exception(Int16Exception const &src) {
	_message = src._message;
}

const char *Int16operand::Int16Exception::what() const noexcept {
	return (_message.c_str());
}

Int16operand::Int16Exception &Int16operand::Int16Exception::operator=(const Int16operand::Int16Exception &src) {
	_message = src._message;
	return (*this);
}