#pragma once
#ifndef _DOUBLYSORTEDLINKEDLIST_H
#define _DOUBLYSORTEDLINKEDLIST_H

#include "ItemType.h"
#include "DoublyIterator.h"

#define min ItemType(INT_MIN)
#define max ItemType(INT_MAX)

template<typename T>
class DoublyIterator;

/**
*	���Ḯ��Ʈ���� ���̴� NodeType�� ����ü
*/
template <typename T>
struct DoublyNodeType
{
	T data; ///< �� ����� ������.
	DoublyNodeType *prev; // �ճ�� ������.
	DoublyNodeType *next; // �޳�� ������.
};

/**
*	���ĵ� �������Ḯ��Ʈ Ŭ����
*/
template <typename T>
class DoublySortedLinkedList
{
	friend class DoublyIterator<T>; ///< DoublyIterator�� ģ�� Ŭ����.
public:
	DoublySortedLinkedList();
	~DoublySortedLinkedList();
	bool IsEmpty();

	bool IsFull();

	/**
	*	@brief	����Ʈ�� ����.
	*	@pre	����.
	*	@post	m_pFirst�� m_pLast�� ������ ��� �����͸� �����.
	*/
	void MakeEmpty();

	/**
	*	@brief	����Ʈ�� ���̸� ��ȯ�Ѵ�.
	*	@pre	����.
	*	@post	����Ʈ�� ���̸� ��ȯ.
	*	@return	m_nLength ����Ʈ�� ���� ��ȯ.
	*/
	int GetLength() const;

	/**
	*	@brief	���ο� �������� ����Ʈ�� �߰��Ѵ�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	�������� ����Ʈ�� �߰��Ѵ�.
	*	@return	���� �������� ������ 0�� ��ȯ�ϰ�, �Է¿� �����ϸ� 1�� ��ȯ.
	*/
	int Add(T item);

	/**
	*	@brief	�Է¹��� �������� ����Ʈ���� �����Ѵ�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	�Է¹��� �������� ����Ʈ���� ã�� �����Ѵ�.
	*/
	void Delete(T item);

	/**
	*	@brief	�Է¹��� ���������� ������ �ٲ۴�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	���ο� ������ ��ü�ȴ�.
	*/
	void Replace(T item);

	/**
	*	@brief	�Է¹��� �������� ������ ���Ͽ� ���� ����Ʈ�� �������� �����´�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	�˻��� �����͸� �����ۿ� �ִ´�.
	*	@return	��ġ�ϴ� �����͸� ã���� 1, �׷��� ������ 0�� ��ȯ.
	*/
	int Get(T &item);

private:
	DoublyNodeType<T>* m_pFirst; ///< �ּҰ��� ������ ����Ʈ�� �� ó��.
	DoublyNodeType<T>* m_pLast; ///< �ִ��� ������ ����Ʈ�� �� ��.
	int m_nLength; ///< ����Ʈ�� ����.
};

// 리스트를 초기화 하여 생성
template <typename T>
DoublySortedLinkedList<T> :: DoublySortedLinkedList()
{  //헤더와 트레일러 역할을 할 2개의 더미노드 생성. 이때 헤더와 트레일러의 위치는 바뀌지 않고 고정 place holding
	m_pFirst = new DoublyNodeType<T>;
	m_pLast = new DoublyNodeType<T>;
	
	// 헤더와 트레일러가 서로 가리키도록 연결
	m_pFirst->next = m_pLast; // 끝과 처음이 서로를 가리키게 초기화
	m_pLast->prev = m_pFirst; // 끝과 처음이 서로를 가리키게 초기화
	// 앞과뒤는 널로 초기화
	m_pLast->next = NULL; 
	m_pFirst->prev = NULL; 
	m_nLength = 0; // 길이는 0.
}

// �Ҹ���.
template <typename T>
DoublySortedLinkedList<T>::~DoublySortedLinkedList()
{
	delete m_pFirst;
	delete m_pLast;
}

// ����Ʈ�� ������� �˻��Ѵ�.
template <typename T>
bool DoublySortedLinkedList<T>::IsEmpty()
{
	if(m_nLength == 0)
		return true;
	else
		return false;
}

// ����Ʈ�� �� ���ִ��� �˻��Ѵ�.
template <typename T>
bool DoublySortedLinkedList<T>::IsFull()
{
	if(m_nLength == 10)
		return true;
	else
		return false;
}

// ����Ʈ�� ����.
template <typename T>
void DoublySortedLinkedList<T>::MakeEmpty()
{
	DoublyNodeType<T> *pItem;
	DoublyIterator<T> itor(*this);
	itor.Begin(); // �������� �̵�.

	while(itor.NotEnd())
	{
		pItem = itor.m_pCurPointer;
		itor.Next(); // ���� �����͸� �������� �̵�.
		delete pItem; 
	}

	m_pFirst->next = m_pLast;
	m_pFirst->prev = NULL;
	m_pLast->prev = m_pFirst;
	m_pLast->next = NULL;

	return;
}

// ����Ʈ�� ���̸� ��ȯ�Ѵ�.
template <typename T>
int DoublySortedLinkedList<T>::GetLength() const
{
	return m_nLength;
}

