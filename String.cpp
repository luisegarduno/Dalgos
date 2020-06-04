//
// Created by Luis on 6/4/2020.
//

#include "String.h"


String::String() {
    //cout << "Default constructor" << endl;

    this->data = new char[1];
    this->data[0] = '\0';
    length = 0;
}

String::String(const char * originalChar){
    this->data = new char[strlen(originalChar) + 1];
    strcpy(this->data, originalChar);
    length = strlen(this->data);
}

String::String(const String & originalString){
    //cout << "Copy constructor" << endl;

    this->data = new char[strlen(originalString.data) + 1];
    strcpy(this->data, originalString.data);
    length = strlen(this->data);
}

String::~String(){
    //cout << "Default destructor" << endl;

    if(this->data != nullptr){
        delete [] this->data;
    }
}

String& String::operator=(const char * originalChar){
    char * oldData = this->data;

    this->data = new char[strlen(originalChar) + 1];
    strcpy(this->data, originalChar);

    delete [] oldData;

    return *this;
}

String& String::operator=(const String & originalString){
    if(this != &originalString){
        if(data != nullptr){
            delete [] data;
            data = nullptr;
        }

        this->data = new char[strlen(originalString.data) + 1];
        strcpy(this->data, originalString.data);
    }

    return *this;
}

String String::operator+(const String & originalString){
    char * tempData = new char[strlen(this->data) + strlen(originalString.data) + 1];

    strcpy(tempData, this->data);
    strcat(tempData, originalString.data);
    String newString = tempData;

    delete [] tempData;

    return newString;
}

String String::operator+=(const String & originalString){
    char * tempChar = this->data;

    this->data = new char[strlen(tempChar) + strlen(originalString.data) + 1];
    strcpy(this->data, tempChar);
    strcat(this->data, originalString.data);

    delete [] tempChar;

    return *this;
}

bool String::operator==(const char * aData) const {
    return this->data == aData;
}

bool String::operator==(const String & aString) const {
    return strcmp(this->data, aString.data) == 0;
}

bool String::operator<(const char * aData) const {
    if(this->data < aData){
        return true;
    }
    else if(this->data == aData){
        for(int i = 0; i < int(strlen(this->data)); i++){
            if(int(this->data[i]) > int(aData[i])){
                return true;
            }
            else if(int(this->data[i]) < int(aData[i])){
                return false;
            }
        }
    }

    return false;
}

bool String::operator<(const String & aString) const {
    if(this->data < aString.data){
        return true;
    }
    else if(this->data == aString.data){
        for(int i = 0; i < int(strlen(this->data)); i++){
            if(int(this->data[i]) > int(aString.data[i])){
                return false;
            }
            else if(int(this->data[i]) < int(aString.data[i])){
                return true;
            }
        }
    }

    return true;
}

bool String::operator>(const char * aData) const {
    if(this->data > aData){
        return true;
    }
    else if(this->data == aData){
        for(int i = 0; i < int(strlen(this->data)); i++){
            if(int(this->data[i]) > int(aData[i])){
                return false;
            }
            else if(int(this->data[i]) < int(aData[i])){
                return true;
            }
        }
    }

    return true;
}

bool String::operator>(const String & aString) const {
    return strcmp(this->data, aString.data) > 0;
}

bool String::operator<=(const String & aString) const {
    return strcmp(this->data, aString.data) <= 0;
}

bool String::operator>=(const String & aString) const {
    return strcmp(this->data, aString.data) >= 0;
}

char & String::operator[](const int indexSize){
    return *(this->data + indexSize);
}

int String::size(){
    return int(strlen(this->data));
}

String String::substring(int a, int b){
    String aString;
    char * tempData = this->data;

    if(b > a){
        if(a == 0){
            this->data = new char[int(b) + 1];
            for(int i = 0; i < b; i++){
                this->data[i] = tempData[i];
            }
            this->data[int(b)] = '\0';
        }
        else if(a != 0){
            int c = (int(b) - a);
            this->data = new char[c + 1];
            for(int i = 0; i < c; i++){
                this->data[i] = tempData[a + i];
            }
            this->data[c] = '\0';
        }

        delete [] tempData;

        return this->data;
    }

    else if(b < a){
        int sizeOfChar = (b * -1) + 1;
        this->data = new char[sizeOfChar];
        for(int i = 0; i < -b; i++){
            this->data[i] = tempData[(a + b) + i];
        }

        aString = this->data;

        delete [] tempData;
        return aString;
    }

    else{
        return aString;
    }
}

char * String::c_str(){
    return this->data;
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
