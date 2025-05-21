#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Lab8_Graphics::MyForm^ form = gcnew Lab8_Graphics::MyForm();
    Application::Run(form);
    return 0;
}
