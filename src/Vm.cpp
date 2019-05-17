#include "../inc/Vm.h"

#define COMMAND 0
#define TYPE 1
#define VAL 2

Vm::Vm(std::vector <std::vector <std::string>> instructions) {
	_type = {{"int8", INT8},
			{"int16", INT16},
			{"int32", INT32},
			{"float", FLOAT},
			{"double", DOUBLE}};
	_lineNum = 0;
	_instructions = instructions;
}

Vm::Vm() {}

Vm::~Vm() {
	for(int i = this->_stack.size() - 1; i >= 0 ; i--)
		delete this->_stack[i];
}

Vm      &Vm::operator=(Vm const &src) {
	if (this == &src)
		return (*this);
	_stack = src._stack;
	_lineNum = src._lineNum;
	_type = src._type;
	_instructions = src._instructions;
	return (*this);
}

void    Vm::push() {
	OperandFactory	create;

	try {
		_stack.push_back(create.createOperand(_type[_instructions[_lineNum][TYPE]], _instructions[_lineNum][VAL]));
	}
	catch (Int8operand::Int8Exception &e) {
		std::cout << "\033[1;31m" << "Error at [" << getLineNum() + 1 << "] line -> ["
				  << e.what() << "]" << "\033[0m" << std::endl;
		exit(1);
	}
	catch (Int16operand::Int16Exception &e) {
		std::cout << "\033[1;31m" << "Error at [" << getLineNum() + 1 << "] line -> ["
				  << e.what() << "]" << "\033[0m" << std::endl;
		exit(1);
	}
	catch (Int32operand::Int32Exception &e) {
		std::cout << "\033[1;31m" << "Error at [" << getLineNum() + 1 << "] line -> ["
				  << e.what() << "]" << "\033[0m" << std::endl;
		exit(1);
	}
	catch (FloatOperand::FloatException &e) {
		std::cout << "\033[1;31m" << "Error at [" << getLineNum() + 1 << "] line -> ["
				  << e.what() << "]" << "\033[0m" << std::endl;
		exit(1);
	}
	catch (DoubleOperand::DoubleException &e) {
		std::cout << "\033[1;31m" << "Error at [" << getLineNum() + 1 << "] line -> ["
				  << e.what() << "]" << "\033[0m" << std::endl;
		exit(1);
	}
}

void    Vm::pop() {
	if (_stack.empty())
		throw VmException("POP on empty stack");
	_stack.pop_back();
}

void    Vm::dump() {
	if (!_stack.empty()) {
		for (auto &i : _stack)
			std::cout << i->toString() << std::endl;
	}
}

void    Vm::assert() {
	if (_stack.empty())
		throw VmException("ASSERT on empty stack");
	else if (_type[_instructions[_lineNum][TYPE]] != _stack[_stack.size() - 1]->getType() || stod(_instructions[_lineNum][VAL]) != stod(_stack.back()->toString()))
		throw VmException("ASSERT instruction is false");
	else
		push();
}

void    Vm::add() {
	IOperand const  *value;

	if (_stack.size() < 2)
		throw VmException("ADD instruction with less than 2 values in stack");
	value = *(_stack[_stack.size() - 2]) + *(_stack[_stack.size() - 1]);
	delete _stack.back();
	_stack.pop_back();
	delete _stack.back();
	_stack.pop_back();
	_stack.push_back(value);
}

void    Vm::sub() {
	IOperand const  *value;

	if (_stack.size() < 2)
		throw VmException("SUB instruction with less than 2 values in stack");
	value = *(_stack[_stack.size() - 2]) - *(_stack[_stack.size() - 1]);
	delete _stack.back();
	_stack.pop_back();
	delete _stack.back();
	_stack.pop_back();
	_stack.push_back(value);
}

void    Vm::mul() {
	IOperand const  *value;

	if (_stack.size() < 2)
		throw VmException("MUL instruction with less than 2 values in stack");
	value = *(_stack[_stack.size() - 2]) * *(_stack[_stack.size() - 1]);
	delete _stack.back();
	_stack.pop_back();
	delete _stack.back();
	_stack.pop_back();
	_stack.push_back(value);
}

