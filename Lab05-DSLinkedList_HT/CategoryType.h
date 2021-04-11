#include "DoublySortedLinkedList.h"
#include "List_Sorted_Array.h"
#include "SimpleProductType.h"
#include "List_Sorted_SingleLink.h"
#include "Application.h"


#define MaxSize 5


class CategoryType
{
public:
    CategoryType()
    {
      itemNum = 0;
    }
    ~CategoryType(){}

    int AddToCatelist(SimpleProductType item);
    void DisplayCatelist();

    // int FindProductinCate();

private:
    int itemNum;
    DoublySortedLinkedList<CategoryType> subcategory;
};



int CategoryType::AddToCatelist(SimpleProductType item)
{ 
    
}

