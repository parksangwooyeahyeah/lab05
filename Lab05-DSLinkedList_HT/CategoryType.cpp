#include "CatergoryType.h"


int CategoryType::AddToCatelist(SimpleProductType item)
{
    item.SetID();
    //doublysorted linked list�� �Ķ���� item�� id�� �������� ��� �������� id���� ������ ����
    // �Ķ������ id�� �������� �������� id�� ������ �ߺ��ƴٴ� ���̹Ƿ� false ��ȯ
    if(cateList.IsFull())
    {
        cout << "your catergory is full" << endl;
        return false;
    }

    else
    {
        cateList.Add(item);
        cout << "i've added to your doubly linked category" << endl;
        return true;
    }
}


void CategoryType::DisplayCatelist()
{   
    // catelist�� �ִ� simpleproducttype item���� id�� �޴´�.(for������ ����� ��ġ�� ��� ��������?)
    // item�� id�� m_list���� ã�´�.
    // m_list.display()
    
    
    SimpleProductType item;
    ItemType data;

    DoublyIterator<SimpleProductType> itor(*this);
	itor.Begin(); // ???????? ???.

	for (itor.Begin(); itor.NotEnd(); itor.Next())
	{
        //catelist?�� ?��?�� id�?? ?��?��?�� ?��?��?��.
        
        item = itor.m_pCurPointer->data;
        data.SetId(item.GetID());
        //m_list�� retrieve�� �Ķ���� itemtype data�� �ް� data�� list�� �ִ��� ������ ���� Ȯ�ݴ٤�.
        // �׸��� �ִ°� Ȯ�εǸ� data�� ����Ʈ�� �ִ� ������ �������ش�.
        // �׸��� ����Ʈ�� �������� ��ġ�ε����� ��ȯ���ش�.
        m_list.Retrieve(data);
        // �?? id??? ?��치하?�� m_list id�?? ?��면에 출력?��?��.
        data.DisplayRecordOnScreen();
    }

}

int CategoryType::FindProductinCate()
{
    //?��?��id�?? ?��?��?��?��.
    SimpleProductType item;
    ItemType data;
    item.SetIDFromKB();

    //?��?��?�� ?��?��id�?? catelist?�� ?��?�� ?��?�� id??? ?��치하?���?? ?��?��?��?��.
    if(cateList.Retrieve(item))
 

    {
        //마스?��리스?��?��?�� id�?? ?��치하?�� ?��?��?�� 찾는?��.
        data.SetId(item.GetID());

        //id�?? ?��치하?�� ?��?��?�� ?��?���??
        if(m_list.Retrieve(data) != -1)
        {
            // ?��보�?? ?��면에 ?��?��?��. 
            data.DisplayRecordOnScreen();
        }

        //id�?? ?��치하?�� ?��?��?�� ?��?���?? 
        else
        {
            //?��?���?? ?���?? 메세�??�?? ?��?��?��
            cout << "Not Found" << endl;
        }

    }
}