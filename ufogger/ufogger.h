/*
 * UFOgger - ultimate logger framework
 * Copyright (C) 2021  Octaviarius
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
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef __UFOGGER_H__
#define __UFOGGER_H__

/**
For use: define in interesting module this code below:

#define UFOGGER_CONFIG_FILEPATH "path_to_ufogger_config.h"
#define UFOGGER_LEVEL_(DEBUG|INFO|WARNING|ERROR|OFF)
#define UFOGGER_TAG_NAME "TAG_NAME"
#define UFOGGER_FEATURE_TRACE
#define UFOGGER_FEATURE_VERBOSE
#define UFOGGER_FEATURE_COLORS
#include <ufogger.h>


Use for simple log:

UFOGGER_LOG_DEBUG("format string", <args>)
UFOGGER_LOG_INFO("format string", <args>)
UFOGGER_LOG_WARN("format string", <args>)
UFOGGER_LOG_ERROR("format string", <args>)


Use for hexdump:

UFOGGER_HEXDUMP_DEBUG("message", data, size)
UFOGGER_HEXDUMP_INFO("message", data, size)
UFOGGER_HEXDUMP_WARN("message", data, size)
UFOGGER_HEXDUMP_ERROR("message", data, size)

Use for assertion log:

UFOGGER_ASSERT_DEBUG(condition, "format string", <args>)
UFOGGER_ASSERT_INFO(condition, "format string", <args>)
UFOGGER_ASSERT_WARN(condition, "format string", <args>)
UFOGGER_ASSERT_ERROR(condition, "format string", <args>)


Use for trace functions:

UFOGGER_TRACE_ENTER("function arguments format", <args>)
UFOGGER_TRACE_EXIT("function result format", <result>)


Minimalistic example:

#define UFOGGER_LEVEL_DEBUG
#define UFOGGER_TAG_NAME "MAIN"
#include <ufogger.h>

*/

/** Define default config filepath */
#ifndef UFOGGER_CONFIG_FILEPATH
#ifdef UFOGGER_CONFIG_FILEPATH_DEFAULT
#define UFOGGER_CONFIG_FILEPATH UFOGGER_CONFIG_FILEPATH_DEFAULT
#else
#define UFOGGER_CONFIG_FILEPATH <ufogger_config.h>
#endif
#endif

/** Include configuration file */
#include UFOGGER_CONFIG_FILEPATH

/** Define default name */
#ifndef UFOGGER_TAG_NAME
#ifdef UFOGGER_CONFIG_TAG_NAME_DEFAULT
#define UFOGGER_TAG_NAME UFOGGER_CONFIG_TAG_NAME_DEFAULT
#else
#define UFOGGER_TAG_NAME ""
#endif
#endif

#ifdef UFOGGER_LEVEL_DEBUG
#define UFOGGER_LOG_DEBUG(fmt, ...)            UFOGGER_CONFIG_LOG_DEBUG(fmt, ##__VA_ARGS__)
#define UFOGGER_LOG_INFO(fmt, ...)             UFOGGER_CONFIG_LOG_INFO(fmt, ##__VA_ARGS__)
#define UFOGGER_LOG_WARN(fmt, ...)             UFOGGER_CONFIG_LOG_WARN(fmt, ##__VA_ARGS__)
#define UFOGGER_LOG_ERROR(fmt, ...)            UFOGGER_CONFIG_LOG_ERROR(fmt, ##__VA_ARGS__)
#define UFOGGER_HEXDUMP_DEBUG(msg, data, size) UFOGGER_CONFIG_HEXDUMP_DEBUG(msg, data, size)
#define UFOGGER_HEXDUMP_INFO(msg, data, size)  UFOGGER_CONFIG_HEXDUMP_INFO(msg, data, size)
#define UFOGGER_HEXDUMP_WARN(msg, data, size)  UFOGGER_CONFIG_HEXDUMP_WARN(msg, data, size)
#define UFOGGER_HEXDUMP_ERROR(msg, data, size) UFOGGER_CONFIG_HEXDUMP_ERROR(msg, data, size)

#ifdef UFOGGER_FEATURE_TRACE
#define UFOGGER_TRACE_ENTER(fmt, ...) UFOGGER_CONFIG_TRACE_ENTER(fmt, ##__VA_ARGS__)
#define UFOGGER_TRACE_EXIT(fmt, ...)  UFOGGER_CONFIG_TRACE_EXIT(fmt, ##__VA_ARGS__)
#else
#define UFOGGER_TRACE_ENTER(fmt, ...)
#define UFOGGER_TRACE_EXIT(fmt, ...)
#endif

