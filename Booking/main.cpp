/******************************
4103056035 周彤 第七次作業12/30
******************************/
#include "MyForm.h" //the header name for your form

using namespace WindowProgram; //the project name in your header file
int* cnt = new int(0);

void init(array<CHotel^>^);
void includeHot(array<CHotel^>^);
void includeGuest(array<CHotel^>^);
void getHotImf(CHotel^, System::String^);
int hotHeader(System::String^ line);

int main(array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	array<CHotel^>^ hotel = gcnew array<CHotel^>(100);
	init(hotel);
	Application::Run(gcnew MyForm(hotel));
	return 0;
}
void init(array<CHotel^>^ hotel){

	includeHot(hotel);
	includeGuest(hotel);
}

void includeHot(array<CHotel^>^ hotel){
	System::IO::StreamReader^ file = System::IO::File::OpenText("Hotel Imformation.txt");
	System::String^ line;

	while ((line = file->ReadLine()) != nullptr){
		hotel[*cnt] = gcnew CHotel();
		getHotImf(hotel[*cnt], line);
		(*cnt)++;
	}
}

void getHotImf(CHotel^ hotel, System::String^ name){
	System::String^ address;
	System::String^ line = L"";
	int type = 0;
	int roomType = 0;

	/***
	**** 利用旅館名稱找到旅館資訊
	***/
	address = name + ".txt";
	System::IO::StreamReader^ hotelImf = gcnew System::IO::StreamReader(System::IO::File::OpenRead(address), System::Text::Encoding::Unicode);

	/****
	***** 儲存旅館資訊
	****/
	hotel->setName(name);
	while ((line = hotelImf->ReadLine()) != nullptr){
		System::String^ str = gcnew System::String(line);
		System::String^ delimStr = L", :";
		System::String^ subStr;
		int^ L = gcnew int(0), ^R = gcnew int(0);
		array<System::String^>^ lines;

		array<System::Char>^ delimiter = delimStr->ToCharArray();

		*R = str->IndexOf(L"	");
		type = hotHeader(str->Substring(*L, *R - *L));
		switch (type){
		case 1:
			*L = *R + 1;
			*R = str->Length;
			subStr = gcnew System::String(str->Substring(*L, *R - *L));
			hotel->setAddress(subStr);
			break;
		case 2:
			*L = *R + 1;
			*R = str->Length;
			hotel->setCity(str->Substring(*L, *R - *L));
			break;
		case 3:
			*L = *R + 1;
			*R = str->Length;
			str = str->Substring(*L, *R - *L);
			hotel->setRoomNum(str);
			break;
		case 4:
			*L = *R + 1;
			*R = str->Length;
			str = str->Substring(*L, *R - *L);
			lines = str->Split(delimiter);
			hotel->setRoomtype(lines);
			break;

		case 5:
			*L = *R + 1;
			*R = str->Length;

			hotel->setDes(str->Substring(*L, *R - *L));
			break;
		default:
			break;
		}
		delete L, R, delimiter, lines;
	}
	delete address, line, hotelImf;
}



int hotHeader(System::String^ line){
	if (!System::String::Compare(line, (System::String^)"address")){
		return 1;
	}
	else if (!System::String::Compare(line, (System::String^)"city")){
		return 2;
	}
	else if (!System::String::Compare(line, (System::String^)"number")){
		return 3;
	}
	else if (!System::String::Compare(line, (System::String^)"price")){
		return 4;
	}
	else if (!System::String::Compare(line, (System::String^)"description")){

		return 5;
	}
	else{
		return 0;
	}
	return 0;
}
void includeGuest(array<CHotel^>^ hotel){
	System::IO::StreamReader^ guestName = gcnew System::IO::StreamReader(System::IO::File::OpenRead("guestName.txt"), System::Text::Encoding::Unicode);
	System::String^ name;
	while ((name = guestName->ReadLine()) != nullptr && name->CompareTo("") ){
		System::String^ path, ^line;
		path = name + ".txt";
		if (System::IO::File::Exists(path))
		{
			System::IO::StreamReader^ guest = gcnew System::IO::StreamReader(System::IO::File::OpenRead(path), System::Text::Encoding::Unicode);
			while (!(line = guest->ReadLine()) && line->CompareTo("")){
				System::String^ delimStr = L" :";
				array<System::Char>^ delimiter = delimStr->ToCharArray();
				array<System::String^>^ lines;

				lines = line->Split(delimiter);
				for (int i = 0; i < (*cnt); i++)
					if (!lines[1]->CompareTo(hotel[i]->getName())){
						hotel[i]->initbooktable(lines[3]);
						break;
					}
			}
			guest->Close();
		}
		
	}
	guestName->Close();
}