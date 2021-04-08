#include "CatergoryType.h"


int CategoryType::AddToCatelist(SimpleProductType item)
{
    item.SetID();
    int index = catelist.Retrieve(item);
    if (index = -1)
    {
        cout << "���� �������� �̹� �����մϴ�" << endl;
        return false;
    }

    else
    {
        cateList.Add(item);
        return true;
    }
}

void CategoryType::DisplayCatelist()
{
    // catelist ?��?�� ?��?��?��?��까�?? 반복?��?��.
    int length = cateList.GetLength();
    SimpleProductType item;
    
    for(int Curpointer = 0; Curpointer < length ; Curpointer++)
    {
        //catelist?�� ?��?�� id�? ?��?��?�� ?��?��?��.
        
        cateList.GetNextItem(item);
        
        // �? id??? ?��치하?�� m_list id�? ?��면에 출력?��?��.
        ItemType data;
        data.SetId(item.GetID());
        m_list.IsExist(data);
        data.DisplayRecordOnScreen();
        
        
    }

}

int CategoryType::FindProductinCate()
{
    //?��?��id�? ?��?��?��?��.
    SimpleProductType item;
    ItemType data;
    item.SetIDFromKB();

    //?��?��?�� ?��?��id�? catelist?�� ?��?�� ?��?�� id??? ?��치하?���? ?��?��?��?��.
    if(cateList.Retrieve(item))
 

    {
        //마스?��리스?��?��?�� id�? ?��치하?�� ?��?��?�� 찾는?��.
        data.SetId(item.GetID());

        //id�? ?��치하?�� ?��?��?�� ?��?���?
        if(m_list.Retrieve(data) != -1)
        {
            // ?��보�?? ?��면에 ?��?��?��. 
            data.DisplayRecordOnScreen();
        }

        //id�? ?��치하?�� ?��?��?�� ?��?���? 
        else
        {
            //?��?���? ?���? 메세�?�? ?��?��?��
            cout << "Not Found" << endl;
        }

    }
}