#include <array>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]

void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MyoEMG::MyForm form;
	Application::Run(%form);
}