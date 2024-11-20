#include"GenericDS.h"
using namespace  std;

int main()
{
    SinglyCL<int> obj;
    obj.InsertFirst(10);
    obj.InsertFirst(9);
    obj.InsertFirst(8);
    obj.InsertFirst(7);
    obj.InsertFirst(6);
    obj.InsertFirst(5);
    obj.InsertFirst(4);
    obj.InsertFirst(3);
    obj.InsertFirst(2);
    obj.InsertFirst(1);


    obj.Display();
    cout<<endl<<endl;

    SinglyCL<int> obj2;

    obj2.InsertLast(1);
    obj2.InsertLast(2);
    obj2.InsertLast(3);
    obj2.InsertLast(4);
    obj2.InsertLast(5);
    obj2.InsertLast(6);
    obj2.InsertLast(7);
    obj2.InsertLast(8);
    obj2.InsertLast(9);
    obj2.InsertLast(10);

    cout<<"Total number of Nodes are :"<<obj2.Count()<<endl;

    obj2.Display();





    return 0;
}
