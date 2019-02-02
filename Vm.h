#ifndef VM_H
#define VM_H

#include "abstractVm.h"
#include "IOperand.h"
#include "stack"

class Vm {
    private:
        std::stack <IOperand const *> _stack;
    public:
        Vm();
        ~Vm();

        Vm &operator=(Vm const &src);

        void push(void);
        void pop(void);
        void dump(void);
        void assert(void);
        void add(void);
        void sub(void);
        void mul(void);
        void div(void);
        void mod(void);
        void print(void);

        int     readStdin();
        int     readFile(std::string fileName);
        int     checkInstruction(std::string instruction);

};

#endif
