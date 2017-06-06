/******************************
4103056035 周彤 第七次作業12/30
******************************/
#pragma once
#include "HotelForm.h"
#include "Hotel.h"
#include "GuestForm.h"

namespace WindowProgram {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm 的摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(array<CHotel^>^ hotel)
		{
			
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
			hotel_form = gcnew Hotel_form(this, hotel);
			
			this->hotel = hotel;
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  btn_start;
	private: System::Windows::Forms::Button^  btn_user;
	private: System::Windows::Forms::Button^  btn_exit;
	private: System::Windows::Forms::TextBox^  txt_name;
	private: System::Windows::Forms::Label^  label1;

	protected:
	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;
		
#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器
		/// 修改這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->btn_start = (gcnew System::Windows::Forms::Button());
			this->btn_exit = (gcnew System::Windows::Forms::Button());
			this->btn_user = (gcnew System::Windows::Forms::Button());
			this->txt_name = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btn_start
			// 
			this->btn_start->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->btn_start->Location = System::Drawing::Point(12, 77);
			this->btn_start->Name = L"btn_start";
			this->btn_start->Size = System::Drawing::Size(81, 26);
			this->btn_start->TabIndex = 0;
			this->btn_start->Text = L"訂房";
			this->btn_start->UseVisualStyleBackColor = true;
			this->btn_start->Click += gcnew System::EventHandler(this, &MyForm::btn_start_Click);
			// 
			// btn_exit
			// 
			this->btn_exit->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->btn_exit->Location = System::Drawing::Point(99, 77);
			this->btn_exit->Name = L"btn_exit";
			this->btn_exit->Size = System::Drawing::Size(82, 26);
			this->btn_exit->TabIndex = 1;
			this->btn_exit->Text = L"離開";
			this->btn_exit->UseVisualStyleBackColor = true;
			this->btn_exit->Click += gcnew System::EventHandler(this, &MyForm::btn_exit_Click);
			// 
			// btn_user
			// 
			this->btn_user->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->btn_user->Location = System::Drawing::Point(12, 45);
			this->btn_user->Name = L"btn_user";
			this->btn_user->Size = System::Drawing::Size(169, 26);
			this->btn_user->TabIndex = 2;
			this->btn_user->Text = L"登入";
			this->btn_user->UseVisualStyleBackColor = true;
			this->btn_user->Click += gcnew System::EventHandler(this, &MyForm::btn_user_Click);
			// 
			// txt_name
			// 
			this->txt_name->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->txt_name->Location = System::Drawing::Point(56, 12);
			this->txt_name->Name = L"txt_name";
			this->txt_name->Size = System::Drawing::Size(125, 27);
			this->txt_name->TabIndex = 3;
			this->txt_name->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::txt_name_MouseDown);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(12, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(39, 19);
			this->label1->TabIndex = 4;
			this->label1->Text = L"名稱";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(193, 115);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txt_name);
			this->Controls->Add(this->btn_user);
			this->Controls->Add(this->btn_exit);
			this->Controls->Add(this->btn_start);
			this->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"MyForm";
			this->Text = L"訂房系統";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
		///環境變數
	private: Hotel_form^ hotel_form;
	private: GuestForm^ Guest_form;
	private: array<CHotel^>^ hotel;

	private: System::Void btn_start_Click(System::Object^  sender, System::EventArgs^  e) {
		hotel_form->Show();
		this->Hide();
	}
	private: System::Void btn_user_Click(System::Object^  sender, System::EventArgs^  e){
		System::String^ name = txt_name->Text;
		System::String ^path, ^guestN, ^str;
		if (!name->CompareTo("")){
			txt_name->BackColor = Color::Khaki;
			txt_name->Text = "請輸入名稱";
			
			return;
		}

		bool ^findGuest = gcnew bool(false);

		path = name + ".txt";

		System::IO::StreamReader^ RguestName = gcnew System::IO::StreamReader(System::IO::File::OpenRead("guestName.txt"), System::Text::Encoding::Unicode);
		while ((guestN = RguestName->ReadLine()))
		{
			if (!System::String::Compare(name, guestN)){
				*findGuest = true;
				break;
			}
		}

		RguestName->Close();

		if (*findGuest)
			Guest_form = gcnew GuestForm(this, name);
		else{
			txt_name->BackColor = Color::Khaki;
			txt_name->Text = "未找到此房客";
			delete findGuest;
			return;
		}
		Guest_form->Show();
		this->Hide();
	}
	private: System::Void txt_name_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (txt_name->BackColor == Color::Khaki){
			txt_name->BackColor = SystemColors::Window;
			txt_name->Text = "";
		}
	}
private: System::Void btn_exit_Click(System::Object^  sender, System::EventArgs^  e) {
	Application::Exit();
}
};
}
