#include<iostream>
using namespace std;

template<class T>
class ArrayX
{
    public : 
        int *Arr;
        int iSize;

        ArrayX(int);
        ~ArrayX();
        void Accept();
        void Display();
        void EvenDisplay();
        void OddDisplay();
        T Summation();
        T Minimum();
        T Maximum();
        int Frequency(T);
        bool LinearSearch(T);
        bool BiDirectionalSearch(T);
        bool BinarySearch(T); 
        bool Sort();
        void BubbleSort(int);
        void EfficientBubbleSort(int);
        void SelectionSort(int);
        void InsertionSort();
};


template <class T>
ArrayX<T>::ArrayX(int iLength)
{
    this->iSize = iLength;
    this->Arr = new T[iSize];
}

template <class T>
void ArrayX<T>::Accept()
{
    cout << "Enter elements : \n";
    for (int iCnt = 0; iCnt < iSize; iCnt++)
    {
        cin >> Arr[iCnt];
    }
}

template <class T>
void ArrayX<T>::Display()
{
    cout << "Elements are : \n";
    for (int iCnt = 0; iCnt < iSize; iCnt++)
    {
        cout << Arr[iCnt] << "\t";
    }
    cout << "\n";
}


template <class T>
void ArrayX<T>::EvenDisplay()
{
    cout<<"Even elements are : \n";
    for (int iCnt = 0; iCnt < iSize; iCnt++)
    {
        if((Arr[iCnt] % 2) == 0)
        {
            cout<<Arr[iCnt]<<"\t";
        }
    }
    cout<<"\n";
}


template <class T>
void ArrayX<T>::OddDisplay()
{
    cout<<"Odd elements are : \n";
    for (int iCnt = 0; iCnt < iSize; iCnt++)
    {
        if((Arr[iCnt] % 2) != 0)
        {
            cout<<Arr[iCnt]<<"\t";
        }
    }
    cout<<"\n";
}

template <class T>
T ArrayX<T>::Summation()
{
    T iSum=0;

    for (int iCnt = 0; iCnt < iSize; iCnt++)
    {
        iSum = iSum + Arr[iCnt];
    }
    
    return iSum;
}

template <class T>
T ArrayX<T>::Minimum()
{
    T iMin=Arr[0];

    for (int iCnt = 0; iCnt < iSize; iCnt++)
    {
        if(Arr[iCnt] < iMin)
        {
            iMin = Arr[iCnt];
        }
    }
    
    return iMin;
}


template <class T>
T ArrayX<T>::Maximum()
{
    T iMax=Arr[0];

    for (int iCnt = 0; iCnt < iSize; iCnt++)
    {
        if(Arr[iCnt] > iMax)
        {
            iMax = Arr[iCnt];
        }
    }
    
    return iMax;
}


template <class T>
int ArrayX<T>::Frequency(T No)
{
    int iCount = 0 ;
    for (int iCnt = 0; iCnt < iSize; iCnt++)
    {
        if(Arr[iCnt] == No)
        {
            iCount++;
        }
    }

    return iCount;
}


template<class T>
bool ArrayX<T>::LinearSearch(T No)
{
    int iCnt = 0;

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        if(Arr[iCnt] == No)
        {
            break;
        }
    }

    if(Arr[iCnt]  ==  No)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<class T>
bool ArrayX<T>::BiDirectionalSearch(T No)
{
    int iStart = 0, iEnd = 0;

    iStart = 0;
    iEnd = (iSize - 1);

    while(iStart <= iEnd)
    {
        if((Arr[iStart] == No)  ||  (Arr[iEnd] == No))
        {
            break;
        }
        iStart++;
        iEnd--;
    }

    if(iStart > iEnd)
    {
        return false;
    }
    else
    {
        return true;
    }
}


template<class T>
bool ArrayX<T>::BinarySearch(T No)
{
    int iStart = 0, iEnd = 0, iMid = 0;
    iEnd = iSize -1 ;
    bool flag=false;

    while(iStart <=iEnd)
    {
        iMid = iStart + (iEnd - iStart) / 2;

        if((Arr[iMid] == No) || (Arr[iStart] == No) || (Arr[iEnd] == No))
        {
            flag = true;
            break;
        }
        else if(Arr[iMid] < No)
        {
            iStart = iMid + 1;
        }
        else if(Arr[iMid] > No)
        {
            iEnd = iMid - 1;
        }
    }

    return flag;
}

template<class T>
bool ArrayX<T>::Sort()
{
    int iCnt = 0;
    bool bFalg = true;

    for(iCnt = 0; iCnt < iSize - 1; iCnt++)
    {
        if(Arr[iCnt] < Arr[iCnt + 1])
        {
            continue;
        }
        else
        {
            bFalg = false;
            break;
        }
    }

    return bFalg;
}

