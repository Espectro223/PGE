#pragma once
#include "MainForm.h"

namespace GitManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	public delegate void CloseCallback(System::Object^ sender, System::EventArgs^ e);
	public delegate void StartCallback(System::Object^ sender, System::EventArgs^ e);
	public delegate void ConfigCallback(System::Object^ sender, System::EventArgs^ e);

	public ref class StartScreen : public System::Windows::Forms::Form
	{
	public:
		StartScreen(void)
		{
			InitializeComponent();
			closecallback = gcnew CloseCallback(this, &StartScreen::btnExit_Click);
			startcallback = gcnew StartCallback(this, &StartScreen::btnStart_Click);
			configcallback = gcnew ConfigCallback(this, &StartScreen::btnConfig_Click);
		}

	protected:
		~StartScreen()
		{
			if (components)
			{
				delete components;
			}
		}
	private: 
		System::Windows::Forms::Label^ labelTitle;
		System::Windows::Forms::Label^ labelAuthors;
		System::Windows::Forms::Button^ btnStart;
		System::Windows::Forms::Button^ btnConfig;
		System::Windows::Forms::Button^ btnExit;

		CloseCallback^ closecallback;
		StartCallback^ startcallback;
		ConfigCallback^ configcallback;

		System::Windows::Forms::GroupBox^ configGroupBox;
		System::Windows::Forms::TextBox^ txtConfigDetails;

	private:
		System::ComponentModel::Container ^components;

		// Destructor para la liberación de recursos no administrados
		!StartScreen() {

			if (components)
			{
				delete components;
			}
		}

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(StartScreen::typeid));
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			this->labelAuthors = (gcnew System::Windows::Forms::Label());
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->btnConfig = (gcnew System::Windows::Forms::Button());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->configGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->txtConfigDetails = (gcnew System::Windows::Forms::TextBox());
			this->configGroupBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// labelTitle
			// 
			this->labelTitle->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->labelTitle->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelTitle->Location = System::Drawing::Point(150, 50);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(300, 50);
			this->labelTitle->TabIndex = 0;
			this->labelTitle->Text = L"Git Manager";
			this->labelTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelAuthors
			// 
			this->labelAuthors->AutoSize = true;
			this->labelAuthors->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->labelAuthors->Location = System::Drawing::Point(235, 117);
			this->labelAuthors->Name = L"labelAuthors";
			this->labelAuthors->Size = System::Drawing::Size(128, 60);
			this->labelAuthors->TabIndex = 1;
			this->labelAuthors->Text = L"   Autores: \r\nKarpowicz Edgar\r\n  Molina Tomás";
			this->labelAuthors->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btnStart
			// 
			this->btnStart->BackColor = System::Drawing::Color::LightSkyBlue;
			this->btnStart->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnStart->Location = System::Drawing::Point(250, 250);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(100, 30);
			this->btnStart->TabIndex = 4;
			this->btnStart->Text = L"Iniciar";
			this->btnStart->UseVisualStyleBackColor = false;
			this->btnStart->Click += gcnew System::EventHandler(this, &StartScreen::btnStart_ClickWrapper);
			// 
			// btnConfig
			// 
			this->btnConfig->BackColor = System::Drawing::Color::LightSkyBlue;
			this->btnConfig->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnConfig->Location = System::Drawing::Point(250, 200);
			this->btnConfig->Name = L"btnConfig";
			this->btnConfig->Size = System::Drawing::Size(100, 30);
			this->btnConfig->TabIndex = 3;
			this->btnConfig->Text = L"Detalles";
			this->btnConfig->UseVisualStyleBackColor = false;
			this->btnConfig->Click += gcnew System::EventHandler(this, &StartScreen::btnConfig_ClickWrapper);
			// 
			// btnExit
			// 
			this->btnExit->BackColor = System::Drawing::Color::LightSkyBlue;
			this->btnExit->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnExit->Location = System::Drawing::Point(250, 300);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(100, 30);
			this->btnExit->TabIndex = 2;
			this->btnExit->Text = L"Salir";
			this->btnExit->UseVisualStyleBackColor = false;
			this->btnExit->Click += gcnew System::EventHandler(this, &StartScreen::btnExit_ClickWrapper);
			// 
			// configGroupBox
			// 
			this->configGroupBox->Controls->Add(this->txtConfigDetails);
			this->configGroupBox->Location = System::Drawing::Point(50, 350);
			this->configGroupBox->Name = L"configGroupBox";
			this->configGroupBox->Size = System::Drawing::Size(500, 200);
			this->configGroupBox->TabIndex = 5;
			this->configGroupBox->TabStop = false;
			this->configGroupBox->Text = L"Detalles del programa";
			this->configGroupBox->Visible = false;
			// 
			// txtConfigDetails
			// 
			this->txtConfigDetails->Location = System::Drawing::Point(10, 20);
			this->txtConfigDetails->Multiline = true;
			this->txtConfigDetails->Name = L"txtConfigDetails";
			this->txtConfigDetails->ReadOnly = true;
			this->txtConfigDetails->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txtConfigDetails->Size = System::Drawing::Size(480, 170);
			this->txtConfigDetails->TabIndex = 0;
			this->txtConfigDetails->Text = resources->GetString(L"txtConfigDetails.Text");
			// 
			// StartScreen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightSeaGreen;
			this->ClientSize = System::Drawing::Size(583, 564);
			this->Controls->Add(this->configGroupBox);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->btnConfig);
			this->Controls->Add(this->btnStart);
			this->Controls->Add(this->labelAuthors);
			this->Controls->Add(this->labelTitle);
			this->Name = L"StartScreen";
			this->Text = L"Pantalla de Inicio";
			this->configGroupBox->ResumeLayout(false);
			this->configGroupBox->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: 
	
		System::Void btnExit_ClickWrapper(System::Object^ sender, System::EventArgs^ e) {

			if (closecallback != nullptr) {
				closecallback(sender, e);
			}
		}

		System::Void btnStart_ClickWrapper(System::Object^ sender, System::EventArgs^ e) {

			if (startcallback != nullptr) {
				startcallback(sender, e);
			}
		}

		System::Void btnConfig_ClickWrapper(System::Object^ sender, System::EventArgs^ e) {

			if (configcallback != nullptr) {
				configcallback(sender, e);
			}
		}

		System::Void btnExit_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close(); // Cerrar la aplicación
		}
	
		System::Void btnConfig_Click(System::Object^ sender, System::EventArgs^ e) {
			this->configGroupBox->Visible = !this->configGroupBox->Visible;

			// Mostrar un mensaje si el GroupBox está visible
			if (this->configGroupBox->Visible) {
				MessageBox::Show("Se han desplegado detalles importantes sobre la configuración.", "Configuración");
			}
		}
	
		System::Void btnStart_Click(System::Object^ sender, System::EventArgs^ e) {
			MainForm^ mainForm = gcnew MainForm();
			mainForm->Show();
			this->Hide(); // Ocultar la pantalla de inicio
		}
	};
}
