#include "arghandler.h"
#include<iostream>
#include<string>
#include<cstring>
#include<cstddef>
#include<cstring>
using namespace std;

void zeroArguments() { //print the usage text
    cout << "Usage: " << endl;
    cout << "If you're already here, I'm assuming you ran already compiled the files and ran the executable..." << endl;
    cout << "When running, you can pass an indefinite number of arguments: \"./commandlinelab |argument1| |argument2| |etc.|\"" << endl;
    cout << "How to run unit tests:" << endl;
    cout << "1. Navigate to the brennanb2021_ComandLineLab folder" << endl;
    cout << "2. Run the makefile: \"make test\"" << endl;
    cout << "3. Run the unit test file: \"./test_runner\"" << endl;
}

string oneArgument( char *argv[] ) {
    string rtn;
    string str = argv[1]; //get first argument (0th will be ./commandlinelab)
    string::const_iterator it = str.begin();
    while (it != str.end() && std::isdigit(*it)) ++it;
    if(!str.empty() && it == str.end()) {
        it = str.begin(); //reset iterator
        while (it != str.end() && *it=='0') ++it; //go thru all chars in string and check if == '0'
        if(it == str.end()) { //if all chars are zero:
            rtn = "Zero";
        } else if((str[str.length()-1]-48)%2 == 0) { 
            //hanling big numbers - just grab the last char and check if even or odd.
            //since the to int methods crash on numbers larger than int.
            rtn = "Even";
        } else {
            rtn = "Odd";
        }
    } else {
        rtn = "Not An Integer";
    }
    return rtn;
}

int multiArguments( int argc, char *args[] ) {
    int totalCs = 0;
    for(int i = 1; i < argc; i++) { //first arg will be ./commandlinelab
        if(args[i] != NULL) {
            string s = args[i];
            for(string::iterator it = s.begin(); it != s.end(); it++) {
                if(*it == 'c' || *it == 'C') { //go thru this string and check if char is a c or C
                    totalCs++;
                }
            }
        }
    }
    return totalCs;
}
