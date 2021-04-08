#include "Application.h"


// ���α׷��� �����Ű��? �Լ�
void Application::Run()
{
	while(1)
	{
		m_Command = GetCommand();

		switch(m_Command)
		{
		case 1:		// ����Ʈ�� �������� �߰��Ѵ�.
			AddItem();
			break;	
		case 2:		// ��ũ���� ����Ʈ�� ���? ������ ������ ����Ѵ�?.
			DisplayAllItem();
			break;
		case 3:		// ����Ʈ�� ����.
			MakeEmptyList();
			break;
		case 4:		// ID�� �̿��Ͽ� ����Ʈ���� �������� ã�´�.
			SearchItembyID();
			break;
		case 5:		// �̸��� �̿��Ͽ� ����Ʈ���� �������� ã�´�.
			SearchByName();
			break;
		case 6:		// ID�� �̿��Ͽ� ����Ʈ���� �������� ã�� �����Ѵ�.
			DeleteItem();
			break;
		case 7:		// ID�� �̿��Ͽ� ����Ʈ���� �������� ã�� ������ �����Ѵ�.
			UpdateInfo();
			break;
		case 8:		// ����Ʈ�� ���? ������ ���Ͽ��� �ҷ��´�.
			ReadDataFromFile();
			break;
		case 9:		// ����Ʈ�� ���? ������ ���Ͽ� �����Ѵ�.
			WriteDataToFile();
			break;
		case 0:		// ���α׷��� ������.
			return;
		default:
			cout << "\tIllegal sellection...\n";
			break;
		}
	}
}


// ��ũ���� command�� ����ϰ�? Ű����κ���? command�� �Է¹޴´�.
int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add new item" << endl;
	cout << "\t   2 : Print all on screen" << endl;
	cout << "\t   3 : Make empty list" << endl;
	cout << "\t   4 : Search item by ID" << endl;
	cout << "\t   5 : Search item by Name" << endl;
	cout << "\t   6 : Delete item" << endl;
	cout << "\t   7 : Update item info" << endl;
	cout << "\t   8 : Get from file" << endl; 
	cout << "\t   9 : Put to file " << endl; 
	cout << "\t   0 : Quit" << endl; 

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}


// ����Ʈ�� ���ο� ������ ������ �߰��Ѵ�.
int Application::AddItem()
{
	// �Է¹��� ���ڵ带 ����Ʈ�� add, ����Ʈ�� full�� ���� add���� �ʰ� 0�� ����
	if(m_List.IsFull())
	{
		cout << "List is full" << endl;
		return 0;
	}

	ItemType item;

	item.SetRecordFromKB();

	if(m_List.Add(item) == 0) // �Է��� ���̵��? ���� ���̵� �̹� ����Ʈ�� ������
	{
		cout << "Already has same ID! Try Again!" << endl; // ���������? ����Ѵ�?.
		return 0;
	}

	// ���� list ���?
	DisplayAllItem();

	return 1;
}

/*
// ��ũ���� ����Ʈ�� ���? ������ �������� ����Ѵ�?.
void Application::DisplayAllItem()
{
	ItemType data;

	cout << "\n\tCurrent list" << endl;

	// list�� ���? �����͸� ȭ�鿡 ���?
	DoublyIterator<ItemType> itor(m_List);
	data = itor.Next();
	while (itor.NextNotNull())
	{
		data.DisplayRecordOnScreen();
		data = itor.Next();
	}
}
*/
// ��ũ���� ����Ʈ�� ���? ������ �������� ����Ѵ�?.
void Application::DisplayAllItem()
{
	ItemType data;

	cout << "\n\tCurrent list" << endl;

	// list�� ���? �����͸� ȭ�鿡 ���?
	DoublyIterator<ItemType> itor(m_List);
	for (itor.Begin(); itor.NotEnd(); itor.Next()) {
		itor.GetCurrentNode()->DisplayRecordOnScreen();
	}
}


// ������ �ҷ��� ������ ���� �Լ�
int Application::OpenInFile(char *fileName)
{
	m_InFile.open(fileName);	// �ҷ����� ���� ���� ����
	
	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if(!m_InFile)	return 0;
	else	return 1;
}


// ������ ������ ������ ���� �Լ�
int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);	// �����ϱ� ���� ���� ����

	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if(!m_OutFile)	return 0;
	else	return 1;
}


