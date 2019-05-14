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
		int					getPrecision() const override;
		eOperandType		getType() const override;
		std::string const	&toString() const override;

		IOperand const 		*operator+(IOperand const&rhs) const override;
		IOperand const 		*operator-(IOperand const&rhs) const override;
		IOperand const 		*operator*(IOperand const&rhs) const override;
		IOperand const 		*operator/(IOperand const&rhs) const override;
		IOperand const 		*operator%(IOperand const&rhs) const override;

	class FloatException: public std::exception {

		private:
			std::string _message;
		public:
	  		FloatException() {}
			~FloatException() noexcept;
	  		FloatException(std::string message) {
				_message = message;
			}
			const char* what() const throw() {
				return (_message.c_str());
			}
  	};
};

#endif
