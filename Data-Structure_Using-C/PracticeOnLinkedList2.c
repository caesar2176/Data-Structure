#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

typedef struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node **PPNODE;

/*
Allocate memory for node
Iniotialise that node
Check whether linked list is empty or not
Insert the node accordingly
*/

void InsertFirst(PPNODE Head, int value)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    
    newn->data = value;
    newn->next = NULL;
    
    if(*Head == NULL)   // If linked list is empty
    {
        *Head = newn;
    }
    else        // If linked list contains atleast one node
    {
        newn->next = *Head;
        *Head = newn;
    }
}

void Display(PNODE Head)
{
    printf("\n");
    while(Head != NULL)
    {
        printf("| %d | -> ",Head->data);
        Head = Head -> next;
    }
    printf("NULL\n");
}

int Count(PNODE Head)
{
    int iCnt = 0;
    
    while(Head != NULL)
    {
        iCnt++;
        Head = Head->next;
    }
    
    return iCnt;
}

void InsertLast(PPNODE Head, int value)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    
    newn = (PNODE)malloc(sizeof(NODE));
    
    newn->data = value;
    newn->next = NULL;
    
    if(*Head == NULL)   // Empty linked list
    {
        *Head = newn;
    }
    else        // Linked list contains atleadst one node
    {
        // travel till the last node
        temp = *Head;       // Store the address of first node
        
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        
        temp->next = newn;
    }
    
}

/*if(*Head == NULL){}
  else{}*/
void DeleteFirst(PPNODE Head)
{
    PNODE temp  = *Head;
    
    if(*Head != NULL)
    {
        *Head = (*Head) -> next;
        free(temp);
    }
}

void DeleteLast(PPNODE Head)
{
    PNODE temp = *Head;
    
    if(*Head == NULL)   // If linked list is empty
    {
        return;
    }
    else if((*Head) -> next == NULL)    // If linked list contains single node
    {
        free(*Head);
        *Head = NULL;
    }
    else    // If linked list contains more that one node
    {
            while(temp->next->next != NULL)
            {
                temp = temp->next;
            }
        
            free(temp->next);
            temp->next = NULL;
    }
}
/*
    Invalid position                                Just return
    First position                                    Call InsertFirst
    Last position                                    call InsertLast
    Position in between first and last        Write separate logic
 */
void InsertAtPos(PPNODE Head, int value, int pos)
{
    int size = 0, i = 0;
    PNODE temp = *Head;
    PNODE newn = NULL;
    
    size = Count(*Head);
    
    if((pos < 1) || (pos > (size + 1)))       // Invalid Position
    {
        return;
    }
    else if(pos == 1)        // First position
    {
        InsertFirst(Head, value);
    }
    else if(pos == size + 1)    // Last position
    {
        InsertLast(Head, value);
    }
    else
    {
        newn= (PNODE)malloc(sizeof(NODE));
        newn->data = value;
        
        for(i = 1; i< pos-1; i++)
        {
            temp = temp->next;
        }
        
        newn->next = temp->next;
        temp->next = newn;
    }
}

void DeleteAtPos(PPNODE Head, int pos)
{
    int size = 0,i = 0;
    size = Count(*Head);
    PNODE temp, temp2;
    if((pos < 1) || (pos > size))
    {
        return;
    }
    if(pos == 1)
    {
        DeleteFirst(Head);
    }
    else if(pos == size)
    {
        DeleteLast(Head);
    }
    else
    {
        temp = *Head;
        for(i = 1; i< pos-1; i++)
        {
            temp = temp->next;
        }
        temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
    }
}



int main()
{
    PNODE First = NULL;     
    int no = 0, iRet = 0;
    
    printf("Enter number : \n");            //51
    scanf("%d",&no);
    InsertFirst(&First, no);
    
    printf("Enter number : \n");            //21
    scanf("%d",&no);
    InsertFirst(&First, no);
    
    printf("Enter number : \n");            //11
    scanf("%d",&no);
    InsertFirst(&First, no);
    
    Display(First);                             //  11  21  51
    
    iRet = Count(First);                        //  3
    printf("Number of nodes in the linkedlist are : %d\n",iRet);                //  3
    
    printf("Enter Number To Add In Last Position : \n");
    scanf("%d",&no);
    InsertLast(&First, no);
    
    printf("Enter Number To Add In Last Position : \n");
    scanf("%d",&no);
    InsertLast(&First, no);

    Display(First);
    
    DeleteFirst(&First);        //11 Deleted
    
    Display(First);         //  21  51  101 111   
    
    iRet = Count(First);
    printf("Number of nodes in the linkedlist are : %d\n",iRet);            //4
    
    Display(First);      //  21  51  101 111  
    
    
    DeleteLast(&First);     //111 Deleted
    
    Display(First);         // 21  51  101
    
    iRet = Count(First);
    printf("Number of nodes in the linkedlist are : %d\n",iRet);

    printf("Enter number : \n");        //121
    scanf("%d",&no);
    InsertAtPos(&First,no,3);
    Display(First);
    
    DeleteAtPos(&First,2);
    Display(First);

    return 0;
}

