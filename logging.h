/* Logging
 * Copyright (C) 2013 Shanika Kuruppu
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * Logging -- Allows logging using the insertion (`<<`) operator.
 * Author: Shanika Kuruppu
 * Usage: LOG(level) << expr1 << expr2 << ...;
 */

#ifndef INCLUDE_LOG_H
#define INCLUDE_LOG_H

#include <iostream>
#include <stdio.h>
#include <string>

#define DEBUG 0
#define INFO 1
#define WARNING 2
#define ERROR 3
#define CRITICAL 4

#ifndef LOGLEVEL
#define LOGLEVEL WARNING
#endif

class Log {
public:
    bool operator&(std::ostream& stream) {
        stream << std::endl;
        return true;
    }
};

std::string log_level_to_str(const int log_level) {
    char buf[12];
    std::string str = "";

    switch(log_level) {
        case DEBUG:
            str = "[DEBUG]";
            break;
        case INFO:
            str = "[INFO]";
            break;
        case WARNING:
            str = "[WARNING]";
            break;
        case ERROR:
            str = "[ERROR]";
            break;
        case CRITICAL:
            str = "[CRITICAL]";
            break;
        default:
            break;
    }

    sprintf(buf, "%-11s ", str.c_str());
    return buf;
}

// If the minimum log level requirement is satisfied then prints the log
// message. This works because the & operator has lower precedence than the <<
// operator, therefore the stream output is evaluated before the Log class is
// initialised.
#define LOG(log_level) log_level >= LOGLEVEL && \
                            Log() & std::cerr << \
                            log_level_to_str(log_level) <<  \
                            __FILE__ << ':' << __LINE__ << ": "

#endif
