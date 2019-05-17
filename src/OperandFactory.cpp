#include "../inc/OperandFactory.h"

IOperand const *OperandFactory::createOperand(eOperandType type, std::string const & value) const {
	switch(type)
	{
		case(INT8):
			return (createInt8(value));
		case(INT16):
			return (createInt16(value));
		case(INT32):
			return (createInt32(value));
		case(FLOAT):
			return (createFloat(value));
		case(DOUBLE):
			return (createDouble(value));
	}
}

IOperand const *OperandFactory::createInt8(std::string const & value) const {
	return (new Int8operand(value));
}

IOperand const *OperandFactory::createInt16( std::string const & value ) const {
	return (new Int16operand(value));
}

IOperand const *OperandFactory::createInt32( std::string const & value ) const {
	return (new Int32operand(value));
}

IOperand const *OperandFactory::createFloat( std::string const & value ) const {
	return (new FloatOperand(value));
}

IOperand const *OperandFactory::createDouble( std::string const & value ) const {
	return (new DoubleOperand(value));
}
