#ifndef READER_H
#define READER_H

#include <string>
#include <vector>
#include <regex>

using namespace std;
using vecVecStr = vector<std::vector<std::string>>;
using vecStr = vector<std::string>;

class Parser {
	private:
  		int 		_lineNum = -1;
  		vecVecStr	_instructions;
  		bool        _correctInstructions = true;
	public:
  		Parser() = default;
  		~Parser() = default;
  		Parser      &operator=(Parser const &src);

		bool    	isCorrectInstruction();
  		int     	getLineNum();
  		vecVecStr	getInstructions();

  		int     	readStdin();
  		int     	readFile(const std::string& fileName);
  		void     	checkInstruction(std::string instruction);
  		bool    	isComment(std::string line);

  		int			addValueCommandToInstructionsVector(const std::string& instruction);
  		int			addCommandToInstructionsVector(const std::string& instruction);
  		vecStr 		parseInstructionWithoutValue(std::string line);
		vecStr 		parseInstructionWithValue(std::string line, std::regex parse);
		
	class ParserException: public std::exception {
	 	private:
	  		std::string _message;
	 	public:
	  		ParserException();
	  		ParserException(std::string message);
	  		ParserException(ParserException const &src);
	 		~ParserException() noexcept;
	  		ParserException	&operator=(ParserException const &src);
	 		const char* what() const noexcept;
	};

};

#endif
