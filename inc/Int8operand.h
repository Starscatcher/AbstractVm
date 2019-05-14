#ifndef INT8OPERAND_H
#define INT8OPERAND_H

#include "abstractVm.h"
#include "IOperand.h"

class Int8operand : public IOperand {
	private:
  		int8_t 			_value;
		eOperandType 	_type;
		int 			_precision;
	public:
  		Int8operand(std::string value);
  		int					getPrecision() const override;
  		eOperandType		getType() const override;
  		std::string const	&toString() const override;
  		int8_t				getValue() const;

  		IOperand const 		*operator+(IOperand const &rhs) const override;
  		IOperand const 		*operator-(IOperand const &rhs) const override;
  		IOperand const 		*operator*(IOperand const &rhs) const override;
  		IOperand const 		*operator/(IOperand const &rhs) const override;
  		IOperand const 		*operator%(IOperand const &rhs) const override;
};

#endif
