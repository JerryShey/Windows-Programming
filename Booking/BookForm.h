/******************************
4103056035 周彤 第七次作業12/30
******************************/
#pragma once
#include "Hotel.h"

namespace WindowProgram {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// BookForm 的摘要
	/// </summary>
	public ref class BookForm : public System::Windows::Forms::Form
	{
	public:
		BookForm(System::Windows::Forms::Form^ lastform, CHotel^ hotel)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
			hotel_form = lastform;
			today = System::DateTime(this->date_startday->Value);
			this->hotel = hotel;
			this->date_startday->MaxDate = today.AddMonths(2);
			this->date_endday->MaxDate = today.AddMonths(2);
			this->date_startday->MinDate = today.AddDays(1);
			this->date_endday->MinDate = today.AddDays(1);
			array<System::String^>^ test = hotel->getroomName();
			this->cmbox_roomtype->Items->AddRange(test);
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~BookForm()
		{
			if (components)
			{
				delete components;
			}
		}

	
		
	private: System::Windows::Forms::Form ^ hotel_form;
	private: System::Windows::Forms::Label^  lbl_name;
	private: System::Windows::Forms::Label^  lbl_phone;
	private: System::Windows::Forms::Label^  lbl_startday;
	private: System::Windows::Forms::Label^  lbl_endday;
	private: System::Windows::Forms::Label^  lbl_roomtype;
	private: System::Windows::Forms::Label^  lbl_peoplenum;
	private: System::Windows::Forms::DateTimePicker^  date_startday;
	private: System::Windows::Forms::DateTimePicker^  date_endday;

	private: System::Windows::Forms::TextBox^  txt_name;
	private: System::Windows::Forms::MaskedTextBox^  txt_phone;
	private: System::Windows::Forms::NumericUpDown^  peoplenum;
	private: System::Windows::Forms::Button^  btn_exit;
	private: System::Windows::Forms::Button^  btn_book;
	private: System::Windows::Forms::Label^  txt_result;

	private: System::Windows::Forms::ComboBox^  cmbox_roomtype;

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
			this->lbl_name = (gcnew System::Windows::Forms::Label());
			this->lbl_phone = (gcnew System::Windows::Forms::Label());
			this->lbl_startday = (gcnew System::Windows::Forms::Label());
			this->lbl_endday = (gcnew System::Windows::Forms::Label());
			this->lbl_roomtype = (gcnew System::Windows::Forms::Label());
			this->lbl_peoplenum = (gcnew System::Windows::Forms::Label());
			this->date_startday = (gcnew System::Windows::Forms::DateTimePicker());
			this->date_endday = (gcnew System::Windows::Forms::DateTimePicker());
			this->txt_name = (gcnew System::Windows::Forms::TextBox());
			this->txt_phone = (gcnew System::Windows::Forms::MaskedTextBox());
			this->peoplenum = (gcnew System::Windows::Forms::NumericUpDown());
			this->cmbox_roomtype = (gcnew System::Windows::Forms::ComboBox());
			this->btn_exit = (gcnew System::Windows::Forms::Button());
			this->btn_book = (gcnew System::Windows::Forms::Button());
			this->txt_result = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->peoplenum))->BeginInit();
			this->SuspendLayout();
			// 
			// lbl_name
			// 
			this->lbl_name->AutoSize = true;
			this->lbl_name->Enabled = false;
			this->lbl_name->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lbl_name->Location = System::Drawing::Point(14, 14);
			this->lbl_name->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->lbl_name->Name = L"lbl_name";
			this->lbl_name->Size = System::Drawing::Size(41, 20);
			this->lbl_name->TabIndex = 0;
			this->lbl_name->Text = L"姓名";
			// 
			// lbl_phone
			// 
			this->lbl_phone->AutoSize = true;
			this->lbl_phone->Enabled = false;
			this->lbl_phone->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lbl_phone->Location = System::Drawing::Point(14, 56);
			this->lbl_phone->Name = L"lbl_phone";
			this->lbl_phone->Size = System::Drawing::Size(41, 20);
			this->lbl_phone->TabIndex = 99;
			this->lbl_phone->Text = L"手機";
			// 
			// lbl_startday
			// 
			this->lbl_startday->AutoSize = true;
			this->lbl_startday->Enabled = false;
			this->lbl_startday->Location = System::Drawing::Point(14, 102);
			this->lbl_startday->Name = L"lbl_startday";
			this->lbl_startday->Size = System::Drawing::Size(73, 20);
			this->lbl_startday->TabIndex = 99;
			this->lbl_startday->Text = L"入住時間";
			// 
			// lbl_endday
			// 
			this->lbl_endday->AutoSize = true;
			this->lbl_endday->Enabled = false;
			this->lbl_endday->Location = System::Drawing::Point(257, 102);
			this->lbl_endday->Name = L"lbl_endday";
			this->lbl_endday->Size = System::Drawing::Size(73, 20);
			this->lbl_endday->TabIndex = 99;
			this->lbl_endday->Text = L"退房時間";
			// 
			// lbl_roomtype
			// 
			this->lbl_roomtype->AutoSize = true;
			this->lbl_roomtype->Enabled = false;
			this->lbl_roomtype->Location = System::Drawing::Point(14, 143);
			this->lbl_roomtype->Name = L"lbl_roomtype";
			this->lbl_roomtype->Size = System::Drawing::Size(73, 20);
			this->lbl_roomtype->TabIndex = 99;
			this->lbl_roomtype->Text = L"房間類型";
			// 
			// lbl_peoplenum
			// 
			this->lbl_peoplenum->AutoSize = true;
			this->lbl_peoplenum->Enabled = false;
			this->lbl_peoplenum->Location = System::Drawing::Point(14, 182);
			this->lbl_peoplenum->Name = L"lbl_peoplenum";
			this->lbl_peoplenum->Size = System::Drawing::Size(41, 20);
			this->lbl_peoplenum->TabIndex = 99;
			this->lbl_peoplenum->Text = L"人數";
			// 
			// date_startday
			// 
			this->date_startday->CalendarFont = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->date_startday->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->date_startday->Location = System::Drawing::Point(97, 99);
			this->date_startday->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->date_startday->MaxDate = System::DateTime(7700, 2, 1, 0, 0, 0, 0);
			this->date_startday->Name = L"date_startday";
			this->date_startday->Size = System::Drawing::Size(145, 29);
			this->date_startday->TabIndex = 2;
			this->date_startday->ValueChanged += gcnew System::EventHandler(this, &BookForm::date_startday_ValueChanged);
			// 
			// date_endday
			// 
			this->date_endday->CalendarFont = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->date_endday->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->date_endday->Location = System::Drawing::Point(341, 99);
			this->date_endday->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->date_endday->Name = L"date_endday";
			this->date_endday->Size = System::Drawing::Size(145, 29);
			this->date_endday->TabIndex = 3;
			// 
			// txt_name
			// 
			this->txt_name->Location = System::Drawing::Point(65, 11);
			this->txt_name->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txt_name->Name = L"txt_name";
			this->txt_name->Size = System::Drawing::Size(120, 29);
			this->txt_name->TabIndex = 0;
			this->txt_name->TextChanged += gcnew System::EventHandler(this, &BookForm::txt_name_TextChanged);
			// 
			// txt_phone
			// 
			this->txt_phone->BackColor = System::Drawing::SystemColors::Window;
			this->txt_phone->Location = System::Drawing::Point(65, 53);
			this->txt_phone->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txt_phone->Mask = L"0900-000-000";
			this->txt_phone->Name = L"txt_phone";
			this->txt_phone->Size = System::Drawing::Size(120, 29);
			this->txt_phone->TabIndex = 1;
			this->txt_phone->MaskInputRejected += gcnew System::Windows::Forms::MaskInputRejectedEventHandler(this, &BookForm::txt_phone_MaskInputRejected);
			// 
			// peoplenum
			// 
			this->peoplenum->Location = System::Drawing::Point(65, 180);
			this->peoplenum->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->peoplenum->Name = L"peoplenum";
			this->peoplenum->Size = System::Drawing::Size(47, 29);
			this->peoplenum->TabIndex = 5;
			this->peoplenum->ValueChanged += gcnew System::EventHandler(this, &BookForm::peoplenum_ValueChanged);
			// 
			// cmbox_roomtype
			// 
			this->cmbox_roomtype->FormattingEnabled = true;
			this->cmbox_roomtype->Location = System::Drawing::Point(97, 140);
			this->cmbox_roomtype->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->cmbox_roomtype->Name = L"cmbox_roomtype";
			this->cmbox_roomtype->Size = System::Drawing::Size(145, 28);
			this->cmbox_roomtype->TabIndex = 4;
			this->cmbox_roomtype->SelectedIndexChanged += gcnew System::EventHandler(this, &BookForm::cmbox_roomtype_SelectedIndexChanged);
			// 
			// btn_exit
			// 
			this->btn_exit->Location = System::Drawing::Point(428, 227);
			this->btn_exit->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn_exit->Name = L"btn_exit";
			this->btn_exit->Size = System::Drawing::Size(68, 27);
			this->btn_exit->TabIndex = 7;
			this->btn_exit->Text = L"取消";
			this->btn_exit->UseVisualStyleBackColor = true;
			this->btn_exit->Click += gcnew System::EventHandler(this, &BookForm::btn_exit_Click);
			// 
			// btn_book
			// 
			this->btn_book->Location = System::Drawing::Point(355, 227);
			this->btn_book->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn_book->Name = L"btn_book";
			this->btn_book->Size = System::Drawing::Size(68, 27);
			this->btn_book->TabIndex = 6;
			this->btn_book->Text = L"訂房";
			this->btn_book->UseVisualStyleBackColor = true;
			this->btn_book->Click += gcnew System::EventHandler(this, &BookForm::btn_book_Click);
			// 
			// txt_result
			// 
			this->txt_result->AutoSize = true;
			this->txt_result->Location = System::Drawing::Point(14, 231);
			this->txt_result->Name = L"txt_result";
			this->txt_result->Size = System::Drawing::Size(0, 20);
			this->txt_result->TabIndex = 14;
			// 
			// BookForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(507, 264);
			this->Controls->Add(this->txt_result);
			this->Controls->Add(this->btn_book);
			this->Controls->Add(this->btn_exit);
			this->Controls->Add(this->cmbox_roomtype);
			this->Controls->Add(this->peoplenum);
			this->Controls->Add(this->txt_phone);
			this->Controls->Add(this->txt_name);
			this->Controls->Add(this->date_endday);
			this->Controls->Add(this->date_startday);
			this->Controls->Add(this->lbl_peoplenum);
			this->Controls->Add(this->lbl_roomtype);
			this->Controls->Add(this->lbl_endday);
			this->Controls->Add(this->lbl_startday);
			this->Controls->Add(this->lbl_phone);
			this->Controls->Add(this->lbl_name);
			this->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(5);
			this->Name = L"BookForm";
			this->Text = L"BookForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->peoplenum))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		/// 環境變數
	private: System::DateTime today;
	private: CHotel^ hotel;

	private: System::Void btn_exit_Click(System::Object^  sender, System::EventArgs^  e) {
		
		hotel_form->Show();
		delete this;
	}

	private: System::Void date_startday_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		date_endday->MinDate = date_startday->Value;
	}
	private: System::Void btn_book_Click(System::Object^  sender, System::EventArgs^  e) {
		System::String^ name = txt_name->Text;
		System::String^ phone = txt_phone->Text;
		System::String^ roomtype = cmbox_roomtype->Text;
		System::Decimal people = peoplenum->Value;
		bool Error = false;

		if (!name->CompareTo("")){
			Error = true;
			txt_name->BackColor = Color::Khaki;
		}
		if (phone->IndexOf(" ")>=0){
			txt_phone->BackColor = Color::Khaki;
			Error = true;
		}
		if (!roomtype->CompareTo("")){
			cmbox_roomtype->BackColor = Color::Khaki;
			Error = true;
		}
		if (people == 0){
			peoplenum->BackColor = Color::Khaki;
			Error = true;
		}

		if (Error){
			txt_result->Text = "請正確填寫資料";
		}
		else{
			int success = hotel->bookRoom(roomtype, name, people, date_startday->Value, date_endday->Value);
			if (success>0)
				txt_result->Text = "成功訂房，記得登入後付款哦~";
			else if(success < 0)
				txt_result->Text = "Oops!!輸入錯誤";
			else
				txt_result->Text = "Oops!!沒有房間囉";
		}
	}
	private: System::Void txt_name_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		txt_name->BackColor = SystemColors::Window;
	}
	private: System::Void txt_phone_MaskInputRejected(System::Object^  sender, System::Windows::Forms::MaskInputRejectedEventArgs^  e) {
		txt_phone->BackColor = SystemColors::Window;
	}

	private: System::Void cmbox_roomtype_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		cmbox_roomtype->BackColor = SystemColors::Window;
	}
	private: System::Void peoplenum_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		peoplenum->BackColor = SystemColors::Window;
	}
};
}
