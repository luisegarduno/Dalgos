/*
 * Dalgos v1.0.0
 * Updated: 2022-06-24
 * --------------------------------------------
 * Created by Luis on 2020-06-04.
 */

#ifndef DS_MISSINGFILESEXCEPTION_H
#define DS_MISSINGFILESEXCEPTION_H

// Custom exception used only at the start of the program when checking
// whether or not the valid number of files are entered into the command line
class MissingFilesException{
    public:
        static const char * what() {
            return "Missing/invalid number of arguments";
        }
};

#endif //DS_MISSINGFILESEXCEPTION_H
