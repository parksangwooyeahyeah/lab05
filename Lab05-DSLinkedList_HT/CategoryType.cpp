// #include "CatergoryType.h"


// int CategoryType::AddToCatelist(SimpleProductType item)
// {
//     item.SetIDFromKB();
//     //doublysorted linked list�� �Ķ���� item�� id�� �������� ��� �������� id���� ������ ����
//     // �Ķ������ id�� �������� �������� id�� ������ �ߺ��ƴٴ� ���̹Ƿ� false ��ȯ
//     if(cateList.IsFull())
//     {
//         cout << "your catergory is full" << endl;
//         return false;
//     }

//     else
//     {
//         cateList.Add(item);
//         cout << "i've added to your doubly linked category" << endl;
//         return true;
//     }
// }


// void CategoryType::DisplayCatelist()
// {   
//     // catelist�� �ִ� simpleproducttype item���� id�� �޴´�.(for������ ����� ��ġ�� ��� ��������?)
//     // item�� id�� m_list���� ã�´�.
//     // m_list.display()
    
    
//     SimpleProductType item;
//     ItemType data;

//     DoublyIterator<SimpleProductType> itor(*this);
// 	itor.Begin(); // ???????? ???.

// 	for (itor.Begin(); itor.NotEnd(); itor.Next())
// 	{
//         //catelist?�� ?��?�� id�?? ?��?��?�� ?��?��?��.
        
//         item = itor.m_pCurPointer->data;
//         data.SetId(item.GetID());
//         //m_list�� retrieve�� �Ķ���� itemtype data�� �ް� data�� list�� �ִ��� ������ ���� Ȯ�ݴ٤�.
//         // �׸��� �ִ°� Ȯ�εǸ� data�� ����Ʈ�� �ִ� ������ �������ش�.
//         // �׸��� ����Ʈ�� �������� ��ġ�ε����� ��ȯ���ش�.
//         m_list.Retrieve(data);
//         // �?? id??? ?��치하?�� m_list id�?? ?��면에 출력?��?��.
//         data.DisplayRecordOnScreen();
//     }

// }

// int CategoryType::FindProductinCate(SimpleProductType item)
// {
//     //ī�װ����� ��ǰ�� �˻��Ѵ�
//     //��ǰ�� ������ id�� �ް� m_list���� ������ �����ͼ� ��¤�����.
    
//     ItemType data;

//     //get�Լ��� ����ũ����Ʈ�� ó������ ������ ��ĵ���� ������� item����� id�� ��ġ�ϸ� �������ش�. �׸��� ����1
//     if(cateList.Get(item))
//     {
        
//         data.SetId(item.GetID());
//         //id�?? ?��치하?�� ?��?��?�� ?��?���??
//         m_list.Retrieve(data);
//         data.DisplayRecordOnScreen();
//         return 1;
//     }

//     else
//     {
//         cout << "Not found" << endl;
//         return 0;
//     }
// }