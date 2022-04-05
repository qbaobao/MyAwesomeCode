# C++11新语法之constexpr

## constexpr由来

C++98/03，只存在**const**关键字，用于修饰变量和函数的不变性。

```c++
const int aSize = 3;
void InitArr1(const int s) {
    int arr[s] = {0}; // err
}
void InitArr2(const int s) {
    const int aSize = 3;
    int arr[aSize] = {0}; // OK
}
```

![constexpr图1](D:\code\git\MyAwesomeCode\C++\constexpr\constexpr图1.png)

从上图可以看出，const修饰的值不一定都是常量。

1. 在InitArr1中const修饰的s是变量，const是说明s**只具有可读属性**。
2. 在InitArr2中const修饰的aSize不仅具有**只读属性**，还具有**常量属性**（编译器能够在变异阶段确认aSize的值）。

在C++11时，将const的属性中的**常量属性划分给了constexpr关键字**。const关键字只保留只读属性。



## constexpr使用介绍

### 什么是常量/常量表达式

常量：固定值，在程序运行期间不会被修改。例如：

> 符号常量：#define ETH_PORT_NUM 3
>
> 常值变量：
>
> const int g_ethPortNum = 3; 
>
> int InitArr1(const int s); // s
>
> 枚举值：enum EthPortType { Fiber, copper, CI };

常量表达式：能在**编译时**求值的表达式。这种表达式能用做非类型模板实参、数组大小，并用于其他要求常量表达式的语境。例如：

> constexpr int a = 1;
>
> constexpr int b = 2;
>
> constexpr int c = a + b;

区别：常量不一定是常量表达式，一部分常量不能再编译时确定值。只有用常量表达式初始化的常量，才能成为常量表达式，用非常量表达式初始化的常量仅仅是常量。如果常量的初始值不是常量表达式,则该常量不是常量表达式。

### constexpr修饰普通变量

使用 constexpr 修饰普通变量时，变量的数值必须在编译阶段能够确定，变量必须经过初始化且初始值必须是一个常量表达式。

```c++
constexpr int num = 1 + 2 + 3; // OK

int num1; // OK
constexpr num = 1 + num1; // ERR
```

![image-20220405201700539](C:\Users\xqma3\AppData\Roaming\Typora\typora-user-images\image-20220405201700539.png)

### constexpr修饰函数

用constexpr修饰返回值的函数必须满足以下**4**条件：

```c++
// 1. 函数返回值不能是void类型
constexpr void ShowSize() { // ERR
    cout << "size is 0\n";
    return;
}

// 2. 函数体重只能有1条return语句(除using指令、typedef语句以及static_assert断言除外)
constexpr int GetSize() {
    int size = 100; // ERR
    return size;
}

// 3. 函数返回值必须是常量表达式
constexpr int GetSize(const int start) {
    return start + 100; // ERR
}

// 4. 函数在使用前，必须有明确的定义语句
constexpr int GetSize();
Void ShowSize() {
    cout << GetSize() << endl; // ERR
}
constexpr int GetSize() {
    return 100;
}

// 正确使用举例：
constexpr int GetArrSize()
{
	return 5;
}
int main()
{
	constexpr int num = 1 + 2 + 3; // OK
	array<int, GetArrSize()> ar1{1,2,3,4,5};
	cout << ar1[3] << ", num = " << num << endl;
	return 0;
}
```

![image-20220405203418240](C:\Users\xqma3\AppData\Roaming\Typora\typora-user-images\image-20220405203418240.png)

### constexpr修饰构造函数

自定义的数据类型，无法直接使用constexpr修饰类名。要求该构造函数的函数体必须为空，且采用**初始化列表**的方式为各个成员赋值时，且必须使用**常量表达式**。

```c++
struct TranserE {
	const char* name;
	int time;
}; // 编译器生成默认的构造函数
struct Transer {
	const char* name;
	int time;
    constexpr Transer(const char* name, int time) : name(name), time(time) {}
};
int main() {
	constexpr TranserE tsr1 = {"mxq", 4}; // OK
	constexpr Transer tsr = {"mxq", 4}; // OK
}
```

### constexpr修饰函数模板

C++11 语法中，constexpr 可以修饰模板函数，但由于模板中类型的不确定性，因此模板函数实例化后的函数是否符合常量表达式函数的要求是不确定的。

针对这种情况下，C++11 标准规定，如果 constexpr 修饰的模板函数实例化结果不满足常量表达式函数的要求，则 constexpr 会被自动忽略，即该函数就等同于一个普通函数。

```c++
struct Rectangle {
	int length;
	int width;
	constexpr Rectangle(int length, int width) : length(length), width(width) {}
};

template<typename T>
constexpr T GetArea(T w, T l) {
	return w * l;
}


int main() {
    // constexpr生效
	constexpr Rectangle r1 = { 3, 4 }; // OK
	array<int, GetArea(r1.length, r1.width)> ar1; // OK

	int w = 1;
	int l = 1;
    // constexpr被忽略，GetArea是普通模板函数
	cout << GetArea(w, l) << endl; // OK
	constexpr Rectangle r1 = { w, l }; // ERR,ERR,表达式必须含有常量值
	array<int, GetArea(w, l)> ar2; // ERR,表达式必须含有常量值
	return 0;
}
```

## 源码分析

```c++
#define constexpr EMIT WARNING C4005
```

