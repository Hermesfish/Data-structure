为了便于书写代码，我采用的是带附加节点的单链表。

首先用struct定义LinkNode类
```c++
template <class T>
struct LinkNode{
      T data;     //定义数据
      LinkNode<T>* link;      //定义指针
      LinkNode(LinkNode<T>* ptr = NULL)   {link = ptr;}     //仅初始化指针成员的构造函数
      LinkNode(const T& item, LinkNode<T>* ptr = NULL){     //初始化数据成员和指针成员的构造函数
              data = item;
              link = ptr;
      }
}；
```
定义链表类及其主要函数
```c++
template <class T>
class List{
      protected:
          LinkNode<T>* first;   //first指针
      public:
          List(){first = new LinkNode<T>;}    //构造函数
          
          List(const T& x){first = new LinkNode<T>(x);}   //带数据成员的first指针的构造函数
          
          List(List<T>& L);     //拷贝构造函数
          
          ~List(){MakeEmpty();}   //析构函数
          
          void MakeEmpty();     //将链表置为空表
          
          int Length() const;   //计算链表的长度
          
          LinkNode<T>* getHead() const{return first;}     //返回头指针
          
          LinkNode<T>* Search(T x);     //搜索值为x的元素，并且返回地址
          
          LinkNOde<T>* Locate(int i);     //搜索第i个元素的地址
          
          bool GetData(int i, T& x);        
          
          bool Insert(int i, T& x);       //将x插在表中第i个元素后
          
          bool Remove(int i, T& x);       //删除第i个元素
          
          bool isEmpty() const{
                  return fisrt->link == NULL? true : false;
          }
          
          bool isFull() const   {return false;}
          
          void Sort();
          
          void Input();
          
          void Output();
          
          Linst<T>& operator=(List<T>& L);
 };
 ```
 先写几个重要函数
 - 拷贝函数
 ```
 template <class T>
 List<T>::List(List<T>& L){
            T data;
            LinkNode<T>* srcptr = L.getHead();
            LinkNode<T>* destptr = fisrt = new LinkNode<T>;
            while(srcptr->link != NULL){
                        value = srcptr->link->data;
                        destptr->link = new LinkNode<T>(value);
                        destptr = destptr->link;
                        srcptr = srcptr->link;
             }
             destptr->link = NULL;
}
```

 
