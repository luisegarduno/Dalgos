/*
 * Dalgos v1.0.0
 * Updated: 2022-06-24
 * --------------------------------------------
 * Created by Luis on 2020-06-04.
 */

#define CATCH_CONFIG_RUNNER
#include <iostream>
#include <cstring>
#include "catch.hpp"
#include "String.h"
#include "Vector.h"

using namespace std;

#define TEST true

int runCatchTests(int argc, char* argv[]){
    // Runs test.cpp using Catch2 lib
    return Catch::Session().run(argc,argv);
}

int main(int argc, char * argv[]){

    // String
    // Vector
    // Node
    // LinkedList

    if(TEST && argc == 1){
        return runCatchTests(argc, argv);
    }



    return 0;
}
