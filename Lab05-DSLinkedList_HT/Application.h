#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "DoublySortedLinkedList.h"
#include "CategoryType.h"


#define FILENAMESIZE 1024

/**
*	�������� �����ϱ� ���� Application Ŭ����.
*/
class Application
{
	friend class categorytype;
public:
	/**
	*	����Ʈ ������.
	*/
	Application()
	{
		m_Command = 0;
	}
	
	/**
	*	�Ҹ���.
	*/
	~Application()	{}

	/**
	*	@brief	���α׷��� �����Ѵ�.
	*	@pre	���α׷��� �����Ѵ�.
	*	@post	���α׷��� ������.
	*/
	void Run();

	/**
	*	@brief	command�� ��ũ���� ����ϰ� Ű����κ��� command�� �Է¹޴´�.
	*	@pre	����.
	*	@post	����.
	*	@return	������ command.
	*/
	int GetCommand();

	/**
	*	@brief	���ο� �������� ������ ����Ʈ�� �߰��Ѵ�.
	*	@pre	����Ʈ�� �ʱ�ȭ�Ǿ�� �Ѵ�.
	*	@post	����Ʈ�� �� �������� ������ �߰��ȴ�.
	*	@return	�Լ��� �� �۵��ϸ� 1�� �����ϰ�, �׷��� ������ 0�� �����Ѵ�.
	*/
	int AddItem();

	/**
	*	@brief	����Ʈ�� ��� ������ �������� ��ũ���� ����Ѵ�.
	*	@pre	����.
	*	@post	����.
	*/
	void DisplayAllItem();

	/**
	*	@brief	������ �ҷ��� ������ ���� ��ũ��Ʈ�� �̿��� ����.
	*	@pre	������ �ҷ��� ������ �����ؾ��Ѵ�.
	*	@post	�б� ���� ������ ����.
	*	@param	fileName	������ �ҷ����� ���� ���� ������ �̸�.
	*	@return	�Լ��� �� �۵��ϸ� 1�� �����ϰ�, �׷��� ������ 0�� �����Ѵ�.
	*/
	int OpenInFile(char *fileName);

	/**
	*	@brief	������ ������ ������ ���� ��ũ��Ʈ�� �̿��� ����.
	*	@pre	����Ʈ�� �ʱ�ȭ�Ǿ��־�� �Ѵ�.
	*	@post	���� ���� ������ ����.
	*	@param	fileName	������ ���� ���� ���� ������ �̸�.
	*	@return	�Լ��� �� �۵��ϸ� 1�� �����ϰ�, �׷��� ������ 0�� �����Ѵ�.
	*/
	int OpenOutFile(char *fileName);

	/**
	*	@brief	�б� ���� ������ ���� ���Ͽ� �ִ� ��� �����͸� �ҷ����� �����͵�� ����Ʈ�� �����.
	*	@pre	������ �������� �ʴ�.
	*	@post	����Ʈ�� ������ ��� ������ �������� �ִ´�.
	*	@return	�Լ��� �� �۵��ϸ� 1�� �����ϰ�, �׷��� ������ 0�� �����Ѵ�.
	*/
	int ReadDataFromFile();

	/**
	*	@brief	O���� ���� ������ ���� ����Ʈ�� ��� �������� �����Ѵ�.
	*	@pre	������ �������� �ʴ�.
	*	@post	�����ϴ� ���Ͽ� ����Ʈ�� ����ȴ�.
	*	@return	�Լ��� �� �۵��ϸ� 1�� �����ϰ�, �׷��� ������ 0�� �����Ѵ�.
	*/
	int WriteDataToFile();

	/**
	*	@brief	�Է¹��� ID�� ������ ������ ã�Ƴ��� ��ũ���� ����Ѵ�.
	*	@pre	����Ʈ�� �����۵��� ������ ����Ǿ� �ִ�.
	*	@post	����Ʈ���� �������� ã�� ����Ѵ�.
	*	@return	�Լ��� �� �۵��ϸ� 1�� �����ϰ�, �׷��� ������ 0�� �����Ѵ�.
	*/
	int SearchItembyID();

	/**
	*	@brief	����Ʈ�� ����.
	*	@pre	����Ʈ�� �����۵��� ������ ����Ǿ� �ִ�.
	*	@post	����Ʈ�� �������.
	*/
	void MakeEmptyList();
	
	/**
	*	@brief	�Է¹��� ID�� �������� ã�Ƴ��� �����Ѵ�.
	*	@pre	����Ʈ�� �����۵��� ������ ����Ǿ� �ִ�.
	*	@post	����Ʈ���� �������� ã�� �����Ѵ�.
	*	@return	�Լ��� �� �۵��ϸ� 1�� �����ϰ�, �׷��� ������ 0�� �����Ѵ�.
	*/
	int DeleteItem();
	
	/**
	*	@brief	�Է¹��� ID�� ������ ������ ã�Ƴ��� �����Ѵ�.
	*	@pre	����Ʈ�� �����۵��� ������ ����Ǿ� �ִ�.
	*	@post	����Ʈ���� �������� ã�� ������ �����Ѵ�.
	*	@return	�Լ��� �� �۵��ϸ� 1�� �����ϰ�, �׷��� ������ 0�� �����Ѵ�.
	*/
	int UpdateInfo();

	/**
	*	@brief	�̸��� �Է¹޾� ���� �̸��� ������ ��� �����۵��� ����Ѵ�.
	*	@pre	�̸��� �Է¹޴´�.
	*	@post	����Ʈ���� ���� �̸��� ���� ��� �����۵��� ��µȴ�.
	*/
	void SearchByName();


private:
	ifstream m_InFile;		///< �Է� ���� ��ũ����.
	ofstream m_OutFile;		///< ��� ���� ��ũ����.
	DoublySortedLinkedList<ItemType> m_list; ///< ������ ����Ʈ.
	DoublySortedLinkedList<CategoryType> catelist;
	int m_Command;			///< ���� command ����.
};

#endif	// _APPLICATION_H