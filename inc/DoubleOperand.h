#ifndef DOUBLEOPERAND_H
#define DOUBLEOPERAND_H

#include "IOperand.h"

class DoubleOperand : public IOperand
{
	private:
		double 				_value;
		eOperandType 		_type;
		int 				_precision;
	public:
		DoubleOperand(std::string value);
		int					getPrecision() const override;
		eOperandType		getType() const override;
		std::string const	&toString() const override;
		double				getValue() const;

		IOperand const 		*operator+(IOperand const&rhs) const override;
		IOperand const 		*operator-(IOperand const&rhs) const override;
		IOperand const 		*operator*(IOperand const&rhs) const override;
		IOperand const 		*operator/(IOperand const&rhs) const override;
		IOperand const 		*operator%(IOperand const&rhs) const override;
};

#endif
