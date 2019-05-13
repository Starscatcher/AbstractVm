#ifndef INT32OPERAND_H
#define INT32OPERAND_H

#include "IOperand.h"

class Int32operand : public IOperand
{
	private:
		int32_t 			_value;
		eOperandType 		_type;
		int 				_precision;
	public:
		Int32operand(std::string value);
		int					getPrecision() const override;
		eOperandType		getType() const override;
		std::string const	&toString() const override;
		int32_t				getValue() const;

		IOperand const 		*operator+(IOperand const &rhs) const override;
		IOperand const 		*operator-(IOperand const &rhs) const override;
		IOperand const 		*operator*(IOperand const &rhs) const override;
		IOperand const 		*operator/(IOperand const &rhs) const override;
		IOperand const 		*operator%(IOperand const &rhs) const override;
};

#endif