#else
#define UFOGGER_LOG_DEBUG(fmt, ...)
#define UFOGGER_HEXDUMP_DEBUG(msg, data, size)
#define UFOGGER_TRACE_ENTER(fmt, ...)
#define UFOGGER_TRACE_EXIT(fmt, ...)

#ifdef UFOGGER_LEVEL_INFO
#define UFOGGER_LOG_INFO(fmt, ...)             UFOGGER_CONFIG_LOG_INFO(fmt, ##__VA_ARGS__)
#define UFOGGER_LOG_WARN(fmt, ...)             UFOGGER_CONFIG_LOG_WARN(fmt, ##__VA_ARGS__)
#define UFOGGER_LOG_ERROR(fmt, ...)            UFOGGER_CONFIG_LOG_ERROR(fmt, ##__VA_ARGS__)
#define UFOGGER_HEXDUMP_INFO(msg, data, size)  UFOGGER_CONFIG_HEXDUMP_INFO(msg, data, size)
#define UFOGGER_HEXDUMP_WARN(msg, data, size)  UFOGGER_CONFIG_HEXDUMP_WARN(msg, data, size)
#define UFOGGER_HEXDUMP_ERROR(msg, data, size) UFOGGER_CONFIG_HEXDUMP_ERROR(msg, data, size)
#else
#define UFOGGER_LOG_INFO(fmt, ...)
#define UFOGGER_HEXDUMP_INFO(msg, data, size)

#ifdef UFOGGER_LEVEL_WARN
#define UFOGGER_LOG_WARN(fmt, ...)             UFOGGER_CONFIG_LOG_WARN(fmt, ##__VA_ARGS__)
#define UFOGGER_LOG_ERROR(fmt, ...)            UFOGGER_CONFIG_LOG_ERROR(fmt, ##__VA_ARGS__)
#define UFOGGER_HEXDUMP_WARN(msg, data, size)  UFOGGER_CONFIG_HEXDUMP_INFO(msg, data, size)
#define UFOGGER_HEXDUMP_ERROR(msg, data, size) UFOGGER_CONFIG_HEXDUMP_WARN(msg, data, size)
#else
#define UFOGGER_LOG_WARN(fmt, ...)
#define UFOGGER_HEXDUMP_WARN(msg, data, size)

#ifdef UFOGGER_LEVEL_ERROR
#define UFOGGER_LOG_ERROR(fmt, ...)            UFOGGER_CONFIG_LOG_ERROR(fmt, ##__VA_ARGS__)
#define UFOGGER_HEXDUMP_ERROR(msg, data, size) UFOGGER_CONFIG_HEXDUMP_ERROR(msg, data, size)
#else
#define UFOGGER_LOG_ERROR(fmt, ...)
#define UFOGGER_HEXDUMP_ERROR(msg, data, size)

#endif // ifdef ERROR
#endif // ifdef WARN
#endif // ifdef INFO
#endif // ifdef DEBUG

#define UFOGGER_ASSERT_DEBUG(condition, fmt, ...)         \
    do                                                    \
    {                                                     \
        if (!(condition))                                 \
        {                                                 \
            UFOGGER_CONFIG_LOG_DEBUG(fmt, ##__VA_ARGS__); \
        }                                                 \
    } while (0)

#define UFOGGER_ASSERT_INFO(condition, fmt, ...)         \
    do                                                   \
    {                                                    \
        if (!(condition))                                \
        {                                                \
            UFOGGER_CONFIG_LOG_INFO(fmt, ##__VA_ARGS__); \
        }                                                \
    } while (0)

#define UFOGGER_ASSERT_WARN(condition, fmt, ...)         \
    do                                                   \
    {                                                    \
        if (!(condition))                                \
        {                                                \
            UFOGGER_CONFIG_LOG_WARN(fmt, ##__VA_ARGS__); \
        }                                                \
    } while (0)

#define UFOGGER_ASSERT_ERROR(condition, fmt, ...)         \
    do                                                    \
    {                                                     \
        if (!(condition))                                 \
        {                                                 \
            UFOGGER_CONFIG_LOG_ERROR(fmt, ##__VA_ARGS__); \
        }                                                 \
    } while (0)

#endif //__UFOGGER_H__