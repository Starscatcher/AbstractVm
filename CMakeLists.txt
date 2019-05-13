cmake_minimum_required(VERSION 3.13)
project(abstractVM)

set(CMAKE_CXX_STANDARD 14)

add_executable(abstractVM main.cpp Vm.cpp Vm.h IOperand.h abstractVm.h Int8operand.cpp Int8operand.h OperandFactory.cpp OperandFactory.h Int32operand.cpp Int32operand.h Int16operand.cpp Int16operand.h FloatOperand.cpp FloatOperand.h DoubleOperand.cpp DoubleOperand.h)