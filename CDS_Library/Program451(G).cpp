// Project : Generic Library 
// Auther name : Devang Bhalerao
// Date : 03-07-2024

#include<iostream>
using namespace std;

//////////////////////////////////////////
//         Code of Singly Linear                 
//////////////////////////////////////////

template <class T>
struct nodeSL
{
    T data;
    struct nodeSL *next;
};

template <class T>
class SinglyLL
{
    private:
        struct nodeSL<T>* First;
        int iCount;

    public:
        SinglyLL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

};

template <class T>
SinglyLL<T>::SinglyLL()
{
    cout<<"Inside Counstructor\n";
    First = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL<T>::Display()
{
    struct nodeSL<T>* temp = First;

    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp= temp->next;
    }
    cout<<"NULL\n";
}

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T>::InsertFirst(T No)
{
    struct nodeSL<T>* newn = NULL;

    newn = new  struct nodeSL<T>;  // Malloc

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;

    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertLast(T No)
{
    struct nodeSL<T>* newn = NULL;
    struct nodeSL<T>* temp = First;

    newn = new struct nodeSL<T>;  // Malloc

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeSL<T>* newn = NULL;
    int i = 0;
    struct nodeSL<T>* temp;

    if((iPos<1) || (iPos>iCount+1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        temp = First;

        newn = new struct nodeSL<T>;
        newn->data = No;
        newn->next = NULL;

        for(i=1; i<iPos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    struct nodeSL<T>* temp = First;

    if(First == NULL)
    {
        cout<<"LL is Empty\n";
        First = NULL;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First->next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    struct nodeSL<T>* temp = First;

    if(First == NULL)
    {
        cout<<"LL is Empty\n";
        First = NULL;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    int i = 0;
    struct nodeSL<T>* temp1;
    struct nodeSL<T>* temp2;

    if((iPos<1) || (iPos>iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;

        for(i=1; i<iPos-1; i++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;

        temp1->next = temp2->next;
        delete temp2;

        iCount--;
    }
}


/////////////////////////////////////////////////
//            Code of Doubly Circular               
/////////////////////////////////////////////////

template <class T>
struct nodeDC
{
    T data;
    struct nodeDC *next;
    struct nodeDC *prev;
};

template <class T>
class DoublyCL
{
    private:
           struct nodeDC<T>* First;
           struct nodeDC<T>* Last;
           int iCount;
    public :
           DoublyCL();

           void Display();
           T Count();

           void InsertFirst(T no);
           void InsertLast(T no);
           void InsertAtPos(T no, int iPos);

           void DeleteFirst();
           void DeleteLast();
           void DeleteAtPos(int iPos);
};
template <class T>
DoublyCL<T>::DoublyCL()
{
    cout<<"Inside Counstructor\n";
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void DoublyCL<T>::Display()
{
    if(First==NULL && Last==NULL)
    {
        cout<<"LL is Empty \n";
        return;
    }
    cout<<"<=>";
    do
    {
        cout<<"| "<<First->data<<" |"<<"<=>";
        First = First->next;
    }while(First != Last->next);

    First = Last->next;
    cout<<"\n";
}

template <class T>
T DoublyCL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyCL<T>::InsertFirst(T No)
{
    struct nodeDC<T>* newn = NULL;
    newn = new struct nodeDC<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(First==NULL && Last==NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    Last->next = First;
    First->prev = Last;

    iCount++;

}

template <class T>
void DoublyCL<T>::InsertLast(T No)
{
    struct nodeDC<T>* newn = NULL;
    newn = new struct nodeDC<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(First==NULL && Last==NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last->next = newn;
        newn->prev = Last;
        Last = newn;
    }
    Last->next = First;
    First->prev = Last;

    iCount++; 
}

template <class T>
void DoublyCL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeDC<T>* newn = NULL;
    struct nodeDC<T>*temp = NULL;
    int i = 0;

    if((iPos<1) || (iPos>iCount+1))
    {
        cout<<"Invalid Position \n";
        return;
    }
    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        temp = First;

        newn = new struct nodeDC<T>;
        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        for(i=1; i<iPos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        newn->prev = temp;

        temp->next->prev = newn;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if(First==NULL && Last==NULL)
    {
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First->next;
        delete (First->prev);
        Last->next = First;
        First->prev = Last;
    }
    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if(First==NULL && Last==NULL)
    {
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        Last = Last->prev;
        delete First->prev;

        Last->next = First;
        First->prev = Last;
    }
    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    struct nodeDC<T>* temp = NULL;
    int i = 0;

    if((iPos<1) || (iPos>iCount))
    {
        cout<<"Invalid Position \n";
        return;
    }
    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = First;

        for(i=1; i<iPos-1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}


/////////////////////////////////////////////////
//       Code of Singly Circular               //
/////////////////////////////////////////////////



template <class T>
struct nodeSC
{
    T data;
    struct nodeSC *next;
};

template <class T>
class SinglyCL
{
    private :
           struct nodeSC<T>* First;
           struct nodeSC<T>* Last;
           int iCount;
    public :
           SinglyCL();

           void Display();
           T Count();

           void InsertFirst(T no);
           void InsertLast(T no);
           void InsertAtPos(T no, int iPos);

           void DeleteFirst();
           void DeleteLast();
           void DeleteAtPos(int iPos);

};

template <class T>
SinglyCL<T>::SinglyCL()
{
    cout<<"Inside Counstructor\n";
    First = NULL;
    Last  = NULL;
    iCount = 0;
}

template <class T>
void SinglyCL<T>::Display()
{
    struct nodeSC<T>* temp = First;
    if((First == NULL) && (Last == NULL)) 
    {
        cout<<"LL is Empty \n";
        return;
    }
    do
    {
        cout<<"| "<<temp->data<<" | ->";
        temp = temp->next;
    }while(temp != Last->next);

    cout<<"\n";
}

template <class T>
T SinglyCL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyCL<T>::InsertFirst(T no)
{
    struct nodeSC<T>* newn = NULL;

    newn = new struct nodeSC<T>;  // Malloc

    newn->data = no;
    newn->next = NULL;

    if(First == NULL && Last == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    Last->next = First;
    iCount++;
}

template <class T>
void SinglyCL<T>::InsertLast(T no)
{
    struct nodeSC<T>* newn = NULL;

    newn = new struct nodeSC<T>;  // Malloc

    newn->data = no;
    newn->next = NULL;

    if(First == NULL && Last == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last->next = newn;
        Last = newn;
    }
    Last->next = First;
    iCount++;
}

template <class T>
void SinglyCL<T>::InsertAtPos(T no, int iPos)
{
    struct nodeSC<T>* newn = NULL;
    struct nodeSC<T>* temp = NULL;
    int i = 0;
    
    if((iPos<1) || (iPos>iCount+1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        temp = First;

        newn = new struct nodeSC<T>;
        newn->next = NULL;
        newn->data = no;

        for(i=1; i<iPos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void SinglyCL<T>::DeleteFirst()
{
    if(First == NULL && Last == NULL)
    {
        printf("LL is Aleady Empty");
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First->next;
        delete (Last->next);
        Last->next = First;
    }
    iCount--;
}

template <class T>
void SinglyCL<T>::DeleteLast()
{
    struct nodeSC<T>* temp = NULL;

    if(First == NULL && Last == NULL)
    {
        printf("LL is Aleady Empty");
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        temp = First;
        while(temp->next != Last)
        {
            temp = temp->next;
        }
        Last = temp;
        delete (temp->next);
        temp->next = First;
    }
    iCount--;
}

template <class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{
    struct nodeSC<T>* temp1 = NULL;
    struct nodeSC<T>* temp2 = NULL;
    int i = 0;
    
    if((iPos<1) || (iPos>iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;

        for(i=1; i<iPos-1; i++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;

        iCount--;
    }
}


/////////////////////////////////////////////////
//       Code of Doubly Linear                 //
/////////////////////////////////////////////////


template <class T>
struct nodeDL
{
    T data;
    struct nodeDL *next;
    struct nodeDL *prev;
};

template <class T>
class DoublyLL
{
    private:
           struct nodeDL<T>* First;
           int iCount;
    public:
        DoublyLL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);   
};

template <class T>
DoublyLL<T>::DoublyLL()
{
    cout<<"Inside Counstructor\n";
    First = NULL;
    iCount = 0;   
}

template <class T>
void DoublyLL<T>::Display()
{
    struct nodeDL<T>* temp = First;

    cout<<"NULL";
    while(temp != NULL)
    {
        cout<<" <=> "<<temp->data;
        temp = temp->next;
    }
    cout<<" <=> NULL";
}

template <class T>
int DoublyLL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyLL<T>::InsertFirst(T No)
{
    struct nodeDL<T>* newn = NULL;

    newn = new struct nodeDL<T>;  

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>::InsertLast(T No)
{
    struct nodeDL<T>* newn = NULL;
    struct nodeDL<T>* temp = First;

    newn = new struct nodeDL<T>;  

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        newn->prev = temp;
        temp->next = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    struct nodeDL<T>* temp = First;

    if(First == NULL)
    {
        cout<<"LL is Empty\n";
        First = NULL;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        temp = First;
        First = First->next;
        delete temp;
        First->prev = NULL;
    }
    iCount--; 
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
    struct nodeDL<T>* temp = First;

    if(First == NULL)
    {
        cout<<"LL is Empty\n";
        First = NULL;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete(temp->next);
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeDL<T>* newn = NULL;
    struct nodeDL<T>* temp = First;
    int i = 0;

    if((iPos<1) || (iPos>iCount+1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        newn = new struct nodeDL<T>;
        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        for(i=1; i<iPos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    struct nodeDL<T>* temp = First;
    int i = 0;

    if((iPos<1) || (iPos>iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        for(i=1; i<iPos-1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}



/////////////////////////////////////////////////
//       Code of Stack                         
/////////////////////////////////////////////////


template<class T>
struct nodeS
{
    T data;
    struct nodeS *next;
};

template<class T>
class Stack
{
    private:
        struct nodeS<T>* First;
        int iCount;

    public:
        Stack();

        void Display();
        int Count();

        void Push(T No);   // InsertFirst()
        T Pop();         // DeleteFirst()
};

template<class T>
Stack<T>:: Stack()
{
    First = NULL;
    iCount = 0;
}

template<class T>
void Stack<T>::Display()
{
    cout<<"Elements of stack are : \n";
    struct nodeS<T>* temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |"<<"\n";
        temp = temp -> next;
    }
    cout<<"\n";
}

template<class T>
int Stack<T>::Count()
{
    return iCount;
}

template<class T>
void Stack<T>::Push(T No)
{
    struct nodeS<T>* newn = NULL;

    newn = new struct nodeS<T>;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

template<class T>
T Stack<T>::Pop()
{
    T iValue = 0;
    struct nodeS<T>* temp = NULL;

    if(First == NULL)
    {
        cout<<"Unable to pop the element as stack is empty\n";
        return -1;
    }
    else
    {
        temp = First;

        iValue = First -> data;
        First = First -> next;
        delete temp;
        
        iCount--;
    }

    return iValue;
}


/////////////////////////////////////////////////
//       Code of Queue                         //
/////////////////////////////////////////////////



#include<iostream>
using namespace std;

template <class T>
struct nodeQ
{
    T data;
    struct nodeQ *next;
};

template <class T>
class Queue
{
    private:
        struct nodeQ<T>* First;
        int iCount;

    public:
        Queue();
        void Display();
        T Count();
        void EnQueue(T No);  // InsertLast()
        T DeQueue();         // DeleteFirst()
};

template <class T>
Queue<T>:: Queue()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void Queue<T>::Display()
{
    cout<<"Elements of Queue are : \n";
    struct nodeQ<T>* temp = First;

    while(temp != NULL)
    {
        cout<<temp->data<<"\t";
        temp = temp -> next;
    }
    cout<<"\n";
}

template <class T>
T Queue<T>::Count()
{
    return iCount;
}

template <class T>
void Queue<T>::EnQueue(T No)
{
    struct nodeQ<T>* newn = NULL;
    struct nodeQ<T>* temp = NULL;

    newn = new struct nodeQ<T>;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;

        while(temp ->next != NULL)
        {
            temp = temp -> next;
        }

        temp->next = newn;
    }
    iCount++;
}

template <class T>
T Queue<T>::DeQueue()
{
    T iValue = 0;
    struct nodeQ<T>* temp = NULL;

    if(First == NULL)
    {
        cout<<"Unable to remove the element as queue is empty\n";
        return -1;
    }
    else
    {
        temp = First;

        iValue = First -> data;
        First = First -> next;
        delete temp;
        
        iCount--;
    }

    return iValue;
}


/////////////////////////////////////////////////
//       Code of Linear Search                 //
/////////////////////////////////////////////////

template <class T>
class ArrayX
{
    public:
        T *Arr;
        int iSize;

        ArrayX(int Value);
        ~ArrayX();
        void Accept();
        void Display();
        bool LinearSearch(T Value);
};

template <class T>
ArrayX<T>::ArrayX(int Value)
{
    this->iSize = Value;
    this->Arr = new T[iSize];
}

template <class T>
ArrayX<T>::~ArrayX()
{
    delete []Arr;
}

template <class T>
void ArrayX<T>::Accept()
{
    int i = 0;

    cout<<"Enter the elements : \n";
    for(i = 0; i < iSize; i++)
    {
        cin>>Arr[i];
    }
}

template <class T>
void ArrayX<T>::Display()
{
    int i = 0;

    cout<<"Entered elements are : \n";
    for(i = 0; i < iSize; i++)
    {
        cout<<Arr[i]<<"\n";
    }
}

template <class T>
bool ArrayX<T>::LinearSearch(T Value)
{
    bool flag = false;
    int i = 0;

    for(i = 0; i < iSize; i++)
    {
        if(Arr[i] == Value)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

/////////////////////////////////////////////////
//       Code of BiDirectionalSearch           //
/////////////////////////////////////////////////


template <class T>
class BidireC
{
    public:
        T *Arr;
        int iSize;

        BidireC(int Value);
        ~BidireC();
        void Accept();
        void Display();
        bool LinearSearch(T Value);
        bool BidirectionalSearch(T Value);
};

template <class T>
BidireC<T>::BidireC(int Value)
{
    this->iSize = Value;
    this->Arr = new T[iSize];
}

template <class T>
BidireC<T>::~BidireC()
{
    delete []Arr;
}

template <class T>
void BidireC<T>::Accept()
{
    int i = 0;

    cout<<"Enter the elements : \n";
    for(i = 0; i < iSize; i++)
    {
        cin>>Arr[i];
    }
}

template <class T>
void BidireC<T>::Display()
{
    int i = 0;

    cout<<"Entered elements are : \n";
    for(i = 0; i < iSize; i++)
    {
        cout<<Arr[i]<<"\n";
    }
}

template <class T>
bool BidireC<T>::LinearSearch(T Value)
{
    bool flag = false;
    int i = 0;

    for(i = 0; i < iSize; i++)
    {
        if(Arr[i] == Value)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

template <class T>
bool BidireC<T>::BidirectionalSearch(T Value) // It will reduces the time complexity
{
    bool bFlag = false;
    int iStart = 0, iEnd = 0;

    iStart = 0;
    iEnd = iSize-1;

    while(iStart <= iEnd)
    {
        if(Arr[iStart] == Value || Arr[iEnd] == Value)
        {
            bFlag = true;
            break;
        }
        iStart++;
        iEnd--;
    }

    return bFlag;
}

/////////////////////////////////////////////////
//       Code of Binary Search                 //
/////////////////////////////////////////////////

template <class T>
class BinaryS
{
    public:
        T *Arr;
        int iSize;

        BinaryS(int Value);
        ~BinaryS();
        void Accept();
        void Display();
        bool LinearSearch(T Value);
        bool BidirectionalSearch(T Value);
        bool BinarySearch(T Value);
};

template <class T>
BinaryS<T>::BinaryS(int Value)
{
    this->iSize = Value;
    this->Arr = new T[iSize];
}

template <class T>
BinaryS<T>::~BinaryS()
{
    delete []Arr;
}

template <class T>
void BinaryS<T>::Accept()
{
    int i = 0;

    cout<<"Enter the elements : \n";
    for(i = 0; i < iSize; i++)
    {
        cin>>Arr[i];
    }
}

template <class T>
void BinaryS<T>::Display()
{
    int i = 0;

    cout<<"Entered elements are : \n";
    for(i = 0; i < iSize; i++)
    {
        cout<<Arr[i]<<"\n";
    }
}

template <class T>
bool BinaryS<T>::LinearSearch(T Value)
{
    bool flag = false;
    int i = 0;

    for(i = 0; i < iSize; i++)
    {
        if(Arr[i] == Value)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

template <class T>
bool BinaryS<T>::BidirectionalSearch(T Value) // It will reduces the time complexity
{
    bool bFlag = false;
    int iStart = 0, iEnd = 0;

    iStart = 0;
    iEnd = iSize-1;

    while(iStart <= iEnd)
    {
        if(Arr[iStart] == Value || Arr[iEnd] == Value)
        {
            bFlag = true;
            break;
        }
        iStart++;
        iEnd--;
    }

    return bFlag;
}

template <class T>
bool BinaryS<T>::BinarySearch(T Value)
{
    bool bFlag = false;
    int iStart = 0, iEnd = 0, iMid = 0;

    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if(Arr[iMid] == Value)
        {
            bFlag = true;
            break;
        }
        else if(Arr[iMid] < Value)
        {
            iStart = iMid + 1;
        }
        else if(Arr[iMid] > Value)
        {
            iEnd = iMid - 1;
        }
    }

    return bFlag;
}

/////////////////////////////////////////////////
//       Code of Bubble Sort                   //
/////////////////////////////////////////////////

template <class T>
class BubbleS
{
    public:
        T *Arr;
        int iSize;

        BubbleS(int Value);
        ~BubbleS();
        void Accept();
        void Display();
        bool LinearSearch(T Value);
        bool BidirectionalSearch(T Value);
        bool BinarySearch(T Value);
        void BubbleSort();
};

template <class T>
BubbleS<T>::BubbleS(int Value)
{
    this->iSize = Value;
    this->Arr = new T[iSize];
}

template <class T>
BubbleS<T>::~BubbleS()
{
    delete []Arr;
}

template <class T>
void BubbleS<T>::Accept()
{
    int i = 0;

    cout<<"Enter the elements : \n";
    for(i = 0; i < iSize; i++)
    {
        cin>>Arr[i];
    }
}

template <class T>
void BubbleS<T>::Display()
{
    int i = 0;

    cout<<"Entered elements are : \n";
    for(i = 0; i < iSize; i++)
    {
        cout<<Arr[i]<<"\n";
    }
}

template <class T>
bool BubbleS<T>::LinearSearch(T Value)
{
    bool flag = false;
    int i = 0;

    for(i = 0; i < iSize; i++)
    {
        if(Arr[i] == Value)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

template <class T>
bool BubbleS<T>::BidirectionalSearch(T Value) // It will reduces the time complexity
{
    bool bFlag = false;
    int iStart = 0, iEnd = 0;

    iStart = 0;
    iEnd = iSize-1;

    while(iStart <= iEnd)
    {
        if(Arr[iStart] == Value || Arr[iEnd] == Value)
        {
            bFlag = true;
            break;
        }
        iStart++;
        iEnd--;
    }

    return bFlag;
}

template <class T>
bool BubbleS<T>::BinarySearch(T Value)
{
    bool bFlag = false;
    int iStart = 0, iEnd = 0, iMid = 0;

    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if(Arr[iMid] == Value)
        {
            bFlag = true;
            break;
        }
        else if(Arr[iMid] < Value)
        {
            iStart = iMid + 1;
        }
        else if(Arr[iMid] > Value)
        {
            iEnd = iMid - 1;
        }
    }

    return bFlag;
}

template <class T>
void BubbleS<T>::BubbleSort()
{
    int Temp = 0;
    int i = 0, j = 0;

    for(i=0; i<iSize-1; i++)
    {
        for(j=0; j<iSize-i-1; j++)  // Reduce the number of Iteration
        {
            if(Arr[j]>Arr[j+1])
            {
                Temp = Arr[j];
                Arr[j]  = Arr[j+1];
                Arr[j+1] = Temp;
            }
        }
        cout<<"\nArray after pass : "<<i+1<<"\n";
        Display();
    }
}

/////////////////////////////////////////////////
//       Code of Bubble Sort Efficient         //
/////////////////////////////////////////////////

template <class T>
class BubbleSE
{
    public:
        T *Arr;
        int iSize;

        BubbleSE(int Value);
        ~BubbleSE();
        void Accept();
        void Display();
        bool LinearSearch(T Value);
        bool BidirectionalSearch(T Value);
        bool BinarySearch(T Value);
        void BubbleSort();
        void BubbleSortEfficient();
};

template <class T>
BubbleSE<T>::BubbleSE(int Value)
{
    this->iSize = Value;
    this->Arr = new T[iSize];
}

template <class T>
BubbleSE<T>::~BubbleSE()
{
    delete []Arr;
}

template <class T>
void BubbleSE<T>::Accept()
{
    int i = 0;

    cout<<"Enter the elements : \n";
    for(i = 0; i < iSize; i++)
    {
        cin>>Arr[i];
    }
}

template <class T>
void BubbleSE<T>::Display()
{
    int i = 0;

    cout<<"Entered elements are : \n";
    for(i = 0; i < iSize; i++)
    {
        cout<<Arr[i]<<"\n";
    }
}

template <class T>
bool BubbleSE<T>::LinearSearch(T Value)
{
    bool flag = false;
    int i = 0;

    for(i = 0; i < iSize; i++)
    {
        if(Arr[i] == Value)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

template <class T>
bool BubbleSE<T>::BidirectionalSearch(T Value) // It will reduces the time complexity
{
    bool bFlag = false;
    int iStart = 0, iEnd = 0;

    iStart = 0;
    iEnd = iSize-1;

    while(iStart <= iEnd)
    {
        if(Arr[iStart] == Value || Arr[iEnd] == Value)
        {
            bFlag = true;
            break;
        }
        iStart++;
        iEnd--;
    }

    return bFlag;
}

template <class T>
bool BubbleSE<T>::BinarySearch(T Value)
{
    bool bFlag = false;
    int iStart = 0, iEnd = 0, iMid = 0;

    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if(Arr[iMid] == Value)
        {
            bFlag = true;
            break;
        }
        else if(Arr[iMid] < Value)
        {
            iStart = iMid + 1;
        }
        else if(Arr[iMid] > Value)
        {
            iEnd = iMid - 1;
        }
    }

    return bFlag;
}

template <class T>
void BubbleSE<T>::BubbleSort()
{
    int Temp = 0;
    int i = 0, j = 0;

    for(i=0; i<iSize-1; i++)
    {
        for(j=0; j<iSize-i-1; j++)  // Reduce the number of Iteration
        {
            if(Arr[j]>Arr[j+1])
            {
                Temp = Arr[j];
                Arr[j]  = Arr[j+1];
                Arr[j+1] = Temp;
            }
        }
        cout<<"\nArray after pass : "<<i+1<<"\n";
        Display();
    }
}

template <class T>
void BubbleSE<T>::BubbleSortEfficient()
{
    T temp;
    int i = 0, j = 0;
    bool flag = false;

    //     1        2      3  
    for(i = 0; i < (iSize -1); i++)  // Outer
    {
        flag = false;
           //    1         2         3  
        for(j = 0; j< iSize - 1 - i; j++)   // Inner
        {
            if(Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
                flag = true;
            }
        }
        if(flag == false)
        {
            break;
        }
        cout<<"\nArray after pass : "<<i+1<<"\n";
        Display();
    }
}  

/////////////////////////////////////////////////
//       Code of Selection Sort                //
/////////////////////////////////////////////////

template <class T>
class Selection
{
    public:
        T *Arr;
        int iSize;

        Selection(int Value);
        ~Selection();
        void Accept();
        void Display();
        bool LinearSearch(T Value);
        bool BidirectionalSearch(T Value);
        bool BinarySearch(T Value);
        void BubbleSort();
        void BubbleSortEfficient();
        void SelectionSort();
};

template <class T>
Selection<T>::Selection(int Value)
{
    this->iSize = Value;
    this->Arr = new T[iSize];
}

template <class T>
Selection<T>::~Selection()
{
    delete []Arr;
}

template <class T>
void Selection<T>::Accept()
{
    int i = 0;

    cout<<"Enter the elements : \n";
    for(i = 0; i < iSize; i++)
    {
        cin>>Arr[i];
    }
}

template <class T>
void Selection<T>::Display()
{
    int i = 0;

    cout<<"Entered elements are : \n";
    for(i = 0; i < iSize; i++)
    {
        cout<<Arr[i]<<"\n";
    }
}

template <class T>
bool Selection<T>::LinearSearch(T Value)
{
    bool flag = false;
    int i = 0;

    for(i = 0; i < iSize; i++)
    {
        if(Arr[i] == Value)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

template <class T>
bool Selection<T>::BidirectionalSearch(T Value) // It will reduces the time complexity
{
    bool bFlag = false;
    int iStart = 0, iEnd = 0;

    iStart = 0;
    iEnd = iSize-1;

    while(iStart <= iEnd)
    {
        if(Arr[iStart] == Value || Arr[iEnd] == Value)
        {
            bFlag = true;
            break;
        }
        iStart++;
        iEnd--;
    }

    return bFlag;
}

template <class T>
bool Selection<T>::BinarySearch(T Value)
{
    bool bFlag = false;
    int iStart = 0, iEnd = 0, iMid = 0;

    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if(Arr[iMid] == Value)
        {
            bFlag = true;
            break;
        }
        else if(Arr[iMid] < Value)
        {
            iStart = iMid + 1;
        }
        else if(Arr[iMid] > Value)
        {
            iEnd = iMid - 1;
        }
    }

    return bFlag;
}

template <class T>
void Selection<T>::BubbleSort()
{
    int Temp = 0;
    int i = 0, j = 0;

    for(i=0; i<iSize-1; i++)
    {
        for(j=0; j<iSize-i-1; j++)  // Reduce the number of Iteration
        {
            if(Arr[j]>Arr[j+1])
            {
                Temp = Arr[j];
                Arr[j]  = Arr[j+1];
                Arr[j+1] = Temp;
            }
        }
        cout<<"\nArray after pass : "<<i+1<<"\n";
        Display();
    }
}

template <class T>
void Selection<T>::BubbleSortEfficient()
{
    T temp;
    int i = 0, j = 0;
    bool flag = true;

    //     1        2      3  
    for(i = 0; i < (iSize -1) && flag == true; i++)  // Outer
    {
        flag = false;
           //    1         2         3  
        for(j = 0; j< iSize - 1 - i; j++)   // Inner
        {
            if(Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
                flag = true;
            }
        }
        cout<<"\nArray after pass : "<<i+1<<"\n";
        Display();
    }
}  

template <class T>
void Selection<T>::SelectionSort()
{
    int i = 0, j = 0, Min_Index = 0;
    int Temp = 0;

    for(i=0; i<iSize-1; i++)
    {
        Min_Index = i;
        for(j=i+1; j<iSize; j++)
        {
            if(Arr[Min_Index] > Arr[j])
            {
                Min_Index = j;
            }
        }
        Temp = Arr[i];
        Arr[i] = Arr[Min_Index];
        Arr[Min_Index] = Temp;
    }
}

/////////////////////////////////////////////////
//       Code for Insertion Sort               //
/////////////////////////////////////////////////

template <class T>
class Insertion
{
    public:
        T *Arr;
        int iSize;

        Insertion(int Value);
        ~Insertion();
        void Accept();
        void Display();
        bool LinearSearch(T Value);
        bool BidirectionalSearch(T Value);
        bool BinarySearch(T Value);
        void BubbleSort();
        void BubbleSortEfficient();
        void SelectionSort();
        void InsertionSort();
};

template <class T>
Insertion<T>::Insertion(int Value)
{
    this->iSize = Value;
    this->Arr = new T[iSize];
}

template <class T>
Insertion<T>::~Insertion()
{
    delete []Arr;
}

template <class T>
void Insertion<T>::Accept()
{
    int i = 0;

    cout<<"Enter the elements : \n";
    for(i = 0; i < iSize; i++)
    {
        cin>>Arr[i];
    }
}

template <class T>
void Insertion<T>::Display()
{
    int i = 0;

    cout<<"Entered elements are : \n";
    for(i = 0; i < iSize; i++)
    {
        cout<<Arr[i]<<"\n";
    }
}

template <class T>
bool Insertion<T>::LinearSearch(T Value)
{
    bool flag = false;
    int i = 0;

    for(i = 0; i < iSize; i++)
    {
        if(Arr[i] == Value)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

template <class T>
bool Insertion<T>::BidirectionalSearch(T Value) // It will reduces the time complexity
{
    bool bFlag = false;
    int iStart = 0, iEnd = 0;

    iStart = 0;
    iEnd = iSize-1;

    while(iStart <= iEnd)
    {
        if(Arr[iStart] == Value || Arr[iEnd] == Value)
        {
            bFlag = true;
            break;
        }
        iStart++;
        iEnd--;
    }

    return bFlag;
}

template <class T>
bool Insertion<T>::BinarySearch(T Value)
{
    bool bFlag = false;
    int iStart = 0, iEnd = 0, iMid = 0;

    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if(Arr[iMid] == Value)
        {
            bFlag = true;
            break;
        }
        else if(Arr[iMid] < Value)
        {
            iStart = iMid + 1;
        }
        else if(Arr[iMid] > Value)
        {
            iEnd = iMid - 1;
        }
    }

    return bFlag;
}

template <class T>
void Insertion<T>::BubbleSort()
{
    int Temp = 0;
    int i = 0, j = 0;

    for(i=0; i<iSize-1; i++)
    {
        for(j=0; j<iSize-i-1; j++)  // Reduce the number of Iteration
        {
            if(Arr[j]>Arr[j+1])
            {
                Temp = Arr[j];
                Arr[j]  = Arr[j+1];
                Arr[j+1] = Temp;
            }
        }
        cout<<"\nArray after pass : "<<i+1<<"\n";
        Display();
    }
}

template <class T>
void Insertion<T>::BubbleSortEfficient()
{
    T temp;
    int i = 0, j = 0;
    bool flag = true;

    //     1        2      3  
    for(i = 0; i < (iSize -1) && flag == true; i++)  // Outer
    {
        flag = false;
           //    1         2         3  
        for(j = 0; j< iSize - 1 - i; j++)   // Inner
        {
            if(Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
                flag = true;
            }
        }
        cout<<"\nArray after pass : "<<i+1<<"\n";
        Display();
    }
}  

template <class T>
void Insertion<T>::SelectionSort()
{
    int i = 0, j = 0, Min_Index = 0;
    int Temp = 0;

    for(i=0; i<iSize-1; i++)
    {
        Min_Index = i;
        for(j=i+1; j<iSize; j++)
        {
            if(Arr[Min_Index] > Arr[j])
            {
                Min_Index = j;
            }
        }
        Temp = Arr[i];
        Arr[i] = Arr[Min_Index];
        Arr[Min_Index] = Temp;
    }
}

template <class T>
void Insertion<T>::InsertionSort()
{
    int i = 0, j = 0;
    int Selected = 0;

    for(i=1; i<iSize; i++)
    {
        for(j=i-1,Selected = Arr[i]; j>=0 && Arr[j] > Selected; j--)
        {
            Arr[j+1] = Arr[j];
        }
        Arr[j+1] = Selected;
    }
}

/////////////////////////////////////////////////
//       Code for Shell Sort Algorithm         //
/////////////////////////////////////////////////


template <class T>
class Shell
{
    public:
        T *Arr;
        int iSize;

        Shell(int Value);
        ~Shell();
        void Accept();
        void Display();
        bool LinearSearch(T Value);
        bool BidirectionalSearch(T Value);
        bool BinarySearch(T Value);
        void BubbleSort();
        void BubbleSortEfficient();
        void SelectionSort();
        void InsertionSort();
        void ShellSort();
};

template <class T>
Shell<T>::Shell(int Value)
{
    this->iSize = Value;
    this->Arr = new T[iSize];
}

template <class T>
Shell<T>::~Shell()
{
    delete []Arr;
}

template <class T>
void Shell<T>::Accept()
{
    int i = 0;

    cout<<"Enter the elements : \n";
    for(i = 0; i < iSize; i++)
    {
        cin>>Arr[i];
    }
}

template <class T>
void Shell<T>::Display()
{
    int i = 0;

    cout<<"Entered elements are : \n";
    for(i = 0; i < iSize; i++)
    {
        cout<<Arr[i]<<"\n";
    }
}

template <class T>
bool Shell<T>::LinearSearch(T Value)
{
    bool flag = false;
    int i = 0;

    for(i = 0; i < iSize; i++)
    {
        if(Arr[i] == Value)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

template <class T>
bool Shell<T>::BidirectionalSearch(T Value) // It will reduces the time complexity
{
    bool bFlag = false;
    int iStart = 0, iEnd = 0;

    iStart = 0;
    iEnd = iSize-1;

    while(iStart <= iEnd)
    {
        if(Arr[iStart] == Value || Arr[iEnd] == Value)
        {
            bFlag = true;
            break;
        }
        iStart++;
        iEnd--;
    }

    return bFlag;
}

template <class T>
bool Shell<T>::BinarySearch(T Value)
{
    bool bFlag = false;
    int iStart = 0, iEnd = 0, iMid = 0;

    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if(Arr[iMid] == Value)
        {
            bFlag = true;
            break;
        }
        else if(Arr[iMid] < Value)
        {
            iStart = iMid + 1;
        }
        else if(Arr[iMid] > Value)
        {
            iEnd = iMid - 1;
        }
    }

    return bFlag;
}

template <class T>
void Shell<T>::BubbleSort()
{
    int Temp = 0;
    int i = 0, j = 0;

    for(i=0; i<iSize-1; i++)
    {
        for(j=0; j<iSize-i-1; j++)  // Reduce the number of Iteration
        {
            if(Arr[j]>Arr[j+1])
            {
                Temp = Arr[j];
                Arr[j]  = Arr[j+1];
                Arr[j+1] = Temp;
            }
        }
        cout<<"\nArray after pass : "<<i+1<<"\n";
        Display();
    }
}

template <class T>
void Shell<T>::BubbleSortEfficient()
{
    T temp;
    int i = 0, j = 0;
    bool flag = true;

    //     1        2      3  
    for(i = 0; i < (iSize -1) && flag == true; i++)  // Outer
    {
        flag = false;
           //    1         2         3  
        for(j = 0; j< iSize - 1 - i; j++)   // Inner
        {
            if(Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
                flag = true;
            }
        }
        cout<<"\nArray after pass : "<<i+1<<"\n";
        Display();
    }
}  

template <class T>
void Shell<T>::SelectionSort()
{
    int i = 0, j = 0, Min_Index = 0;
    int Temp = 0;

    for(i=0; i<iSize-1; i++)
    {
        Min_Index = i;
        for(j=i+1; j<iSize; j++)
        {
            if(Arr[Min_Index] > Arr[j])
            {
                Min_Index = j;
            }
        }
        Temp = Arr[i];
        Arr[i] = Arr[Min_Index];
        Arr[Min_Index] = Temp;
    }
}

template <class T>
void Shell<T>::InsertionSort()
{
    int i = 0, j = 0;
    int Selected = 0;

    for(i=1; i<iSize; i++)
    {
        for(j=i-1,Selected = Arr[i]; j>=0 && Arr[j] > Selected; j--)
        {
            Arr[j+1] = Arr[j];
        }
        Arr[j+1] = Selected;
    }
}

template <class T>
void Shell<T>::ShellSort()
{
    int iGap = 0, i = 0, j = 0;
    int Temp = 0;

    for(iGap=(iSize/2); iGap>=1; iGap /= 2)
    {
        for(j=iGap; j<iSize; j++)
        {
            for(i=j-iGap; i>=0; i -= iGap)
            {
                if(Arr[i+iGap] > Arr[i])
                {
                    break;
                }
                else
                {
                    Temp = Arr[i+iGap];
                    Arr[i+iGap] = Arr[i];
                    Arr[i] = Temp;
                }
            }
        }
    }
}


/////////////////////////////////////////////////
//       Code For Merge Sort                   //
/////////////////////////////////////////////////


template <class T>
class MergeS
{
    public:
        T *Arr;
        int iSize;

        MergeS(int Value);
        ~MergeS();
        void Accept();
        void Display();
        bool LinearSearch(T Value);
        bool BidirectionalSearch(T Value);
        bool BinarySearch(T Value);
        void BubbleSort();
        void BubbleSortEfficient();
        void SelectionSort();
        void InsertionSort();
        void ShellSort();
        void Divide(int Left, int Right);
        void MergeSort();
        void Merge(int Lb, int Mid, int Ub);
        
};

template <class T>
MergeS<T>::MergeS(int Value)
{
    this->iSize = Value;
    this->Arr = new T[iSize];
}

template <class T>
MergeS<T>::~MergeS()
{
    delete []Arr;
}

template <class T>
void MergeS<T>::Accept()
{
    int i = 0;

    cout<<"Enter the elements : \n";
    for(i = 0; i < iSize; i++)
    {
        cin>>Arr[i];
    }
}

template <class T>
void MergeS<T>::Display()
{
    int i = 0;

    cout<<"Entered elements are : \n";
    for(i = 0; i < iSize; i++)
    {
        cout<<Arr[i]<<"\n";
    }
}

template <class T>
bool MergeS<T>::LinearSearch(T Value)
{
    bool flag = false;
    int i = 0;

    for(i = 0; i < iSize; i++)
    {
        if(Arr[i] == Value)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

template <class T>
bool MergeS<T>::BidirectionalSearch(T Value) // It will reduces the time complexity
{
    bool bFlag = false;
    int iStart = 0, iEnd = 0;

    iStart = 0;
    iEnd = iSize-1;

    while(iStart <= iEnd)
    {
        if(Arr[iStart] == Value || Arr[iEnd] == Value)
        {
            bFlag = true;
            break;
        }
        iStart++;
        iEnd--;
    }

    return bFlag;
}

template <class T>
bool MergeS<T>::BinarySearch(T Value)
{
    bool bFlag = false;
    int iStart = 0, iEnd = 0, iMid = 0;

    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if(Arr[iMid] == Value)
        {
            bFlag = true;
            break;
        }
        else if(Arr[iMid] < Value)
        {
            iStart = iMid + 1;
        }
        else if(Arr[iMid] > Value)
        {
            iEnd = iMid - 1;
        }
    }

    return bFlag;
}

template <class T>
void MergeS<T>::BubbleSort()
{
    T Temp = 0;
    int i = 0, j = 0;

    for(i=0; i<iSize-1; i++)
    {
        for(j=0; j<iSize-i-1; j++)  // Reduce the number of Iteration
        {
            if(Arr[j]>Arr[j+1])
            {
                Temp = Arr[j];
                Arr[j]  = Arr[j+1];
                Arr[j+1] = Temp;
            }
        }
        cout<<"\nArray after pass : "<<i+1<<"\n";
        Display();
    }
}

template <class T>
void MergeS<T>::BubbleSortEfficient()
{
    T temp;
    int i = 0, j = 0;
    bool flag = true;

    //     1        2      3  
    for(i = 0; i < (iSize -1) && flag == true; i++)  // Outer
    {
        flag = false;
           //    1         2         3  
        for(j = 0; j< iSize - 1 - i; j++)   // Inner
        {
            if(Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
                flag = true;
            }
        }
        cout<<"\nArray after pass : "<<i+1<<"\n";
        Display();
    }
}  

template <class T>
void MergeS<T>::SelectionSort()
{
    int i = 0, j = 0, Min_Index = 0;
    T Temp = 0;

    for(i=0; i<iSize-1; i++)
    {
        Min_Index = i;
        for(j=i+1; j<iSize; j++)
        {
            if(Arr[Min_Index] > Arr[j])
            {
                Min_Index = j;
            }
        }
        Temp = Arr[i];
        Arr[i] = Arr[Min_Index];
        Arr[Min_Index] = Temp;
    }
}

template <class T>
void MergeS<T>::InsertionSort()
{
    int i = 0, j = 0;
    T Selected ;

    for(i=1; i<iSize; i++)
    {
        for(j=i-1,Selected = Arr[i]; j>=0 && Arr[j] > Selected; j--)
        {
            Arr[j+1] = Arr[j];
        }
        Arr[j+1] = Selected;
    }
}

template <class T>
void MergeS<T>::ShellSort()
{
    int iGap = 0, i = 0, j = 0;
    T Temp = 0;

    for(iGap=(iSize/2); iGap>=1; iGap /= 2)
    {
        for(j=iGap; j<iSize; j++)
        {
            for(i=j-iGap; i>=0; i -= iGap)
            {
                if(Arr[i+iGap] > Arr[i])
                {
                    break;
                }
                else
                {
                    Temp = Arr[i+iGap];
                    Arr[i+iGap] = Arr[i];
                    Arr[i] = Temp;
                }
            }
        }
    }
}

template <class T>
void MergeS<T>::Divide(int Left, int Right)
{
    int iMid;

    if(Right > Left)
    {
        iMid = (Right + Left)/2;

        Divide(Left, iMid);
        Divide(iMid+1, Right);
        Merge(Left, iMid, Right);  
    }
}

template <class T>
void MergeS<T>::Merge(int Lb, int Mid, int Ub)
{
    int i = Lb;
    int j = Mid+1;
    int k = Lb;
    T Temp[iSize];

    while(i <= Mid && j <=  Ub)
    {
        if(Arr[i] <= Arr[j])
        {
            Temp[k] = Arr[i];
            i++;   
        }
        else
        {
            Temp[k] = Arr[j];
            j++;
        }
        k++;
    }
    if(i > Mid)
    {
        while(j <= Ub)
        {
            Temp[k] = Arr[j];
            j++;
            k++;
        }
    }
    else if(j > Ub)
    {
        while(i <= Mid)
        {
            Temp[k] = Arr[i];
            i++;
            k++;
        }
    }

    for(k=Lb; k<=Ub; k++)
    {
        Arr[k] = Temp[k];
    }
}

template <class T>
void MergeS<T>::MergeSort()
{
    int iStart = 0, iEnd = 0;

    iStart = 0;
    iEnd = iSize-1;

    Divide(iStart, iEnd);

}


/////////////////////////////////////////////////
//       Code of Binary Search Tree            //
/////////////////////////////////////////////////



int main ()
{
    cout<<"------------------------------------\n";
    cout<<"Operation for Singly Linear LL :\n";
    cout<<"------------------------------------\n";
    cout<<"\n";

    int iRet = 0, iLength = 0, No = 0;
    bool  bRet = false;
    SinglyLL<int>*iobj = new SinglyLL<int>();


    iobj->InsertFirst(51);
    iobj->InsertFirst(21);
    iobj->InsertFirst(11);

    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elements are : "<<iRet<<endl;
    cout<<"\n";

    iobj->InsertLast(101);
    iobj->InsertLast(111);
    iobj->InsertLast(121);

    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elements are : "<<iRet<<endl;
    cout<<"\n";

    iobj->InsertAtPos(105, 5);
    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elements are : "<<iRet<<endl;
    cout<<"\n";

    iobj->DeleteAtPos(4);
    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elements are : "<<iRet<<endl;
    cout<<"\n";
    
    iobj->DeleteFirst();
    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elements are : "<<iRet<<endl;
    cout<<"\n";

    iobj->DeleteLast();
    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elements are : "<<iRet<<endl;
    cout<<"\n";

    iobj->DeleteAtPos(4);
    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elements are : "<<iRet<<endl;
    cout<<"\n";



    cout<<"------------------------------------\n";
    cout<<"Operation for Singly Circular LL :\n";
    cout<<"------------------------------------\n";
    cout<<"\n";



    SinglyCL<float>*fobj = new SinglyCL<float>();

    fobj->InsertFirst(51.12f);
    fobj->InsertFirst(21.13f);
    fobj->InsertFirst(11.14f);

    fobj->Display();
    iRet = fobj->Count();
    cout<<"Number of elements are : "<<iRet<<endl;
    cout<<"\n";

    fobj->InsertLast(111.15f);
    fobj->InsertLast(121.16f);
    fobj->InsertLast(151.17f);

    fobj->Display();
    iRet = fobj->Count();
    cout<<"Number of elements are : "<<iRet<<endl;
    cout<<"\n";

    fobj->InsertAtPos(116.11f, 5);

    fobj->Display();
    iRet = fobj->Count();
    cout<<"Number of elements are : "<<iRet<<endl;
    cout<<"\n";

    fobj->DeleteFirst();

    fobj->Display();
    iRet = fobj->Count();
    cout<<"Number of elements are : "<<iRet<<endl;
    cout<<"\n";

    fobj->DeleteLast();

    fobj->Display();
    iRet = fobj->Count();
    cout<<"Number of elements are : "<<iRet<<endl;
    cout<<"\n";

    fobj->DeleteAtPos(4);

    fobj->Display();
    iRet = fobj->Count();
    cout<<"Number of elements are : "<<iRet<<endl;
    cout<<"\n";
 

    cout<<"------------------------------------\n";
    cout<<"Operation for Doubly Linear LL :\n";
    cout<<"------------------------------------\n";
    cout<<"\n";


    DoublyLL<char>*cobj = new DoublyLL<char>();

    cobj->InsertFirst('A');
    cobj->InsertFirst('B');
    cobj->InsertFirst('C');

    cobj->Display();
    iRet = cobj->Count();
    cout<<"\nNumber of elements are : "<<iRet<<endl;
    cout<<"\n";

    cobj->InsertLast('U');
    cobj->InsertLast('X');
    cobj->InsertLast('Z');

    cobj->Display();
    iRet = cobj->Count();
    cout<<"\nNumber of elements are : "<<iRet<<"\n";
    cout<<"\n";

    cobj->InsertAtPos('M', 5);
    cobj->Display();
    iRet = cobj->Count();
    cout<<"\nNumber of elements are : "<<iRet<<"\n";
    cout<<"\n";

    cobj->DeleteFirst();
    cobj->Display();
    iRet = cobj->Count();
    cout<<"\nNumber of elements are : "<<iRet<<"\n";
    cout<<"\n";

    cobj->DeleteLast();
    cobj->Display();
    iRet = cobj->Count();
    cout<<"\nNumber of elements are : "<<iRet<<"\n";
    cout<<"\n";

    cobj->DeleteAtPos(4);
    cobj->Display();
    iRet = cobj->Count();
    cout<<"\nNumber of elements are : "<<iRet<<"\n";
    cout<<"\n";


    cout<<"------------------------------------\n";
    cout<<"Operation for Doubly Circular LL :\n";
    cout<<"------------------------------------\n";
    cout<<"\n";


    DoublyCL<double>*dobj = new DoublyCL<double>();

    dobj->InsertFirst(51.1233);
    dobj->InsertFirst(21.2455);
    dobj->InsertFirst(11.4567);

    dobj->Display();
    iRet = dobj->Count();
    cout<<"Number of elements are : "<<iRet<<endl;
    cout<<"\n";

    dobj->InsertLast(111.4670);
    dobj->InsertLast(121.4677);
    dobj->InsertLast(151.2345);

    dobj->Display();
    iRet = dobj->Count();
    cout<<"Number of elements are : "<<iRet<<endl;
    cout<<"\n";

    dobj->InsertAtPos(34.3467, 5);
    dobj->Display();
    iRet = dobj->Count();
    cout<<"Number of elements are : "<<iRet<<endl;
    cout<<"\n";

    dobj->DeleteFirst();

    dobj->Display();
    iRet = dobj->Count();
    cout<<"Number of elements are : "<<iRet<<endl;
    cout<<"\n";

    dobj->DeleteLast();

    dobj->Display();
    iRet = dobj->Count();
    cout<<"Number of elements are : "<<iRet<<endl;
    cout<<"\n";

    dobj->DeleteAtPos(4);
    dobj->Display();
    iRet = dobj->Count();
    cout<<"Number of elements are : "<<iRet<<endl;
    cout<<"\n";


    cout<<"------------------------------------\n";
    cout<<"Operation for Stack :\n";
    cout<<"------------------------------------\n";
    cout<<"\n";

    Stack<int>*sobj = new Stack<int>();

    sobj->Push(10);
    sobj->Push(20);
    sobj->Push(30);
    sobj->Push(40);

    sobj->Display();
    iRet = sobj->Count();
    cout<<"Number of elements in the stack are : "<<iRet<<"\n";
    cout<<'\n';
    
    iRet = sobj->Pop();

    cout<<"Poped element is : "<<iRet<<"\n";

    iRet = sobj->Pop();

    cout<<"Poped element is : "<<iRet<<"\n";
    
    sobj->Display();
    iRet = sobj->Count();
    cout<<"Number of elements in the stack are : "<<iRet<<"\n";
    cout<<'\n';

    sobj->Push(50);

    sobj->Display();
    iRet = sobj->Count();
    cout<<"Number of elements in the stack are : "<<iRet<<"\n";
    cout<<'\n';

    cout<<"------------------------------------\n";
    cout<<"Operation for Stack :\n";
    cout<<"------------------------------------\n";
    cout<<"\n";

    Queue<int>*Qobj = new Queue<int>();

    Qobj->EnQueue(10);
    Qobj->EnQueue(20);
    Qobj->EnQueue(30);
    Qobj->EnQueue(40);

    Qobj->Display();
    iRet = Qobj->Count();
    cout<<"Number of elements in the Queue are : "<<iRet<<"\n";
    cout<<"\n";
    
    iRet = Qobj->DeQueue();

    cout<<"Removed element is : "<<iRet<<"\n";

    iRet = Qobj->DeQueue();

    cout<<"Removed element is : "<<iRet<<"\n";
    
    Qobj->Display();
    iRet = Qobj->Count();
    cout<<"Number of elements in the Queue are : "<<iRet<<"\n";
    cout<<"\n";

    Qobj->EnQueue(50);

    Qobj->Display();
    iRet = Qobj->Count();
    cout<<"Number of elements in the Queue are : "<<iRet<<"\n";
    cout<<"\n";
  
    cout<<"------------------------------------\n";
    cout<<"Operation for LinearSearch algorithm :\n";
    cout<<"------------------------------------\n";
    cout<<"\n";


    cout<<"Enter the number of elements : \n";
    cin>>iLength;

    ArrayX<int> *Lobj = new ArrayX<int>(iLength);

    Lobj->Accept();
    Lobj->Display();
    
    cout<<"Enter the element that you want to search : \n";
    cin>>No;

    bRet = Lobj->LinearSearch(No);

    if(bRet == true)
    {
        cout<<"Element is present \n"<<endl;
    }
    else
    {
        cout<<"There is no such element\n"<<endl;
    }

    cout<<"-------------------------------------------------\n";
    cout<<"Operation for Bidirectional Searching algorithm :\n";
    cout<<"-------------------------------------------------\n";
    cout<<"\n";

    cout<<"Enter the number of elements : \n";
    cin>>iLength;

    BidireC<int> *Bobj = new BidireC<int>(iLength);

    Bobj->Accept();
    Bobj->Display();
    
    cout<<"Enter the element that you want to search : \n";
    cin>>No;

    bRet = Bobj->BidirectionalSearch(No);

    if(bRet == true)
    {
        cout<<"Element is present \n";
    }
    else
    {
        cout<<"There is no such element\n";
    }

    cout<<"----------------------------------------------\n";
    cout<<"Operation for Binary Searching  algorithm :\n";
    cout<<"-----------------------------------------------\n";
    cout<<"\n";

    cout<<"Enter the number of elements : \n";
    cin>>iLength;

    BinaryS<int> *BSobj = new BinaryS<int>(iLength);

    BSobj->Accept();
    BSobj->Display();
    
    cout<<"Enter the element that you want to search : \n";
    cin>>No;

    bRet = BSobj->BinarySearch(No);

    if(bRet == true)
    {
        cout<<"Element is present \n";
    }
    else
    {
        cout<<"There is no such element\n";
    }

    cout<<"----------------------------------------------\n";
    cout<<"Operation for Bubble Sort algorithm :\n";
    cout<<"-----------------------------------------------\n";
    cout<<"\n";
    
    cout<<"Enter the number of elements : \n";
    cin>>iLength;

    BubbleS<int> *BubbleObj = new BubbleS<int>(iLength);

    BubbleObj->Accept();
    BubbleObj->Display();
    
    BubbleObj->BubbleSort();

    cout<<"Data after sorting : \n";
    BubbleObj->Display();

    cout<<"----------------------------------------------\n";
    cout<<"Operation for Bubble Sort Efficient :\n";
    cout<<"-----------------------------------------------\n";
    cout<<"\n";

    cout<<"Enter the number of elements : \n";
    cin>>iLength;

    BubbleSE<int> *BubbleEObj = new BubbleSE<int>(iLength);

    BubbleEObj->Accept();
    BubbleEObj->Display();
    
    BubbleEObj->BubbleSortEfficient();

    cout<<"Data after sorting : \n";
    BubbleEObj->Display();

    cout<<"----------------------------------------------\n";
    cout<<"Operation for Selection Sort :\n";
    cout<<"-----------------------------------------------\n";
    cout<<"\n";

    cout<<"Enter the number of elements : \n";
    cin>>iLength;

    Selection<int> *SelecObj = new Selection<int>(iLength);

    SelecObj->Accept();
    cout<<"Data before sorting : \n";

    SelecObj->Display();

    SelecObj->SelectionSort();

    cout<<"\nData after sorting : \n";
    SelecObj->Display();

    cout<<"----------------------------------------------\n";
    cout<<"Operation for Insertion Sort :\n";
    cout<<"-----------------------------------------------\n";
    cout<<"\n";

    cout<<"Enter the number of elements : \n";
    cin>>iLength;

    Insertion<int> *InserObj = new Insertion<int>(iLength);

    InserObj->Accept();
    cout<<"Data before sorting : \n";

    InserObj->Display();

    InserObj->InsertionSort();

    cout<<"\nData after sorting : \n";
    InserObj->Display();

    cout<<"----------------------------------------------\n";
    cout<<"Operation for Shell Sort :\n";
    cout<<"-----------------------------------------------\n";
    cout<<"\n";

    cout<<"Enter the number of elements : \n";
    cin>>iLength;

    Shell<int> *ShellObj = new Shell<int>(iLength);

    ShellObj->Accept();
    cout<<"Data before sorting : \n";

    ShellObj->Display();

    ShellObj->ShellSort();

    cout<<"\nData after Shell Sorting : \n";
    ShellObj->Display();

    cout<<"----------------------------------------------\n";
    cout<<"Operation for Merge Sort :\n";
    cout<<"-----------------------------------------------\n";
    cout<<"\n";

    cout<<"Enter the number of elements : \n";
    cin>>iLength;

    MergeS<int> *MergeObj = new MergeS<int>(iLength);

    MergeObj->Accept();
    cout<<"Data before sorting : \n";

    MergeObj->Display();

    MergeObj->MergeSort();

    cout<<"\nData after Merge Sorting : \n";
    MergeObj->Display();

    return 0;
}