//在构建二叉树的过程中出现问题，不知道出在哪里
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int post[35],pre[35];
set<int> s1,s2;
vector<int> ans;
struct Node {
    int id;
    Node *lchild,*rchild;
    Node(){}
    Node(int _id) {
        id=_id;
        lchild=NULL;
        rchild=NULL;
    }
};
bool isunique=false;

void create(Node* &root,int prebegin,int preend,int postbegin,int postend) {
    if(prebegin>preend)
        return;
    if(prebegin==preend) {
        Node a=Node(pre[prebegin]);
        root=&a;
        return;
    }
    Node temp=Node(pre[prebegin]);
    root=&temp;
    int left1=prebegin+1,right1=preend;
    int left2=postbegin,right2=postend-1;
    int rel_left1=prebegin,rel_left2=postbegin;
    int cot=0;
    bool isvis=false;
    while(left1<=right1) {                                   //关键是这里面中间的变量最后没有被赋值，也没有初始化，导致最后的结果太大了，在pre处出现段错误
        s1.insert(pre[left1++]);
        s2.insert(post[left2++]);
        if(s1==s2)
            cot++;
        if(cot==1&&isvis==false) {
            rel_left1=left1;
            rel_left2=left2;
            isvis=true;
        }
        if(cot>1) {
            isunique=true;
            break;
        }
    }
    /*
    if(pre[prebegin+1]==post[postend-1]){
        cot++;
    }
    if(cot==1&&isvis==false) {
            rel_left1=left1;
            rel_left2=left2;
            isvis=true;
        }
    if(cot>1)
        isunique=true;
        */
    s1.clear();
    s2.clear();
    create(root->lchild,prebegin+1,rel_left1-1,postbegin,rel_left2-1);
    create(root->rchild,rel_left1,preend,rel_left2,postend-1);
}
void inorder(Node *root) {
    if(root==NULL)
        return;
    ans.push_back(root->id);
    inorder(root->lchild);
    inorder(root->rchild);
}

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&pre[i]);
    }
    for(int i=0;i<n;i++) {
        scanf("%d",&post[i]);
    }
    Node *root=NULL;
    create(root,0,n-1,0,n-1);
    inorder(root);
    if(isunique==true)
        printf("NO\n");
    else
        printf("YES\n");
    printf("%d",ans[0]);
    for(int i=1;i<ans.size();i++) {
        printf(" %d",ans[i]);
    }
    return 0;

}
