/******************************
4103056035 周彤 第七次作業12/30
******************************/
#pragma once
#include "pay.h"

namespace WindowProgram {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// GuestForm 的摘要
	/// </summary>
	public ref class GuestForm : public System::Windows::Forms::Form
	{
	public:
		GuestForm(System::Windows::Forms::Form^ lastform, System::String^ name)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
			this->lastform = lastform;
			lbl_title->Text = "Welcome " + name;
			System::String^ path = name + ".txt";
			System::IO::StreamReader^ bookrecord = gcnew System::IO::StreamReader(System::IO::File::OpenRead(path), System::Text::Encoding::Unicode);
			System::String^ line;
			while ((line = bookrecord->ReadLine()) != nullptr){
				list_record->Items->Insert(list_record->Items->Count, line);
			}
			bookrecord->Close();
			this->path = path;
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~GuestForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^  list_record;
	private: System::Windows::Forms::Label^  lbl_title;
	private: System::Windows::Forms::Button^  btn_pay;
	private: System::Windows::Forms::Button^  btn_del;
	private: System::Windows::Forms::Button^  btn_exit;


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
			this->list_record = (gcnew System::Windows::Forms::ListBox());
			this->lbl_title = (gcnew System::Windows::Forms::Label());
			this->btn_pay = (gcnew System::Windows::Forms::Button());
			this->btn_del = (gcnew System::Windows::Forms::Button());
			this->btn_exit = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// list_record
			// 
			this->list_record->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->list_record->FormattingEnabled = true;
			this->list_record->ItemHeight = 15;
			this->list_record->Location = System::Drawing::Point(13, 196);
			this->list_record->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->list_record->Name = L"list_record";
			this->list_record->Size = System::Drawing::Size(485, 124);
			this->list_record->TabIndex = 0;
			this->list_record->DoubleClick += gcnew System::EventHandler(this, &GuestForm::list_record_DoubleClick);
			// 
			// lbl_title
			// 
			this->lbl_title->AutoSize = true;
			this->lbl_title->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->lbl_title->Location = System::Drawing::Point(13, 9);
			this->lbl_title->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbl_title->Name = L"lbl_title";
			this->lbl_title->Size = System::Drawing::Size(0, 19);
			this->lbl_title->TabIndex = 1;
			// 
			// btn_pay
			// 
			this->btn_pay->Location = System::Drawing::Point(306, 157);
			this->btn_pay->Name = L"btn_pay";
			this->btn_pay->Size = System::Drawing::Size(93, 31);
			this->btn_pay->TabIndex = 2;
			this->btn_pay->Text = L"付款";
			this->btn_pay->UseVisualStyleBackColor = true;
			this->btn_pay->Click += gcnew System::EventHandler(this, &GuestForm::btn_pay_Click);
			// 
			// btn_del
			// 
			this->btn_del->Location = System::Drawing::Point(207, 157);
			this->btn_del->Name = L"btn_del";
			this->btn_del->Size = System::Drawing::Size(93, 31);
			this->btn_del->TabIndex = 3;
			this->btn_del->Text = L"取消訂房";
			this->btn_del->UseVisualStyleBackColor = true;
			this->btn_del->Click += gcnew System::EventHandler(this, &GuestForm::btn_del_Click);
			// 
			// btn_exit
			// 
			this->btn_exit->Location = System::Drawing::Point(405, 157);
			this->btn_exit->Name = L"btn_exit";
			this->btn_exit->Size = System::Drawing::Size(93, 31);
			this->btn_exit->TabIndex = 4;
			this->btn_exit->Text = L"離開";
			this->btn_exit->UseVisualStyleBackColor = true;
			this->btn_exit->Click += gcnew System::EventHandler(this, &GuestForm::btn_exit_Click);
			// 
			// GuestForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 19);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(511, 334);
			this->Controls->Add(this->btn_exit);
			this->Controls->Add(this->btn_del);
			this->Controls->Add(this->btn_pay);
			this->Controls->Add(this->lbl_title);
			this->Controls->Add(this->list_record);
			this->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"GuestForm";
			this->Text = L"GuestForm";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GuestForm::GuestForm_Paint);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Windows::Forms::Form^ lastform;
	private: pay^ payform;
	private: bool^ success = gcnew bool(false);
	private: System::String^ path;

	private: System::Void list_record_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
		int i = list_record->Items->Count - 1;
		for (i; i >= 0; i--){
			if (list_record->GetSelected(i)){
				if (list_record->Items[i]->ToString()->Contains("未付款")){
					payform = gcnew pay(this, success);
					payform->Show();
					this->Hide();
				}
			}
			else
				continue;
		}
	}
	private: System::Void btn_exit_Click(System::Object^  sender, System::EventArgs^  e) {
		System::IO::StreamWriter^ book = gcnew System::IO::StreamWriter(path, false, System::Text::Encoding::Unicode);
		for (int i = 0; i < list_record->Items->Count; i++){
			System::String^ line = list_record->Items[i]->ToString();
			if (line->CompareTo(""))
				book->WriteLine(line);
		}
		book->Close();
		lastform->Show();
		delete this;
	}
	private: System::Void btn_pay_Click(System::Object^  sender, System::EventArgs^  e) {
		int i = list_record->Items->Count - 1;
		for (i; i >= 0; i--){
			if (list_record->GetSelected(i)){
				if (list_record->Items[i]->ToString()->Contains("未付款")){
					payform = gcnew pay(this, success);
					payform->Show();
					this->Hide();
				}
			}
			else
				continue;
		}
	}
	private: System::Void GuestForm_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		if (*success){
			int i = list_record->Items->Count - 1;
			for (i; i >= 0; i--){
				if (list_record->GetSelected(i)){
					System::String^ line;
					line = list_record->Items[i]->ToString();
					line = line->Replace("未付款", "已付款");
					list_record->Items->RemoveAt(i);
					list_record->Items->Insert(i, line);
					*success = false;
				}
				else
					continue;
			}
		}
	}
	private: System::Void btn_del_Click(System::Object^  sender, System::EventArgs^  e) {
		int i = list_record->Items->Count - 1;
		for (i; i >= 0; i--){
			if (list_record->GetSelected(i)){
				list_record->Items->RemoveAt(i);
			}
		}
	}
};
}
