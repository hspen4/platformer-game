#ifndef ASSERT_H
#define ASSERT_H

#include <cassert>
#define assertm(exp, message) assert(((void)message, exp))

#endif
