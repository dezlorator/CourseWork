#include "MyForm.h"
using namespace System::Windows::Forms;


void main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Lab4::MyForm form; //WinFormsTest - имя вашего проекта
	Application::Run(% form);
}

