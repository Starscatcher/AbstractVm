#include <iostream>
#include "../inc/Vm.h"
#include "../inc/Parser.h"

static void		usage() {
    std::cout << "USAGE :" << std::endl;
    std::cout << " ./avm" << std::endl;
    std::cout << " ./avm <filename>" << std::endl;
}

int				main(int ac, char **av) {
	Parser Reader;

	try {
		if (ac == 1)
			Reader.readStdin();
		else if (ac <= 2)
			Reader.readFile(av[1]);
		else {
			usage();
			return (1);
		}
	}
	catch (Parser::ParserException &e) {
		std::cout	<< "\033[1;31m" << "Error at [" << Reader.getLineNum() + 1 << "] line -> ["
					 << e.what() << "]" << "\033[0m" << std::endl;
		return (0);
	}

    if (Reader.isCorrectInstruction()) {
		Vm  Vm(Reader.getInstructions());
		try {
			Vm.makeInstructions();
		}
		catch (Vm::VmException &e) {
			std::cout	<< "\033[1;31m" << "Error at [" << Vm.getLineNum() + 1 << "] line -> ["
						 << e.what() << "]" << "\033[0m" << std::endl;
		}
    }
    return (0);
}
