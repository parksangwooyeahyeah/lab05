#pragma once
#ifndef _DOUBLYITERATOR_H
#define _DOUBLYITERATOR_H

#include "DoublySortedLinkedList.h"

template<typename T>
struct DoublyNodeType;
template<typename T>
class DoublySortedLinkedList;

/**
*	연결리스트에서 쓰이는 Iterator의 클래스.
*/
template <typename T>
class DoublyIterator
{
	friend class DoublySortedLinkedList<T>;
public:
	DoublyIterator(const DoublySortedLinkedList<T> &list) : m_List(list), m_pCurPointer(list.m_pFirst)
	{};
	// set the current pointer to the first node
	void Begin() {
		m_pCurPointer = m_List.m_pFirst->next;
	}
	// move current pointer to next
	void Next() {
		m_pCurPointer = m_pCurPointer->next;
	}
	// current node의 data 포인터를 리턴
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