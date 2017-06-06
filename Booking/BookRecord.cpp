/******************************
4103056035 �P�� �ĤC���@�~12/30
******************************/
#include "stdafx.h"
#include "BookRecord.h"


CBookRecord::CBookRecord()
{
}


bool CBookRecord::Book(System::String^ hotelName, System::String^ path, char* Rnum, System::Decimal Pnum, System::DateTime day, int days, int price)
{
	array<System::String^>^ lines;
	int cnt = 0;
	if (System::IO::File::Exists(path))
	{
		lines = gcnew array<System::String^>(100);
		System::String^ line;
		System::IO::StreamReader^ guest = gcnew System::IO::StreamReader(System::IO::File::OpenRead(path), System::Text::Encoding::Unicode);
		
			while ((line = guest->ReadLine()) != nullptr && line->CompareTo(""))
				lines[cnt++] = line;
		guest->Close();
	}
	
	System::IO::StreamWriter^ book = gcnew System::IO::StreamWriter(System::IO::File::OpenWrite(path), System::Text::Encoding::Unicode);
	System::String^ roomName = gcnew System::String(Rnum);
	for (int i = 0; i < cnt; i++){
		book->WriteLine(lines[i]);
	}
	book->WriteLine("���]�W��:{0} �и�:{1}�� �H��:{2}�H ���:{3}�~{4}��{5}�� �Ѽ�:{6}�� ���B:{7}�� ���I��", hotelName, roomName, Pnum, day.Year, day.Month, day.Day, days, price);

	book->Close();
	delete roomName;
	return true;
}
