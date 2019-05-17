#include "../inc/Int32operand.h"
#include "../inc/OperandFactory.h"

Int32operand::Int32operand(std::string value) {
	_precision = 0;
	_type = INT32;
	if (stold(value) < std::numeric_limits<int32_t>::lowest())
		throw Int32Exception("Underflow int32");
	else if (stold(value) > std::numeric_limits<int32_t>::max())
		throw Int32Exception("Overflow int32");
	_value = std::stoi(value);
	_stringValue = std::to_string(_value);
}

Int32operand::~Int32operand() {}

Int32operand      &Int32operand::operator=(Int32operand const &src) {
	if (this == &src)
		return (*this);
	_value = src._value;
	_precision = src._precision;
	_stringValue = src._stringValue;
	_type = src._type;
	return (*this);
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

	return (create.createOperand(type, std::to_string(_value + stod(rhs.toString()))));
}

IOperand const *Int32operand::operator-(IOperand const &rhs) const {
	OperandFactory create;
	eOperandType type = rhs.getType() >= _type ? rhs.getType() : _type;

	return (create.createOperand(type, std::to_string(_value - stod(rhs.toString()))));
}

IOperand const *Int32operand::operator*(IOperand const &rhs) const {
	OperandFactory create;
	eOperandType type = rhs.getType() >= _type ? rhs.getType() : _type;

	return (create.createOperand(type, std::to_string(_value * stod(rhs.toString()))));
}

IOperand const *Int32operand::operator/(IOperand const &rhs) const {
	OperandFactory create;
	eOperandType type = rhs.getType() >= _type ? rhs.getType() : _type;

	return (create.createOperand(type, std::to_string(_value / stod(rhs.toString()))));
}

IOperand const *Int32operand::operator%(IOperand const &rhs) const {
	OperandFactory create;
	eOperandType type = rhs.getType() >= _type ? rhs.getType() : _type;

	return (create.createOperand(type, std::to_string(fmod(_value, stod(rhs.toString())))));
}

IOperand const *Int32operand::operator&(IOperand const &rhs) const {
	OperandFactory	create;
	eOperandType	type = rhs.getType() > _type ? rhs.getType() : _type;

	return (create.createOperand(type, std::to_string(_value & stoi(rhs.toString()))));
}

IOperand const * Int32operand::operator|(IOperand const &rhs) const {
	OperandFactory	create;
	eOperandType	type = rhs.getType() > _type ? rhs.getType() : _type;

	return (create.createOperand(type, std::to_string(_value | stoi(rhs.toString()))));
}

IOperand const * Int32operand::operator^(IOperand const &rhs) const {
	OperandFactory	create;
	eOperandType	type = rhs.getType() > _type ? rhs.getType() : _type;

	return (create.createOperand(type, std::to_string(_value ^ stoi(rhs.toString()))));
}


Int32operand::Int32Exception::Int32Exception() {
	_message = nullptr;
}

Int32operand::Int32Exception::Int32Exception(std::string message) {
	_message = message;
}

Int32operand::Int32Exception::~Int32Exception() noexcept {}

Int32operand::Int32Exception::Int32Exception(Int32Exception const &src) {
	_message = src._message;
}

const char *Int32operand::Int32Exception::what() const noexcept {
	return (_message.c_str());
}

Int32operand::Int32Exception &Int32operand::Int32Exception::operator=(const Int32operand::Int32Exception &src) {
	_message = src._message;
	return (*this);
}