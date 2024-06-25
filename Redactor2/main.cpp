#include<iostream>
using namespace std;



class Document// интерфейс документа 
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
class Factory//фабрика созданания интерфейса документа
{
public:
	virtual Document* creatDocument() = 0;
	virtual ~Factory() = default;
};



//конкретный класс документа -наследует методы документа
class TextDocument :public Document
{
public:
	void New()override
	{
		cout << "создали новый документ" << endl;
	}
	void Open()override
	{
		cout << "Открыли документ" << endl;
	}
	void Save()override
	{
		cout << "Сохранили документ" << endl;
	}
	void SaveNewName()override
	{
		cout << "Сохраниил документ с новым именем" << endl;
	}
	void Print()override
	{
		cout << "Печать документа" << endl;
	}
	void Close()override
	{
		cout << "Закрытие документа" << endl;
	}
};
//фабрика создания доку
class DocumentFactory:public Factory
{
public:
	Document* creatDocument()override
	{
		return new TextDocument();
	}
};


/*
				Здесь можео создать еще различные документы
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
	//Client использует фабрику для создания и работы с документами
	//DocumentFactory() - фабрика для создания документов
	//Клиент создает указатель- исполь новый экземпляр клиента с экземпляром фабрики
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