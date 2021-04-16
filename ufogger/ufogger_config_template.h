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

#ifndef __UFOGGER_CONFIG_TEMPLATE_H__
#define __UFOGGER_CONFIG_TEMPLATE_H__

/* ===== INCLUDES =========================================================== */

/* ===== DEFINITIONS ======================================================== */

/* ===== IMPLEMENTATION ===================================================== */

#ifdef UFOGGER_FEATURE_COLORS
#define __UFOGGER_FEATURE_COLORS_DEBUG // color formating expression for DEBUG output
#define __UFOGGER_FEATURE_COLORS_INFO  // color formating expression for INFO output
#define __UFOGGER_FEATURE_COLORS_WARN  // color formating expression for WARNING output
#define __UFOGGER_FEATURE_COLORS_ERROR // color formating expression for ERROR output
#else
#define __UFOGGER_FEATURE_COLORS_DEBUG "[DEBUG] "
#define __UFOGGER_FEATURE_COLORS_INFO  "[INFO] "
#define __UFOGGER_FEATURE_COLORS_WARN  "[WARN] "
#define __UFOGGER_FEATURE_COLORS_ERROR "[ERROR] "
#endif

#ifdef UFOGGER_FEATURE_VERBOSE
#define UFOGGER_CONFIG_LOG_DEBUG(fmt, ...)            // expression for verbose DEBUG output
#define UFOGGER_CONFIG_LOG_INFO(fmt, ...)             // expression for verbose INFO output
#define UFOGGER_CONFIG_LOG_WARN(fmt, ...)             // expression for verbose WARNING output
#define UFOGGER_CONFIG_LOG_ERROR(fmt, ...)            // expression for verbose WARNING output
#define UFOGGER_CONFIG_HEXDUMP_DEBUG(msg, data, size) // expression for verbose DEBUG hexdump
#define UFOGGER_CONFIG_HEXDUMP_INFO(msg, data, size)  // expression for verbose INFO hexdump
#define UFOGGER_CONFIG_HEXDUMP_WARN(msg, data, size)  // expression for verbose WARNING hexdump
#define UFOGGER_CONFIG_HEXDUMP_ERROR(msg, data, size) // expression for verbose WARNING hexdump
#else
#define UFOGGER_CONFIG_LOG_DEBUG(fmt, ...)            // expression for compact DEBUG output
#define UFOGGER_CONFIG_LOG_INFO(fmt, ...)             // expression for compact INFO output
#define UFOGGER_CONFIG_LOG_WARN(fmt, ...)             // expression for compact WARNING output
#define UFOGGER_CONFIG_LOG_ERROR(fmt, ...)            // expression for compact ERROR output
#define UFOGGER_CONFIG_HEXDUMP_DEBUG(msg, data, size) // expression for compact DEBUG hexdump
#define UFOGGER_CONFIG_HEXDUMP_INFO(msg, data, size)  // expression for compact INFO hexdump
#define UFOGGER_CONFIG_HEXDUMP_WARN(msg, data, size)  // expression for compact WARNING hexdump
#define UFOGGER_CONFIG_HEXDUMP_ERROR(msg, data, size) // expression for compact WARNING hexdump
#endif

#ifdef UFOGGER_FEATURE_TRACE
#define UFOGGER_CONFIG_TRACE_ENTER(fmt, ...) // expression for output enter function
#define UFOGGER_CONFIG_TRACE_EXIT(fmt, ...)  // expression for output exit function
#else
#define UFOGGER_CONFIG_TRACE_ENTER(fmt, ...)
#define UFOGGER_CONFIG_TRACE_EXIT(fmt, ...)
#endif

#endif //__UFOGGER_CONFIG_TEMPLATE_H__