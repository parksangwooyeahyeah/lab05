#pragma once

#include <iostream>
#include <fstream>

#include "ItemType.h"
#include "DoublyIterator.h"

#define MAXSIZE 50

using namespace std;

template <typename T>	//generic data�� ���� template ����
class List_Sorted_Array
{
private:
    T m_Array[MAXSIZE];
    int m_Length;
    int m_CurPointer;
    DoublyIterator<T> itor(*this);
public:
	// Default constructor
    List_Sorted_Array()
    {
        m_Length = 0;
        ResetList();
    }


	// Destructor
    ~List_Sorted_Array() {}


    /**
    *	@brief	Get a number of records in current list.
    *	@pre	none.
    *	@post	none.
    *	@return	number of records in current list.
    */
    int GetLength()
    {
        return m_Length;
    }


    /**
    *	@brief	Check capacity of list is full.
    *	@pre	none.
    *	@post	none.
    *	@return	return true if list capacity reached to the upper bound, otherwise return false.
    */
    bool IsFull()
    {
        return m_Length >= MAXSIZE;
    }


    /**
    *	@brief	Check capacity of list is empty.
    *	@pre	none.
    *	@post	none.
    *	@return	return true if list capacity is empty.
    */
    bool IsEmpty()
    {
        return m_Length <= 0;
    }

	
    /**
    *	@brief	Make list empty.
    *	@pre	none.
    *	@post	clear list.
    */
    void MakeEmpty();


    /**
    *	@brief	add a new data into list.
    *	@pre	list should be initialized.
    *	@post	added the new record into the list.
    *	@param	data	new data.
    *	@return	return 1 if this function works well, otherwise 0.
    */
    bool Add(T data);


    /**
    *	@brief	Initialize list iterator.
    *	@pre	list should be initialized.
    *	@post	iterator is reset.
    */
    void ResetList();


    /**
    *	@brief	move list iterator to the next item in list and get that item.
    *	@pre	list and list iterator should not be initialized.
    *	@post	iterator is moved to next item.
    *	@param	data	get current iterator's item. it does not need to be initialized.
    *	@return	index of current iterator's item if is not end of list, otherwise return -1.
    */
    int GetNextItem(T& data);


	/**
	*	@brief	Check whether the record with the same primary key exist in the list.
	*	@pre	data holds the primary key to be searched
	*	@post   none.
	*	@return	index of target item, otherwise return -1.
	*/
	int IsExist(T data);

	/**
	  *	@brief	Get item that has same name with parameter data.
	  *	@pre	data holds the primary key to be searched.
	  *	@post   none.
	  *	@param	data holds the record found in the list
	  *	@return	index of target item, otherwise return -1.
	  */
	int Retrieve(T& data);


    /**
    *	@brief	Delete item that has same name with parameter data.
    *	@pre	list and list iterator should not be initialized.
    *	@post   Target item is removed.
    *	@param	data	Temp item that has same name with target item.
    *	@return	return true if deletion is successfully completed.
    */
    bool Delete(T& data);


    /**
    *	@brief	Replace item that has same name with parameter data into parameter data.
    *	@pre	list and list iterator should not be initialized.
    *	@post   Target item is replaced.
    *	@param	data	Temp item that has same name with target item.
    *	@return	return true if replace is successfully completed.
    */
    bool Replace(T data);
};

template <typename T>
void List_Sorted_Array<T>::MakeEmpty()
{
	m_Length = 0;
	ResetList();
}

template <typename T>
bool List_Sorted_Array<T>::Add(T data)
{
	// list�� full�̸� false ����
	if (IsFull()) return false;
	// list�� empty�̸� �Ǿտ� �����ϰ� true ����
	if (m_Length == 0) {
		m_Array[0] = data;
		m_Length++;
		return true;
	}

	// �� �׸��� ���� ��ġ iPos�� �˻�
	// ���� �����ϰų� data���� ũ�ų� ���� ������ �˻� 
	int iPos = 0;
	bool found = false;
	while (!found && iPos < m_Length) {
		if (data > m_Array[iPos]) // >
			iPos++;
		else // <=
			found = true;
	}
	// �ߺ�Ű�� ���? ���� �޽��� ���?
	if (data == m_Array[iPos]) {
		cout << "\n Same primary key exists in list\n";
		return false;
	}
	/* �߰��̳� �� ���� ����: ������ ������ Ȯ���ϱ�
	���Ͽ� iPos���� m_Length-1������ ���? �׸��� ���? �̵�
	iPos==m_Length�� ���� �̵����� ����*/
	for (int i = m_Length; i > iPos; i--)
		m_Array[i] = m_Array[i - 1];
	// iPos�� �����ϰ� length ����.
	m_Array[iPos] = data;
	m_Length++;
	return true;
}

template <typename T>
void List_Sorted_Array<T>::ResetList()
{
	m_CurPointer = -1;
}

template <typename T>
int List_Sorted_Array<T>::GetNextItem(T& data)
{
	m_CurPointer++;
	if (m_CurPointer == MAXSIZE)
		return -1;

	data = m_Array[m_CurPointer];

	return m_CurPointer;
}

template <typename T>
int List_Sorted_Array<T>::IsExist(T data) {
	int CurPos = 0;
	bool moreToSearch = true, found = false;
	while (moreToSearch && !found)
	{
		if (data > m_Array[CurPos]) {
			CurPos++;
			moreToSearch = CurPos < m_Length;
		}
		else found = true;
	}
	if (found && data == m_Array[CurPos]) return CurPos;
	else 	return -1;
}

template <typename T>
int List_Sorted_Array<T>::Retrieve(T& data)
{
	int index = IsExist(data);
	if (index != -1) data = m_Array[index];
	return index;
}

template <typename T>
bool List_Sorted_Array<T>::Delete(T& data)
{
	int index = IsExist(data); // Try to get data, invalid : -1
	if (index == -1) return false;
	// overwrite the current record
	for (int i = index; i < m_Length - 1; i++)   // shift right to make the space to insert
		m_Array[i] = m_Array[i + 1];
	m_Length--;
	return true;
}

template <typename T>
bool List_Sorted_Array<T>::Replace(T data)
{
	int index = IsExist(data);
	if (index == -1) return false;
	m_Array[index] = data;
	return true;
}