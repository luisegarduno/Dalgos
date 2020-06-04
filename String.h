//
// Created by Luis on 6/4/2020.
//

#ifndef DATASTRUCTURES_STRING_H
#define DATASTRUCTURES_STRING_H

#include <cstring>
#include <iostream>

using std::cout;
using std::endl;

class String {

    public:
        // Default constructor
        String();

        // Constructor w/ one parameter
        String(const char *);

        // Copy constructor
        String(const String &);

        // Default destructor
        ~String();

        String& operator=(const char *);
        String& operator=(const String &);

        String operator+(const String &);
        String operator+=(const String &);

        bool operator==(const char *) const;
        bool operator==(const String &) const;

        bool operator<(const char *) const;
        bool operator<(const String &) const;

        bool operator>(const char *) const;
        bool operator>(const String &) const;

        bool operator<=(const String &) const;
        bool operator>=(const String &) const;

        char & operator[](const int);
        int size();

        String substring(int a, int b);

        char * c_str();

        friend std::ostream& operator<<(std::ostream &, const String &);
        friend std::istream& operator>>(std::istream &, String &);

    private:
        char * data;
        size_t length;
};


#endif //DATASTRUCTURES_STRING_H
