#ifndef DOUBLEOPERAND_H
#define DOUBLEOPERAND_H

#include "IOperand.h"

class DoubleOperand : public IOperand
{
	private:
		double 				_value;
		eOperandType 		_type;
		int 				_precision;
  		std::string			_stringValue;
	public:
		DoubleOperand(std::string value);
  		~DoubleOperand();
  		DoubleOperand      	&operator=(DoubleOperand const &src);


		int					getPrecision() const override;
		eOperandType		getType() const override;
		std::string const	&toString() const override;


		IOperand const 		*operator+(IOperand const&rhs) const override;
		IOperand const 		*operator-(IOperand const&rhs) const override;
		IOperand const 		*operator*(IOperand const&rhs) const override;
		IOperand const 		*operator/(IOperand const&rhs) const override;
		IOperand const 		*operator%(IOperand const&rhs) const override;
  		IOperand const 		*operator&(IOperand const &rhs) const override;
  		IOperand const 		*operator|(IOperand const &rhs) const override;
  		IOperand const 		*operator^(IOperand const &rhs) const override;


 	class DoubleException: public std::exception {
 	 	private:
			std::string _message;
 	 	public:
	  		DoubleException();
	  		DoubleException(std::string message);
	  		DoubleException(DoubleException const &src);
			~DoubleException() noexcept;
	  		DoubleException	&operator=(DoubleException const &src);
			const char* what() const noexcept;
 	};
};

#endif
