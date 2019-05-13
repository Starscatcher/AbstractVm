#include <iostream>
#include "Vm.h"

static void    usage()
{
    std::cout << "USAGE :" << std::endl;
    std::cout << " ./avm" << std::endl;
    std::cout << " ./avm <filename>" << std::endl;
}

int             main(int ac, char **av)
{
    Vm  vm;

    if (ac == 1)
        vm.readStdin();
    else if (ac <= 2)
        vm.readFile(av[1]);
    else
    {
        usage();
        return (1);
    }

    //vm.stackProcessing();

    return (0);
}
