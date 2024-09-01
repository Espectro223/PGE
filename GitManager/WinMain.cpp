#include "StartScreen.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Crea una instancia de MainForm y ejecuta la aplicación

    Application::Run(gcnew GitManager::StartScreen());
    return 0;
}