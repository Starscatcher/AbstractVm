#ifndef OPERANDFACTORY_H
#define OPERANDFACTORY_H

#include "IOperand.h"
#include "Int8operand.h"
#include "Int16operand.h"
#include "Int32operand.h"
#include "FloatOperand.h"
#include "DoubleOperand.h"

class OperandFactory
{
	public:
  		IOperand const * createOperand(eOperandType type, std::string const &value) const;

 	private:
  		IOperand const * createInt8(std::string const &value) const;
  		IOperand const * createInt16(std::string const &value) const;
  		IOperand const * createInt32(std::string const &value) const;
  		IOperand const * createFloat(std::string const &value) const;
  		IOperand const * createDouble(std::string const &value) const;
};

#endif
