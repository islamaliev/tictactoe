cmake_minimum_required(VERSION 3.6)
project(tictactoe)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp TicTacToeGame.cpp HumanPlayer.cpp PlayersInitializer.cpp ConsoleGridRenderer.cpp
        RandomCellCoordinateGenerator.cpp)
add_executable(tictactoe ${SOURCE_FILES})
set_target_properties(tictactoe PROPERTIES LINKER_LANGUAGE CXX)