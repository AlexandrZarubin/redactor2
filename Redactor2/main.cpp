#include<iostream>
using namespace std;



class Document// ��������� ��������� 
{
public:
	virtual void New() = 0;
	virtual void Open() = 0;
	virtual void Save() = 0;
	virtual void SaveNewName() = 0;
	virtual void Print() = 0;
	virtual void Close() = 0;
	virtual ~Document() = default;
};
class Factory//������� ���������� ���������� ���������
{
public:
	virtual Document* creatDocument() = 0;
	virtual ~Factory() = default;
};



//���������� ����� ��������� -��������� ������ ���������
class TextDocument :public Document
{
public:
	void New()override
	{
		cout << "������� ����� ��������" << endl;
	}
	void Open()override
	{
		cout << "������� ��������" << endl;
	}
	void Save()override
	{
		cout << "��������� ��������" << endl;
	}
	void SaveNewName()override
	{
		cout << "��������� �������� � ����� ������" << endl;
	}
	void Print()override
	{
		cout << "������ ���������" << endl;
	}
	void Close()override
	{
		cout << "�������� ���������" << endl;
	}
};
//������� �������� ����
class DocumentFactory:public Factory
{
public:
	Document* creatDocument()override
	{
		return new TextDocument();
	}
};


/*
				����� ����� ������� ��� ��������� ���������
				class Tablica:public Document
				{};
				class Tablica_Factory:public Factory
				{};

				class Presentacia:public Document
				{};
				class Presentacia_Factory:public Factory
				{};

*/

class Client
{
	Factory* factory;
	Document* ThisDocument;
public:
	Client(Factory*factory):factory(factory),ThisDocument(nullptr){}
	void NewDoc()
	{
		ThisDocument = factory->creatDocument();
	}
	void OpenDoc()
	{
		ThisDocument->Open();
	}
	void SaveDoc()
	{
		ThisDocument->Save();
	}
	void  SaveNameDoc()
	{
		ThisDocument->SaveNewName();
	}
	void PrintDoc()
	{
		ThisDocument->Print();
	}
	void CloseDoc()
	{
		ThisDocument->Close();
	}
	~Client()
	{
		delete factory;
	}
};
int main()
{
	setlocale(LC_ALL, "rus");
	//Client ���������� ������� ��� �������� � ������ � �����������
	//DocumentFactory() - ������� ��� �������� ����������
	//������ ������� ���������- ������ ����� ��������� ������� � ����������� �������
	Client* NewDoc = new Client(new DocumentFactory());

	NewDoc->NewDoc();
	NewDoc->OpenDoc();
	NewDoc->PrintDoc();
	NewDoc->SaveDoc();
	NewDoc->SaveNameDoc();
	NewDoc->CloseDoc();

	delete NewDoc;
	return 0;
}