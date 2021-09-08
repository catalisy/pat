//2021.3.15
#include <stdio.h>
#include <vector>
#include <algorithm>

#define MAX 50005
using namespace std;
struct item{
    int index;
    int num;
};
int n,k,a[MAX];

bool cmp(struct item a,struct item b)  {
    if(a.num>b.num)
        return true;
    else if(a.index<b.index&&a.num==b.num)
        return true;
    else
        return false;

}
int main(){
    scanf("%d %d",&n,&k);
    int i;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    vector<struct item> itms;
    for(i=1;i<n;i++){
        sort(a,a+i);
        int j=0,num1=1;
        for(;j<i;j++)
        {
            if(j+1<i&&a[j]==a[j+1])
                num1++;
            else
            {
                struct item temp;
                temp.index=a[j];
                temp.num=num1;
                num1=1;
                itms.push_back(temp);
            }
        }
        sort(itms.begin(),itms.end(),cmp);
        printf("%d:",a[i]);
        for(j=0;j<(int)itms.size()&&j<k;j++)
            printf(" %d",itms[j].index);
        printf("\n");
        itms.clear();

    }

}
