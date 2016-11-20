//---------------------------------------------------------------
//
// Log.h
//

#pragma once

#include <string>
#include <iostream>
#include <sstream>

namespace Logger {

//==============================================================================

enum LogSink
{
	DEBUG_WINDOW,
	CONSOLE
};

void LogDebugMessage(const std::string& message, LogSink messageType, const char* functionName);

#define LOG_DEBUG_CONSOLE(msg)                                          \
{                                                                       \
LogDebugMessage(msg, Logger::CONSOLE, __FUNCTION__);          \
}

#define LOG_DEBUG_OUTPUT_WINDOW(msg)                                    \
{                                                                       \
LogDebugMessage(msg, Logger::DEBUG_WINDOW, __FILE__, __LINE__);     \
}

//==============================================================================

} // namespace Logger
