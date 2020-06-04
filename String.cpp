//
// Created by Luis on 6/4/2020.
//

#include "String.h"


String::String() {
    cout << "Default constructor" << endl;
}

String::String(const String & oldString){
    cout << "Copy constructor" << endl;
}

String::~String(){
    cout << "Default destructor" << endl;
}

String& String::operator=(const char *){

}

String& String::operator=(const String &){

}

String String::operator+(const String &){

}

String String::operator+=(const String &){

}

bool String::operator==(const char *) const {

}

bool String::operator==(const String &) const {

}

bool String::operator<(const char *) const {

}

bool String::operator<(const String &) const {

}

bool String::operator>(const char *) const {

}

bool String::operator>(const String &) const {

}

bool String::operator<=(const String &) const {

}

bool String::operator>=(const String &) const {

}

char & String::operator[](const int){

}

int size(){

}

String substring(int a, int b){

}

char * c_str(){

}

std::ostream& operator<<(std::ostream & out, const String & theString){
    out << theString.data;

    return out;
}

std::istream& operator>>(std::istream & stream, String & theString){
    char * aChar = theString.data;
    theString.data = new char[100];

    if(stream.good()){
        while(!stream.eof()){
            stream >> *(theString.data);
        }
    }

    delete [] aChar;

    return stream;
}
