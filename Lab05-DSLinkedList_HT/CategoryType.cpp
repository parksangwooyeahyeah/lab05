#include "CatergoryType.h"


int CategoryType::AddToCatelist(SimpleProductType item)
{
    item.SetID();
    //doublysorted linked list´Â ÆÄ¶ó¹ÌÅÍ itemÀÇ id°¡ ÄÃÆ÷ÀÎÅÍ ³ëµå µ¥ÀÌÅÍÀÇ idº¸´Ù ÀÛÀ¸¸é »ğÀÔ
    // ÆÄ¶ó¹ÌÅÍÀÇ id°¡ ÄÃÆ÷ÀÎÅÍ µ¥ÀÌÅÍÀÇ id¿Í °°À¸¸é Áßº¹µÆ´Ù´Â °ÍÀÌ¹Ç·Î false ¹İÈ¯
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
    // catelist¿¡ ÀÖ´Â simpleproducttype itemµéÀÇ id¸¦ ¹Ş´Â´Ù.(for¹®¿¡¼­ ³ëµåÀÇ À§Ä¡´Â ¾î¶»°Ô °áÁ¤ÇÏÁö?)
    // itemÀÇ id¸¦ m_list¿¡¼­ Ã£´Â´Ù.
    // m_list.display()
    
    
    SimpleProductType item;
    ItemType data;

    DoublyIterator<SimpleProductType> itor(*this);
	itor.Begin(); // ???????? ???.

	for (itor.Begin(); itor.NotEnd(); itor.Next())
	{
        //catelist?ï¿½ï¿½ ?ï¿½ï¿½?ï¿½ï¿½ idï¿?? ?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½ ?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½.
        
        item = itor.m_pCurPointer->data;
        data.SetId(item.GetID());
        //m_listÀÇ retrieve´Â ÆÄ¶ó¹ÌÅÍ itemtype data¸¦ ¹Ş°í data°¡ list¿¡ ÀÖ´ÂÁö ¾ø´ÂÁö ¸ÕÀú È®Ÿİ´Ù¤¿.
        // ±×¸®°í ÀÖ´Â°Ô È®ÀÎµÇ¸é data¿¡ ¸®½ºÆ®¿¡ ÀÖ´Â Á¤º¸¸¦ º¹»çÇØÁØ´Ù.
        // ±×¸®°í ¸®½ºÆ®ÀÇ º¹»çÇØÁØ À§Ä¡ÀÎµ¦½º¸¦ ¹İÈ¯ÇØÁØ´Ù.
        m_list.Retrieve(data);
        // ï¿?? id??? ?ï¿½ï¿½ì¹˜í•˜?ï¿½ï¿½ m_list idï¿?? ?ï¿½ï¿½ë©´ì— ì¶œë ¥?ï¿½ï¿½?ï¿½ï¿½.
        data.DisplayRecordOnScreen();
    }

}

int CategoryType::FindProductinCate()
{
    //?ï¿½ï¿½?ï¿½ï¿½idï¿?? ?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½.
    SimpleProductType item;
    ItemType data;
    item.SetIDFromKB();

    //?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½ ?ï¿½ï¿½?ï¿½ï¿½idï¿?? catelist?ï¿½ï¿½ ?ï¿½ï¿½?ï¿½ï¿½ ?ï¿½ï¿½?ï¿½ï¿½ id??? ?ï¿½ï¿½ì¹˜í•˜?ï¿½ï¿½ï¿?? ?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½.
    if(cateList.Retrieve(item))
 

    {
        //ë§ˆìŠ¤?ï¿½ï¿½ë¦¬ìŠ¤?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½ idï¿?? ?ï¿½ï¿½ì¹˜í•˜?ï¿½ï¿½ ?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½ ì°¾ëŠ”?ï¿½ï¿½.
        data.SetId(item.GetID());

        //idï¿?? ?ï¿½ï¿½ì¹˜í•˜?ï¿½ï¿½ ?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½ ?ï¿½ï¿½?ï¿½ï¿½ï¿??
        if(m_list.Retrieve(data) != -1)
        {
            // ?ï¿½ï¿½ë³´ï¿½?? ?ï¿½ï¿½ë©´ì— ?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½. 
            data.DisplayRecordOnScreen();
        }

        //idï¿?? ?ï¿½ï¿½ì¹˜í•˜?ï¿½ï¿½ ?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½ ?ï¿½ï¿½?ï¿½ï¿½ï¿?? 
        else
        {
            //?ï¿½ï¿½?ï¿½ï¿½ï¿?? ?ï¿½ï¿½ï¿?? ë©”ì„¸ï¿??ï¿?? ?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½
            cout << "Not Found" << endl;
        }

    }
}