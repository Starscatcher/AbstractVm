#ifndef READER_H
#define READER_H

#include <string>
#include <vector>

class Parser {
	private:
  		int 									_lineNum;
  		std::vector <std::vector <std::string>>	_instructions;
  		bool                            		_correctInstructions;
	public:
  		Parser();
  		~Parser();
  		Parser      							&operator=(Parser const &src);


  		int     								readStdin();
  		int     								readFile(const std::string& fileName);
  		void     								checkInstruction(std::string instruction);
  		bool    								isComment(std::string line);
  		int										addValueCommandToInstructionsVector(const std::string& instruction);
  		int										addCommandToInstructionsVector(const std::string& instruction);
  		std::vector<std::string> 				parseInt(std::string instr);
  		std::vector<std::string> 				parsePointed(std::string instr);
  		std::vector<std::string> 				parseWithoutValue(std::string instr);


  		bool    								isCorrectInstruction();
  		int     								getLineNum();
  		std::vector <std::vector <std::string>>	getInstructions();


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
