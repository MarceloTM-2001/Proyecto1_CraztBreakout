cmake_minimum_required(VERSION 3.20)
project(untitled2)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)

add_executable(untitled2 main.cpp Server Server "Server/LogisiticaBloques/Bloque.cpp" "Server/LogisiticaBloques/Bloque.h" "Server/LogisiticaBloques/BloqueComun.cpp" "Server/LogisiticaBloques/BloqueComun.h" "Server/LogisiticaBloques/BloqueDoble.cpp" "Server/LogisiticaBloques/BloqueDoble.h" "Server/LogisiticaBloques/BloqueTriple.cpp" "Server/LogisiticaBloques/BloqueTriple.h" "Server/LogisiticaBloques/BloqueInterno.cpp" "Server/LogisiticaBloques/BloqueInterno.h" "Server/LogisiticaBloques/BloqueProfundo.cpp" "Server/LogisiticaBloques/BloqueProfundo.h" "Server/LogisiticaBloques/Bloques.cpp" "Server/LogisiticaBloques/Bloques.h" "Server/server.cpp" "Server/server.h" "Server/Comunicaciones/Msgcreator.cpp" "Server/Comunicaciones/Msgcreator.h")
