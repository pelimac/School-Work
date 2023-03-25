/* Brandon McFarlane
CISC 2200
*/
//adds methods to search and to remove an item with a specified key value
//linkList2.cpp
//demonstrates linked list
#include <iostream>

using namespace std;
////////////////////////////////////////////////////////////////
class Link {
  public:
    int iData; //data item (key)
  Link * pNext; //next link in list
  //-------------------------------------------------------------
  Link(int id): //constructor
    iData(id), pNext(NULL) {}
  //-------------------------------------------------------------
  void displayLink() //display ourself: {22, 2.99}
  {
    cout << "{" << iData << "} ";
  }
}; //end class Link
////////////////////////////////////////////////////////////////
class LinkList {
  private:
    Link * pFirst; //ptr to first link on list
  public:
    //-------------------------------------------------------------
    LinkList(): pFirst(NULL) //constructor
  {} //(no links on list yet)
  //-------------------------------------------------------------
  ~LinkList() //destructor (deletes links)
  {
    Link * pCurrent = pFirst; //start at beginning of list
    while (pCurrent != NULL) //until end of list,
    {
      Link * pOldCur = pCurrent; //save current link
      pCurrent = pCurrent -> pNext; //move to next link
      delete pOldCur; //delete old current
    }
  }
  //-------------------------------------------------------------
  void insertFirst(int id) { //make new link
    Link * pNewLink = new Link(id);
    pNewLink -> pNext = pFirst; //it points to old first link
    pFirst = pNewLink; //now first points to this
  }
  //-------------------------------------------------------------
  Link * find(int key) //find link with given key
  { //(assumes non-empty list)

    Link * pCurrent = pFirst; //start at ‘first'

    while (pCurrent -> iData != key) //while no match,
    {

      if (pCurrent -> pNext == NULL) //if end of list,
        return NULL; //didn't find it
      else //not end of list,
        pCurrent = pCurrent -> pNext; //go to next link
    }
    return pCurrent; //found it

  }
  //-------------------------------------------------------------
  bool remove(int key) //remove link with given key
  { //(assumes non-empty list)

    Link * pCurrent = pFirst; //search for link

    Link * pPrevious = pFirst;

    while (pCurrent -> iData != key) {

      if (pCurrent -> pNext == NULL)
        return false; //didn't find it
      else {

        pPrevious = pCurrent; //go to next link

        pCurrent = pCurrent -> pNext;

      }
    } //found it
    if (pCurrent == pFirst) //if first link,
      pFirst = pFirst -> pNext; //change first
    else //otherwise,
      pPrevious -> pNext = pCurrent -> pNext; //bypass it
    delete pCurrent; //delete link

    return true; //successful removal

  }
  //-------------------------------------------------------------
  void displayList() //display the list
  {

    cout << "List (first-->last): ";

    Link * pCurrent = pFirst; //start at beginning of list

    while (pCurrent != NULL) //until end of list,
    {

      pCurrent -> displayLink(); //print data

      pCurrent = pCurrent -> pNext; //move to next link

    }
    cout << endl;

  }
  //-------------------------------------------------------------

bool removeLast(int key) //remove last link
{ 
    if (pFirst == NULL) //if list is empty
        return false;

    Link *pCurrent = pFirst;
    Link *pPrevious = NULL;

    while (pCurrent->pNext != NULL) //find the last link
    { 
        pPrevious = pCurrent;
        pCurrent = pCurrent->pNext;
    }

    if (pPrevious == NULL) //if there was only one link in the list
        pFirst = NULL; //set first to null
    else
        pPrevious->pNext = NULL; //set the previous link's next to null

    delete pCurrent; //delete the last link
    return true;
}

  //-------------------------------------------------------------
void removeAll(int n) //remove all links with a given key
{
    Link *pCurrent = pFirst;
    Link *pPrevious = NULL;

    while (pCurrent != NULL) 
    {
        if (pCurrent->iData == n) 
        {
            if (pPrevious == NULL)
                pFirst = pCurrent->pNext;
            else
                pPrevious->pNext = pCurrent->pNext;

            Link *pOldCurrent = pCurrent;
            pCurrent = pCurrent->pNext;
            delete pOldCurrent;
        } else 
        {
            pPrevious = pCurrent;
            pCurrent = pCurrent->pNext;
        }
    }
}

  
}; //end class LinkList
////////////////////////////////////////////////////////////////
int main() {
 LinkList lst1; //make list
  lst1.insertFirst(2);
  lst1.insertFirst(7);
  lst1.insertFirst(3);
  lst1.insertFirst(7);
  lst1.insertFirst(4);
  lst1.insertFirst(7);
  lst1.insertFirst(3);
  lst1.insertFirst(1);

 lst1.removeLast(7);
 lst1.displayList();
 lst1.removeAll(7);
 lst1.displayList();
 return 0;
}