#pragma once
#include "Hotel.h"
#include "BookForm.h"

namespace WindowProgram {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Hotel 的摘要
	/// </summary>
	public ref class Hotel_form : public System::Windows::Forms::Form
	{
	public:
		Hotel_form(System::Windows::Forms::Form ^ lastform, array<CHotel^>^ hotel)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
			start_form = lastform;
			this->hotel = hotel;
			txt_hotel->Text = hotel[0]->printHotelImf();
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~Hotel_form()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  btn_exit;
	private: System::Windows::Forms::Label^  txt_name;
	private: System::Windows::Forms::RichTextBox^  txt_hotel;
	private: System::Windows::Forms::Button^  btn_right;
	private: System::Windows::Forms::Button^  btn_left;
	private: System::Windows::Forms::Button^  btn_bookroom;

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
			this->btn_exit = (gcnew System::Windows::Forms::Button());
			this->txt_name = (gcnew System::Windows::Forms::Label());
			this->txt_hotel = (gcnew System::Windows::Forms::RichTextBox());
			this->btn_right = (gcnew System::Windows::Forms::Button());
			this->btn_left = (gcnew System::Windows::Forms::Button());
			this->btn_bookroom = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btn_exit
			// 
			this->btn_exit->Cursor = System::Windows::Forms::Cursors::Default;
			this->btn_exit->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->btn_exit->Location = System::Drawing::Point(419, 250);
			this->btn_exit->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->btn_exit->Name = L"btn_exit";
			this->btn_exit->Size = System::Drawing::Size(87, 31);
			this->btn_exit->TabIndex = 0;
			this->btn_exit->Text = L"離開";
			this->btn_exit->UseVisualStyleBackColor = true;
			this->btn_exit->Click += gcnew System::EventHandler(this, &Hotel_form::button1_Click);
			// 
			// txt_name
			// 
			this->txt_name->AutoSize = true;
			this->txt_name->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->txt_name->Location = System::Drawing::Point(12, 12);
			this->txt_name->Name = L"txt_name";
			this->txt_name->Size = System::Drawing::Size(39, 19);
			this->txt_name->TabIndex = 1;
			this->txt_name->Text = L"簡介";
			// 
			// txt_hotel
			// 
			this->txt_hotel->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->txt_hotel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txt_hotel->Cursor = System::Windows::Forms::Cursors::Default;
			this->txt_hotel->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->txt_hotel->Location = System::Drawing::Point(86, 12);
			this->txt_hotel->Name = L"txt_hotel";
			this->txt_hotel->ReadOnly = true;
			this->txt_hotel->Size = System::Drawing::Size(420, 176);
			this->txt_hotel->TabIndex = 2;
			this->txt_hotel->TabStop = false;
			this->txt_hotel->Text = L"";
			// 
			// btn_right
			// 
			this->btn_right->Location = System::Drawing::Point(485, 194);
			this->btn_right->Name = L"btn_right";
			this->btn_right->Size = System::Drawing::Size(21, 23);
			this->btn_right->TabIndex = 3;
			this->btn_right->Text = L"▶";
			this->btn_right->UseVisualStyleBackColor = true;
			this->btn_right->Click += gcnew System::EventHandler(this, &Hotel_form::btn_right_Click);
			// 
			// btn_left
			// 
			this->btn_left->Location = System::Drawing::Point(458, 194);
			this->btn_left->Name = L"btn_left";
			this->btn_left->Size = System::Drawing::Size(21, 23);
			this->btn_left->TabIndex = 4;
			this->btn_left->Text = L"◀";
			this->btn_left->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->btn_left->UseVisualStyleBackColor = true;
			this->btn_left->Click += gcnew System::EventHandler(this, &Hotel_form::btn_left_Click);
			// 
			// btn_bookroom
			// 
			this->btn_bookroom->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->btn_bookroom->Location = System::Drawing::Point(326, 250);
			this->btn_bookroom->Name = L"btn_bookroom";
			this->btn_bookroom->Size = System::Drawing::Size(87, 32);
			this->btn_bookroom->TabIndex = 5;
			this->btn_bookroom->Text = L"訂房";
			this->btn_bookroom->UseVisualStyleBackColor = true;
			this->btn_bookroom->Click += gcnew System::EventHandler(this, &Hotel_form::btn_bookroom_Click);
			// 
			// Hotel_form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->ClientSize = System::Drawing::Size(518, 294);
			this->Controls->Add(this->btn_bookroom);
			this->Controls->Add(this->btn_left);
			this->Controls->Add(this->btn_right);
			this->Controls->Add(this->txt_hotel);
			this->Controls->Add(this->txt_name);
			this->Controls->Add(this->btn_exit);
			this->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"Hotel_form";
			this->Text = L"Hotel";
			this->Load += gcnew System::EventHandler(this, &Hotel_form::Hotel_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	///環境變數
	private: System::Windows::Forms::Form ^ start_form;
	private: BookForm^ book_form;
	private: array<CHotel^>^ hotel;
	private: int now_hotel = 0;

	private: System::Void Hotel_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Hide();
		start_form->Show();
	}
	private: System::Void btn_right_Click(System::Object^  sender, System::EventArgs^  e) {
		if (hotel[now_hotel + 1] != nullptr){
			now_hotel++;
			txt_hotel->Text = hotel[now_hotel]->printHotelImf();
		}
	
	}
	private: System::Void btn_left_Click(System::Object^  sender, System::EventArgs^  e) {
		if (now_hotel != 0){
			now_hotel--;
			txt_hotel->Text = hotel[now_hotel]->printHotelImf();
		}
	}
	private: System::Void btn_bookroom_Click(System::Object^  sender, System::EventArgs^  e) {
		//delete book_form;
		book_form = gcnew BookForm(this, hotel[now_hotel]);
		book_form->Show();
		this->Hide();
	}
};
}