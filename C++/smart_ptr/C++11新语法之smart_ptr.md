# C++11新语法之smart pointer

## 智能指针由来

智能指针主要用于管理在**堆上分配的内存**，它将普通的指针封装为一个栈对象。当栈对象的生存周期结束后，会在析构函数中释放掉申请的内存，从而防止内存泄漏。C++11中引入了**unique_ptr**/**shared_ptr**/**weak_ptr**

## auto_ptr

C++17已不支持。

![image-20220406215814988](https://github.com/qbaobao/MyAwesomeCode/blob/master/C%2B%2B/smart_ptr/image-20220406215814988.png)

最简单的智能指针实现。实现参见<memory>。auto_ptr使用时，需要注意指针权限的转移和指针的生命周期管理。

```c++
int main() {
	auto_ptr<int> p1(new int(0)); // p1地址0x00DA4CA0
    cout << "0. p1: 0x" << p1.get() << endl;
	auto_ptr<int> p2(p1); // p2地址0x00DA4CA0，指针权限发生转移。此时p1为空指针
	auto_ptr<int> p3(p1); // p3何p1一样，为空指针
	cout << "1. p1: 0x" << p1.get() << endl;
	cout << "2. p2: 0x" << p2.get() << endl;
	cout << "3. p3: 0x" << p3.get() << endl;
	return 0;
}
```

![image-20220406220443532](https://github.com/qbaobao/MyAwesomeCode/blob/master/C%2B%2B/smart_ptr/image-20220406220443532.png)

## unique_ptr

为了解决auto_ptr的缺陷，C++11推出了unique_ptr。**unique_ptr不允许通过拷贝或者赋值的形式转移权限**（删除了拷贝构造函数和赋值操作符）。在一定程度上保障了指针管理者的唯一性。

```c++
/* C++源码实现如下，详情参见<memory> */
unique_ptr(const unique_ptr&) = delete;
unique_ptr& operator=(const unique_ptr&) = delete;
```

如果要实现unique_ptr权限转移，需要使用**右值构造函数/右值赋值运算符**。此时会发生指针权限的转移。

```c++
/* 赋值操作符 */
unique_ptr& operator=(unique_ptr&& _Right) noexcept {
    if (this != _STD addressof(_Right)) {
        reset(_Right.release()); //释放右值管理的指针的权限
        _Mypair._Get_first() = _STD forward<_Dx>(_Right._Mypair._Get_first()); //接管指针权限
    }
    return *this;
}

/* 右值构造函数 */
unique_ptr(unique_ptr&& _Right) noexcept
    : _Mypair(_One_then_variadic_args_t(), _STD forward<_Dx>(_Right.get_deleter()), _Right.release()) {}
```

unique_ptr使用方法举例：

```c++
int main() {
	unique_ptr<int> p1(new int(0));
	cout << "0. p1: 0x" << p1.get() << endl;
	// unique_ptr<int> p2(p1); ERR
	unique_ptr<int> p2(std::move(p1)); // p2接管指针，p1指向空
	cout << "1. p1: 0x" << p1.get() << endl;
	cout << "2. p2: 0x" << p2.get() << endl;
    unique_ptr<int> p3 = std::make_unique<int>(123);
    /* 创建一个指向包含3个元素的数组的智能指针 */
    unique_ptr<int[]> p4 = std::make_unique<int[]>(3);
	return 0;
}
```

![image-20220406221328795](https://github.com/qbaobao/MyAwesomeCode/blob/master/C%2B%2B/smart_ptr/image-20220406221328795.png)

上图中，比较规范的做法是采用**make_unique**创建unique智能指针。

## shared_ptr

与unique_ptr相比，shared_ptr更灵活，它允许多个智能指针对象管理同一个指针资源。shared_ptr有一个计数器，用于记录有多少个shared_ptr对象在共享这个资源。当构造一个指向此资源的shared_ptr，计数加1。当析构一个指向此资源的shared_ptr时，计数减1。原理如下：

```c++
~shared_ptr() noexcept { // release resource
    this->_Decref();
}
shared_ptr(const shared_ptr& _Other) noexcept { // construct shared_ptr object that owns same resource as _Other
    this->_Copy_construct_from(_Other); // _Copy_construct_from调用基类的_Incref函数，完成原子加
}

void _Decref() noexcept { // decrement use count
    if (_MT_DECR(_Uses) == 0) { // 判断引用计数是否为0
        _Destroy();
        _Decwref();
    }
}
void _Incref() noexcept { // increment use count
    _MT_INCR(_Uses); // 引用计数加1
}

/* _InterlockedDecrement为系统函数，执行多线程原子减 */
#define _MT_DECR(x) _INTRIN_ACQ_REL(_InterlockedDecrement)(reinterpret_cast<volatile long*>(&x))
/* _InterlockedDecrement为系统函数，执行多线程原子加 */
#define _MT_INCR(x) _INTRIN_RELAXED(_InterlockedIncrement)(reinterpret_cast<volatile long*>(&x))

```

shared_ptr使用方法举例：

```c++
int main() {
	shared_ptr<int> p1 = make_shared<int>(2);
	cout << "0. use_count: " << p1.use_count() << endl;
	shared_ptr<int> p2(p1);
	cout << "1. use_count: " << p1.use_count() << endl;
	{
		shared_ptr<int> p3(p1);
		cout << "2. use_count: " << p1.use_count() << endl;
	}
	shared_ptr<int> p4(std::move(p1)); // p1释放管理权限。只剩下p2和p4共享资源
	cout << "3. p1 use_count: " << p1.use_count() << endl;
	cout << "3. p2 use_count: " << p2.use_count() << endl;
	cout << "3. p4 use_count: " << p4.use_count() << endl;
	return 0;
}
```

![image-20220406224223798](https://github.com/qbaobao/MyAwesomeCode/blob/master/C%2B%2B/smart_ptr/image-20220406224223798.png)

## weak_ptr

weak_ptr不接管资源的权限，不控制资源的生命周期。只是提供一种访问资源的方式。

> Special-case smart pointer for use in conjunction with `shared_ptr`. A `weak_ptr` provides access to an object that is owned by one or more `shared_ptr` instances, but does not participate in reference counting. Use when you want to observe an object, but do not require it to remain alive. Required in some cases to break circular references between `shared_ptr` instances. 
>
> // 摘抄自[微软官方文档]([Smart pointers (Modern C++) | Microsoft Docs](https://docs.microsoft.com/en-us/cpp/cpp/smart-pointers-modern-cpp?view=msvc-170))。

在使用weak_ptr时，我们需要确保资源是存在的，防止引起系统异常。我们可以使用`expired()`方法检测资源是否存在。

```c++
int main() {
	shared_ptr<int> p1 = make_shared<int>(2);
	cout << "0. use_count: " << p1.use_count() << endl;
	weak_ptr<int> p2(p1);
	cout << "1. use_count: " << p1.use_count() << endl;

	if (p2.expired()) {
		cout << "2. not exit" << endl;
	}
	{
		shared_ptr<int> p3 = make_shared<int>(2);
		p2 = p3;
	}
	if (p2.expired()) {
		cout << "3. not exit" << endl;
	}
	return 0;
}
```

![image-20220406225621986](https://github.com/qbaobao/MyAwesomeCode/blob/master/C%2B%2B/smart_ptr/image-20220406225621986.png)

## 智能指针使用限制

1. 软件成本

## 智能指针使用注意事项

1. 使用指针智能后，不建议再操作原始裸指针。否则会引入一些隐性的问题。

   ```c++
   class MyClass{
   public:
       MyClass(int other) : other(other) {}
       int GetOther() { return other; }
   private:
       int other;
   };
   MyClass* p = new MyClass(99);
   shared_ptr<MyClass> pp(p);
   delete p;
   pp->GetOther(); // ERR访问空指针，造成系统异常
   ```

2. 使用shared_ptr，要注意资源间权限的相互引用造成的资源泄露。

   ```c++
   class MyClassB;
   class MyClassA {
   public:
   	~MyClassA() { cout << "A end\n"; }
   	shared_ptr<MyClassB> m_share;
   };
   
   class MyClassB {
   public:
   	~MyClassB() { cout << "B end\n"; }
   	shared_ptr<MyClassA> m_share;
   };
   
   int main() {
   	shared_ptr<MyClassA> ppA = make_shared<MyClassA>();
   	shared_ptr<MyClassB> ppB = make_shared<MyClassB>();
   	ppA->m_share = ppB;
   	ppB->m_share = ppA;
   	return 0;
   }
   ```

   ![image-20220406232124791](https://github.com/qbaobao/MyAwesomeCode/blob/master/C%2B%2B/smart_ptr/image-20220406232124791.png)

   从图中可以看出，ppA和ppB指向的资源并没有释放。(没有调用析构函数)所以此处造成了资源泄露。

3. 不能用智能指针管理栈对象!!

4. **使用智能指针时，一定要注意资源的权限转移和生命周期！！！**特别是结合容器使用的场合。

5. 一些典型的智能指针使用场景。