template<class T>
void ArrayX<T>::BubbleSort(int No)
{
    int i = 0, j= 0;
    T temp;

    if(No == 0)
    {
        for(i = 0; i < iSize;i++)
        {
            for(j = 0; j < iSize-i-1; j++)
            {
                if(Arr[j] > Arr[j+1])
                {
                    temp=Arr[j];
                    Arr[j]=Arr[j+1];
                    Arr[j+1]=temp;
                }
            }
        }
    }
    else if(No == 1)
    {
        for(i = 0; i < iSize;i++)
        {
            for(j = 0; j < iSize-i-1; j++)
            {
                if(Arr[j] < Arr[j+1])
                {
                    temp=Arr[j];
                    Arr[j]=Arr[j+1];
                    Arr[j+1]=temp;
                }
            }
        }
    }
    else
    {
        return ;
    }

    Display();
}

template<class T>
void ArrayX<T>::EfficientBubbleSort(int No)
{
    int i = 0, j= 0;
    T temp;
    bool bFalg = false;

    if(No == 0)
    {
        for(i = 0; i < iSize;i++)
        {
            bFalg = false;
            for(j = 0; j < iSize-i-1; j++)
            {
                if(Arr[j] > Arr[j+1])
                {
                    temp=Arr[j];
                    Arr[j]=Arr[j+1];
                    Arr[j+1]=temp;
                    bFalg=true;
                }
            }
            if(bFalg == false)
            {
                break;
            }
        }
    }
    else if(No == 1)
    {
        for(i = 0; i < iSize;i++)
        {
            bFalg = false;
            for(j = 0; j < iSize-i-1; j++)
            {
                if(Arr[j] < Arr[j+1])
                {
                    temp=Arr[j];
                    Arr[j]=Arr[j+1];
                    Arr[j+1]=temp;
                    bFalg=true;
                }
            }
            if(bFalg == false)
            {
                break;
            }
        }
    }
    else
    {
        return;
    }
    Display();
}

template<class T>
void ArrayX<T>::SelectionSort(int No)
{
    int i = 0, j = 0, min_index = 0;
    T temp;
    
    if(No == 0)
    {
        for(i = 0; i <iSize; i++)
        {
            min_index = i;

            for(j = i + 1; j < iSize; j++)
            {
                if(Arr[j] < Arr[min_index])
                {
                    min_index = j;
                }
            }
            temp=Arr[i];
            Arr[i]=Arr[min_index];
            Arr[min_index]=temp;
        }
    }
    else if(No == 1)
    {
        for(i = 0; i <iSize; i++)
        {
            min_index = i;

            for(j = i + 1; j < iSize; j++)
            {
                if(Arr[j] > Arr[min_index])
                {
                    min_index = j;
                }
            }
            temp=Arr[i];
            Arr[i]=Arr[min_index];
            Arr[min_index]=temp;
        }
    }
    else
    {
        return;
    }
    Display();
}

template<class T>
void ArrayX<T>::InsertionSort()
{
    int i = 0, j = 0;
    T selected;

    for(i = 1; i < iSize ; i++)
    {
        for(j = i -1,selected=Arr[i];((j >= 0)  ||  (Arr[j] > selected));j--)
        {
            Arr[j+1]=Arr[i];
        }
        Arr[j + 1] = selected;
    }

    Display();
}

template <class T>
ArrayX<T>::~ArrayX()
{
    delete[] Arr;
}

























template<class T>
class NodeDCL
{
    public:
        T data;
        NodeDCL *next;
        NodeDCL *prev;

        NodeDCL()
        {
            data=0;
            next=NULL;
            prev=NULL;
        }

        NodeDCL(T X)
        {
            data=X;
            next=NULL;
            prev=NULL;
        }
};

template <class T>
class DoublyCL
{
public:
    NodeDCL<T> *First;
    NodeDCL<T> *Last;
    int iCount;

