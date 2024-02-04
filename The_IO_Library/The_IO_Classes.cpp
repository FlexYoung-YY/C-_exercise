#include <fstream>
#include <iostream>
#include <string>
using std::ofstream;
using std::ifstream;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main()
{
    ofstream out1, out2; // 这里ofstream是类; out1, out2是对象。类似于cout。
    // out1 = out2; // error: cannot assign stream objects
    // ofstream print(ofstream); // error: can't initialize the ofstream parameter
    // out2 = print(out2); // error: cannot copy stream objects
    /*
    int i;
    char str[20];
    string s1;
    cout << "enter a string: ";
    cin >> s1; // 由于命令行各参数默认是以空格为界定符的，单词后是空格，因此解析串到此位置就停止了
    cout << "s1 = " << typeid(s1).name() << endl;
    cin >> str;
    cout << "str = " << typeid(str).name() << endl;
    cout << typeid("str = ").name() << endl;
    cout << "enter an integer and a string: ";
    cin >> i >> str;
    cout << "i = " << i << endl;
    cout << "str = " << str << endl;
    char str1[20];
    cout << "enter a string: ";
    cin >> str1;
    cout << "str1 = " << str1 << endl;
    */
    /* 
    char *p;
    char c = '1';
    auto s = "111";
    string str = "222";
    char a[] = "111";
    char* const s1 = &c; 
    char c2 = '2';
    cout << typeid(p).name() << endl;
    cout << typeid(s).name() << endl;
    cout << typeid(str).name() << endl;
    cout << typeid(a).name() << endl;
    cout << typeid("111").name() << endl;
    s = "123123";
    cout << typeid(s).name() << endl;
    cout << typeid(s1).name() << endl;
    */
   
    /*
    cin.tie(&cout);
    string str;
    cin >> str;
    */

    /*
    string ifile = "ifile.txt"; 
    string in_result;
    ifstream in(ifile); // 自带open， in 提供了读取，文件不存在则不创建

    if (in)
    {
        cout << "success" << endl;
        for (int i = 0; i < 3; i++) // 如何知道行数？
        {
            in >> in_result;
            cout << "result: " << in_result << endl;
        }

    }
    in.close();
    if (!in) // 表示文件是否存在，而不是是否open。
    {
        cout << "not exist" << endl;
    }
    if (!in.is_open()) //可以用is_open()来确认是否成功关闭。或者用析构函数（还没学到）
    {
        cout << "closed" << endl;
    }
    string ofile = "ofile.txt";
    string out_result;
    ofstream out; // 没有确定open了哪个file， out 提供了写入，文件不存在则创建
    out.open(ofile); //associate 了具体的file
    if (out)
    {
        cout << "success" << endl;
        for (int i = 0; i < 4; i++)
        {   
            out_result = "row: " + std::to_string(i);
            out << out_result << endl;
        }
    }
    out.close();
    if (!out.is_open())
    {
        cout << "closed" << endl;
    }

    ofstream out_1;
    out_1.open("ofile.txt", ofstream::app); // 如果不用app，则默认为覆盖
    //out_1.open("ofile.txt"); // 如果不用app，则默认为覆盖
    if (out_1)
    {
        cout << "success" << endl;
        for (int i = 4; i < 8; i++)
        {   
            out_result = "row: " + std::to_string(i);
            out_1 << out_result << endl;
        }
    }    
    out_1.close();
    */
    return 0;
}