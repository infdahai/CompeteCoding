#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
struct node{
    string xm;//姓名
    int qm,bj;//期末平均成绩，班级评议成绩
    char bgb,xb;//是否是学生干部，是否是西部省份学生
    int lw;//发表的论文数
    int ans;//个人所获的奖金数
    int sum;//序号数，因为题目要求两个人所获的奖金数相同时，输出先出现的，即序号较靠前的（较小的）
}a[101];
int n,tot=0;
bool cmp(node x,node y)
{
    if(x.ans==y.ans)return x.sum<y.sum;
    else return x.ans>y.ans;//奖学金数从大到小排序，相同时按序号数从小到大排序
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].xm>>a[i].qm>>a[i].bj>>a[i].bgb>>a[i].xb>>a[i].lw;
        if(a[i].qm>80&&a[i].lw>=1)a[i].ans+=8000;
        if(a[i].qm>85&&a[i].bj>80)a[i].ans+=4000;
        if(a[i].qm>90)a[i].ans+=2000;
        if(a[i].xb=='Y'&&a[i].qm>85)a[i].ans+=1000;
        if(a[i].bj>80&&a[i].bgb=='Y')a[i].ans+=850;
        a[i].sum=i;
        tot+=a[i].ans;//tot为总的奖学金数
    }
    sort(a+1,a+n+1,cmp);
    cout<<a[1].xm<<endl<<a[1].ans<<endl<<tot;
    return 0;
}