#include "SimpleProductType.h"
#include "List_Sorted_SingleLink.h"
class subCategoryType{
    public:
    subCategoryType(){}
    ~subCategoryType(){}
    private:
    List_Sorted_SingleLink<SimpleProductType> catelist;
    
}