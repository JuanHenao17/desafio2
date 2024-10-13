cmake_minimum_required(VERSION 3.16)

project(codigoFuente LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(codigoFuente main.cpp
    RedNacional.cpp
    RedNacional.h
    EstacionServicio.cpp
    EstacionServicio.h)

include(GNUInstallDirs)
install(TARGETS codigoFuente
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
