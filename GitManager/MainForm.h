﻿#pragma once

#include <string>
namespace GitManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;

	// Definir el tipo de delegado para la función callback
	public delegate void GitStatusCallback(System::Object^ sender, System::EventArgs^ e);
	public delegate void OnGitPushClickCallback(System::Object^ sender, System::EventArgs^ e);
	public delegate void btnViewData_ClickCallback(System::Object^ sender, System::EventArgs^ e);
	public delegate void OnGitAddCommitClickCallback(System::Object^ sender, System::EventArgs^ e);
	public delegate void OnConfigureGitClickCallback(System::Object^ sender, System::EventArgs^ e);
	public delegate void OnGitInitClickCallback(System::Object^ sender, System::EventArgs^ e);
	public delegate void btnExit_ClickCallback(System::Object^ sender, System::EventArgs^ e);
	public delegate void btnBrowserFolder_ClickCallback(System::Object^ sender, System::EventArgs^ e);

	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			// Asignar el callback al método
			gitStatusCallback = gcnew GitStatusCallback(this, &MainForm::OnGitStatusClick);

			gitOnGitPushClickCallback = gcnew OnGitPushClickCallback(this, &MainForm::OnGitPushClick);
			gitbtnViewData_ClickCallback = gcnew btnViewData_ClickCallback(this, &MainForm::btnViewData_Click);
			gitOnGitAddCommitClickCallback = gcnew OnGitAddCommitClickCallback(this, &MainForm::OnGitAddCommitClick);
			gitOnConfigureGitClickCallback = gcnew OnConfigureGitClickCallback(this, &MainForm::OnConfigureGitClick);
			gitOnGitInitClickCallback = gcnew OnGitInitClickCallback(this, &MainForm::OnGitInitClick);
			gitbtnExit_ClickCallback = gcnew btnExit_ClickCallback(this, &MainForm::btnExit_Click);
			gitbtnBrowseFolder_Click = gcnew btnBrowserFolder_ClickCallback(this, &MainForm::btnBrowseFolder_Click);
		}

	protected:

		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

		// Declarar el callback como un miembro de la clase	
	private:

		GitStatusCallback^ gitStatusCallback;
		OnGitPushClickCallback^ gitOnGitPushClickCallback;
		btnViewData_ClickCallback^ gitbtnViewData_ClickCallback;
		OnGitAddCommitClickCallback^ gitOnGitAddCommitClickCallback;
		OnConfigureGitClickCallback^ gitOnConfigureGitClickCallback;
		OnGitInitClickCallback^ gitOnGitInitClickCallback;
		btnExit_ClickCallback^ gitbtnExit_ClickCallback;
		btnBrowserFolder_ClickCallback^ gitbtnBrowseFolder_Click;

		System::Windows::Forms::RichTextBox^ richTextBox1;

		System::Windows::Forms::TextBox^ textBox1;
		System::Windows::Forms::TextBox^ txtUserEmail;
		System::Windows::Forms::TextBox^ txtUserName;
		System::Windows::Forms::TextBox^ txtRepoName;

		System::Windows::Forms::Button^ btnConfigureGit;
		System::Windows::Forms::Button^ button1; //Estado del Git - GitStatus
		System::Windows::Forms::Button^ btnGitPush;
		System::Windows::Forms::Button^ btnGitInit;
		System::Windows::Forms::Button^ btnGitAddCommit;
		System::Windows::Forms::Button^ btnViewData;
		System::Windows::Forms::Button^ btnExit;

		System::Windows::Forms::Button^ btnBrowseFolder;  // Botón para explorar carpetas

		bool isGitConfigured;

		System::ComponentModel::Container^ components;

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>

		TextBox^ txtRepoPath;
		Button^ btnGitStatus;
		Button^ button2;
		TextBox^ textBox2;
		TextBox^ textBox3;
		System::Windows::Forms::Label^ labelEmail;
		System::Windows::Forms::Label^ labelUsername;
		RichTextBox^ rtbGitOutput;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->txtRepoPath = (gcnew System::Windows::Forms::TextBox());
			this->btnGitStatus = (gcnew System::Windows::Forms::Button());
			this->rtbGitOutput = (gcnew System::Windows::Forms::RichTextBox());
			this->txtUserEmail = (gcnew System::Windows::Forms::TextBox());
			this->txtUserName = (gcnew System::Windows::Forms::TextBox());
			this->btnConfigureGit = (gcnew System::Windows::Forms::Button());
			this->btnGitInit = (gcnew System::Windows::Forms::Button());
			this->btnGitAddCommit = (gcnew System::Windows::Forms::Button());
			this->txtRepoName = (gcnew System::Windows::Forms::TextBox());
			this->btnGitPush = (gcnew System::Windows::Forms::Button());
			this->btnViewData = (gcnew System::Windows::Forms::Button());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->labelEmail = (gcnew System::Windows::Forms::Label());
			this->labelUsername = (gcnew System::Windows::Forms::Label());
			this->btnBrowseFolder = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// txtRepoPath
			// 
			this->txtRepoPath->Location = System::Drawing::Point(10, 10);
			this->txtRepoPath->Name = L"txtRepoPath";
			this->txtRepoPath->Size = System::Drawing::Size(400, 20);
			this->txtRepoPath->TabIndex = 1;
			// 
			// btnGitStatus
			// 
			this->btnGitStatus->Location = System::Drawing::Point(420, 10);
			this->btnGitStatus->Name = L"btnGitStatus";
			this->btnGitStatus->Size = System::Drawing::Size(100, 30);
			this->btnGitStatus->TabIndex = 2;
			this->btnGitStatus->Text = L"GitStatus";
			this->btnGitStatus->UseVisualStyleBackColor = true;
			this->btnGitStatus->Click += gcnew System::EventHandler(this, &MainForm::OnGitStatusClickWrapper);
			// 
			// rtbGitOutput
			// 
			this->rtbGitOutput->Location = System::Drawing::Point(10, 170);
			this->rtbGitOutput->Name = L"rtbGitOutput";
			this->rtbGitOutput->ReadOnly = true;
			this->rtbGitOutput->Size = System::Drawing::Size(580, 300);
			this->rtbGitOutput->TabIndex = 0;
			this->rtbGitOutput->Text = L"";
			// 
			// txtUserEmail
			// 
			this->txtUserEmail->Location = System::Drawing::Point(75, 40);
			this->txtUserEmail->Name = L"txtUserEmail";
			this->txtUserEmail->Size = System::Drawing::Size(335, 20);
			this->txtUserEmail->TabIndex = 3;
			this->txtUserEmail->Text = L"Ingrese su email de GitHub";
			// 
			// txtUserName
			// 
			this->txtUserName->Location = System::Drawing::Point(75, 70);
			this->txtUserName->Name = L"txtUserName";
			this->txtUserName->Size = System::Drawing::Size(335, 20);
			this->txtUserName->TabIndex = 4;
			this->txtUserName->Text = L"Ingrese su nombre de usuario de GitHub";
			// 
			// btnConfigureGit
			// 
			this->btnConfigureGit->Location = System::Drawing::Point(420, 40);
			this->btnConfigureGit->Name = L"btnConfigureGit";
			this->btnConfigureGit->Size = System::Drawing::Size(150, 50);
			this->btnConfigureGit->TabIndex = 5;
			this->btnConfigureGit->Text = L"Configurar Git";
			this->btnConfigureGit->Click += gcnew System::EventHandler(this, &MainForm::OnConfigureGitClickWrapper);
			// 
			// btnGitInit
			// 
			this->btnGitInit->Location = System::Drawing::Point(10, 130);
			this->btnGitInit->Name = L"btnGitInit";
			this->btnGitInit->Size = System::Drawing::Size(150, 30);
			this->btnGitInit->TabIndex = 7;
			this->btnGitInit->Text = L"Iniciar Git";
			this->btnGitInit->Click += gcnew System::EventHandler(this, &MainForm::OnGitInitClickWrapper);
			// 
			// btnGitAddCommit
			// 
			this->btnGitAddCommit->Location = System::Drawing::Point(170, 130);
			this->btnGitAddCommit->Name = L"btnGitAddCommit";
			this->btnGitAddCommit->Size = System::Drawing::Size(150, 30);
			this->btnGitAddCommit->TabIndex = 8;
			this->btnGitAddCommit->Text = L"Git Add & Commit";
			this->btnGitAddCommit->Click += gcnew System::EventHandler(this, &MainForm::OnGitAddCommitClickWrapper);
			// 
			// txtRepoName
			// 
			this->txtRepoName->Location = System::Drawing::Point(10, 100);
			this->txtRepoName->Name = L"txtRepoName";
			this->txtRepoName->Size = System::Drawing::Size(400, 20);
			this->txtRepoName->TabIndex = 6;
			this->txtRepoName->Text = L"Ingrese el nombre del repositorio";
			// 
			// btnGitPush
			// 
			this->btnGitPush->Location = System::Drawing::Point(330, 130);
			this->btnGitPush->Name = L"btnGitPush";
			this->btnGitPush->Size = System::Drawing::Size(150, 30);
			this->btnGitPush->TabIndex = 9;
			this->btnGitPush->Text = L"Git Push";
			this->btnGitPush->Click += gcnew System::EventHandler(this, &MainForm::OnGitPushClickWrapper);
			// 
			// btnViewData
			// 
			this->btnViewData->Location = System::Drawing::Point(420, 90);
			this->btnViewData->Name = L"btnViewData";
			this->btnViewData->Size = System::Drawing::Size(100, 30);
			this->btnViewData->TabIndex = 10;
			this->btnViewData->Text = L"Ver Datos";
			this->btnViewData->UseVisualStyleBackColor = true;
			this->btnViewData->Click += gcnew System::EventHandler(this, &MainForm::btnViewData_ClickWrapper);
			// 
			// btnExit
			// 
			this->btnExit->Location = System::Drawing::Point(10, 480);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(150, 50);
			this->btnExit->TabIndex = 11;
			this->btnExit->Text = L"Salir";
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &MainForm::btnExit_ClickWrapper);
			// 
			// labelEmail
			// 
			this->labelEmail->AutoSize = true;
			this->labelEmail->Location = System::Drawing::Point(21, 43);
			this->labelEmail->Name = L"labelEmail";
			this->labelEmail->Size = System::Drawing::Size(32, 13);
			this->labelEmail->TabIndex = 0;
			this->labelEmail->Text = L"Email";
			// 
			// labelUsername
			// 
			this->labelUsername->AutoSize = true;
			this->labelUsername->Location = System::Drawing::Point(7, 73);
			this->labelUsername->Name = L"labelUsername";
			this->labelUsername->Size = System::Drawing::Size(55, 13);
			this->labelUsername->TabIndex = 0;
			this->labelUsername->Text = L"Username";
			// 
			// btnBrowseFolder
			// 
			this->btnBrowseFolder->Location = System::Drawing::Point(526, 10);
			this->btnBrowseFolder->Name = L"btnBrowseFolder";
			this->btnBrowseFolder->Size = System::Drawing::Size(44, 30);
			this->btnBrowseFolder->TabIndex = 0;
			this->btnBrowseFolder->Text = L"📁\r\n";
			this->btnBrowseFolder->UseVisualStyleBackColor = true;
			this->btnBrowseFolder->Click += gcnew System::EventHandler(this, &MainForm::btnBrowseFolder_ClickWrapper);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(650, 550);
			this->Controls->Add(this->labelUsername);
			this->Controls->Add(this->labelEmail);
			this->Controls->Add(this->rtbGitOutput);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->btnGitStatus);
			this->Controls->Add(this->txtRepoPath);
			this->Controls->Add(this->txtUserEmail);
			this->Controls->Add(this->txtRepoName);
			this->Controls->Add(this->txtUserName);
			this->Controls->Add(this->btnConfigureGit);
			this->Controls->Add(this->btnGitInit);
			this->Controls->Add(this->btnGitPush);
			this->Controls->Add(this->btnViewData);
			this->Controls->Add(this->btnGitAddCommit);
			this->Controls->Add(this->btnBrowseFolder);
			this->Name = L"MainForm";
			this->Text = L"Git Manager";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:

		// El wrapper se utiliza para llamar al callback
		System::Void btnExit_ClickWrapper(System::Object^ sender, System::EventArgs^ e) {

			if (gitbtnExit_ClickCallback != nullptr) {
				gitbtnExit_ClickCallback(sender, e);
			}
		}

		System::Void btnViewData_ClickWrapper(System::Object^ sender, System::EventArgs^ e)
		{
			if (gitbtnViewData_ClickCallback != nullptr) {
				gitbtnViewData_ClickCallback(sender, e);
			}
		}
		System::Void OnGitInitClickWrapper(System::Object^ sender, System::EventArgs^ e)
		{
			if (gitOnGitInitClickCallback != nullptr) {
				gitOnGitInitClickCallback(sender, e);
			}
		}

		System::Void OnGitPushClickWrapper(System::Object^ sender, System::EventArgs^ e)
		{
			if (gitOnGitPushClickCallback != nullptr) {
				gitOnGitPushClickCallback(sender, e);
			}
		}

		System::Void OnGitAddCommitClickWrapper(System::Object^ sender, System::EventArgs^ e)
		{
			if (gitOnGitAddCommitClickCallback != nullptr) {
				gitOnGitAddCommitClickCallback(sender, e);
			}
		}

		System::Void OnGitStatusClickWrapper(System::Object^ sender, System::EventArgs^ e)
		{
			if (gitStatusCallback != nullptr) {
				gitStatusCallback(sender, e);
			}
		}

		System::Void OnConfigureGitClickWrapper(System::Object^ sender, System::EventArgs^ e)
		{
			if (gitOnConfigureGitClickCallback != nullptr) {
				gitOnConfigureGitClickCallback(sender, e);
			}
		}
		System::Void btnBrowseFolder_ClickWrapper(System::Object^ sender, System::EventArgs^ e)
		{
			if (gitbtnBrowseFolder_Click != nullptr) {
				gitbtnBrowseFolder_Click(sender, e);
			}
		}


		// Método para cerrar la ventana
		System::Void btnExit_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close(); // Cerrar la aplicación
		}
		
		// Método para ejecutar git status
		System::Void OnGitStatusClick(System::Object^ sender, System::EventArgs^ e)
		{
			String^ repoPath = this->txtRepoPath->Text;

			if (String::IsNullOrEmpty(repoPath) || !System::IO::Directory::Exists(repoPath))
			{
				MessageBox::Show("Por favor, ingrese una ruta válida al repositorio local.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			// Ejecutar el comando git status
			Process^ gitProcess = gcnew Process();
			gitProcess->StartInfo->FileName = "git";
			gitProcess->StartInfo->Arguments = "status";
			gitProcess->StartInfo->WorkingDirectory = repoPath; // Ruta local, no una URL
			gitProcess->StartInfo->RedirectStandardOutput = true;
			gitProcess->StartInfo->UseShellExecute = false;
			gitProcess->StartInfo->CreateNoWindow = true;
			gitProcess->Start();

			// Capturar la salida del comando
			String^ output = gitProcess->StandardOutput->ReadToEnd();
			gitProcess->WaitForExit();

			// Mostrar la salida en el RichTextBox
			rtbGitOutput->Text = output;
		}

		// Método para ejecutar git remote add origin y git push
		System::Void OnGitPushClick(System::Object^ sender, System::EventArgs^ e)
		{
			String^ repoPath = txtRepoPath->Text;
			String^ repoName = txtRepoName->Text;
			String^ userName = txtUserName->Text;

			if (String::IsNullOrEmpty(userName) || String::IsNullOrEmpty(repoName))
			{
				MessageBox::Show("Por favor, ingrese tanto el nombre de usuario como el nombre del repositorio.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			if (String::IsNullOrEmpty(repoPath) || !System::IO::Directory::Exists(repoPath))
			{
				MessageBox::Show("Por favor, ingrese una ruta válida al repositorio local.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			// Formar la URL del repositorio
			String^ repoURL = "https://github.com/" + userName + "/" + repoName + ".git";

			// Verificar si el repositorio existe
			Process^ gitCheckRepoProcess = gcnew Process();
			gitCheckRepoProcess->StartInfo->FileName = "git";
			gitCheckRepoProcess->StartInfo->Arguments = "ls-remote " + repoURL;
			gitCheckRepoProcess->StartInfo->RedirectStandardOutput = true;
			gitCheckRepoProcess->StartInfo->UseShellExecute = false;
			gitCheckRepoProcess->StartInfo->CreateNoWindow = true;
			gitCheckRepoProcess->Start();

			String^ checkOutput = gitCheckRepoProcess->StandardOutput->ReadToEnd();
			gitCheckRepoProcess->WaitForExit();

			if (String::IsNullOrEmpty(checkOutput))
			{
				MessageBox::Show("El repositorio no existe. Por favor, cree el repositorio en GitHub antes de continuar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			// Agregar el repositorio remoto
			try
			{
				Process^ gitCheckRemoteProcess = gcnew Process();
				gitCheckRemoteProcess->StartInfo->FileName = "git";
				gitCheckRemoteProcess->StartInfo->Arguments = "remote -v";
				gitCheckRemoteProcess->StartInfo->WorkingDirectory = repoPath;
				gitCheckRemoteProcess->StartInfo->RedirectStandardOutput = true;
				gitCheckRemoteProcess->StartInfo->RedirectStandardError = true;
				gitCheckRemoteProcess->StartInfo->UseShellExecute = false;
				gitCheckRemoteProcess->StartInfo->CreateNoWindow = true;

				gitCheckRemoteProcess->Start();

				// Capturar la salida estándar y la salida de error
				String^ remoteOutput = gitCheckRemoteProcess->StandardOutput->ReadToEnd();
				gitCheckRemoteProcess->WaitForExit();

				// Verificar si "origin" ya existe
				if (!remoteOutput->Contains("origin"))
				{
					// Si "origin" no existe, agregarlo
					Process^ gitRemoteAddProcess = gcnew Process();
					gitRemoteAddProcess->StartInfo->FileName = "git";
					gitRemoteAddProcess->StartInfo->Arguments = "remote add origin " + repoURL;
					gitRemoteAddProcess->StartInfo->WorkingDirectory = repoPath;
					gitRemoteAddProcess->StartInfo->RedirectStandardOutput = true;
					gitRemoteAddProcess->StartInfo->RedirectStandardError = true;
					gitRemoteAddProcess->StartInfo->UseShellExecute = false;
					gitRemoteAddProcess->StartInfo->CreateNoWindow = true;

					gitRemoteAddProcess->Start();

					String^ addOutput = gitRemoteAddProcess->StandardOutput->ReadToEnd();
					String^ addErrorOutput = gitRemoteAddProcess->StandardError->ReadToEnd();
					gitRemoteAddProcess->WaitForExit();

					// Mostrar la salida en el RichTextBox
					rtbGitOutput->Text = addOutput;

					if (gitRemoteAddProcess->ExitCode != 0)
					{
						throw gcnew Exception("Error al ejecutar 'git remote add origin': " + addErrorOutput);
					}
				}

				// Ejecutar git push -u origin master
				Process^ gitPushProcess = gcnew Process();
				gitPushProcess->StartInfo->FileName = "git";
				gitPushProcess->StartInfo->Arguments = "push -u origin master";
				gitPushProcess->StartInfo->WorkingDirectory = repoPath;
				gitPushProcess->StartInfo->RedirectStandardOutput = true;
				gitPushProcess->StartInfo->RedirectStandardError = true;
				gitPushProcess->StartInfo->UseShellExecute = false;
				gitPushProcess->StartInfo->CreateNoWindow = true;

				gitPushProcess->Start();

				String^ pushOutput = gitPushProcess->StandardOutput->ReadToEnd();
				String^ pushErrorOutput = gitPushProcess->StandardError->ReadToEnd();
				gitPushProcess->WaitForExit();

				if (gitPushProcess->ExitCode != 0)
				{
					throw gcnew Exception("Error al ejecutar 'git push -u origin master': " + pushErrorOutput);
				}

				// Mostrar la salida en el RichTextBox
				rtbGitOutput->Text = pushOutput;

				// Mostrar éxito al usuario
				MessageBox::Show("Cambios empujados exitosamente a 'origin/master'", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			catch (Exception^ ex)
			{
				// Mostrar un mensaje de error al usuario
				MessageBox::Show("Ocurrió un error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		
		// Método para ver los datos
		System::Void btnViewData_Click(System::Object^ sender, System::EventArgs^ e) {
			// Obtener datos de los TextBox
			String^ email = txtUserEmail->Text;
			String^ userName = txtUserName->Text;
			String^ repoPath = txtRepoPath->Text;
			String^ repoName = txtRepoName->Text;

			// Construir el mensaje
			String^ message = "Correo Electrónico: " + email + "\n" +
				"Nombre de Usuario: " + userName + "\n" +
				"Ruta del Repositorio: " + repoPath + "\n" +
				"Nombre del Repositorio: " + repoName;

			// Mostrar el mensaje
			MessageBox::Show(message, "Datos del Usuario");
		}

		// Método para ejecutar git add . y git commit
		System::Void OnGitAddCommitClick(System::Object^ sender, System::EventArgs^ e)
		{
			String^ repoPath = txtRepoPath->Text;

			if (!isGitConfigured)
			{
				MessageBox::Show("Por favor, configure Git con su correo electrónico y nombre de usuario antes de continuar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			if (String::IsNullOrEmpty(repoPath) || !System::IO::Directory::Exists(repoPath))
			{
				MessageBox::Show("Por favor, ingrese una ruta válida al repositorio local.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			// Ejecutar git add .
			Process^ gitAddProcess = gcnew Process();
			gitAddProcess->StartInfo->FileName = "git";
			gitAddProcess->StartInfo->Arguments = "add .";
			gitAddProcess->StartInfo->WorkingDirectory = repoPath;
			gitAddProcess->StartInfo->RedirectStandardOutput = true;
			gitAddProcess->StartInfo->UseShellExecute = false;
			gitAddProcess->StartInfo->CreateNoWindow = true;
			gitAddProcess->Start();
			gitAddProcess->WaitForExit();

			// Ejecutar git commit
			Process^ gitCommitProcess = gcnew Process();
			gitCommitProcess->StartInfo->FileName = "git";
			gitCommitProcess->StartInfo->Arguments = "commit -m \"First commit\"";
			gitCommitProcess->StartInfo->WorkingDirectory = repoPath;
			gitCommitProcess->StartInfo->RedirectStandardOutput = true;
			gitCommitProcess->StartInfo->UseShellExecute = false;
			gitCommitProcess->StartInfo->CreateNoWindow = true;
			gitCommitProcess->Start();

			// Capturar la salida del comando git commit
			String^ output = gitCommitProcess->StandardOutput->ReadToEnd();
			gitCommitProcess->WaitForExit();

			MessageBox::Show("Espere unos segundos.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);

			// Mostrar la salida en el RichTextBox
			rtbGitOutput->Text = output;
		}

		// Inicializar un repositorio Git en la carpeta especificada
		System::Void OnGitInitClick(System::Object^ sender, System::EventArgs^ e)
		{
			String^ repoPath = txtRepoPath->Text;

			if (String::IsNullOrEmpty(repoPath) || !System::IO::Directory::Exists(repoPath))
			{
				MessageBox::Show("Por favor, ingrese una ruta válida al repositorio local.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			// Ejecutar el comando git init
			Process^ gitInitProcess = gcnew Process();
			gitInitProcess->StartInfo->FileName = "git";
			gitInitProcess->StartInfo->Arguments = "init";
			gitInitProcess->StartInfo->WorkingDirectory = repoPath;
			gitInitProcess->StartInfo->RedirectStandardOutput = true;
			gitInitProcess->StartInfo->UseShellExecute = false;
			gitInitProcess->StartInfo->CreateNoWindow = true;
			gitInitProcess->Start();

			// Capturar la salida del comando
			String^ output = gitInitProcess->StandardOutput->ReadToEnd();
			gitInitProcess->WaitForExit();

			// Mostrar la salida en el RichTextBox
			rtbGitOutput->Text = output;
		}

		// Configurar Git con email y nombre de usuario
		System::Void OnConfigureGitClick(System::Object^ sender, System::EventArgs^ e)
		{
			String^ userEmail = txtUserEmail->Text;
			String^ userName = txtUserName->Text;

			if (String::IsNullOrEmpty(userEmail) || String::IsNullOrEmpty(userName))
			{
				MessageBox::Show("Por favor, ingrese tanto el correo electrónico como el nombre de usuario.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			// Configurar el email de Git
			Process^ gitConfigEmail = gcnew Process();
			gitConfigEmail->StartInfo->FileName = "git";
			gitConfigEmail->StartInfo->Arguments = "config --global user.email \"" + userEmail + "\"";
			gitConfigEmail->StartInfo->RedirectStandardOutput = true;
			gitConfigEmail->StartInfo->UseShellExecute = false;
			gitConfigEmail->StartInfo->CreateNoWindow = true;
			gitConfigEmail->Start();
			gitConfigEmail->WaitForExit();

			// Configurar el nombre de usuario de Git
			Process^ gitConfigName = gcnew Process();
			gitConfigName->StartInfo->FileName = "git";
			gitConfigName->StartInfo->Arguments = "config --global user.name \"" + userName + "\"";
			gitConfigName->StartInfo->RedirectStandardOutput = true;
			gitConfigName->StartInfo->UseShellExecute = false;
			gitConfigName->StartInfo->CreateNoWindow = true;
			gitConfigName->Start();
			gitConfigName->WaitForExit();

			MessageBox::Show("Git configurado correctamente con el correo electrónico y nombre de usuario proporcionados.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
		
			// Marcar que Git ha sido configurado
			isGitConfigured = true;
		}

		// Método para buscar carpetas en el sistema
		System::Void btnBrowseFolder_Click(System::Object^ sender, System::EventArgs^ e) {
			FolderBrowserDialog^ folderBrowserDialog = gcnew FolderBrowserDialog();

			// Configurar y mostrar el diálogo
			if (folderBrowserDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				// Establecer la ruta seleccionada en el TextBox
				this->txtRepoPath->Text = folderBrowserDialog->SelectedPath;
			}
		}
	};
}
