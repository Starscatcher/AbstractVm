#ifndef INT16OPERAND_H
#define INT16OPERAND_H

#include "IOperand.h"

class Int16operand : public IOperand
{
	private:
		int32_t 			_value;
		eOperandType 		_type;
		int 				_precision;
  		std::string			_stringValue;
	public:
		Int16operand(std::string value);
		~Int16operand();
  		Int16operand      	&operator=(Int16operand const &src);


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


 	class Int16Exception: public std::exception {
		private:
			std::string _message;
 	 	public:
			Int16Exception();
	  		Int16Exception(std::string message);
			Int16Exception(Int16Exception const &src);
			~Int16Exception() noexcept;
			Int16Exception	&operator=(Int16Exception const &src);
			const char* what() const noexcept;
 	};
};


#endif
