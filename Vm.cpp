#include <fstream>
#include "Vm.h"

Vm::Vm() {}

Vm::~Vm() {}

Vm      &Vm::operator=(Vm const &src) {}

void    Vm::push() {
	OperandFactory	create;

	_stack.push_back(create.createOperand(type, val));
}

void    Vm::pop() {
	if (_stack.empty())
		return; //error

	_stack.pop_back();
}

void    Vm::dump() {
	if (_stack.empty())
		return; //error
	for (auto & i : _stack) {
		std::cout << i << std::endl;
	}
}

void    Vm::assert() {
	if (type != _stack[_stack.size() - 1]->getType() || val != _stack[_stack.size() - 1].getValue())
		return; //error
	else
		push();
}

void    Vm::add() {
	IOperand const  *value;

	if (_stack.size() < 2)
		return; //error
	value = *(_stack[_stack.size() - 1]) + *(_stack[_stack.size() - 2]);
	_stack.pop_back();
	_stack.pop_back();
	_stack.push_back(value);
}

void    Vm::sub() {
	IOperand const  *value;

	if (_stack.size() < 2)
		return; //error
	value = *(_stack[_stack.size() - 1]) - *(_stack[_stack.size() - 2]);
	_stack.pop_back();
	_stack.pop_back();
	_stack.push_back(value);
}

void    Vm::mul() {
	IOperand const  *value;

	if (_stack.size() < 2)
		return; //error
	value = *(_stack[_stack.size() - 1]) * *(_stack[_stack.size() - 2]);
	_stack.pop_back();
	_stack.pop_back();
	_stack.push_back(value);
}

void    Vm::div() {
	IOperand const  *value;

	if (_stack.size() < 2 || _stack[_stack.size()] - 2 == 0)
		return; //error
	value = *(_stack[_stack.size() - 1]) / *(_stack[_stack.size() - 2]);
	_stack.pop_back();
	_stack.pop_back();
	_stack.push_back(value);
}

void    Vm::mod() {
	IOperand const  *value;

	if (_stack.size() < 2 || _stack[_stack.size()] - 2 == 0)
		return; //error
	value = *(_stack[_stack.size() - 1]) % *(_stack[_stack.size() - 2]);
	_stack.pop_back();
	_stack.pop_back();
	_stack.push_back(value);
}

void    Vm::print() {
	if (_stack[_stack.size() - 1]->getType() != INT8)
		return; //error
	else
		std::cout << _stack[_stack.size() - 1] << std::endl;
}

int     Vm::checkInstruction(const std::string instruction) {

}

int     Vm::readStdin() {
    std::string line;

    while (getline(std::cin, line) && line != "exit")
    {
        if (!checkInstruction(line))
        {
            std::cout << "Invalid instruction" << std::endl;
            return (1);
        }
    }
    if (line == "exit")
    {
        getline(std::cin, line);
        if (line != ";;")
        {
            std::cout << "Invalid ;; instruction" << std::endl;
            return (1);
        }
    }
    else
    {
        std::cout << "Invalid exit instruction" << std::endl;
        return (1);
    }
    return (0);
}

int     Vm::readFile(const std::string fileName) {
    std::ifstream   fd(fileName);
    std::string     line;

    if (fd)
    {
        while (getline(fd, line) && line != "exit")
        {
            if (!checkInstruction(line))
            {
                std::cout << "Invalid instruction" << std::endl;
                return (1);
            }
        }
        if (line != "exit")
        {
            std::cout << "Invalid exit instruction" << std::endl;
            return (1);
        }
    }
}