void    Vm::div() {
	IOperand const  *value;

	if (_stack.size() < 2)
		throw VmException("DIV instruction with less than 2 values in stack");
	else if (_stack[_stack.size() - 1]->toString() == "0")
		throw VmException("DIV by 0");
	else if (stold(_stack[_stack.size() - 1]->toString()) == 0)
		throw VmException("DIV by 0");
	value = *(_stack[_stack.size() - 2]) / *(_stack[_stack.size() - 1]);
	delete _stack.back();
	_stack.pop_back();
	delete _stack.back();
	_stack.pop_back();
	_stack.push_back(value);
}

void    Vm::mod() {
	IOperand const  *value;

	if (_stack.size() < 2)
		throw VmException("MOD instruction with less than 2 values in stack");
	else if (_stack[_stack.size() - 1]->toString() == "0")
		throw VmException("DIV by 0");
	else if (stold(_stack[_stack.size() - 1]->toString()) == 0)
		throw VmException("DIV by 0");
	value = *(_stack[_stack.size() - 2]) % *(_stack[_stack.size() - 1]);
	delete _stack.back();
	_stack.pop_back();
	delete _stack.back();
	_stack.pop_back();
	_stack.push_back(value);
}


void    Vm::and_b()
{
	IOperand const  *value;
	if (_stack.size() < 2)
		throw VmException("XOR instruction with less than 2 values in stack");
	value = *(_stack[_stack.size() - 2]) & *(_stack[_stack.size() - 1]);
	delete _stack.back();
	_stack.pop_back();
	delete _stack.back();
	_stack.pop_back();
	_stack.push_back(value);
}

void    Vm::or_b()
{
	IOperand const  *value;
	if (_stack.size() < 2)
		throw VmException("XOR instruction with less than 2 values in stack");
	value = *(_stack[_stack.size() - 2]) | *(_stack[_stack.size() - 1]);
	delete _stack.back();
	_stack.pop_back();
	delete _stack.back();
	_stack.pop_back();
	_stack.push_back(value);
}

void    Vm::xor_b()
{
	IOperand const  *value;
	if (_stack.size() < 2)
		throw VmException("XOR instruction with less than 2 values in stack");
	value = *(_stack[_stack.size() - 2]) ^ *(_stack[_stack.size() - 1]);
	delete _stack.back();
	_stack.pop_back();
	delete _stack.back();
	_stack.pop_back();
	_stack.push_back(value);
}

void    Vm::print() {
	if (_stack[_stack.size() - 1]->getType() != INT8)
		throw VmException("PRINT not int8 type");
	else
		std::cout << (char)(std::stoi(_stack[_stack.size() - 1]->toString())) << std::endl;
}

void     Vm::makeInstructions()
{
    for (_lineNum = 0; (size_t)_lineNum < _instructions.size(); _lineNum++) {
			if (_instructions[_lineNum][0] == "push")
				push();
			else if (_instructions[_lineNum][COMMAND] == "pop")
				pop();
			else if (_instructions[_lineNum][COMMAND] == "dump")
				dump();
			else if (_instructions[_lineNum][COMMAND] == "assert")
				assert();
			else if (_instructions[_lineNum][COMMAND] == "add")
				add();
			else if (_instructions[_lineNum][COMMAND] == "sub")
				sub();
			else if (_instructions[_lineNum][COMMAND] == "mul")
				mul();
			else if (_instructions[_lineNum][COMMAND] == "div")
				div();
			else if (_instructions[_lineNum][COMMAND] == "mod")
				mod();
			else if (_instructions[_lineNum][COMMAND] == "print")
				print();
			else if (_instructions[_lineNum][COMMAND] == "and")
				and_b();
			else if (_instructions[_lineNum][COMMAND] == "or")
				or_b();
			else if (_instructions[_lineNum][COMMAND] == "xor")
				xor_b();
    }
}

int     Vm::getLineNum() {
	return (_lineNum);
}

Vm::VmException::VmException(std::string message) {
	_message = message;
}

Vm::VmException::VmException() {
	_message = nullptr;
}

Vm::VmException::~VmException() noexcept {}

Vm::VmException::VmException(VmException const &src) {
	_message = src._message;
}

const char *Vm::VmException::what() const noexcept {
	return (_message.c_str());
}

Vm::VmException &Vm::VmException::operator=(const Vm::VmException &src) {
	_message = src._message;
	return (*this);
}