// �б� ���� ������ ���� ���Ͽ� �ִ� ���? �����͸� �ҷ����� �����͵��? ����Ʈ�� �����?.
int Application::ReadDataFromFile()
{
	int index = 0;
	ItemType data;	// �б��? �ӽ� ����
	
	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if(!OpenInFile(filename))
		return 0;

	// ������ ���? ������ �о� list�� �߰�
	while(!m_InFile.eof())
	{
		// array�� �л����� ������ ����ִ�? structure ����
		data.ReadDataFromFile(m_InFile);
		m_List.Add(data);
	}

	m_InFile.close();	// ������ �ݴ´�.

	// ���� list ���?
	DisplayAllItem();

	return 1;
}


// ���� ���� ������ ���� ����Ʈ�� ���? �������� �����Ѵ�.
int Application::WriteDataToFile()
{
	ItemType data;	// �����? �ӽ� ����

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if(!OpenOutFile(filename))
		return 0;


	// list�� ���? �����͸� ���Ͽ� ����
	DoublyIterator<ItemType> itor(m_List);
	itor.Begin();
	for (itor.Begin(); itor.NotEnd(); itor.Next())
	{ 
		itor.GetCurrentNode()->WriteDataToFile(m_OutFile);
	}

	m_OutFile.close();	// ������ �ݴ´�.

	return 1;
}


// �Է¹��� ID�� ������ ������ ã�Ƴ��� ��ũ���� ����Ѵ�?.
int Application::SearchItembyID()
{
	ItemType data;
	data.SetIdFromKB(); // Ű����κ���? ID�� �Է¹޴´�.
	if(m_List.Get(data) == 0)
		cout << "\tNo match. Try Again." << endl; // ����Ʈ�� ��ġ�ϴ� �������� ���� ���? ��õ�? ���� ���?
	else
		data.DisplayRecordOnScreen(); //����Ʈ�� ��ġ�ϴ� �������� �߰��ϸ� �� �������� ���? ������ ���?

	return 1;
}


// ����Ʈ�� ���� �Լ�
void Application::MakeEmptyList()
{
	m_List.MakeEmpty(); // ����Ʈ�� ����
	cout << "\tCompelete. List is Empty" << endl; // ����Ʈ ���⿡ �����ߴٴ� ���� ���?
}


// �Է¹��� ID�� �������� ã�Ƴ��� �� �������� ���? ������ ����Ʈ���� �����Ѵ�.
int Application::DeleteItem()
{
	if(m_List.IsEmpty() == true) // ����Ʈ�� �����? �� �����͸� ���� �߰��϶��? ���� ���?
	{
		cout << "\tData is Empty. Add new data and Try again." << endl;
		return 0;
	}
	ItemType data;
	data.SetIdFromKB(); // Ű����κ���? ID�� �Է¹޴´�.
	if(m_List.Get(data) == 0) // ��ġ�ϴ� �������� ���� ���? ��õ�? ���� ���?
	{
		cout << "\tNo Match. Try Again" << endl;
		return 0;
	}
	m_List.Delete(data); // �������� ������ �����Ѵ�.
	cout << "\tDelete compelete." << endl; // ���� �Ϸ� ���� ���?
	return 1;
}


// �Է¹��� ID�� �������� ã�Ƴ��� �� �������� ������ �����Ѵ�.
int Application::UpdateInfo()
{
	ItemType data;
	data.SetIdFromKB(); // Ű����κ���? ID�� �Է¹޴´�.
	if(m_List.Get(data) == 0) // ��ġ�ϴ� �������� ���� ���? ��õ�? ���� ���?
	{
		cout << "\tNo Match. Try Again" << endl;
		return 0;
	}
	data.SetNameFromKB();
	data.SetManufacturerFromKB();
	m_List.Replace(data); // �������� ������ �����Ѵ�.
	cout << "\tUpdate compelete." << endl; // ���� �Ϸ� ���� ���?
	return 1;
}



//�̸��� �Է¹޾� ���� �̸��� ���� ���? �����۵��� ����Ѵ�?.
void Application::SearchByName()
{

	ItemType target;
	target.SetNameFromKB(); // Ű����κ���? �̸��� �Է¹޴´�.

	ItemType* data;

	cout << "\n\tCurrent list" << endl;

	DoublyIterator<ItemType> itor(m_List);								
	for( itor.Begin(); itor.NotEnd(); itor.Next())
	{		
		data = itor.GetCurrentNode();
		if ( data->GetName().find(target.GetName(),0) != -1 ) // �������� �̸��� ��
			data->DisplayRecordOnScreen(); // ��ġ�ϸ� ���?
	}

	return;
}

// Singlylinkedlist�α�����ī�װ����ǻ�ǰ����Ʈ��Header��trailernode���̿���doublylinkedlist�α����Ѵ