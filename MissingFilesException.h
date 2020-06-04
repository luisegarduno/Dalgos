//
// Created by Luis on 6/4/2020.
//

#ifndef DATASTRUCTURES_MISSINGFILESEXCEPTION_H
#define DATASTRUCTURES_MISSINGFILESEXCEPTION_H

// Custom exception used only at the start of the program when checking
// whether or not the valid number of files are entered into the command line
class MissingFilesException{
    public:
        static const char * what() {
            return "Missing/invalid number of arguments";
        }
};

#endif //DATASTRUCTURES_MISSINGFILESEXCEPTION_H
