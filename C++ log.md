# C++ Log

## C++是一个复合集合

c++由c语言演变而来，所以c语言也是c++的一个子集，c++也拥有面向对象与泛型编程的特点，综合来看，可由c++由以下部分组成

1. c语言
2. 基于对象(像我这样的菜鸡一直在写这样的代码)
3. 面向对象
4. STL(泛型编程)

<br/>

## C

### 数据

#### 基本数据类型

1. 整型

   - 字符
   - 短整型
   - 整型
   - 长整型

2. 浮点型

3. 指针

   每个内存位置都由地址唯一确定并引用，指针只是地址的另一个名字罢了

4. 聚合类型

#### static

当它用于函数定义时，或用于代码块之外的变量声明时，static关键字用于修改标识符的链接属性，从external改为internal，但标识符的存储类型和作用域不受影响，用这种方式声明的函数或变量只能在它们的源文件中访问

当它用于代码块内部的变量声明时，static关键字用于修改变量的存储类型，从自动变量变为静态变量，但变量的链接属性和作用域不受影响，用这种方式声明的变量在程序执行之前创建，并在程序的整个执行期间一直存在，而不是每次在代码块开始执行时创建，在代码块执行完毕后销毁

#### 变量的三个属性

变量的作用域、链接属性、和存储属性决定了一个变量可以在什么地方使用和它的值能保持多久

| 变量类型 | 声明的位置     | 是否存于堆栈 | 作用域           | 如果声明为static                           |
| -------- | -------------- | ------------ | ---------------- | ------------------------------------------ |
| 全局     | 所有代码块之外 | 否           | 从声明处到文件尾 | 不允许从其他文件访问                       |
| 局部     | 代码块起始处   | 是           | 整个代码块       | 变量不存储于堆栈中，值在程序执行期一直保持 |
| 形式参数 | 函数头部       | 是           | 整个函数         | 不允许                                     |

<br/>

### 指针

计算机内存中的每个位置由一个独一无二的地址标示，内存中的每个位置都包含一个值

利用地址操作那个位置的值并不可行，所以通过编译器的帮助，利用变量名来访问内存的位置，这些变量给我们一种更方便的方法记住地址，**但是硬件仍然通过地址访问内存位置**

指针变量可以作为左值，并不是因为它们是指针，而是因为它们是变量



## OOP & OBP

### OOP与OBP的区别

OBP编程没有继承的概念，同时也没有多态的概念，并没有从某类派生出子类，OBP具有提高了代码复用，使用多态使开发者可以使用同一个接口实现达到不同的函数实现

### 什么是Class

class是c++用来实现OOP封装、继承、多态的核心机制，粗略的讲class便是数据与其相关算法的集合，使用class的概念对数据进行封装，只需要提供相应的接口供使用者使用，只要接口不变，内部内容可以任意的改动而不影响使用，而且不暴露内部实现及数据，保证了使用的安全性

### Class的组成分类

1. data member
   * static data member
   * non static data member
2. member function
   - static member function
   - non static member function
   - virtual function

#### 特殊的成员函数

- 构造函数
- 拷贝构造函数
- 拷贝赋值运算符
- 析构函数
- 移动构造函数
- 移动赋值运算符

### 构造函数

#### 什么是构造函数

一种特殊的函数，主要用来在创建对象时初始化对象，即为对象成员变量赋初始值

#### 构造函数函数体内执行初始化操作与在初始值列表中初始化成员变量有何区别？

若是没有初始值列表，那么编译器会为成员执行默认初始化，举例来说，假如定义的类中有一个string成员变量data，你想为让string的值为0，即string(0)，如果不在初始值列表中初始化，那么编译器实际会先执行string成员的默认构造函数，然后生成一个临时对象temp=string(0)，再调用赋值运算符将temp赋值给成员变量，可以看到做了一些多余的工作，产生了不必要的临时对象，因为需要的仅仅是初始化而已。如果改用在初始值列表中初始化data,即data(0),那么data便会直接调用string的构造函数初始化，即data.string(0)，没有产生多余的临时对象，也省去了不必要的函数调用。

#### 什么时候使用初始值列表是必要的？

1. 初始化reference member，因为引用必须要有宿主才能存在，所以必须初始化
2. const member,const对象只能初始化不能赋值
3. 当调用base class的constructor，并且拥有一组参数
4. 当调用member class的constructor，并且拥有一组参数

