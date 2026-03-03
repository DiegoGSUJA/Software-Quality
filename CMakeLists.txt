# Establece la versión mínima de CMake. Es muy inusual usar 4.0;
# se recomienda una versión moderna (e.g., 3.10 o superior).
cmake_minimum_required(VERSION 3.10)

# Define el nombre del proyecto. ¡Correcto!
project(EEDD_PRACTICAS)

# Define el estándar C++ a usar. ¡Correcto!
set(CMAKE_CXX_STANDARD 14)
# Asegura que el estándar 14 sea obligatorio
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Indica dónde buscar los archivos de encabezado. 
# Usar "." significa el directorio actual. ¡Correcto!
include_directories(.)

# Define el ejecutable. ¡Solo incluimos archivos .cpp!
add_executable(EEDD_PRACTICAS
        Farmacia.cpp
        Laboratorio.cpp
        main.cpp
        MediExpress.cpp
        PaMedicamento.cpp
        Stock.cpp
)