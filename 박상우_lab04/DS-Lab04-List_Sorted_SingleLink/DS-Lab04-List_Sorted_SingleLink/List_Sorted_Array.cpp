#include "List_Sorted_Array.h"

void List_Sorted_Array::MakeEmpty()
{
    m_Length = 0;
    ResetList();
}


bool List_Sorted_Array::Add(ItemType data)
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
	int iPos=0;
	bool found = false;
	while (!found && iPos< m_Length) {
		if (data > m_Array[iPos]) // >
			iPos++;
		else // <=
			found = true;
	}
	// �ߺ�Ű�� ��� ���� �޽��� ���
	if (data==m_Array[iPos])  { 
		cout << "\n Same primary key exists in list\n";
		return false;
	}
	/* �߰��̳� �� ���� ����: ������ ������ Ȯ���ϱ� 
	���Ͽ� iPos���� m_Length-1������ ��� �׸��� ��� �̵�
	iPos==m_Length�� ���� �̵����� ����*/
	for (int i = m_Length; i > iPos; i--)  
		m_Array[i] = m_Array[i - 1];
	// iPos�� �����ϰ� length ����.
	m_Array[iPos] = data; 
    m_Length++;
    return true;
}


void List_Sorted_Array::ResetList()
{
    m_CurPointer = -1;
}


int List_Sorted_Array::GetNextItem(ItemType& data)
{
    m_CurPointer++;
    if (m_CurPointer == MAXSIZE) 
        return -1;
	
    data = m_Array[m_CurPointer];

    return m_CurPointer;
}


int List_Sorted_Array::IsExist(ItemType data) {
	int CurPos=0;
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


int List_Sorted_Array::Retrieve(ItemType& data)
{
	int index = IsExist(data);
	if (index != -1) data = m_Array[index];
	return index;
}


bool List_Sorted_Array::Delete(ItemType& data)
{
    int index = IsExist(data); // Try to get data, invalid : -1
	if (index == -1) return false;
    // overwrite the current record
	for (int i = index; i < m_Length-1; i++)   // shift right to make the space to insert
		m_Array[i] = m_Array[i+1];
	m_Length--;
    return true;
}


bool List_Sorted_Array::Replace(ItemType data)
{
	int index = IsExist(data);
	if (index == -1) return false;
	m_Array[index] = data;
    return true;
}