#include "headers/error_handler.h"

#include <iostream>
#include <sstream>
#include <string>

bool checkStringVal(string val){
    if (val.length() == 0)
        return false;
    else if (val.length() > 0)
        return true;
    else
        return false;
}

error_handler::error_handler()
{

}
