#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <typeinfo>
#include "util/comparator.h"



#if defined (DSA_DEBUG)
#define DSA(x) {x}

#else
#define DSA(x) 

#endif
