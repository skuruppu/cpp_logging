Logging
=======

A macro that allows logging using the insertion (`<<`) operator for C++.

Usage
-----

    LOG(level) << expr1 << expr2 << ...;

`level` is the log level.
`expr` can be any expression.

Only log messages with a level greater than or equal to the LOGLEVEL value are
output. Compile your program with -DLOGLEVEL=log_level to specify the minimum
log level. All log messages are output to `std::cerr`.

Available log levels:

    DEBUG       0
    INFO        1
    WARNING     2
    ERROR       3
    CRITICAL    4

Example
-------

    #include <exception>

    #include "logging.h"

    int main(int argc, char** argv) {
        int x = 5, y = 10, z;

        // LOGLEVEL=1
        LOG(INFO) << "Running program...";

        // LOGLEVEL=0
        z = x + y;
        LOG(DEBUG) << "x+y = " << z;

        // LOGLEVEL=2
        z = x;
        if (z < y) {
            LOG(WARNING) << "z=" << z << " < y=" << y;
        }

        // LOGLEVEL=3
        z = x + y + 1;
        if (z != x + y) {
            LOG(ERROR) << "z=" << z << " != " << x + y;
        }

        // LOGLEVEL=4
        try {
            int* large_array = new int[1000000000000];
        } catch (std::exception& e) {
            LOG(CRITICAL) << e.what();
        }

        return 0;
    }

Distribution
------------

Refer to the `COPYING` file for licensing information of this program.