#### 编译器何时会生成默认构造函数？做了什么事情？

1. 含有类对象数据成员，且类型有默认构造函数

2. 基类带有默认构造函数的派生类

   如果设计者定义了多个构造函数，编译器不会重新定义一个合成默认构造函数，而是把合成默认构造函数的内容插入到每一个构造函数中去

3. 带有虚函数的类

   1)类本身定义了自己的虚函数

   2)类从继承体系中继承了虚函数

   需要的原因是因为含有虚函数的类对象都有一个虚表指针vptr，编译器需要对vptr设置默认初值以满足虚函数机制的正确运行，编译器会把这个设置初值的操作放在默认构造函数中。

   如果设计者没有定义任何一个默认构造函数，则编译器会合成一个默认构造函数完成工作，否则，编译器将在每一个构造函数中扩展代码完成必要的工作。

4. 带有一个Virtual Base Class的Class

   因为必须使virtual base class在其每一个derived class object中的位置能够于执行期准备妥当

   

### Class控制拷贝的操作

三是指拷贝构造、拷贝赋值运算符、析构函数，而后新标准添加了移动语义，所以增加移动构造与移动赋值运算符，它们对应相应的拷贝操作，但是区别是进行“窃取”而不是拷贝。

1. 拷贝构造函数
   - 注意第一个参数为引用类型，防止无限递归调用
   - 多余的参数必须有默认实参
2. 拷贝赋值运算符
   - 防止自赋值操作，一定得增加自赋值检查，否则会让别人觉得代码质量差
   - 对于含有指针的类需要多加注意，若是指向堆上的数据，则应该先释放相应的资源再重新对指针赋值
3. 析构函数
4. 移动构造函数
   - 第一个参数为**右值引用**，防止无限递归调用
   - 多余的参数必须有默认实参
   - 如果不抛出任何异常，应标记为noexcept
5. 移动赋值运算符
   - 如果不抛出任何异常，应该标记为noexcept
   - 自赋值检查
   - 释放拥有的资源
   - 接手别的资源

### member function应当注意的点

1. const成员函数，根据是否改变对象的状态决定添加const,const成员函数语法上是在参数列表后添加const，实际修饰this指针，也就是调用这个函数的对象
   - const对象只能调用const成员函数，不能调用非const成员函数
   - 非const对象可以调用const成员函数，也可以调用非const成员函数
2. 参数应该是传值还是传引用
   - 一般来将基本类型传值即可，对于一些自定义类型一般或传值成本较高的对象传引用
3. 参数是否应该用const修饰，采用传引用的方式，若不改变参数的状态，则应该用const修饰
4. 返回类型应该是传值还是传引用
   - 局部变量一定不能以传引用的方式传回
   - 一些自定义类型和传值成本高的类型应该以传引用方式返回值

### 面向对象-继承

多继承暂且不考虑，只考虑单继承问题，单继承时子类对象包含父类对象成员

1. 单继承
2. 多继承(会出现菱形继承问题)

#### 继承方式

1. public继承
2. protected继承
3. private继承

#### 三种继承方式的意义？

public继承可以理解为“is a”，可以用派生类的引用来调用基类，比如猪是哺乳动物，哺乳动物能做的猪都可以做。private是子类使的实现使用了基类的方法，但是子类并不是父类，语义上可以理解为“根据某物实现出”protected不建议使用

#### public 、protected、private标号的访问范围

|   标号    | 本类中的函数 | 子类的函数 | 友元函数 | 本类对象 |
| :-------: | ------------ | ---------- | -------- | -------- |
|  public   | 可以         | 可以       | 可以     | 可以     |
| protected | 可以         | 可以       | 可以     | 不可以   |
|  private  | 可以         | 不可以     | 可以     | 不可以   |

#### 三种继承方式的访问权限

|   继承方式    | 基类的public成员  | 基类的protected成员 | 基类的private成员 | 继承引起的访问控制关系变化             |
| :-----------: | ----------------- | ------------------- | ----------------- | -------------------------------------- |
|  public继承   | 仍为public成员    | 仍未protected成员   | 不可见            | 基类的非私有成员访问属性不变           |
| protected继承 | 变为protected成员 | 变为protected成员   | 不可见            | 基类的非私有成员都成为子类的保护成员   |
|  private继承  | 变为private成员   | 变为private成员     | 不可见            | 基类中的非私有成员都成为子类的私有成员 |

