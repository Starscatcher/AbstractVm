#include <fstream>
#include <sstream>
#include <regex>
#include "Vm.h"

#define COMMAND 0
#define TYPE 1
#define VAL 2

Vm::Vm() {
	_type = {{"int8", INT8},
			{"int16", INT16},
			{"int32", INT32},
			{"float", FLOAT},
			{"double", DOUBLE}};
	_lineNum = 0;
	_correctInstructions = true;
}

Vm::~Vm() {}

Vm      &Vm::operator=(Vm const &src) {}

void    Vm::push() {
	OperandFactory	create;

	_stack.push_back(create.createOperand(_type[_instructions[_lineNum][TYPE]], _instructions[_lineNum][VAL]));
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
	value = *(_stack[_stack.size() - 1]) + *(_stack[_stack.size() - 2]);
	_stack.pop_back();
	_stack.pop_back();
	_stack.push_back(value);
}

void    Vm::sub() {
	IOperand const  *value;

	if (_stack.size() < 2)
		throw VmException("SUB instruction with less than 2 values in stack");
	value = *(_stack[_stack.size() - 1]) - *(_stack[_stack.size() - 2]);
	_stack.pop_back();
	_stack.pop_back();
	_stack.push_back(value);
}

void    Vm::mul() {
	IOperand const  *value;

	if (_stack.size() < 2)
		throw VmException("MUL instruction with less than 2 values in stack");
	value = *(_stack[_stack.size() - 1]) * *(_stack[_stack.size() - 2]);
	_stack.pop_back();
	_stack.pop_back();
	_stack.push_back(value);
}

void    Vm::div() {
	IOperand const  *value;

	if (_stack.size() < 2)
		throw VmException("DIV instruction with less than 2 values in stack");
	else if (_stack[_stack.size() - 2] == 0)
		throw VmException("DIV by 0");
	value = *(_stack[_stack.size() - 1]) / *(_stack[_stack.size() - 2]);
	_stack.pop_back();
	_stack.pop_back();
	_stack.push_back(value);
}

void    Vm::mod() {
	IOperand const  *value;

	if (_stack.size() < 2)
		throw VmException("MOD instruction with less than 2 values in stack");
	else if (_stack[_stack.size() - 2] == 0)
		throw VmException("DIV by 0");
	value = *(_stack[_stack.size() - 1]) % *(_stack[_stack.size() - 2]);
	_stack.pop_back();
	_stack.pop_back();
	_stack.push_back(value);
}

void    Vm::print() {
	if (_stack[_stack.size() - 1]->getType() != INT8)
		throw VmException("PRINT not int8 type");
	else
		std::cout << _stack[_stack.size() - 1] << std::endl;
}

int     Vm::makeInstructions()
{
    for (_lineNum = 0; _lineNum < _instructions.size(); _lineNum++) {
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
    }
}

//зчитка + створюю *вектор з вхідними даними

int     Vm::getLine() {
	return (_lineNum);
}

bool    Vm::getCorrectInstruction() {
	return (_correctInstructions);
}

int     Vm::createInstructionsVector(const std::string& instruction) {
    std::stringstream ss(instruction);
    std::string word;
    std::vector <std::string> params;
	std::string val;
	int from = 0;

    if (!_correctInstructions)
        return (0);
    while (ss >> word) {
    	if (params.size() == 1)
		{
			while (word[from] != '(')
				from++;
			val = word.substr(0, from);
			params.push_back(val);
			val = word.substr(from + 1, word.size() - 2 - from);
			params.push_back(val);
		}
		else
			params.push_back(word);
	}
    _instructions.push_back(params);
	_lineNum++;
    return (1);
}

int     Vm::checkInstruction(std::string instruction) {
    std::regex 	commands("^( *)(pop|dump|add|sub|mul|div|mod|print|and|or|xor)( *)$");
    std::regex 	intCommands("^( *)(push|assert)( +)(int8|int16|int32)\\({1}(-*)([0-9]+)\\){1}( *)$");
    std::regex 	floatCommands("^( *)(push|assert)( +)(float|double)\\({1}(-*)([0-9]+)(.{1})([0-9]+)\\){1}( *)$");

    if (regex_match(instruction.begin(), instruction.end(), commands))
        return (createInstructionsVector(instruction));
    else if (regex_match(instruction.begin(), instruction.end(), intCommands))
		return (createInstructionsVector(instruction));
    else if (regex_match(instruction.begin(), instruction.end(), floatCommands))
        return (createInstructionsVector(instruction));
    else
        return (0);
}

int     Vm::readStdin() {
    std::string     line;

    while (getline(std::cin, line) && line != ";;") {
        _lineNum++;
        if (!checkInstruction(line))
			throw VmException("There is no such instruction");
    }
    if (line.empty()) {
		throw VmException("Make sure that your instructions ends with ;;");
    }
    return (1);
}

int     Vm::readFile(const std::string& fileName) {
    std::ifstream   fd(fileName);
    std::string     line;

    if (fd) {
        while (getline(fd, line) && line != "exit") {
            _lineNum++;
            if (!checkInstruction(line))
				throw VmException("There is no such instruction");
        }
        if (line.empty())
            throw VmException("Make sure that your instructions ends with exit instruction");
    }
    return (1);
}
