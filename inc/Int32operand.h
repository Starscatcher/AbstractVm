#ifndef INT32OPERAND_H
#define INT32OPERAND_H

#include "IOperand.h"

class Int32operand : public IOperand
{
	private:
		int32_t 			_value;
		eOperandType 		_type;
		int 				_precision;
 	 	std::string			_stringValue;
	public:
		Int32operand(std::string value);
		~Int32operand();
  		Int32operand      	&operator=(Int32operand const &src);


		int					getPrecision() const override;
		eOperandType		getType() const override;
		std::string const	&toString() const override;


		IOperand const 		*operator+(IOperand const &rhs) const override;
		IOperand const 		*operator-(IOperand const &rhs) const override;
		IOperand const 		*operator*(IOperand const &rhs) const override;
		IOperand const 		*operator/(IOperand const &rhs) const override;
		IOperand const 		*operator%(IOperand const &rhs) const override;
  		IOperand const 		*operator&(IOperand const &rhs) const override;
  		IOperand const 		*operator|(IOperand const &rhs) const override;
  		IOperand const 		*operator^(IOperand const &rhs) const override;


  	class Int32Exception: public std::exception {
  	 	private:
			std::string _message;
  	 	public:
	  		Int32Exception();
	  		Int32Exception(std::string message);
	  		Int32Exception(Int32Exception const &src);
			~Int32Exception() noexcept;
	  		Int32Exception	&operator=(Int32Exception const &src);
			const char* what() const noexcept;
  	};
};

#endif
