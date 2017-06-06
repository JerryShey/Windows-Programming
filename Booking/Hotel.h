/******************************
4103056035 周彤 第七次作業12/30
******************************/
#pragma once
#include "RoomType.h"
#include "BookRecord.h"

ref class CHotel
{
public:
	CHotel();
	void setAddress(System::String^);
	void setDes(System::String^);
	void setName(System::String^);
	void setCity(System::String^);
	void setRoomtype(array<System::String^>^);
	void setRoomNum(System::String^);
	System::String^ getName();
	System::String^ getDes();
	System::String^ getAdres();
	System::String^ getCity();

	int getHotelNum();
	array<System::String^>^ getroomName();
	bool^ findRoom(int^, System::String^ chs, int^ Pnum, char*);
	int bookRoom(System::String^, System::String^, System::Decimal Pnum, System::DateTime, System::DateTime);
	System::String^ printHotelImf();
	bool initbooktable(System::String^ roomNum);

private:
	int^ cnt = gcnew int(0);
	System::String^ m_name, ^m_address, ^m_city, ^m_des;
	array<CRoomType^>^ m_Roomtype = gcnew array<CRoomType^>(20);
	CBookRecord^ m_Bookrecord = gcnew CBookRecord();
	array<System::String^>^ roomName;
	
};

