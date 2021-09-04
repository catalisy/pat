//自己做的17分版本
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;

vector<double> d;
int n;
double change(string str) {
    double rel=0;
    bool lowzero=false;
    int p_locate=-1;
    if(str[0]=='-') {
        lowzero=true;
        str.erase(str.begin());
    }
    for(int i=0;i<str.size();i++) {
        if(str[i]=='.')
            p_locate=i;
    }
    if(p_locate==-1) {
        for(int i=0;i<str.size();i++)
            rel+=rel*10+str[i]-'0';
    }
    else {
        double z=0,x=0;
        for(int i=0;i<p_locate;i++)
            z=z*10+str[i]-'0';
        for(int i=str.size()-1;i>p_locate;i--)
            x=x*0.1+str[i]-'0';
        rel=z+x*0.1;
    }
    if(lowzero==true)
        return -rel;
    else
        return rel;

}
bool judge(string str) {
    int p_locate=-1,p_num=0,f_locate=0,f_num=0;
    for(int i=0;i<str.size();i++) {
        if(!(str[i]>='0'&&str[i]<='9'||str[i]=='.'||str[i]=='-'))
            return false;
        if(str[i]=='-') {
            f_locate=i;
            f_num++;
        }
        if(str[i]=='.') {
            p_locate=i;
            p_num++;
        }
    }
    if(p_num>1||f_num>1||p_locate==0||p_locate==str.size()-1||f_locate!=0)
        return false;
    if(f_locate==0&&p_locate==1&&f_num>0)
        return false;
    if(p_num==1&&str.size()-p_locate>3)
        return false;
    double rel=change(str);
    if(rel<-1000||rel>1000)
        return false;
    return true;
}

int main() {
    cin>>n;
    double rel=0;
    for(int i=0;i<n;i++) {
        string str;
        cin>>str;
        if(judge(str)==false)
            cout<<"ERROR: "<<str<<" is not a legal number"<<endl;
        else
            d.push_back(change(str));
    }
    if(d.size()==0)
        printf("The average of 0 numbers is Undefined");
    else {
        if(d.size()==1)
        printf("The average of 1 number is %0.2f",d[0]);
        else {
        for(int i=0;i<d.size();i++)
            rel+=d[i];
        printf("The average of %d numbers is %.2f",d.size(),rel/d.size());
        }
    }
    return 0;
}
