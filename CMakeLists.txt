cmake_minimum_required(VERSION 3.15)
project(flysimulator1_0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(flysimulator1_0 main.cpp lexer.cpp lexer.h Command.cpp Command.h OpenServerCommand.cpp OpenServerCommand.h ConnectCommand.cpp ConnectCommand.h
        DefineVarCommand.cpp DefineVarCommand.h PrintCommand.cpp PrintCommand.h SleepCommand.cpp SleepCommand.h
        Client.cpp Client.h Server.cpp Server.h Singleton.cpp Server.h ex1.cpp ex1.h Expression.cpp Expression.h WhileCommand.cpp WhileCommand.h)