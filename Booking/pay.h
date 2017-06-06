/******************************
4103056035 周彤 第七次作業12/30
******************************/
#pragma once
#include "myMath.h"

namespace WindowProgram {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// pay 的摘要
	/// </summary>
	public ref class pay : public System::Windows::Forms::Form
	{
	public:
		pay(System::Windows::Forms::Form^ lastform, bool^ success )
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
			this->lastform = lastform;
			this->success = success;
			today = System::DateTime(this->date_today->Value);
			int year = today.Year;
			for (int i = 0; i < 20; i++)
				cmbox_year->Items->Add(year + i);

		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~pay()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  lbl_num;
	private: System::Windows::Forms::MaskedTextBox^  txtbox_num;
	protected:

	private: System::Windows::Forms::Label^  lbl_name;
	private: System::Windows::Forms::TextBox^  txt_name;

	private: System::Windows::Forms::Label^  lbl_dateline;
	private: System::Windows::Forms::ComboBox^  cmbox_month;
	private: System::Windows::Forms::Label^  lbl_month;
	private: System::Windows::Forms::ComboBox^  cmbox_year;
	private: System::Windows::Forms::Label^  lbl_year;
	private: System::Windows::Forms::Label^  lbl_money;
	private: System::Windows::Forms::Button^  btn_submit;
	private: System::Windows::Forms::Button^  btn_del;


	private: System::Windows::Forms::DateTimePicker^  date_today;

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
			this->lbl_num = (gcnew System::Windows::Forms::Label());
			this->txtbox_num = (gcnew System::Windows::Forms::MaskedTextBox());
			this->lbl_name = (gcnew System::Windows::Forms::Label());
			this->txt_name = (gcnew System::Windows::Forms::TextBox());
			this->lbl_dateline = (gcnew System::Windows::Forms::Label());
			this->cmbox_month = (gcnew System::Windows::Forms::ComboBox());
			this->lbl_month = (gcnew System::Windows::Forms::Label());
			this->cmbox_year = (gcnew System::Windows::Forms::ComboBox());
			this->lbl_year = (gcnew System::Windows::Forms::Label());
			this->lbl_money = (gcnew System::Windows::Forms::Label());
			this->btn_submit = (gcnew System::Windows::Forms::Button());
			this->btn_del = (gcnew System::Windows::Forms::Button());
			this->date_today = (gcnew System::Windows::Forms::DateTimePicker());
			this->SuspendLayout();
			// 
			// lbl_num
			// 
			this->lbl_num->AutoSize = true;
			this->lbl_num->Location = System::Drawing::Point(12, 15);
			this->lbl_num->Name = L"lbl_num";
			this->lbl_num->Size = System::Drawing::Size(39, 19);
			this->lbl_num->TabIndex = 99;
			this->lbl_num->Text = L"卡號";
			// 
			// txtbox_num
			// 
			this->txtbox_num->Location = System::Drawing::Point(98, 12);
			this->txtbox_num->Mask = L"0000-0000-0000-0000";
			this->txtbox_num->Name = L"txtbox_num";
			this->txtbox_num->Size = System::Drawing::Size(269, 27);
			this->txtbox_num->TabIndex = 0;
			this->txtbox_num->MaskInputRejected += gcnew System::Windows::Forms::MaskInputRejectedEventHandler(this, &pay::txtbox_num_MaskInputRejected);
			// 
			// lbl_name
			// 
			this->lbl_name->AutoSize = true;
			this->lbl_name->Location = System::Drawing::Point(12, 61);
			this->lbl_name->Name = L"lbl_name";
			this->lbl_name->Size = System::Drawing::Size(84, 19);
			this->lbl_name->TabIndex = 100;
			this->lbl_name->Text = L"持卡人名稱";
			// 
			// txt_name
			// 
			this->txt_name->Location = System::Drawing::Point(98, 58);
			this->txt_name->Name = L"txt_name";
			this->txt_name->Size = System::Drawing::Size(269, 27);
			this->txt_name->TabIndex = 1;
			this->txt_name->TextChanged += gcnew System::EventHandler(this, &pay::txt_name_TextChanged);
			// 
			// lbl_dateline
			// 
			this->lbl_dateline->AutoSize = true;
			this->lbl_dateline->Location = System::Drawing::Point(12, 104);
			this->lbl_dateline->Name = L"lbl_dateline";
			this->lbl_dateline->Size = System::Drawing::Size(69, 19);
			this->lbl_dateline->TabIndex = 102;
			this->lbl_dateline->Text = L"有效期限";
			// 
			// cmbox_month
			// 
			this->cmbox_month->FormattingEnabled = true;
			this->cmbox_month->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8",
					L"9", L"10", L"11", L"12"
			});
			this->cmbox_month->Location = System::Drawing::Point(239, 101);
			this->cmbox_month->Name = L"cmbox_month";
			this->cmbox_month->Size = System::Drawing::Size(98, 27);
			this->cmbox_month->TabIndex = 3;
			this->cmbox_month->SelectedIndexChanged += gcnew System::EventHandler(this, &pay::cmbox_month_SelectedIndexChanged);
			// 
			// lbl_month
			// 
			this->lbl_month->AutoSize = true;
			this->lbl_month->Cursor = System::Windows::Forms::Cursors::Default;
			this->lbl_month->Location = System::Drawing::Point(343, 104);
			this->lbl_month->Name = L"lbl_month";
			this->lbl_month->Size = System::Drawing::Size(24, 19);
			this->lbl_month->TabIndex = 103;
			this->lbl_month->Text = L"月";
			// 
			// cmbox_year
			// 
			this->cmbox_year->FormattingEnabled = true;
			this->cmbox_year->Location = System::Drawing::Point(98, 101);
			this->cmbox_year->Name = L"cmbox_year";
			this->cmbox_year->Size = System::Drawing::Size(105, 27);
			this->cmbox_year->TabIndex = 3;
			this->cmbox_year->SelectedIndexChanged += gcnew System::EventHandler(this, &pay::cmbox_year_SelectedIndexChanged);
			// 
			// lbl_year
			// 
			this->lbl_year->AutoSize = true;
			this->lbl_year->Location = System::Drawing::Point(209, 104);
			this->lbl_year->Name = L"lbl_year";
			this->lbl_year->Size = System::Drawing::Size(24, 19);
			this->lbl_year->TabIndex = 105;
			this->lbl_year->Text = L"年";
			// 
			// lbl_money
			// 
			this->lbl_money->AutoSize = true;
			this->lbl_money->Location = System::Drawing::Point(12, 158);
			this->lbl_money->Name = L"lbl_money";
			this->lbl_money->Size = System::Drawing::Size(0, 19);
			this->lbl_money->TabIndex = 106;
			// 
			// btn_submit
			// 
			this->btn_submit->Location = System::Drawing::Point(278, 152);
			this->btn_submit->Name = L"btn_submit";
			this->btn_submit->Size = System::Drawing::Size(89, 30);
			this->btn_submit->TabIndex = 5;
			this->btn_submit->Text = L"確認付款";
			this->btn_submit->UseVisualStyleBackColor = true;
			this->btn_submit->Click += gcnew System::EventHandler(this, &pay::btn_submit_Click);
			// 
			// btn_del
			// 
			this->btn_del->Location = System::Drawing::Point(183, 152);
			this->btn_del->Name = L"btn_del";
			this->btn_del->Size = System::Drawing::Size(89, 30);
			this->btn_del->TabIndex = 4;
			this->btn_del->Text = L"取消付款";
			this->btn_del->UseVisualStyleBackColor = true;
			this->btn_del->Click += gcnew System::EventHandler(this, &pay::btn_del_Click);
			// 
			// date_today
			// 
			this->date_today->Location = System::Drawing::Point(98, 181);
			this->date_today->Name = L"date_today";
			this->date_today->Size = System::Drawing::Size(64, 27);
			this->date_today->TabIndex = 107;
			this->date_today->Visible = false;
			// 
			// pay
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 19);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(379, 194);
			this->Controls->Add(this->date_today);
			this->Controls->Add(this->btn_del);
			this->Controls->Add(this->btn_submit);
			this->Controls->Add(this->lbl_money);
			this->Controls->Add(this->lbl_year);
			this->Controls->Add(this->cmbox_year);
			this->Controls->Add(this->lbl_month);
			this->Controls->Add(this->cmbox_month);
			this->Controls->Add(this->lbl_dateline);
			this->Controls->Add(this->txt_name);
			this->Controls->Add(this->lbl_name);
			this->Controls->Add(this->txtbox_num);
			this->Controls->Add(this->lbl_num);
			this->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"pay";
			this->Text = L"pay";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Windows::Forms::Form^ lastform;
	private: bool^ success;
	private: System::DateTime today;

	private: System::Void btn_submit_Click(System::Object^  sender, System::EventArgs^  e) {
		System::String^ name = txt_name->Text;
		System::String^ num = txtbox_num->Text;
		System::String^ txtyear = cmbox_year->Text;
		System::String^ txtmonth = cmbox_month->Text;
		int^ year = gcnew int(0), ^month = gcnew int(0);

		bool Error = false;

		if (!name->CompareTo("")){
			Error = true;
			txt_name->BackColor = Color::Khaki;
		}

		if (num->IndexOf(" ") >= 0){
			txtbox_num->BackColor = Color::Khaki;
			Error = true;
		}

		if (!txtyear->CompareTo("")){
			cmbox_year->BackColor = Color::Khaki;
			Error = true;
		}
		else{
			calc(txtyear->ToCharArray(), year);
			if (*year < today.Year){
				cmbox_year->BackColor = Color::Khaki;
				Error = true;
			}
		}
		if (!txtmonth->CompareTo("")){
			cmbox_month->BackColor = Color::Khaki;
			Error = true;
		}
		else{
			calc(txtmonth->ToCharArray(), month);
			if (*month < 0 || (*month) > 12){
				cmbox_month->BackColor = Color::Khaki;
				Error = true;
			}
			else if (today.Year == (*year)){
				if (today.Month >(*month)){
					cmbox_month->BackColor = Color::Khaki;
					Error = true;
				}
			}
		}
		
		if (Error){
			lbl_money->Text = "輸入錯誤";
		}
		else{
			*success = true;
			lastform->Show();
			delete this;
		}
	}
	private: System::Void btn_del_Click(System::Object^  sender, System::EventArgs^  e) {
		*success = false;
		lastform->Show();
		delete this;
	}
	private: System::Void txtbox_num_MaskInputRejected(System::Object^  sender, System::Windows::Forms::MaskInputRejectedEventArgs^  e) {
		txtbox_num->BackColor = SystemColors::Window;
	}
	private: System::Void txt_name_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		txt_name->BackColor = SystemColors::Window;
	}
	private: System::Void cmbox_year_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		cmbox_year->BackColor = SystemColors::Window;
	}
	private: System::Void cmbox_month_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		cmbox_month->BackColor = SystemColors::Window;
	}
};
}
