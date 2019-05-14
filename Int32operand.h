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
		int					getPrecision() const override;
		eOperandType		getType() const override;
		std::string const	&toString() const override;

		IOperand const 		*operator+(IOperand const &rhs) const override;
		IOperand const 		*operator-(IOperand const &rhs) const override;
		IOperand const 		*operator*(IOperand const &rhs) const override;
		IOperand const 		*operator/(IOperand const &rhs) const override;
		IOperand const 		*operator%(IOperand const &rhs) const override;

	class Int32Exception: public std::exception {
		private:
			std::string _message;
   		public:
	  		Int32Exception() {}
			~Int32Exception() noexcept {}
	  		Int32Exception(std::string message) {
				_message = message;
			}
			const char* what() const noexcept {
				return (_message.c_str());
			}
  	};
};

#endif
