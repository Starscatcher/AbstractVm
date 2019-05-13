#ifndef FLOATOPERAND_H
#define FLOATOPERAND_H

#include "IOperand.h"

class FloatOperand : public IOperand
{
	private:
		float				_value;
		eOperandType 		_type;
		int 				_precision;
	public:
		FloatOperand(std::string value);
		int					getPrecision() const override;
		eOperandType		getType() const override;
		std::string const	&toString() const override;
		float				getValue() const;

		IOperand const 		*operator+(IOperand const&rhs) const override;
		IOperand const 		*operator-(IOperand const&rhs) const override;
		IOperand const 		*operator*(IOperand const&rhs) const override;
		IOperand const 		*operator/(IOperand const&rhs) const override;
		IOperand const 		*operator%(IOperand const&rhs) const override;
};

#endif