// �������� �Է¹޾� ����Ʈ�� �´� �ڸ��� ã�� �����Ѵ�.
template <typename T>
int DoublySortedLinkedList<T>::Add(T item)
{
	DoublyIterator<T> itor(*this);
	itor.Begin(); // �������� �̵�.

	for (itor.Begin(); itor.NotEnd(); itor.Next())
	{
		if (item < itor.m_pCurPointer->data) // �´� �ڸ��� ã�´�.
			break;  // exit the loop
		else if (item == itor.m_pCurPointer->data) // ���� ������ �������� ������
			return 0; // duplicated primary key, retur with 0
		itor.Next(); // �������� �̵�.
	}
	// end with m_pCurPointer==m_pLast
	// or item<m_pCurPointer->data
	// �ΰ�� ��� ���� ��� �տ� �߰�
	DoublyNodeType<T> *pItem = new DoublyNodeType<T>;
	pItem->data = item;
	pItem->prev = itor.m_pCurPointer->prev;
	pItem->next = itor.m_pCurPointer;
	itor.m_pCurPointer->prev->next = pItem;
	itor.m_pCurPointer->prev = pItem; // �������� ����.
	m_nLength++;
	return 1;

}

// 싱글링크드는 두포인터가 이동해나가다가 현재 노드가 인서트하고자 하는 것보다 크면 어쩌고저쩌고
// 더블링크드는 하나의 노드가 전과 후를 가리키기 떄문에 두개의 노드가 필없ㅇ므
// 헤드와 트레일러를 사용해서 항상 둘사이에 인서트하는 경우로 압축됨. 애드하는 케이스를 4가지로 안나눠도됨.
/*
template <typename T> 
int DoublySortedLinkedList<T>::Add(T item) 
{
	DoublyIterator<T> itor(*this);
	itor.Begin(); // ㄷ음으로 이동.

	if(IsEmpty()) // ó�� ������ ��
	{
		DoublyNodeType<T> *pItem = new DoublyNodeType<T>;
		pItem->data = item;
		m_pFirst->next = pItem;
		pItem->prev = m_pFirst;
		pItem->next = m_pLast;
		m_pLast->prev = pItem; // ó���� �� ���̿� ����.
		m_nLength++;
		return 1;
	}
	else // ó���� �ƴ� ��
	{
		while(1)
		{
			if(item < itor.m_pCurPointer->data) // 현재 노드가 크면 현재노드앞에 추가.
			{
				DoublyNodeType<T> *pItem = new DoublyNodeType<T>; // 추가로 저장할 노드
				pItem->data = item; // 새노드에 데이터저장
				pItem->prev = itor.m_pCurPointer->prev; //추가할 노드 전은 현재노드 앞
				pItem->next = itor.m_pCurPointer; // 추가할 노드 후는 현재노드 뒤
				itor.m_pCurPointer->prev->next = pItem; // 앞 노드의 다음은 현재 추가할 노드를 가리킴
				itor.m_pCurPointer->prev = pItem; // 커런노드의 전은 새로추가할 노드 이게 먼솔??
				m_nLength++;
				return 1;
			}
			else if(item == itor.m_pCurPointer->data) // ���� ������ �������� ������
				return 0; // 0�� ��ȯ.
			else
				itor.Next(); // �������� �̵�.
		}
	}
}
*/


// �Է¹��� �������� �����Ϳ��� ã�Ƴ��� �����Ѵ�.
template <typename T>
void DoublySortedLinkedList<T>::Delete(T item)
{
	DoublyIterator<T> itor(*this);
	itor.Begin(); // �������� �̵�.

	while(itor.m_pCurPointer != m_pLast)
	{
		if(itor.m_pCurPointer->data == item) // ��ġ�ϴ� �����͸� ã�´�.
		{
			DoublyNodeType<T> *pItem = new DoublyNodeType<T>;
			pItem = itor.m_pCurPointer;
			itor.Next();
			pItem->prev->next = itor.m_pCurPointer;
			itor.m_pCurPointer->prev = pItem->prev; // �����ϴ� ����� �հ� �ڸ� ���� �̾��ش�.
			delete pItem; // ����.
			return;
		}
		else
			itor.Next();
	}
	m_nLength--; // ���� ����.
	return;
}

// �Է¹��� �������� ������ ��ü�Ѵ�.
template <typename T>
void DoublySortedLinkedList<T>::Replace(T item)
{
	DoublyIterator<T> itor(*this);
	itor.Begin(); // �������� �̵�.
	 
	while(itor.m_pCurPointer != m_pLast)
	{
		if(itor.m_pCurPointer->data == item)
		{
			itor.m_pCurPointer->data = item; // ������ ��ü.
			return;
		}
		else
			itor.Next();
	}

	return;
}

// retrieve와 같음. 아이템타입의 키와 일치하는걸 찾아서 복사한뒤 리턴
template <typename T>
int DoublySortedLinkedList<T>::Get(T &item)
{
	DoublyIterator<T> itor(*this); //스캐닝하고자 하는 리스트를 파라미터를 이터레이터에 전달.
	for (itor.Begin(); itor.NotEnd(); itor.Next()) //이터레이터가 끝에 도달할때까지
	{
		if (*itor.GetCurrentNode() == item) //현재노드와 찾는 노드가 같으면
		{
			item = *itor.GetCurrentNode();
			return 1; // 일치하면 1
		}
	}

	return 0; // 안일치시 0
}
/*
template <typename T>
int DoublySortedLinkedList<T>::Get(T &item)
{
	DoublyIterator<T> itor(*this);
	itor.Begin();

	while (itor.m_pCurPointer != m_pLast)
	{
		if (itor.m_pCurPointer->data == item)
		{
			item = itor.m_pCurPointer->data;
			return 1; // ��ġ�ϸ� 1�� ��ȯ.
		}
		else
			itor.Next(); // �������� �̵�.
	}

	return 0; // ��ġ���� ������ 0�� ��ȯ.
}
*/
#endif _DOUBLYSORTEDLINKEDLIST_H