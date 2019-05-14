#ifndef VM_H
#define VM_H

#include "abstractVm.h"
#include "IOperand.h"
#include "vector"
#include "OperandFactory.h"
#include "map"

class Vm {
    private:
        std::vector <IOperand const *>	_stack;
        std::vector <std::vector <std::string>>       _instructions;
        int                             _lineNum;
        bool                            _correctInstructions;
  		std::map<std::string, eOperandType> _type;
    public:
        Vm();
        ~Vm();

        Vm &operator=(Vm const &src);

        void push();
        void pop();
        void dump();
        void assert();
        void add();
        void sub();
        void mul();
        void div();
        void mod();
        void print();

        int     readStdin();
        int     readFile(const std::string& fileName);
        int     checkInstruction(std::string instruction);
        int     makeInstructions();
        int     createInstructionsVector(const std::string& instruction);

        bool    getCorrectInstruction();
  		int     getLine();

  		class VmException: public std::exception {
  		 	private:
				std::string _message;
   			public:
		  		VmException() {};
		  		~VmException() noexcept {};
		  		VmException(std::string message) {
			  		_message = message;
		  		}
		  		const char* what() const noexcept {
			  		return (_message.c_str());
		  		}
  		};
};

#endif
