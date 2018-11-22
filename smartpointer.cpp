class Test
{
public:
    Test(string s)
    {
        str = s;
       cout<<"Test creat\n";
    }
    ~Test()
    {
        cout<<"Test delete:"<<str<<endl;
    }
    string& getStr()
    {
        return str;
    }
    void setStr(string s)
    {
        str = s;
    }
    void print()
    {
        cout<<str<<endl;
    }
private:
    string str;
};


unique_ptr<Test> fun()
{
    return unique_ptr<Test>(new Test("789"));
}

int UniquePtrTest()
{
    unique_ptr<Test> ptest(new Test("123"));
    unique_ptr<Test> ptest2(new Test("456"));
    ptest->print();
    ptest2 = std::move(ptest);//不能直接ptest2 = ptest
    if(ptest == NULL)cout<<"ptest = NULL\n";
    Test* p = ptest2.release();
    p->print();
    ptest.reset(p);
    ptest->print();
    ptest2 = fun(); //这里可以用=，因为使用了移动构造函数
    ptest2->print();
    return 0;
}

int SharedPtrTest()
{
    shared_ptr<Test> ptest(new Test("123"));
    shared_ptr<Test> ptest2(new Test("456"));
    cout<<ptest2->getStr()<<endl;
    cout<<ptest2.use_count()<<endl;
    ptest = ptest2;//"456"引用次数加1，“123”销毁
    ptest->print();
    cout<<ptest2.use_count()<<endl;//2
    cout<<ptest.use_count()<<endl;//2
    ptest.reset();
    ptest2.reset();//此时“456”销毁
    cout<<"done !\n";
    return 0;
}