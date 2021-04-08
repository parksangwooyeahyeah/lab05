#include <iostream>
#include <string>
using namespace std;

class SimpleProductType
{
public:
    SimpleProductType()
    {
        name = "";
        ID = 0;
    }
    ~SimpleProductType(){}

    void SetIDFromKB()
    {
        cout << "상품 ID를 입력하세요." << endl;
        cin >> ID;
    }

    void SetNameFromKB()
    {
        cout << "상품 이름을 입력하세요. " << endl;
        cin >> name;
    }

    int GetID()
    {
        return ID;
    }

    string GetName()
    {
        return name;
    }
    
    void operator=(const SimpleProductType target)
    {
        name = target.name;
        ID = target.ID;
    }
private:
    string name;
    int ID;
};