    DoublyCL();
    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

template <class T>
DoublyCL<T>::DoublyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void DoublyCL<T>::Display()
{
    NodeDCL<T> *Head=First, *Tail=Last;

    for(int iCnt=1; iCnt <= iCount; iCnt++)
    {
        std::cout<<"| "<<Head->data<<" |<=>";
        Head=Head->next;
    }
    std::cout<<"\n";
}

template <class T>
int DoublyCL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyCL<T>::InsertFirst(T No)
{
    NodeDCL<T> *newn=new NodeDCL<T>(No);

    if((First == NULL)  &&  (Last == NULL))
    {
        First=newn;
        Last=newn;
    }
    else
    {
        newn->next=First;
        First->prev=newn;
        First=newn;
    }
    First->prev=Last;
    Last->next=First;
    iCount++;
}

template <class T>
void DoublyCL<T>::InsertLast(T No)
{
    NodeDCL<T> *newn=new NodeDCL<T>(No), *temp=First;

    if((First == NULL)  &&  (Last == NULL))
    {
        First=newn;
        Last=newn;
    }
    else
    {
        newn->prev=Last;
        Last->next=newn;
        Last=newn;
    }
    First->prev=Last;
    Last->next=First;
    iCount++;
}

template <class T>
void DoublyCL<T>::InsertAtPos(T No, int iPos)
{
    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(No);
    }
    else
    {
        NodeDCL<T> *temp=First, *newn=new NodeDCL<T>(No);

        for(int iCnt = 1; iCnt < (iPos - 1); iCnt++)
        {
            temp = temp->next;
        }
        newn->next=temp->next;
        temp->next->prev=newn;
        temp->next=newn;
        newn->prev=temp;

        iCount++;
    }
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if((First == NULL)  &&  (Last == NULL))
    {
        return;
    }
    else if(First == Last)
    {
        delete First;
        First=NULL;
        Last=NULL;
    }
    else
    {
        First=First->next;
        delete First->prev;
        First->prev=Last;
        Last->next=First;
    }
    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if((First == NULL)  &&  (Last == NULL))
    {
        return;
    }
    else if(First == Last)
    {
        delete First;
        First=NULL;
        Last=NULL;
    }
    else
    {
        Last=Last->prev;
        delete Last->next;
        First->prev=Last;
        Last->next=First;
    }
    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
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
        NodeDCL<T> *temp=First;

        for(int iCnt = 1; iCnt < (iPos - 1); iCnt++)
        {
            temp = temp->next;
        }
        temp->next=temp->next->next;
        delete temp->next->prev;
        temp->next->prev=temp;
        iCount--;
    }
}



















template<class T>
class NodeLL

{
    public:
        T data;
        NodeLL
         *next;
        NodeLL
         *prev;

        NodeLL
        ()
        {
            data=0;
            next=NULL;
            prev=NULL;
        }

        NodeLL
        (T X)
        {
            data=X;
            next=NULL;
            prev=NULL;
        }
};

template <class T>
class DoublyLL
{
public:
    NodeLL
    <T> *First;
    int iCount;

