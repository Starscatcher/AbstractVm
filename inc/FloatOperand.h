#ifndef FLOATOPERAND_H
#define FLOATOPERAND_H

#include "IOperand.h"
#include "abstractVm.h"

class FloatOperand : public IOperand
{
	private:
		float				_value;
		eOperandType 		_type;
		int 				_precision;
  		std::string			_stringValue;
	public:
		FloatOperand(std::string value);
  		~FloatOperand();
  		FloatOperand      	&operator=(FloatOperand const &src);


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


 	class FloatException: public std::exception {
 	 	private:
			std::string _message;
 	 	public:
	  		FloatException();
	  		FloatException(std::string message);
	  		FloatException(FloatException const &src);
			~FloatException() noexcept;
	  		FloatException	&operator=(FloatException const &src);
			const char* what() const noexcept;
 	};
};

#endif
