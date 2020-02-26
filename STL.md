# 1.容器

## 1.1.vector

```cpp
vector<vector<int>> v;

v.size();		//返回行数

v[0].size();	//返回列数
```



`decltype` 关键字是为了解决 auto 关键字只能对变量进行类型推导的缺陷而出现的。

异或能解决一类数据中找到不重复的值

```c++
int singleNumber(vector<int>& nums) {
    if(nums.empty()) return 0;
    int len = nums.size();
    int temp = 0;
    for(int i = 0 ; i < len ; i++){
        temp ^=nums[i];
    }
    return temp;
}
```
# 委托构造函数

```c++
class Base {
public:
    int value1;
    int value2;
    Base() {
        value1 = 1;
    }
    Base(int value) : Base() {  // 委托 Base() 构造函数
        value2 = 2;
    }
};
```

# 继承构造

在继承体系中，如果派生类想要使用基类的构造函数，需要在构造函数中显式声明。 
 假若基类拥有为数众多的不同版本的构造函数，这样，在派生类中得写很多对应的“透传”构造函数。如下：

```c++
struct A
{
  A(int i) {}
  A(double d,int i){}
  A(float f,int i,const char* c){}
  //...等等系列的构造函数版本
}；
struct B:A
{
  B(int i):A(i){}
  B(double d,int i):A(d,i){}
  B(folat f,int i,const char* c):A(f,i,e){}
  //......等等好多个和基类构造函数对应的构造函数
}；
```

C++11的继承构造：

```c++
struct A
{
  A(int i) {}
  A(double d,int i){}
  A(float f,int i,const char* c){}
  //...等等系列的构造函数版本
}；
struct B:A
{
  using A::A;
  //关于基类各构造函数的继承一句话搞定
  //......
}；
```

# lambda

```
int a = 0;
auto f = [=] { return a; };

a+=1;

cout << f() << endl;       //输出0

int a = 0;
auto f = [&a] { return a; };

a+=1;

cout << f() <<endl;       //输出1
```

# 2.智能指针

对于编译器来说，智能指针实际上是一个栈对象，并非指针类型，在栈对象生命期即将结束时，智能指针通过析构函数释放有它管理的堆内存。所有智能指针都重载了“operator->”操作符，直接返回对象的引用，用以操作对象。访问智能指针原来的方法则使用“.”操作符。

访问智能指针包含的裸指针则可以用 get() 函数。由于智能指针是一个对象，所以if (my_smart_object)永远为真，要判断智能指针的裸指针是否为空，需要这样判断：if (my_smart_object.get())。

## 2.1	auto_ptr

**采用管理权转移，拷贝时会导致对象悬空，设计有缺陷，不建议使用**

```c++
//auto_ptr<int> p;//初始化为NULL
//  错误写法  auto_ptr<int> p = new int(123);
auto_ptr<int> p(new int(123));
cout << *p;
```

```c++
    auto_ptr<int> p(new int(123));
    auto_ptr<int> p1(p);//将p的使用权转给p1,p1已经指向nullptr无法正常访问
//    cout << *p << endl;
    cout << *p1 << endl;
```

## 2.2	unique_ptr

**特点：防拷贝，简单粗暴，建议使用**

**缺点：不能拷贝，可以转让**

```c++
unique_ptr<int> p(new int(123));
*p = 7;
cout << *p<< endl;
```

```c++
unique_ptr<string> upt1=std::move(upt);  //控制权限转移
if(upt.get()!=nullptr)					//判空操作更安全
{
	//do something
}
```



## 2.3	shared_ptr

 shared_ptr的原理：通过引用计数的方式来实现多个shared_ptr对象之间共享资源。

1. shared_ptr在其内部，给每个资源都维护了一份计数，用来记录该份资源被几个对象共享。
2. 在对象被销毁时(也就是析构函数调用)，就说明自己不使用该资源了，对象的引用计数减一。
3. 如果引用计数是0，就说明自己是最后一个使用该资源的对象，必须释放该资源。
4. 如果不是0，就说明除了自己还有其他对象在使用该份资源，不能释放该资源，否则其他对象就成野指针了。

