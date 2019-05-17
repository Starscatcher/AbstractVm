#ifndef VM_H
#define VM_H

#include "abstractVm.h"
#include "IOperand.h"
#include "vector"
#include "OperandFactory.h"
#include "map"

class Vm {
    private:
        std::vector <IOperand const *>			_stack;
        int                             		_lineNum;
  		std::map<std::string, eOperandType>		_type;
  		std::vector <std::vector <std::string>>	_instructions;
    public:
        Vm(std::vector <std::vector <std::string>> instructions);
  		Vm();
        ~Vm();
        Vm		&operator=(Vm const &src);


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
  		void    and_b();
  		void    or_b();
  		void    xor_b();


        void    makeInstructions();
  		int     getLineNum();


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
