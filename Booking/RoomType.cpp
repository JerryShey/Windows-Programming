/******************************
4103056035 周彤 第七次作業12/30
******************************/
#include "stdafx.h"
#include "RoomType.h"

#include "myMath.h"

CRoomType::CRoomType()
{
}


CRoomType::CRoomType(System::String^ name, System::String^ price)
{

	m_roomName = gcnew System::String(name);
	array<System::Char>^ number = price->ToCharArray();
	m_price = gcnew int(0);
	cnt = gcnew int(0);
	calc(number, m_price);
	int^R = gcnew int(name->IndexOf(L"人"));

	m_NumOfPeople = gcnew int(0);
	calc((name->System::String::Substring(0, *R))->System::String::ToCharArray(), m_NumOfPeople);
	delete number;
}


void CRoomType::setroomNum(System::String^ line)
{
	System::String^ delimStr = " ";
	array<System::Char>^ delimiter = delimStr->ToCharArray();

	array<System::String^>^ lines = line->Split(delimiter);
	for (; *cnt < (lines->Length); (*cnt)++){
		m_roomNum[*cnt] = gcnew System::String(lines[*cnt]);

	}
	delete delimiter, delimStr, lines;
}


int CRoomType::getPrice()
{
	return *m_price;
}


System::String^ CRoomType::getroomName(){
	return m_roomName;
}

bool^ CRoomType::findRoom(int^ Pnum, char* Rnum)
{
	*Pnum = *m_NumOfPeople;
	for (int ^i = gcnew int(0); *i < *cnt; (*i)++){
		if (m_book[*i])
			continue;
		else{
			for (int^ j = gcnew int(0); (*j) < m_roomNum[*i]->Length; (*j)++)
				Rnum[*j] = m_roomNum[*i][*j];
			Rnum[m_roomNum[*i]->Length] = '\0';
			m_book[*i] = true;
			return m_book[*i];
		}
	}
	return nullptr;
}


bool CRoomType::initbooktable(System::String^ roomNum)
{
	System::String^ line; 
	line = roomNum->Substring(0, roomNum->Length - 1);
	for (int i = 0; i < (*cnt); i++){
		if (!line->CompareTo(m_roomNum[i])){
			m_book[i] = true;
			return true;
		}
	}
	return false;
}