#### 继承下的构造函数与析构函数执行顺序是怎样的

1. 构造函数遵循由内而外，先执行父类的构造函数，而后执行子类的构造函数
2. 析构函数遵循由外而内，先执行子类的构造函数，而后执行父类的构造函数

### 面向对象-多态

#### 什么是多态

多态字面意思可以理解为多种形态，可以简单定义为“一个接口，多种方法”，程序在运行时才决定调用的函数

#### 多态的分类

1. 静态多态
2. 动态多态

#### 静态多态

也称为编译期多态，编译器在编译期间完成的，编译器根据函数实参的类型推断出要调用哪个函数，如果有对应的函数就调用该函数，否则出现编译错误

##### 实现方式

1. 函数重载

   - 普通函数的重载
   - 成员函数的重载

   函数重载可以理解为同一个名字在不同上下文中具有不同的意思，这个上下文就是参数列表，实际实现方式是c++编译器对其函数名称进行加工，产生一个独一无二的新函数名称

2. 函数模板的使用

   函数模板是通用的函数描述，使用泛型定义函数，通过将类型作为参数传递给模板，可使编译器生成该类型的函数

#### 动态多态

又称动态绑定，即运行时的多态，在程序执行期间根据所引用对象的实际类型调用相应的方法

##### 两个重要概念

- 静态类型：对象声明时的类型，编译时确定
- 动态类型：目前所指对象的类型，运行时确定

##### 动态多态实现的方式

继承+虚函数

<br/>

##### 动态绑定的条件

1. 指针或引用调用

2. 虚函数

3. 向上转型

   调用形式：(*p->vptr[n])(p)

<br/>

##### 虚表与虚表指针如何配合实现动态调用虚函数

如果一个类含有虚函数或一个类继承自一个含有虚函数的基类，那么编译器便为这样的类都分配一个虚函数表，该类的每个对象都包含一个编译器帮助生成的虚表指针，虚表指针指向虚表，该表是一个指针数组，指针值为该类虚函数的地址。派生类继承基类的虚函数后，若不将其覆写(overwrite)那么其虚表中的相应位置的指针便与基类的虚表中相应位置的指针内容相同，即其指向的虚函数是同一个虚函数。若将其覆写，便会使虚表中相应位置的指针指向覆写的虚函数。通过基类的引用或指针调用，根据运行时确定的实际指向或引用类型确定调用基类的虚函数或派生类的虚函数。

<br/>

##### 派生类虚函数表的组成

- 首先拷贝基类的虚函数表
- 如果派生类覆写了基类的某个虚函数，便用派生类的虚函数替换虚表同位置的基类虚函数
- 如果派生类又新定义了自己的虚函数，则将其填充在虚表中

##### 构造函数是否可以为虚函数？

不可以，因为生成对象的过程是首先分配一片内存，然后调用构造函数，若虚构函数是虚函数，则需要虚表指针找到虚函数表的位置，但是显然一片空内存无法定位虚函数表，也就无法调用虚函数。

<br/>

##### 析构函数能否是虚函数

可以，通过基类指针销毁对象时，如果析构函数不为虚函数，可能会导致出错，因为若该指针实际指向一个派生类对象，但因为析构函数不是虚函数，那么便不会触发多态，只会调用基类的析构函数导致出错。

<br/>

##  泛型编程-STL

### 泛型编程与OO的区别

OO通过class将数据与函数实现集中起来，泛型编程则是采用数据与函数实现分离的手法

### 模板

#### 模板分类

1. 函数模板
2. 成员模板
3. 类模板
   - 泛化
   - 偏特化
     - 个数偏特化
     - 范围偏特化
   - 全特化

#### Variadic Templates是什么

模板参数数量不定的一种表示形式

<br/>

#### ...语法不同上下文下的意义

1. 用于template parameters，就是模板函数包
2. 用于function parameter types，就是函数类型包
3. 用于function parameters，就是函数参数包

OP与OBP<br/>

#### Variadic Templates示例

```c++
void print()
{
    
}

template <typename T,typename... Types>
void print(const T& firstArg,const Types&... args)
{
    cout<<firstArg<<endl;
    print(args...);
}
```

#### 标准库中的Variadic Templates

