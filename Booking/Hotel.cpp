/******************************
4103056035 周彤 第七次作業12/30
******************************/
#include "stdafx.h"
#include "Hotel.h"
#include "myMath.h"

CHotel::CHotel()
{
}

void CHotel::setAddress(System::String^ ades)
{
	m_address = gcnew System::String(ades);
}

void CHotel::setDes(System::String^ des)
{
	m_des = gcnew System::String(des);
}

void CHotel::setName(System::String^ name)
{
	m_name = gcnew System::String(name);
}

void CHotel::setCity(System::String^ city)
{
	m_city = gcnew System::String(city);
}

void CHotel::setRoomtype(array<System::String^>^ roomtype)
{
	int^ i = gcnew int(0);
	int^ j = gcnew int(0);
	for (*i = 0; *i < (roomtype->Length); (*i)+=2){
		if (*j)
			*j = 1 - *j;
		else
			m_Roomtype[(*cnt)++] = gcnew CRoomType(roomtype[*i], roomtype[(*i)+1]);
	}
	roomName = gcnew array<System::String^>(*cnt);
	for ((*i) = 0; (*i) < (*cnt); (*i)++)
		roomName[(*i)] = m_Roomtype[(*i)]->getroomName();
	
	delete i, j;
}

void CHotel::setRoomNum(System::String^ line)
{
	int^ temp = gcnew int(0), ^i = gcnew int(0);

	System::String^ delimStr = L",:";
	array<System::Char>^ delimiter = delimStr->ToCharArray();

	array<System::String^>^lines = line->Split(delimiter);
	while (*i < (lines->Length)){
		for (*temp = 0; *temp < *cnt; (*temp)++)
			if (!(System::String::Compare(lines[*i], m_Roomtype[*temp]->getroomName()))){
				(*i)++;
				m_Roomtype[*temp]->setroomNum(lines[*i]);
				(*i)++;
			} 
	}
	delete temp, i, delimiter, delimStr;

}

System::String^ CHotel::getName()
{
	return m_name;
	//TODO: insert return statement here
}

System::String^ CHotel::getDes()
{
	return m_des;
	//TODO: insert return statement here
}

System::String^ CHotel::getAdres()
{
	return m_address;
	//TODO: insert return statement here
}

System::String^ CHotel::getCity()
{
	return m_city;
	//TODO: insert return statement here
}

int CHotel::getHotelNum(){
	return *cnt;
}

array<System::String^>^ CHotel::getroomName()
{
	
	return roomName;
}

bool^ CHotel::findRoom(int^ num, System::String^ chs, int^ Pnum, char* Rnum)
{
	for (int room = 0; room < *cnt; room++){
		if (m_Roomtype[room]->getroomName() == chs){
			*num = room;
			return m_Roomtype[room]->findRoom(Pnum, Rnum);
		}
	}
		
	return nullptr;
}

int CHotel::bookRoom(System::String^ Rname, System::String^ Pname, System::Decimal Pnum, System::DateTime startday, System::DateTime endday)
{ 
	System::String ^path, ^guestN, ^str;
	array<System::String^>^ lines = gcnew array<System::String^>(100);
	int^ RPnum = gcnew int(0);
	char* Rnum = new char(NULL);
	int^ num = gcnew int(0);
	bool^ book = gcnew bool(true);

	book = findRoom(num, Rname, RPnum, Rnum);

	if (book == nullptr){
		return 0;
	}
	if (*RPnum < Pnum)
		return -1;

	bool ^findGuest = gcnew bool(false);

	path = Pname + ".txt";
	
	System::IO::StreamReader^ RguestName = gcnew System::IO::StreamReader(System::IO::File::OpenRead("guestName.txt"), System::Text::Encoding::Unicode);
	int cnt = 0;
	while ((guestN = RguestName->ReadLine()) !=nullptr && guestN->CompareTo(""))
	{
		lines[cnt++] = guestN;
		if (!System::String::Compare(Pname, guestN)){
			*findGuest = true;
			break;
		}		
	}
	RguestName->Close();

	if (!(*findGuest)){
		System::IO::StreamWriter^ WguestName = gcnew System::IO::StreamWriter(System::IO::File::OpenWrite("guestName.txt"), System::Text::Encoding::Unicode);
		WguestName->WriteLine(Pname);
		for (int i = 0; i < cnt; i++){
			WguestName->WriteLine(lines[i]);
		}
		WguestName->Close();
	}

	int days = calcday(startday, endday);

	m_Bookrecord->Book(getName(), path, Rnum, Pnum, startday, days, days*(m_Roomtype[*num]->getPrice()));
	//System::Console::WriteLine(L"成功訂房，您的房號是{0}室", Rnum);
	*book = true;
	delete path;
	delete findGuest;
	delete lines;
	return 1;
	

}

System::String^ CHotel::printHotelImf(){
	System::String^ line;
	line = "旅館名稱：" + m_name + "\n旅館資訊：" + m_des + "\n地區：" + m_city + "\n地址：" + 
		m_address + "\n房型與價位：\n";
	for (int *i = new int(0); *i < *cnt; (*i)++){
		line += "\t" + (*i + 1) + ". " + m_Roomtype[*i]->getroomName() + " " + m_Roomtype[*i]->getPrice() + "元/晚\n";
	}
	return line;
}

bool CHotel::initbooktable(System::String^ roomNum)
{
	for (int i = 0; i < (*cnt); i++)
		if (m_Roomtype[i]->initbooktable(roomNum))
			return true;
	return false;
}