```c++
shared_ptr<int> p1(new int(123));
shared_ptr<int> p2(p1);
shared_ptr<int> p3(p2);
cout << *p1 << " " << p1.use_count() << endl;
cout << *p2 << " " << p2.use_count() << endl;
```
循环引用

循坏引用分析：

1. node1和node2两个智能指针对象指向两个结点，引用计数变成1，我们不需要手动delete。
2. node1和_next指向node2，node2的_prev还指向下一个结点。但是_prev还指向上一个节点。
3. node1和node2析构，引用计数减一，但是_next还指向下一个节点。但是_prev还指向上一个节点。
4. 也就是说_next析构了，node2就释放了。
5. 也就是说_prev析构了，node1就释放了。
6. 但是_next属于node成员，node1释放了，_next才会析构，而node1由_prev管理，_prev属于node2成员，所以这就叫循环引用，谁也不会释放。

```c++
#include<memory>
#include <iostream>

using namespace std;

struct ListNode {
    int _data;
    shared_ptr<ListNode> _prev;
    shared_ptr<ListNode> _next;

    ~ListNode() {
        cout << "~ListNode()" << endl;
    }

};

int main() {
    shared_ptr<ListNode> node1(new ListNode);
    shared_ptr<ListNode> node2(new ListNode);
    cout << node1.use_count() << endl;
    cout << node2.use_count() << endl;

    node1->_next = node2;
    node2->_prev = node1;
    cout << node1.use_count() << endl;
    cout << node2.use_count() << endl;
    return 0;
}
```

**解决方案：在引用计数的场景下，把节点中的_prev和_next改成weak_ptr就可以了**

**原理：node1->_next = node2;和node2->_prev = node1;时weak_ptr的_next和_prev不会增加 node1和node2的引用计数。** 

## 2.4	weak_ptr

weak_ptr 被设计为与 shared_ptr 共同工作，可以从一个 shared_ptr 或者另一个 weak_ptr 对象构造而来。weak_ptr 是为了配合 shared_ptr 而引入的一种智能指针，它更像是 shared_ptr 的一个助手而不是智能指针，因为它不具有普通指针的行为，没有重载 operator* 和 operator-> ，因此取名为 weak，表明其是功能较弱的智能指针。它的最大作用在于协助 shared_ptr 工作，可获得资源的观测权，像旁观者那样观测资源的使用情况。观察者意味着 weak_ptr 只对 shared_ptr 进行引用，而不改变其引用计数，当被观察的 shared_ptr 失效后，相应的 weak_ptr 也相应失效。

```c++
#include<memory>
#include <iostream>

using namespace std;

struct ListNode {
    int _data;
    weak_ptr<ListNode> _prev;
    weak_ptr<ListNode> _next;

~ListNode() {
    cout << "~ListNode()" << endl;
}

};

int main() {
    shared_ptr<ListNode> node1(new ListNode);
    shared_ptr<ListNode> node2(new ListNode);
    cout << node1.use_count() << endl;
    cout << node2.use_count() << endl;

    node1->_next = node2;
    node2->_prev = node1;
    cout << node1.use_count() << endl;
    cout << node2.use_count() << endl;
    return 0;
}
```

下面给出几个使用指南。
（1）如果程序要使用多个指向同一个对象的指针，应选择shared_ptr。这样的情况包括：
（a）的元素和最小的元素；
（b）两个对象都包含指向第三个对象的指针；
（c）STL容器包含指针。很多STL算法都支持复制和赋值操作，这些操作可用于shared_ptr，但不能用于unique_ptr（编译器发出warning）和auto_ptr（行为不确定）。如果你的编译器没有提供shared_ptr，可使用Boost库提供的shared_ptr