```c++
template<typename... Values> class tuple;
template<> class tuple<> {};
```

```c++
template<typename Head,typename... Tail>
class tuple<Head,Tail...>
    :private tuple<Tail...>
    {
        typedef tuple<Tail...> inherited;
        public:
        	tuple(){}
        	tuple(Head v,Tail... vtail)
                :m_head(v),inherited(vtail...){}
        
        typename Head::type head() {return m_head;}
		inherited& tail() {return *this;}
        
        protected:
        	Head m_head;
    };
```







### 容器、算法、迭代器的关系

算法看不到容器，对其一无所指，所以它需要的一切信息都必须从迭代器取得，而迭代器必须能够回答算法的提问，才能够搭配该算法的所有操作。迭代器充当了胶水的作用，用来粘合算法与容器。

### 容器

#### 容器分类

1. 序列容器（底层实现为数组与链表）
   1. Array
   2. Vector
   3. Deque
   4. List
   5. ForwardList
2. 关联容器(底层实现为红黑树)
   1. Set
   2. Multiset
   3. Map
   4. Multimap
3. 无序关联容器(底层实现为hash table)
   1. Unordered set
   2. Unordered Multiset
   3. Unordered map
   4. Unordered Multimap

### 迭代器

#### 迭代器的分类

1. input_iterator_tag

1. forward_iterator_tag
2. bidirectional_iterator_tag
3. random_access_iterator_tag
4. output_iterator_tag

###　为什么需要iterator_category

因为算法对容器一无所知，所以需要通过将不同的迭代器种类实现为不同的class的方式传递给算法，通过函数重载的方式处理不同类别的迭代器

### iterator_category和type_traits对算法的影响

算法会根据迭代器种类调用相应的泛化版本与重载版本，当然也会根据所操作对象的特性选择不同的操作，举个例子来说就是假如我们我们目前有一个处理食材的函数，食材有多种种类，我们假设分为三类：肉类、蔬菜类、蛋类，现实生活中我们肯定不会对所有的食材使用相同的处理方式，也是会根据食材的种类进行不同的处理，当然可能也会针对特定的食材进行特定的处理

#### 为什么需要Iterator Traits

Iterator Traits用以分离class iterators和non-class iterators

标准库代码如下：

```c++
// 泛化版本
template <class I>
 struct iterator_traits {
        typedef typename I::iterator_category            iterator_category;
        typedef typename I::value_type                         value_type;
        typedef typename I::difference_type                difference_type;
        typedef typename I::pointer                                  pointer;
        typedef typename I::reference                              reference;
    };

// 针对指针的偏特化版本
template <class T>
 struct iterator_traits<T*> {
     typedef random_access_iterator_tag          iterator_category;
     typedef T                                                                   value_type;
     typedef ptrdiff_t                                                     difference_type;
     typedef T*                                                                  pointer;
     typedef T&                                                                 reference;
 };

// 针对常量指针的偏特化版本
template <class T>
 struct iterator_traits<const T*> {
      typedef random_access_iterator_tag          iterator_category;
     typedef T                                                                   value_type;
     typedef ptrdiff_t                                                     difference_type;
     typedef T*                                                                  pointer;
     typedef T&                                                                 reference;
 }


```



### 函数适配器

#### 什么是函数适配器

一般也是一个模板类，通过辅助函数进行调用，对待修饰函数或者函数对象进行一定的处理修饰，返回类型为被修饰对象的返回类型

#### 怎么样可以成为函数适配器



## C++11新特性

### decltype

- 推断返回类型
- 元编程
- pass the type of lambda

### lambda

形式：

```c++
[...](...) mutable  throwSpec  ->retType {...}
```

```c++
// lambda的底层实现其实就是一个类对象,往函数对象那一套想就对了
int tobefound = 5;
auto lambda1 = [tobefound] (int val) {return val == tobefound;};

//   这个类可以看做是lambda1的底层实现方式
class UnnamedLocalFunction
{
    int localVar;
    public:
    	UnNameLocalFunction(int var) :localVar(var) {}
    	bool operator() (int val)
        {return val == localVar;}
};

UnNamedLocalFunction lambda2(tobefound);

bool b1 = lambda1(5);
bool b2 = lambda2(5);
```

### explicit

- explicit for ctors taking one argument

  避免编译器做隐式转换

- explicit for more than one argument





