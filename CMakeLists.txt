cmake_minimum_required(VERSION 3.14)
project(AbstractVm)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(AbstractVm
        abstractVm.h
        DoubleOperand.cpp
        DoubleOperand.h
        FloatOperand.cpp
        FloatOperand.h
        Int16operand.cpp
        Int16operand.h
        Int32operand.cpp
        Int32operand.h
        Int8operand.cpp
        Int8operand.h
        IOperand.h
        main.cpp
        OperandFactory.cpp
        OperandFactory.h
        Vm.cpp
        Vm.h)
