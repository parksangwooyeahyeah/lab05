#include "DoublySortedLinkedList.h"
#include "List_Sorted_Array.h"
#include "SimpleProductType.h"
#include "List_Sorted_SingleLink.h"
#include "subcategorytype.h"

#define MaxSize 5

class CategoryType
{
public:
    CategoryType(const DoublySortedLinkedList<CategoryType> &category) : m_category(category)
    {
      category = new doubly
    }
    ~CategoryType(){}

    int AddToCatelist(SimpleProductType item);
    void DisplayCatelist();
    int FindProductinCate(SimpleProductType item);

private:
    int itemNum;
    DoublySortedLinkedList<subCategoryType> subCategory;
    DoublySortedLinkedList<CategoryType>& m_category;
};