#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str1,str2,str3;
    getline(cin,str1,'?');
    getline(cin,str2,':');
    getline(cin,str3);

    cout<<"if("<<str1<<")\n     "<<str2<<";\nelse\n     "<<str3<<";";
}