    DoublyLL();
    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

template <class T>
DoublyLL<T>::DoublyLL()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void DoublyLL<T>::Display()
{
    NodeLL
    <T> *temp=First;

    std::cout<<"NULL->";
    while(temp != NULL)
    {
        std::cout<<"| "<<temp->data<<" |<->";
        temp=temp->next;
    }
    std::cout<<"NULL\n";
}

template <class T>
int DoublyLL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyLL<T>::InsertFirst(T No)
{
    NodeLL
    <T> *newn=new NodeLL
    <T>(No);

    if(First == NULL)
    {
        First=newn;
    }
    else
    {
        newn->next=First;
        First=newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>::InsertLast(T No)
{
    NodeLL
    <T> *newn=new NodeLL
    <T>(No), *temp=First;

    if(First == NULL)
    {
        First=newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp=temp->next;
        }
        newn->prev=temp;
        temp->next=newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>::InsertAtPos(T No, int iPos)
{
    int iLength=Count();

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == (iLength + 1))
    {
        InsertLast(No);
    }
    else
    {
        NodeLL
        <T> *newn=new NodeLL
        <T>(No), *temp=First;

        for(int iCnt = 1; iCnt < (iPos - 1); iCnt++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next->prev=newn;
        temp->next=newn;
        newn->prev=temp;

        iCount++;
    }
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if(First == NULL)
    {
        return ;
    }
    else if(First->next == NULL)
    {
        delete First;
        First=NULL;
    }
    else
    {
        First=First->next;
        delete First->prev;
        First->prev=NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
    if(First == NULL)
    {
        return ;
    }
    else if(First->next == NULL)
    {
        delete First;
        First=NULL;
    }
    else
    {
        NodeLL
        <T> *temp=First;

        while(temp->next->next != NULL)
        {
            temp=temp->next;
        }
        delete temp->next;
        temp->next=NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    int iLength=Count();

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iLength)
    {
        DeleteLast();
    }
    else
    {
        NodeLL
        <T> *temp=First;

        for(int iCnt = 1; iCnt < (iPos - 1); iCnt++)
        {
            temp=temp->next;
        }
        temp->next=temp->next->next;
        delete temp->next->prev;
        temp->next->prev=temp;

        iCount--;
    }
}





















template <class T>
class NodeCL
{
public:
    T data;
    NodeCL *next;

    NodeCL(T X)
    {
        data = X;
        next = NULL;
    }
};

template <class T>
class SinglyCL
{
public:
    NodeCL<T> *First;
    NodeCL<T> *Last;
    int iCount;

    SinglyCL();
    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

template <class T>
SinglyCL<T>::SinglyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void SinglyCL<T>::Display()
{
    NodeCL<T> *Head = First, *Tail = Last;
    std::cout << "NULL->";
    do
    {
        std::cout << "| " << Head->data << " |=>";
        Head = Head->next;
    } while (Head != Tail->next);
    std::cout << "NULL\n";
}

template <class T>
int SinglyCL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyCL<T>::InsertFirst(T No)
{
    NodeCL<T> *newn = new NodeCL<T>(No);

    if ((First == NULL) && (Last == NULL))
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
void SinglyCL<T>::InsertLast(T No)
{
    NodeCL<T> *newn = new NodeCL<T>(No), *temp = First;

    if ((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last->next = newn;
        Last = Last->next;
    }
    Last->next = First;
    iCount++;
}

template <class T>
void SinglyCL<T>::InsertAtPos(T No, int iPos)
{
    int iLength = Count();

    if (iPos == 1)
    {
        InsertFirst(No);
    }
    else if (iPos == iLength + 1)
    {
        InsertLast(No);
    }
    else
    {
        NodeCL<T> *newn = new NodeCL<T>(No), *temp = First;

        for (int iCnt = 1; iCnt < (iPos - 1); iCnt++)
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
    if ((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if (First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First->next;
        Last->next = First;
    }
    iCount--;
}

template <class T>
void SinglyCL<T>::DeleteLast()
{
    NodeCL<T> *temp = First;

    if ((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if (First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        while (temp->next->next != First)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = First;
        Last = temp;
    }
    iCount--;
}

template <class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{
    int iLength = Count();

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iLength)
    {
        DeleteLast();
    }
    else
    {
        NodeCL<T> *temp = First, *tempX = NULL;

        for (int iCnt = 1; iCnt < (iPos - 1); iCnt++)
        {
            temp = temp->next;
        }
        tempX = temp->next;
        temp->next = temp->next->next;
        delete tempX;

        iCount--;
    }
}















template <class T>
class NodeSLL
{
public:
    T data;
    NodeSLL *next;

    NodeSLL(T X)
    {
        data = X;
        next = NULL;
    }
};

template <class T>
class SinglyLL
{
public:
    NodeSLL<T> *First;
    int iCount;

    SinglyLL();
    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

template <class T>
SinglyLL<T>::SinglyLL() // SLL
{
    First = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL<T>::Display()  // SLL
{
    NodeSLL<T> *temp = First;

    while (temp != NULL)
    {
        std::cout << "| " << temp->data << " |->";
        temp = temp->next;
    }
    std::cout << "NULL\n";
}

template <class T>
int SinglyLL<T>::Count()    // SLL
{
    return iCount;
}

template <class T>
void SinglyLL<T>::InsertFirst(T No)     // SLL
{
    NodeSLL<T> *newn = new NodeSLL<T>(No);

    if (First != NULL)
    {
        newn->next = First;
    }
    First = newn;
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertLast(T No)      // SLL
{
    NodeSLL<T> *newn = new NodeSLL<T>(No);

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        NodeSLL<T> *temp=First;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T No, int iPos)   // SLL
{
    int iLength=Count();

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iLength + 1)
    {
        InsertLast(No);
    }
    else
    {
        NodeSLL<T> *newn=new NodeSLL<T>(No),*temp=First;

        for(int iCnt = 1; iCnt < (iPos - 1); iCnt++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;
        iCount++;
    }
}

template <class T>
void SinglyLL<T>::DeleteFirst()     // SLL
{
    NodeSLL<T> *temp = First;

    if (First == NULL)
    {
        return;
    }
    else if (First->next == NULL)
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
void SinglyLL<T>::DeleteLast()      // SLL
{
    NodeSLL<T> *temp = First;

    if (First == NULL)
    {
        return;
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)     // SLL
{
    int iLength=Count();

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iLength)
    {
        DeleteLast();
    }
    else
    {
        NodeSLL<T> *temp=First,*tempX=NULL;

        for(int iCnt = 1; iCnt < (iPos - 1); iCnt++)
        {
            temp=temp->next;
        }
        tempX=temp->next;
        temp->next=temp->next->next;
        delete tempX;

        iCount--;
    }
}
