#ifndef VM_H
#define VM_H

#include "abstractVm.h"
#include "IOperand.h"
#include "vector"
#include "OperandFactory.h"
#include "map"

using vecVecStr = std::vector<std::vector<std::string>>;
using vecStr = std::vector<std::string>;

class Vm {
   private:
      std::vector <IOperand const *>   _stack;
      std::map<std::string, eOperandType> _type = {{"int8", INT8}, {"int16", INT16}, {"int32", INT32}, {"float", FLOAT}, {"double", DOUBLE}};
      int         _lineNum = 0;
      vecVecStr   _instructions;
   public:
      Vm(vecVecStr instructions);
      Vm() = default;
      ~Vm();
      Vm		&operator=(Vm const &src);

      void    makeInstructions();

      int     getLineNum();

      void	push();
      void	pop();
      void	dump();
      void	assert();
      void	add();
      void	sub();
      void	mul();
      void	div();
      void	mod();
      void	print();
      void  and_b();
      void  or_b();
      void  xor_b();

  		class VmException: public std::exception {
  		 	private:
		  		std::string _message;
   			public:
		  		VmException();
		  		VmException(std::string message);
		  		VmException(VmException const &src);
		  		~VmException() noexcept;
		  		VmException	&operator=(VmException const &src);
		  		const char* what() const noexcept;
  		};
};

#endif
