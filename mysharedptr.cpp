#include <iostream>  
#include <stdio.h>  
#include <string.h>  
#include <vector>  
using namespace std;  

//每个smart_ptr都有一个ptr和use_count，其中ptr指向共享的对象。use_count指向共享对象的引用计数。
//这个计数当然是需要共享一份。如果各自有各自的计数(例如使用int use_count;)，那肯定出问题。
template<class T> class smart_ptr
{
public:
    smart_ptr(T *p);
    ~smart_ptr();
    smart_ptr(const smart_ptr<T> &orig);
    smart_ptr<T>& operator=(const smart_ptr<T> &rhs);
    
private:
    T *ptr;
    int *use_count;
};

// 常规的构造函数
template<class T> smart_ptr<T>::smart_ptr(T *p) : ptr(p)
{
    use_count = new int(1);
    printf("smart_ptr(T *p) is called!");
}

//带参数的构造函数，适应这种初始化smart_ptr<int> p2(p1);
template<class T> smart_ptr<T>::smart_ptr(const smart_ptr<T> &orig)
{
    ptr = orig.ptr;
    use_count = orig.use_count;
    ++(*use_count);
    printf("smart_ptr(const smart_ptr<T> &orig) is called!");
}

template<class T> smart_ptr<T>::~smart_ptr()
{
    if (--(*use_count) == 0){
        delete ptr;
        delete use_count;
        ptr = NULL;
        use_count = NULL;
        printf("~smart_ptr() is called!");
    }
}

//重载"="操作符:增加右侧计数，减少左侧计数。
template<class T> smart_ptr<T>& smart_ptr<T>::operator=(const smart_ptr<T> &rhs)
{
    ++(*rhs.use_count);

    if (--(*use_count) == 0){
        delete ptr;
        delete use_count;
        printf("operator=(const smart_ptr<T> &rhs) is called, delete left side.\n");
    }

    ptr = rhs.ptr;
    use_count = rhs.use_count;
    
    printf("operator=(const smart_ptr<T> &rhs) is called.\n");
    return *this;
}

int main()
{
    smart_ptr<int> p1(new int(0));
    p1 = p1;
    
    smart_ptr<int> p2(p1);
    
    smart_ptr<int> p3(new int(1));
    p3 = p1;
    
    return 0;
}