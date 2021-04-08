#include "DoublySortedLinkedList.h"
#include "List_Sorted_Array.h"
#include "SimpleProductType.h"

class CategoryType
{
public:
    CategoryType(){}
    ~CategoryType(){}

    int AddToCatelist(SimpleProductType item);
    void DisplayCatelist();
    int FindProductinCate(SimpleProductType item);

private:
    int itemNum;
    DoublySortedLinkedList<SimpleProductType> cateList;
    List_Sorted_Array<ItemType> m_list; //마스터리스트는 이미 애플리케이션에서 존재하는걸 가져와야하는데 어떻게 가져오지?
};