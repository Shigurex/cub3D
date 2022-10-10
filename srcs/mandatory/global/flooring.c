#include "debug.h"

unsigned int flooring(unsigned int set)
{
    static unsigned int clor;

    if (set)
        clor = set;
    return (clor);
}