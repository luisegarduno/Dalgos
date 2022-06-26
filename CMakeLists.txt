cmake_minimum_required(VERSION 3.16)
project(DS)
set (EXE_NAME DataTypes)

link_libraries(-lstdc++fs)

############################################
# Enter the name of the input files in the
# quotes. Ex: set (input01 "train_data.csv")
set (input01 "")
set (input02 "")
############################################

# Copy data files to build directory
foreach(file IN LISTS input01 input02)
    configure_file(${file} ${file} COPYONLY)
endforeach()

set(CMAKE_CXX_STANDARD 17)
add_executable(${EXE_NAME} main.cpp String.h LinkedList.h Node.h Vector.h Stack.h MissingFilesException.h OUT_OF_BOUNDS.h test.cpp catch.hpp)