/******************************
4103056035 周彤 第七次作業12/30
******************************/
#pragma once
ref class CRoomType
{
public:
	CRoomType();
	CRoomType(System::String^, System::String^);
	void setroomNum(System::String^);
	int getPrice();
	System::String^ getroomName();
	bool^ findRoom(int^ Pnum, char*);
	bool initbooktable(System::String^ roomNum);

private:
	System::String^ m_roomName;
	array<System::String^>^ m_roomNum = gcnew array<System::String^>(20);
	int^ m_NumOfPeople;
	int^ m_price;
	array<bool>^ m_book = gcnew array<bool>(20);
	int^ cnt = gcnew int(0);
	
};

