//------------------------------------------------------------------------------
//
// Just a simple cheat sheet(program?) to help beginning programmers
// understand the following concepts
// - Passing an address to a pointer
// - Passing by reference
// - Passing by value
// - Scoping
// 
// Joshua Sanders
//

#include "Log.h"
#include <stdio.h>
#include <string.h>
#include <memory>
#include <string>
#include <functional>

namespace {

//------------------------------------------------------------------------------

// Don't freak out! You don't need to worry about this section! Move along! Its okay!
class OutputHelper
{
public:
	OutputHelper() {}
	~OutputHelper() {}

	void DataAddressOutput(int& a, int& b, char* functionName)
	{
		std::stringstream ss;
		ss << "Speed address: " << &a << " HP address: " << &b << " | " << functionName << "\n";
		LOG_DEBUG_CONSOLE(ss.str());
	}

	void DataValueOutput(int& a, int& b, char* functionName)
	{
		std::stringstream ss;
		ss << "Speed value: " << a << " HP value: " << b << " | " << functionName << "\n";
		LOG_DEBUG_CONSOLE(ss.str());
	};

	void DataPtrAddressOutput(int** ptrA, int** ptrB, char* functionName)
	{
		std::stringstream ss;
		ss << "Speed* address: " << &(*ptrA) << " HP* address : " << &(*ptrB) << " | " << functionName << "\n";
		LOG_DEBUG_CONSOLE(ss.str());
		ss.str(std::string());
	}

	void DataPtrValueAddressOutput(int* ptrA, int* ptrB, char* functionName)
	{
		std::stringstream ss;
		ss << "Speed* address: " << ptrA << " HP* address : " << ptrB << " | " << functionName << "\n";
		LOG_DEBUG_CONSOLE(ss.str());
		ss.str(std::string());
	}

	void PrintSpacerMessage()
	{
		LOG_DEBUG_CONSOLE(m_spacerMessage);
	}

private:
	const std::string m_spacerMessage = "\n--------------------------------------------------------\n\n";
};

//------------------------------------------------------------------------------

}

// We pass an actual address by value here. This creates a local copy of two pointers
// speedAddress and hpAddress.
void PassAddressByValue(int* speedAddress, int* hpAddress)
{
	OutputHelper helper;
	*speedAddress = 75;
	*hpAddress = 1000;
	// This will print the address of the temporary local pointer itself.
	helper.DataPtrAddressOutput(&speedAddress, &hpAddress, __FUNCTION__);

	// This will print the address that the pointer stores. 
	helper.DataPtrValueAddressOutput(speedAddress, hpAddress, __FUNCTION__);
	helper.DataValueOutput(*speedAddress, *hpAddress, __FUNCTION__);

} // The local speedAddress pointer and hpAddress pointer are destroyed here.

void PassByReference(int& speed, int& hp)
{
	OutputHelper helper;
	speed = 10;
	hp = 20;

	helper.DataAddressOutput(speed, hp, __FUNCTION__);
	helper.DataValueOutput(speed, hp, __FUNCTION__);
}// Neither speed, or hp are destroyed here as their lifetime is managed outside of this scope.

 // Creates a copy of speed and hp, and stores them into a different address on the stack.
void PassByValue(int speed, int hp)
{
	OutputHelper helper;
	speed = 10;
	hp = 20;

	helper.DataAddressOutput(speed, hp, __FUNCTION__);
	helper.DataValueOutput(speed, hp, __FUNCTION__);
} // Leaving scope, the copy of speed	and hp are destroyed here.

int main()
{
	// Initialize.
	OutputHelper helper;
	int speed = 0;
	int hp = 0;

	helper.DataAddressOutput(speed, hp, __FUNCTION__);
	helper.DataValueOutput(speed, hp, __FUNCTION__);

	//--------------------------------------------------------------
	helper.PrintSpacerMessage();

	// What happens when we pass by value?
	PassByValue(speed, hp);

	helper.DataValueOutput(speed, hp, __FUNCTION__);

	//--------------------------------------------------------------
	helper.PrintSpacerMessage();

	// What happens when we pass by reference?
	PassByReference(speed, hp);

	helper.DataValueOutput(speed, hp, __FUNCTION__);

	///////////////////////////////////////////////////////////////////////////
	// Bonus - This explains what was asked about passing an actual address in.
	///////////////////////////////////////////////////////////////////////////
	helper.PrintSpacerMessage();

	speed = 7;
	hp = 9;

	// A pointer is a data type that stores an address. Therefore, the value of a pointer, IS an address.
	// The address that a pointer points to does NOT have to be valid and as such is not guaranteed to be.

	// This is actually passing the address of speed and hp.
	PassAddressByValue(&speed, &hp);

	helper.DataValueOutput(speed, hp, __FUNCTION__);

	return 0;
}
