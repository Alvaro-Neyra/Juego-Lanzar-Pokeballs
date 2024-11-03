#include "JuegoForm.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew RepasoPC02::JuegoForm());
	//Project1 es el nombre del proyecto
}