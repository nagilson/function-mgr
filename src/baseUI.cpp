/* 
Viru
baseUI.cpp 

This .cpp file establishes the main framework for building 
	and compiling data for the GUI using a function main. 

*/

#include "baseUI.h"
#define NDEBUG // The parameters sent to main are ok, and this prevents such a warning from occuring. 

// The Code Below is considered standard for GUI compilation and Builds in 
// Windows Systems. 

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ arg)

/// ------------------------------------------------------------------------------------ ///
/*
This function, main, is passed in an array of System::String pointers to manage the heap. 
Essentially, it allows the GUI in baseUI.h to build and compile. 
*/
/// ------------------------------------------------------------------------------------ ///

{
Application::EnableVisualStyles();
Application::SetCompatibleTextRenderingDefault(false);

fctMgr::baseUI form; // if the project solution changes, it must be changed here to compile 
Application::Run(%form); 
}

// End Compilation & Build Setup. 
