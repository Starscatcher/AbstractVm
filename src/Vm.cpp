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

int     Vm::makeInstructions()
{
    _operations.emplace("push", &Vm::push);
    _operations.emplace("dump", &Vm::dump);
    _operations.emplace("assert", &Vm::assert);
    _operations.emplace("add", &Vm::add);
    _operations.emplace("sub", &Vm::sub);
    _operations.emplace("mul", &Vm::mul);
    _operations.emplace("div", &Vm::div);
    _operations.emplace("mod", &Vm::mod);
    _operations.emplace("print", &Vm::print);

    while (_i < _instructions->size()) {
        _operations.at(_instructions[_i][0])();
        _i++;
    }
}

//зчитка + створюю *вектор з вхідними даними

int     Vm::error(const std::string errorLine, unsigned long lineNum)
{
    std::cout << "Invalid instruction at " << lineNum << " line" << std::endl;
    std::cout << errorLine << std::endl;
    _correctInstructions = false;
    return (0);
}

int     Vm::error(unsigned long lineNum)
{
    std::cout << "Invalid instruction at " << lineNum << " line" << std::endl;
    _correctInstructions = false;
    return (0);
}

int     Vm::createInstructionsVector(const std::string instruction)
{
    std::stringstream ss(instruction);
    std::string word;

    if (!_correctInstructions)
        return (0);
    while (ss >> word)
        _instructions[_i].push_back(word);
    _i++;
    return (1);
}

int     Vm::checkInstruction(const std::string instruction)
{
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

int     Vm::readStdin()
{
    std::string     line;
    unsigned long   lineNum = 0;

    while (getline(std::cin, line) && line != "exit") {
        lineNum++;
        if (!checkInstruction(line))
            error(lineNum);
    }
    if (!line.empty() && line == "exit") {
        getline(std::cin, line);
        if (line != ";;")
            error("Make sure that your instructions have ;; at the end", lineNum);
    }
    else
        error("Make sure that your wrote exit instruction", lineNum);
    return (1);
}

int     Vm::readFile(const std::string fileName)
{
    std::ifstream   fd(fileName);
    std::string     line;
    unsigned long   lineNum = 0;

    if (fd) {
        while (getline(fd, line) && line != "exit") {
            lineNum++;
            if (!checkInstruction(line))
                error(lineNum);
        }
        if (!line.empty() && line != "exit")
            error("Make sure that your wrote exit instruction", lineNum);
    }
    return (1);
}
