#ifndef INT16OPERAND_H
#define INT16OPERAND_H

#include "IOperand.h"

class Int16operand : public IOperand
{
	private:
		int32_t 			_value;
		eOperandType 		_type;
		int 				_precision;
	public:
		Int16operand(std::string value) ;
		int					getPrecision() const override;
		eOperandType		getType() const override;
		std::string const	&toString() const override;
		int16_t				getValue() const;

		IOperand const 		*operator+(IOperand const &rhs) const override;
		IOperand const 		*operator-(IOperand const &rhs) const override;
		IOperand const 		*operator*(IOperand const &rhs) const override;
		IOperand const 		*operator/(IOperand const &rhs) const override;
		IOperand const 		*operator%(IOperand const &rhs) const override;
};


#endif
