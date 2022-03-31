#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100

struct goods{
int sign;//物品序号
int wight;//物品重量
int value;//物品价值
};

int n,bestValue,cv,cw,C;//物品数量，价值最大，当前价值，当前重量，背包容量
int X[N],cx[N];//最终存储状态，当前存储状态
struct goods goods[N];
float q[1000];
float proportion[1000];

bool compare (float a,float b)
{
    // 非递增排列;
    return a>b;
}

void Quick_sort(float q[],int l,int r)
{
    if(l>=r) return;
    int i=l-1,j=r+1,x=q[l+r >> 1];
    while(i<j)
    {
        do i++;while(q[i]<x);
        do j--;while(q[j]>x);
        if(i<j)
        {
            int temp = q[i];
            q[i]=q[j];
            q[j]=temp;
        }
    }
    Quick_sort(q,l,j),Quick_sort(q,j+1,r);
}

int main()
{
	FILE *fp;
    char filename[30],x[31];
    cout<<"测试文件：\n"; 
    cout<<"beibao0.in\nbeibao1.in\nbeibao2.in\nbeibao3.in\n";
    cout<<"beibao4.in\nbeibao5.in\nbeibao6.in\nbeibao7.in\nbeibao8.in\nbeibao9.in\n";
    cout<<"请输入测试数据文件名（带后缀）:\n";
    gets(filename);
    if((fp=fopen(filename,"r+"))==NULL){
        printf("ERROR!\n");
        exit(0);
    }
	fscanf(fp,"%d %d", &C, &n);
	printf("背包容量为: %d，物品个数为: %d\n", C, n);
	for(int i = 0; i < n; i++)
    {
		fscanf(fp, "%d %d",&goods[i].wight,&goods[i].value);
        printf("%d %d\n", goods[i].wight,goods[i].value); 
    }
    
    for(int i = 0; i < n; i++)
    {
		proportion[i]=(float)goods[i].wight/goods[i].value;
    }
    
    printf("非递增排序前：");
    for(int i = 0; i < n; i++)
    {
		cout<<proportion[i]<<" ";
    }
    cout<<endl;
    
    sort(proportion,proportion+10,compare);
    
    printf("非递增排序后：");
    for(int i=0;i<n;i++) 
	{ 
		cout<<proportion[i]<<" ";
	} 
    cout<<endl;
    
    return 0;
} 
