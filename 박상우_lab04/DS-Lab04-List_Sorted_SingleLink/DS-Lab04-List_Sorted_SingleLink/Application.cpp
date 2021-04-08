#include "Application.h"


// Program driver.
int GetCommand(int num, string name[]);
void Application::Run()
{
	string cmmdArray[] = { "0 : Quit ", "1 : Insert Item", "2 : Display all Item","3 : Make empty list"
	,"4 : Retrieve by ID","5 : Delete by ID","6 : Update item","7 : Read from file"
	,"8 : Write to file",};
    #define CMMDNUM 9
	while(1)
	{
		m_nCurCommand = GetCommand(CMMDNUM, cmmdArray);

		switch(m_nCurCommand)
		{
		case 0:	// quit
			return;
		case 1:		// inset item
			InsertItem();
			break;
		case 2:		// display all items
			DisplayAll();
			break;
		case 3:		// make the list empty
			MakeEmpty();
			break;
		case 4:		// retrieves item
			RetrieveItem();
			break;
		case 5:		// delete item
			DeleteItem();
			break;
		case 6:		// change value of an item
			Update();
			break;
		case 7:		// get data from data file
			ReadDataFromFile();
			break;
		case 8:		// put data to data file
			WriteDataToFile();
			break;
		default:
			cout << "\tIllegal sellection...\n";
			break;
		}
	}	
}

// Add new record into list.
int Application::InsertItem()
{
	ItemType item;

	cout << "Input Item : ";
	item.SetRecordFromKB();	//�߰��� ������ �Է��Ѵ�.
	
	m_List.Add(item);	//����Ʈ�� �׸��� �߰��Ѵ�.
	DisplayAll();	//����Ʈ�� ȭ�鿡 ����Ѵ�.

	return 1;
}

//Delete record into list.
int Application::DeleteItem()
{
	ItemType item;

	cout << "\tDelete item : ";
	item.SetIdFromKB();	//������ �׸��� id�� �Է�

	if(m_List.Delete(item))
	{
		cout << "\tDeleted " << item.GetId() << " Successfully." << endl;
		return 1;
	}	//������ �����ϸ� ���� �޽����� ���
	else
	{
		cout <<"\t"<< item.GetId() << " is not found." << endl;
		return 0;
	}	//�ش� �׸��� ã�� �� ������ ã�� ���ߴٴ� �޽����� ���
}


// Display all records in the list on screen.
void Application::DisplayAll()
{
	ItemType data;

	cout << "\n\tCurrent list" << endl;

	m_List.ResetList();	// ����Ʈ �ʱ�ȭ
	// list�� ��� �����͸� ȭ�鿡 ���
	for(int i = 0; i < m_List.GetLength(); i++)
	{
		m_List.GetNextItem(data);
		data.DisplayRecordOnScreen();
		cout << "\n";
	}
}

//Make empty list.
int Application::MakeEmpty()
{
	m_List.MakeEmpty();
	cout << "\t List is now empty.";
	return 0;
}


// Retrieve item in the list.
int Application::RetrieveItem()
{
	ItemType item;
	ItemType* itemPtr;
	cout << "\t Enter a item's ID for search : ";
	item.SetIdFromKB();	//ã�� �׸��� id�� �Է�

	if (m_List.Retrieve(item))
	//if (itemPtr=m_List.RetrievePtr(item))
	{
		cout << "\t Target item exists in the list." << endl;
		item.DisplayRecordOnScreen();		
		//itemPtr->DisplayRecordOnScreen();
		return 1;
	}	//ã�°��� �����ϸ� �ش� �׸��� ������ ȭ�鿡 ���
	else
	{
		cout << "\t Target item is not in the list." << endl;
		return 0;
	}	//ã�� �� ���ٸ� ã�� �� ���ٴ� �޽��� ���
}

//Change item's value in the list.
int Application::Update()
{
	ItemType item;
	cout << "\t Enter a item's ID for search : ";
	item.SetIdFromKB();	//������ ������ �׸��� id�� �Է�

	if(!m_List.Retrieve(item))
	{
		cout << "\t Target item is not in the list." << endl;
		return 0;
	}	//�ش� �׸��� ����Ʈ�� ������ ã�� ���ߴٴ� �޽��� ���
	else
	{
		item.SetNameFromKB();
		item.SetAddressFromKB();	//������ ���� �Է�
		if(m_List.Replace(item))	//�Է¹��� ������ ����Ʈ�� �ݿ�
			cout << "\t ���� �Ϸ�" << endl;
		else
			cout << "\t ���� ����" << endl;
	}
	return 1;
}

// Open a file by file descriptor as an input file.
int Application::OpenInFile(string fileName)
{
	m_InFile.open(fileName);	// file open for reading.
	
	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if (!m_InFile) {
		cout << "\t Input File open Error: NO Such File\n";
		return 0;
	}
	else	return 1;
}


// Open a file by file descriptor as an output file.
int Application::OpenOutFile(string fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if(!m_OutFile)	return 0;
	else	return 1;
}


// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile()
{
	int index = 0;
	
	string filename;
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if(!OpenInFile(filename))
		return 0;

	// ������ ��� ������ �о� list�� �߰�
	ItemType readData;	// �б�� �ӽ� ����
	bool hasMissingData = false;
	int readDataCount = 0;
	while (!m_InFile.eof())
	{
		if (readData.ReadDataFromFile(m_InFile)) // Add only valid data
		{
			m_List.Add(readData);
			readDataCount++;
		}
		else
		{
			hasMissingData = true;
		}
	}

	if (hasMissingData) // If missing data exist, show below error
	{
		cout << "\n\t [!]ERROR There's missing data due to invalid element" << endl;
	}

	m_InFile.close();
	return true;
	
}


// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile()
{
	int length = m_List.GetLength();
	if (length <= 0)
	{
		cout << "\n\t [!]ERROR There's no data to save" << endl;
		return false;
	}
	
	ItemType data;	// ����� �ӽ� ����

	string filename;
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if(!OpenOutFile(filename))
		return 0;

	// list �����͸� �ʱ�ȭ
	m_List.ResetList();
	bool hasInvalidData = false;
	int index = 0;
	while(m_List.GetNextItem(data) && index < length)
	{
		if (!data.WriteDataToFile(m_OutFile)) // Write only valid data
		{
			hasInvalidData = true;
		}
		if (index != length - 1)
			m_OutFile << endl;
		index++;
	}

	if (hasInvalidData) // If invalid data exist, show below error
	{
		cout << "\n\t [!]ERROR There's data that has not been written due to invalid element value" << endl;
	}

	m_OutFile.close();	// file close
	return true;
}