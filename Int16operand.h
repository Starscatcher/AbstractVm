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
		Int16operand(std::string value) ;
		int					getPrecision() const override;
		eOperandType		getType() const override;
		std::string const	&toString() const override;

		IOperand const 		*operator+(IOperand const &rhs) const override;
		IOperand const 		*operator-(IOperand const &rhs) const override;
		IOperand const 		*operator*(IOperand const &rhs) const override;
		IOperand const 		*operator/(IOperand const &rhs) const override;
		IOperand const 		*operator%(IOperand const &rhs) const override;

	class Int16Exception: public std::exception {

		private:
			std::string _message;
		public:
	  		Int16Exception() {}
			~Int16Exception() noexcept {}
	  		Int16Exception(std::string message) {
				_message = message;
			}
			const char* what() const noexcept {
				return (_message.c_str());
			}
	};
};


#endif
