cmake_minimum_required(VERSION 3.13)
project(abstractVM)

set(CMAKE_CXX_STANDARD 14)

add_executable(abstractVM main.cpp Vm.cpp Vm.h IOperand.cpp IOperand.h abstractVm.h Operand.cpp Operand.h)