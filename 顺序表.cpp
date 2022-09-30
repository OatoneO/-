

#include <iostream>
#include<algorithm>
using namespace std;

#define N 100

typedef struct slNode      //顺序表的类型定义
{
    int data[N];           //顺序表，N为顺序表元素数量的上限
    int len;               //顺序表的长度（元素的个数）
    slNode() :len(0){};    //构造函数，将len的初始值设为0

}seqList;

//在顺序表sl的位置p处插入一个元素，元素值为x。tips:sl必须为引用或指针类型
void sl_insert(seqList& sl, int p, int x)
{
    if (sl.len >= N)
        cout << "表满，插入失败！" << endl;
    if (p >= sl.len)        //若插入位置大于最后一个元素的下标，则将x插入表尾
        sl.data[sl.len] = x;
    else
    {
        if (p < 0)
            p = 0;
        for (int i = sl.len; i >= p; i--)
        {
            sl.data[i] = sl.data[i - 1];      //将原表中位置p及其之后的元素向后移动一位
        }
        sl.data[p] = x;
        cout << p << "处数值已改为" << x << endl;
    }
    sl.len++;
}

//在顺序表的末尾插入元素
void sl_pushBack(seqList& sl, int x)
{
    sl.data[sl.len] = x;
    sl.len++;
}

//查找顺序表sl中位置p开始的第一个值为x的元素，如果存在，则返回下标
int sl_search(seqList sl, int p, int x)
{
    int i;
    if (p >= sl.len)
        return -1;
    for (i = max(0, p); i < sl.len; i++)
    {
        if (sl.data[i] == x)
            return i;
            break;
    }
    return -1;
}

//删除表中指定位置的元素
void sl_delete(seqList& sl, int p)
{
    if (p >= sl.len || p < 0 || sl.len == 0)
    {
        cout << "删除失败" << endl;
        return;
    }
    for (int i = p; i < sl.len; i++)
    {
        sl.data[i] = sl.data[i + 1];
    }
    sl.len--;
}

int main()
{
    seqList sl;
    for (int i = 0; i < 10; i++)
    {
        sl.data[i] = i+2;
        sl.len++;
    }
    //cout << sl.len << endl;
    //sl_insert(sl, -1, 1);
    //cout << sl.data[0] << endl;
    //cout << sl_search(sl, 0, 1) << endl;
}




