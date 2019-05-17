#include <regex>
#include <iostream>
#include <sstream>
#include <fstream>
#include "../inc/Parser.h"

Parser::Parser() {
	_lineNum = -1;
	_correctInstructions = true;
}

Parser::~Parser() {}

Parser      &Parser::operator=(Parser const &src) {
	if (this == &src)
		return (*this);
	_lineNum = src._lineNum;
	_instructions = src._instructions;
	_correctInstructions = src._correctInstructions;
	return (*this);
}

std::vector<std::string> Parser::parseWithoutValue(std::string line)
{
	std::vector<std::string> parseInt;
	std::regex  rx("(\\w+)");
	std::smatch	match;

	std::regex_search(line, match, rx);
	parseInt.push_back(match[1]);
	return (parseInt);
}

std::vector<std::string> Parser::parseInt(std::string line)
{
	std::vector<std::string> parseInt;
	std::smatch	match;
	std::regex  rx("(\\w+)( +)(\\w+\\d+)\\((-?\\d+)\\)");

	std::regex_search(line, match, rx);
	parseInt.push_back(match[1]);
	parseInt.push_back(match[3]);
	parseInt.push_back(match[4]);
	return (parseInt);
}

std::vector<std::string> Parser::parsePointed(std::string line)
{
	std::vector<std::string> parseInt;
	std::smatch	match;
	std::regex rx("(\\w+)( +)(\\w+)\\((-?\\d+.\\d+)\\)");

	std::regex_search(line, match, rx);
	parseInt.push_back(match[1]);
	parseInt.push_back(match[3]);
	parseInt.push_back(match[4]);
	return (parseInt);
}

void     Parser::checkInstruction(std::string line) {
	std::regex commands("^( *)(pop|dump|add|sub|mul|div|mod|print|and|or|xor)( *)(\\;.*)?$");
	std::regex intCommands("^( *)(push|assert)( *)+(int8|int16|int32)[\\(][-]?[0-9]+[\\)]( *)(\\;.*)?$");
	std::regex floatCommands("^( *)(push|assert)( *)+(float|double)[\\(][-]?[0-9]+.[0-9]+[\\)]( *)(\\;.*?)?$");
	std::vector<std::string>	parseInstr;

	if (regex_match(line.begin(), line.end(), commands))
		parseInstr = parseWithoutValue(line);
	else if (regex_match(line.begin(), line.end(), intCommands))
		parseInstr = parseInt(line);
	else if (regex_match(line.begin(), line.end(), floatCommands))
		parseInstr = parsePointed(line);
	else
		throw ParserException("There is no such instruction or the value does not match the type");
	_instructions.push_back(parseInstr);
}

bool     Parser::isComment(std::string line) {
	std::regex comment("^( *)(;{1})(.*)$");

	if (regex_match(line.begin(), line.end(), comment))
		return (true);
	else
		return (false);
}


int     Parser::readStdin() {
	std::string     line;

	while (getline(std::cin, line)) {
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

	if (fd) {
		while (getline(fd, line)) {
			_lineNum++;
			try {
				if (line == "exit" && !getline(fd, line))
					return (1);
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
	return (1);
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
