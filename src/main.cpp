#include<iostream>
#include "arghandler.h"
using namespace std;

// C++ Program begins execution here
int main( int argc, char* argv[] ){
    if(argc == 1) {  //no args
        zeroArguments();
    } else {
        if(argc == 2) { //only one arg
            cout << oneArgument(argv) << endl;
        } else { //>1 arg
            cout << multiArguments(argc, argv) << endl;
        }
    }
    return 0;
}
