#pragma once

namespace Pr72OPC {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text;
	using namespace System::Text::RegularExpressions;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ labelLogin;
	private: System::Windows::Forms::TextBox^ textBoxLogin;
	private: System::Windows::Forms::Label^ labelPassword;
	private: System::Windows::Forms::TextBox^ textBoxPassword;
	private: System::Windows::Forms::Button^ buttonCheck;
	private: System::Windows::Forms::Button^ buttonGenerate;
	private: System::Windows::Forms::CheckBox^ checkBoxShowPassword;

	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->labelLogin = (gcnew System::Windows::Forms::Label());
			this->textBoxLogin = (gcnew System::Windows::Forms::TextBox());
			this->labelPassword = (gcnew System::Windows::Forms::Label());
			this->textBoxPassword = (gcnew System::Windows::Forms::TextBox());
			this->buttonCheck = (gcnew System::Windows::Forms::Button());
			this->buttonGenerate = (gcnew System::Windows::Forms::Button());
			this->checkBoxShowPassword = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// labelLogin
			// 
			this->labelLogin->AutoSize = true;
			this->labelLogin->Location = System::Drawing::Point(76, 24);
			this->labelLogin->Name = L"labelLogin";
			this->labelLogin->Size = System::Drawing::Size(36, 13);
			this->labelLogin->TabIndex = 0;
			this->labelLogin->Text = L"Login:";
			// 
			// textBoxLogin
			// 
			this->textBoxLogin->Location = System::Drawing::Point(150, 24);
			this->textBoxLogin->Name = L"textBoxLogin";
			this->textBoxLogin->Size = System::Drawing::Size(100, 20);
			this->textBoxLogin->TabIndex = 1;
			// 
			// labelPassword
			// 
			this->labelPassword->AutoSize = true;
			this->labelPassword->Location = System::Drawing::Point(79, 59);
			this->labelPassword->Name = L"labelPassword";
			this->labelPassword->Size = System::Drawing::Size(56, 13);
			this->labelPassword->TabIndex = 2;
			this->labelPassword->Text = L"Password:";
			// 
			// textBoxPassword
			// 
			this->textBoxPassword->Location = System::Drawing::Point(150, 59);
			this->textBoxPassword->Name = L"textBoxPassword";
			this->textBoxPassword->Size = System::Drawing::Size(100, 20);
			this->textBoxPassword->TabIndex = 3;
			this->textBoxPassword->UseSystemPasswordChar = true;
			// 
			// buttonCheck
			// 
			this->buttonCheck->Location = System::Drawing::Point(310, 19);
			this->buttonCheck->Name = L"buttonCheck";
			this->buttonCheck->Size = System::Drawing::Size(75, 23);
			this->buttonCheck->TabIndex = 4;
			this->buttonCheck->Text = L"Check Login and  Password";
			this->buttonCheck->UseVisualStyleBackColor = true;
			this->buttonCheck->Click += gcnew System::EventHandler(this, &MyForm::buttonCheck_Click);
			// 
			// buttonGenerate
			// 
			this->buttonGenerate->Location = System::Drawing::Point(310, 59);
			this->buttonGenerate->Name = L"buttonGenerate";
			this->buttonGenerate->Size = System::Drawing::Size(75, 23);
			this->buttonGenerate->TabIndex = 5;
			this->buttonGenerate->Text = L"Generate Password";
			this->buttonGenerate->UseVisualStyleBackColor = true;
			this->buttonGenerate->Click += gcnew System::EventHandler(this, &MyForm::buttonGenerate_Click);
			// 
			// checkBoxShowPassword
			// 
			this->checkBoxShowPassword->AutoSize = true;
			this->checkBoxShowPassword->Location = System::Drawing::Point(69, 99);
			this->checkBoxShowPassword->Name = L"checkBoxShowPassword";
			this->checkBoxShowPassword->Size = System::Drawing::Size(114, 17);
			this->checkBoxShowPassword->TabIndex = 6;
			this->checkBoxShowPassword->Text = L"Показати пароль";
			this->checkBoxShowPassword->UseVisualStyleBackColor = true;
			this->checkBoxShowPassword->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBoxShowPassword_CheckedChanged);  // Підключення обробника події
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(418, 170);
			this->Controls->Add(this->checkBoxShowPassword);
			this->Controls->Add(this->buttonGenerate);
			this->Controls->Add(this->buttonCheck);
			this->Controls->Add(this->textBoxPassword);
			this->Controls->Add(this->labelPassword);
			this->Controls->Add(this->textBoxLogin);
			this->Controls->Add(this->labelLogin);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void buttonCheck_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ login = textBoxLogin->Text;
		String^ password = textBoxPassword->Text;

		try {
			if (!Regex::IsMatch(login, "^(?=.*[A-Z])(?=.*\\d)(?=.*[!@#$%^&*])[A-Za-z\\d!@#$%^&*]{8,}$")) {
				throw gcnew Exception("Login must contain at least 1 uppercase letter, 1 digit, 1 special character, be at least 8 characters long, and use only English letters./// логін має містити щонайменше 1 цифру, 1 велику літеру, 1 спецсимвол (!@#$%^&*), бути не менше 8 символів, і лише англійські літери");
			}

			if (!Regex::IsMatch(password, "^(?=.*[A-Z])(?=.*[a-z])(?=.*\\d)(?=.*[^A-Za-z0-9]).{8,}$")) {
				throw gcnew Exception("Password does not meet complexity requirements.");
			}

			MessageBox::Show("Login and password are valid!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message, "Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

		   private: System::Void checkBoxShowPassword_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			   textBoxPassword->UseSystemPasswordChar = !checkBoxShowPassword->Checked;
		   }


	private: System::Void buttonGenerate_Click(System::Object^ sender, System::EventArgs^ e) {
		Random^ rand = gcnew Random();
		String^ chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*";
		StringBuilder^ sb = gcnew StringBuilder();

		while (true) {
			sb->Clear();
			for (int i = 0; i < 12; i++) {
				sb->Append(chars[rand->Next(chars->Length)]);
			}

			String^ password = sb->ToString();
			if (Regex::IsMatch(password, "^(?=.*[A-Z])(?=.*[a-z])(?=.*\\d)(?=.*[^A-Za-z0-9]).{8,}$")) {
				textBoxPassword->Text = password;
				break;
			}
		}
	};
	};
}
