#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
int trees[MAXN];
int a[MAXN];

int n; //下标要从1开始

int lowbit(x) {return x&(-x);}

void tadd(int x, int k) // x的地方加上k
{
    while(x<=n)
    {
        trees[x] += k;
        x += lowbit(x); // 找父节点
    }
}

int tsearch(int x) // 搜索x之前的前缀和
{
    int ans = 0;
    while(x)
    {
        ans += trees[x];
        x -= lowbit(x); // 找x的前继节点
    }
    return ans;
}

//维护区间最值
void tadd(int x, int k) // 仅建树的时候可以用
{
    while(x <= n)
    {
        trees[x] = max(trees[x], k);
        x += lowbit(x);
    }
}
/*
说一下为什么只有建树的时候才可以用，而update的时候不能用。因为假如你修改的是位置x的值为k，并且你是维护最大值，那么你层层往上更新和这个
点有关的trees的值时，假如用的还是max(trees[x], k)，那么假如之前tress[x]里存的最大值恰好是这里位置为x的值，而你这次的k又把这个a[x]改
小了，那么你这次修改其实并不能反映出这个信息，因为你max一下还是之前的值。所以update函数要另外写一个。
*/


int tsearch(int x, int y)
{
    int ans = -1;
    while(y>=x)
    {
        ans = max(ans, a[y--]); //先这样搞一下，减少一下y，反正也不亏，还能预防y-lowbit(y)爆出去(小于x)
        for(; y-lowbit(y)>=x; y-=lowbit(y))
            ans = max(ans, trees[y]);
    }
    return ans;
}
/*
关于最值维护的tsearch说明一下，这里最重要的地方就是理解trees[i]的含义：trees[i]里储存的是从a[i-lowbit(i)+1]到a[i]
的最大值，而我们在求一段区间[x,y]内的最大值时，若发现y-lowbit(y)>=x，我们就可以用max(ans, trees[y])来求得这一段区间的最值
（因为这段区间包含在我们的目标区间内）。而当y-lowbit(y)<x的时候，区间已经爆出去了，要用max(ans, a[y--])来更新ans，然后重新
去判断新的y是否满足y-lowbit(y)>=x。不断重复直至y不满足y>=x跳出去。
*/

void update(int x) //之前已经更新了a[x] = k;
{
    int lx, i;
    while(x <= n)
    {
        trees[x] = a[x];
        lx = lowbit(x);
        for(int i=1; i<lx; i<<=2)
            trees[x] = max(trees[x], trees[x-i]);
        x += lowbit(x);
    }
}