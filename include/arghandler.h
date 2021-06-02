#ifndef __ARG_HANDLER_H__
#define __ARG_HANDLER_H__

#include <string>

void zeroArguments();
std::string oneArgument( char *argv[] );
int multiArguments( int argc, char *args[] );

#endif
