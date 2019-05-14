#ifndef INT8OPERAND_H
#define INT8OPERAND_H

#include "abstractVm.h"
#include "IOperand.h"

class Int8operand : public IOperand {
	private:
  		int8_t 			_value;
		eOperandType 	_type;
		int 			_precision;
		std::string		_stringValue;
	public:
  		Int8operand(std::string value);
  		int					getPrecision() const override;
  		eOperandType		getType() const override;
  		std::string const	&toString() const override;

  		IOperand const 		*operator+(IOperand const &rhs) const override;
  		IOperand const 		*operator-(IOperand const &rhs) const override;
  		IOperand const 		*operator*(IOperand const &rhs) const override;
  		IOperand const 		*operator/(IOperand const &rhs) const override;
  		IOperand const 		*operator%(IOperand const &rhs) const override;

	class Int8Exception: public std::exception {

   		private:
			std::string _message;
   		public:
	  		Int8Exception() {}
			~Int8Exception() noexcept {}
			Int8Exception(std::string message) {
				_message = message;
			}
			const char* what() const noexcept {
				return (_message.c_str());
			}
  	};
};

#endif
