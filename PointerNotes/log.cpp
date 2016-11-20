//---------------------------------------------------------------
//
// Log.cpp
//

#include "Log.h"
#include <algorithm>

#define NOMINMAX
#include <windows.h>

namespace {

//==============================================================================

const int s_maxLength = 70;

enum MessageType
{
	DEBUG_WINDOW,
	CONSOLE
};

void AppendLoggingInfoToLog(const std::string& functionName, std::string& messageOut)
{
	// Remove full path from the filename.
	std::stringstream ss;
	ss << messageOut;
	ss << " | " << functionName << "\n";
	messageOut = ss.str();
}

//==============================================================================

} // anonymous namespace

void Logger::LogDebugMessage(const std::string& message, LogSink messageType, const char* functionName)
{
if (message.empty())
	return;

std::string guardedMessage = message;
//AppendLoggingInfoToLog(functionName, guardedMessage);

switch (messageType)
{
case DEBUG_WINDOW:
	OutputDebugString(guardedMessage.c_str());
	break;
case CONSOLE:
	std::cout << guardedMessage;
	break;
default:
	break;
}

//==============================================================================

} // anonymous namespace
