#include <regex>
#include <iostream>
#include <sstream>
#include <fstream>
#include "../inc/Parser.h"

Parser      &Parser::operator=(Parser const &src) {
	if (this == &src)
		return (*this);
	_lineNum = src._lineNum;
	_instructions = src._instructions;
	_correctInstructions = src._correctInstructions;
	return (*this);
}

vecStr Parser::parseInstructionWithoutValue(std::string line) {
	std::regex  rx("(\\w+)");
	std::smatch	match;

	std::regex_search(line, match, rx);
	return {match[1]};
}

vecStr Parser::parseInstructionWithValue(std::string line, std::regex parse) {
	std::smatch	match;

	std::regex_search(line, match, parse);
	return {match[1], match[3], match[4]};
}

void     Parser::checkInstruction(std::string line) {
	std::regex commands("^( *)(pop|dump|add|sub|mul|div|mod|print|and|or|xor)( *)(\\;.*)?$");
	std::regex intCommands("^( *)(push|assert)( *)+(int8|int16|int32)[\\(][-]?[0-9]+[\\)]( *)(\\;.*)?$");
	std::regex floatCommands("^( *)(push|assert)( *)+(float|double)[\\(][-]?[0-9]+.[0-9]+[\\)]( *)(\\;.*?)?$");
	std::regex parseInt("(\\w+)( +)(\\w+\\d+)\\((-?\\d+)\\)");
	std::regex parsePointed("(\\w+)( +)(\\w+)\\((-?\\d+.\\d+)\\)");

	if (regex_match(line.begin(), line.end(), commands))
		_instructions.push_back(parseInstructionWithoutValue(line));
	else if (regex_match(line.begin(), line.end(), intCommands))
		_instructions.push_back(parseInstructionWithValue(line, parseInt));
	else if (regex_match(line.begin(), line.end(), floatCommands))
		_instructions.push_back(parseInstructionWithValue(line, parsePointed));
	else
		throw ParserException("There is no such instruction or the value does not match the type");
}

bool     Parser::isComment(std::string line) {
	std::regex comment("^( *)(;{1})(.*)$");

	return regex_match(line.begin(), line.end(), comment);
}

int     Parser::readStdin() {
	std::string     line;

	while (getline(std::cin, line))
	{
		_lineNum++;
		if (line == "exit") {
			getline(std::cin, line);
			if (line == ";;")
				return (0);
			else
				throw ParserException("Make sure that your instructions ends with ;;");
		}
		if (isComment(line) || line == "")
			continue;
		checkInstruction(line);
	}
	throw ParserException("Make sure that your instructions ends with EXIT instruction");
}

int     Parser::readFile(const std::string& fileName) {
	std::ifstream   fd(fileName);
	std::string     line;

	if (!fd)
		throw ParserException("Something wrong with file");
	while (getline(fd, line)) {
		_lineNum++;
		try {
			if (line == "exit") {
				if (!getline(fd, line))
					return (0);
				else
					throw ParserException("Make sure that you don't have any instruction after EXIT");
			}
			else if (isComment(line) || line == "")
				continue;
			checkInstruction(line);
		}
		catch (Parser::ParserException &e) {
			std::cout	<< "\033[1;31m" << "Error at [" << _lineNum + 1 << "] line -> ["
							<< e.what() << "]" << "\033[0m" << std::endl;
			_correctInstructions = false;
			continue;
		}
	}
	throw ParserException("Make sure that your instructions ends with EXIT instruction");
}

int     Parser::getLineNum() {
	return (_lineNum);
}

bool    Parser::isCorrectInstruction() {
	return (_correctInstructions);
}

std::vector <std::vector <std::string>>	Parser::getInstructions() {
	return (_instructions);
}


Parser::ParserException::ParserException() {
	_message = nullptr;
}

Parser::ParserException::ParserException(std::string message) {
	_message = message;
}

Parser::ParserException::~ParserException() noexcept {}

Parser::ParserException::ParserException(ParserException const &src) {
	_message = src._message;
}

const char *Parser::ParserException::what() const noexcept {
	return (_message.c_str());
}

Parser::ParserException &Parser::ParserException::operator=(const Parser::ParserException &src) {
	_message = src._message;
	return (*this);
}
