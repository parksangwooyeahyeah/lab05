#pragma once
#ifndef _DOUBLYITERATOR_H
#define _DOUBLYITERATOR_H

#include "DoublySortedLinkedList.h"

template<typename T>
struct DoublyNodeType;
template<typename T>
class DoublySortedLinkedList;

/**
*	���Ḯ��Ʈ���� ���̴� Iterator�� Ŭ����.
*/
template <typename T>
class DoublyIterator
{
	friend class DoublySortedLinkedList<T>;
public:
	DoublyIterator(const DoublySortedLinkedList<T> &list) : m_List(list), m_pCurPointer(list.m_pFirst) // 엠피퍼스트는 헤더
	{};
	// set the current pointer to the first node 헤드다음. 헤드와 트레일러에는 데이터 저장안됨
	void Begin() {
		m_pCurPointer = m_List.m_pFirst->next;
	}
	// move current pointer to next
	void Next() {
		m_pCurPointer = m_pCurPointer->next;
	}
	// current node�� data �����͸� ����
	T* GetCurrentNode() {
		return &m_pCurPointer->data;
	}
	// not end?
	bool NotEnd() {
		if (m_pCurPointer->next == NULL)
			return false;
		else
			return true;
	}

private:
	const DoublySortedLinkedList<T> &m_List;
	DoublyNodeType<T>* m_pCurPointer;
};


#endif _DOUBLYITERATOR_H