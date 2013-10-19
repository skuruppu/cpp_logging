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
 * Logging -- A simple logger that permits use of the stream syntax.
 * Author: Shanika Kuruppu
 * Usage: LOG(level) << expr1 << expr2 << ...;
 * The logging level is the minimum level a log message must satisfy before it
 * is output.
 */

#ifndef INCLUDE_LOG_H
#define INCLUDE_LOG_H

#include <iostream>

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

// If the minimum log level requirement is satisfied then prints the log
// message. This works because the & operator has lower precedence than the <<
// operator, therefore the stream output is evaluated before the Log class is
// initialised.
#define LOG(log_level) log_level >= LOGLEVEL && \
                       Log() & std::cerr << __FILE__ << ':' << __LINE__ << ':'

#endif
