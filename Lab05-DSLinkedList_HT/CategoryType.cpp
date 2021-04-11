// #include "CatergoryType.h"


// int CategoryType::AddToCatelist(SimpleProductType item)
// {
//     item.SetIDFromKB();
//     //doublysorted linked list는 파라미터 item의 id가 컬포인터 노드 데이터의 id보다 작으면 삽입
//     // 파라미터의 id가 컬포인터 데이터의 id와 같으면 중복됐다는 것이므로 false 반환
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
//     // catelist에 있는 simpleproducttype item들의 id를 받는다.(for문에서 노드의 위치는 어떻게 결정하지?)
//     // item의 id를 m_list에서 찾는다.
//     // m_list.display()
    
    
//     SimpleProductType item;
//     ItemType data;

//     DoublyIterator<SimpleProductType> itor(*this);
// 	itor.Begin(); // ???????? ???.

// 	for (itor.Begin(); itor.NotEnd(); itor.Next())
// 	{
//         //catelist?占쏙옙 ?占쏙옙?占쏙옙 id占?? ?占쏙옙?占쏙옙?占쏙옙 ?占쏙옙?占쏙옙?占쏙옙.
        
//         item = itor.m_pCurPointer->data;
//         data.SetId(item.GetID());
//         //m_list의 retrieve는 파라미터 itemtype data를 받고 data가 list에 있는지 없는지 먼저 확읺다ㅏ.
//         // 그리고 있는게 확인되면 data에 리스트에 있는 정보를 복사해준다.
//         // 그리고 리스트의 복사해준 위치인덱스를 반환해준다.
//         m_list.Retrieve(data);
//         // 占?? id??? ?占쏙옙移섑븯?占쏙옙 m_list id占?? ?占쏙옙硫댁뿉 異쒕젰?占쏙옙?占쏙옙.
//         data.DisplayRecordOnScreen();
//     }

// }

// int CategoryType::FindProductinCate(SimpleProductType item)
// {
//     //카테고리에서 상품을 검색한다
//     //상품이 있으면 id를 받고 m_list에서 정보를 가져와서 출력ㅎ나다.
    
//     ItemType data;

//     //get함수는 더블링크리스트를 처음부터 끝까지 스캔떠서 현재노드와 item노드의 id가 일치하면 복사해준다. 그리고 리턴1
//     if(cateList.Get(item))
//     {
        
//         data.SetId(item.GetID());
//         //id占?? ?占쏙옙移섑븯?占쏙옙 ?占쏙옙?占쏙옙?占쏙옙 ?占쏙옙?占쏙옙占??
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