// CloneRepoForm.h
#pragma once

namespace GitManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Diagnostics;

	// Definir el tipo de delegado para la función callback
	public delegate void GitCloneCallback(System::Object^ sender, System::EventArgs^ e);
	public delegate void GitCloseCallback(System::Object^ sender, System::EventArgs^ e);

	public ref class CloneRepoForm : public System::Windows::Forms::Form
	{
	public:
		CloneRepoForm(System::String^ textRepo)
		{
			textRepoPath = textRepo;
			InitializeComponent();

			// Asignar el callback al método
			gitCloneCallback = gcnew GitCloneCallback(this, &CloneRepoForm::btnCloneRepo_Click);
			gitCloseCallback = gcnew GitCloseCallback(this, &CloneRepoForm::btnClose_Click);
		}

	protected:
		~CloneRepoForm()
		{
			if (components)
			{
				delete components;
			}
		}

		// Componentes de la ventana
	private:

		GitCloneCallback^ gitCloneCallback;
		GitCloseCallback^ gitCloseCallback;

		System::Windows::Forms::TextBox^ txtRepoURL;
		System::Windows::Forms::TextBox^ txtFolderName;
		System::Windows::Forms::Button^ btnCloneRepo;
		System::Windows::Forms::Button^ btnClose;
		System::Windows::Forms::Label^ lblRepoURL;
		System::Windows::Forms::Label^ lblFolderName;
		System::Windows::Forms::RichTextBox^ rtbCloneOutput;
		System::String^ textRepoPath;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{

			this->txtRepoURL = (gcnew System::Windows::Forms::TextBox());
			this->txtFolderName = (gcnew System::Windows::Forms::TextBox());
			this->btnCloneRepo = (gcnew System::Windows::Forms::Button());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->lblRepoURL = (gcnew System::Windows::Forms::Label());
			this->lblFolderName = (gcnew System::Windows::Forms::Label());
			this->rtbCloneOutput = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();

			// 
			// lblRepoURL
			// 
			this->lblRepoURL->Location = System::Drawing::Point(50, 20);
			this->lblRepoURL->Name = L"lblRepoURL";
			this->lblRepoURL->Size = System::Drawing::Size(100, 23);
			this->lblRepoURL->Text = L"URL del Repositorio:";

			// 
			// txtRepoURL
			// 
			this->txtRepoURL->Location = System::Drawing::Point(160, 20);
			this->txtRepoURL->Name = L"txtRepoURL";
			this->txtRepoURL->Size = System::Drawing::Size(300, 20);
			this->txtRepoURL->TabIndex = 0;

			// 
			// lblFolderName
			// 
			this->lblFolderName->Location = System::Drawing::Point(50, 60);
			this->lblFolderName->Name = L"lblFolderName";
			this->lblFolderName->Size = System::Drawing::Size(100, 23);
			this->lblFolderName->Text = L"Nombre de Carpeta:";

			// 
			// txtFolderName
			// 
			this->txtFolderName->Location = System::Drawing::Point(160, 60);
			this->txtFolderName->Name = L"txtFolderName";
			this->txtFolderName->Size = System::Drawing::Size(300, 20);
			this->txtFolderName->TabIndex = 1;

			// 
			// btnCloneRepo
			// 
			this->btnCloneRepo->Location = System::Drawing::Point(200, 100);
			this->btnCloneRepo->Name = L"btnCloneRepo";
			this->btnCloneRepo->Size = System::Drawing::Size(100, 25);
			this->btnCloneRepo->Text = L"Clonar";
			this->btnCloneRepo->UseVisualStyleBackColor = true;
			this->btnCloneRepo->Click += gcnew System::EventHandler(this, &CloneRepoForm::btnCloneRepo_ClickWrapper);
		
			// 
			// btnClose
			// 
			this->btnClose->Location = System::Drawing::Point(320, 100);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(100, 25);
			this->btnClose->Text = L"Cerrar";
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &CloneRepoForm::btnClose_ClickWrapper);

			// 
			// rtbCloneOutput
			// 
			this->rtbCloneOutput->Location = System::Drawing::Point(50, 150);
			this->rtbCloneOutput->Name = L"rtbCloneOutput";
			this->rtbCloneOutput->Size = System::Drawing::Size(400, 200);
			this->rtbCloneOutput->TabIndex = 3;
			this->rtbCloneOutput->ReadOnly = true;
			this->rtbCloneOutput->Text = L"";

			// 
			// CloneRepoForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(500, 400);
			this->Controls->Add(this->txtRepoURL);
			this->Controls->Add(this->txtFolderName);
			this->Controls->Add(this->btnCloneRepo);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->lblRepoURL);
			this->Controls->Add(this->lblFolderName);
			this->Controls->Add(this->rtbCloneOutput);
			this->Name = L"CloneRepoForm";
			this->Text = L"Clonar Repositorio";
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

		System::Void btnCloneRepo_ClickWrapper(System::Object^ sender, System::EventArgs^ e)
		{
			if (gitCloneCallback != nullptr) {
				gitCloneCallback(sender, e);
			}
		}

		System::Void btnClose_ClickWrapper(System::Object^ sender, System::EventArgs^ e)
		{
			if (gitCloseCallback != nullptr) {
				gitCloseCallback(sender, e);
			}
		}

		// Método para clonar el repositorio
		System::Void btnCloneRepo_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ repoPath = textRepoPath;
			String^ repoURL = this->txtRepoURL->Text;
			String^ folderName = this->txtFolderName->Text;

			if (String::IsNullOrEmpty(repoURL) || String::IsNullOrEmpty(folderName)) {
				MessageBox::Show("Por favor, ingresa la URL del repositorio y el nombre de la carpeta.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			try {
				// Verificar si la carpeta ya existe
				if (Directory::Exists(repoPath + "\\" + folderName)) {
					MessageBox::Show("La carpeta ya existe. Ingresa un nombre de carpeta diferente.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}

				// Crear la carpeta
				Directory::CreateDirectory(repoPath + "\\" + folderName);

				// Ejecutar el comando git clone
				Process^ gitCloneProcess = gcnew Process();
				gitCloneProcess->StartInfo->FileName = "git";
				gitCloneProcess->StartInfo->Arguments = "clone " + repoURL + " " + folderName;
				gitCloneProcess->StartInfo->WorkingDirectory = repoPath;
				gitCloneProcess->StartInfo->RedirectStandardOutput = true;
				gitCloneProcess->StartInfo->RedirectStandardError = true;
				gitCloneProcess->StartInfo->UseShellExecute = false;
				gitCloneProcess->StartInfo->CreateNoWindow = true;

				gitCloneProcess->Start();

				// Capturar la salida del comando git
				String^ errorOutput = gitCloneProcess->StandardError->ReadToEnd();
				gitCloneProcess->WaitForExit();

				if (!String::IsNullOrEmpty(errorOutput)) {
					this->rtbCloneOutput->AppendText(errorOutput + "\n");
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show("Ocurrió un error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		   // Método para cerrar la ventana y volver a la pantalla principal
		System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();  // Cerrar la ventana
		}
	};
}
