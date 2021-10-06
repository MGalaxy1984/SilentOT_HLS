cmake_minimum_required(VERSION 3.20)
project(SilentOT_HLS)

set(CMAKE_CXX_STANDARD 17)

add_executable(SilentOT_HLS main.cpp Modules/PRNG.cpp Modules/PRNG.h Defines.h Debug/DebugPrint.cpp Debug/DebugPrint.h Modules/TopLevel.cpp Modules/TopLevel.h Modules/Terminal.cpp Modules/Terminal.h Tests/PRNGTests.cpp Tests/PRNGTests.h Tools/PRNGTool.cpp Tools/PRNGTool.h Modules/MatrixMul.cpp Modules/MatrixMul.h Modules/MatrixTranspose.cpp Modules/MatrixTranspose.h Common/Sender.cpp Common/Sender.h Common/Message.cpp Common/Message.h Modules/StateMachine.cpp Modules/StateMachine.h)