#include "DoublySortedLinkedList.h"
#include "List_Sorted_Array.h"
#include "SimpleProductType.h"
#include "List_Sorted_SingleLink.h"

class CategoryType
{
public:
    CategoryType()
    {
        List_Sorted_Array<string> **cateList = new List_Sorted_Array<SimpleProductType> *subcatecory;
        List_Sorted_Array<SimpleProductType> *subcatecory = new List_Sorted_Array<SimpleProductType> subsubcategory;

    }
    ~CategoryType(){}

    int AddToCatelist(SimpleProductType item);
    void DisplayCatelist();
    int FindProductinCate(SimpleProductType item);

private:
    int itemNum;
    List_Sorted_Array<string> category;
    List_Sorted_Array<string> subcatecory;
    List_Sorted_Array<string> subsubcategory;
    DoublySortedLinkedList<SimpleProductType> catelist;
    List_Sorted_Array<ItemType> m_list; //마스터리스트는 이미 애플리케이션에서 존재하는걸 가져와야하는데 어떻게 가져오지?
};