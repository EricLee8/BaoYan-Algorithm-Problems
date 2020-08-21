#include<bits/stdc++.h>

const int MAXN = 10005;
const int MAXM = 1000005*2;

int head[MAXN], cur[MAXN], dis[MAXN], n, s, t, cnt=1; // start, terminate
bool vis[MAXN];

struct edge{
    int to, next, val;
}e[MAXM];

void add(int u, int v, int w)
{
    e[++cnt].to = v; // edge下标从2开始（为了之后的异或1操作服务
    e[cnt].val = w;
    e[cnt].next = head[u];
    head[u] = cnt;
}

bool bfs()
{
    for(int i=0; i<=n; i++) vis[i]=0, cur[i]=head[i];
    queue<int> q;
    q.push(s); dis[s]=0; vis[s]=1;
    int u, v;
    while(q.size())
    {
        u = q.front(); q.pop();
        for(int i=head[u]; i; i=e[i].next)
        {
            v = e[i].to;
            if(!vis[v] && e[i].val>0)
            {
                dis[v] = dis[u]+1;
                vis[v] = 1;
                if(v == t) return true;
                q.push(v);
            }
        }
    }
    return false;
}

int dfs(int now, int flow) // now是当前处理节点，而flow是带进当前节点的流量大小
{
    if(flow==0 || now==t) return flow;
    int used = 0, v; // used表示用掉了多少当前带进来的流量了
    for(int i=cur[now]; i; i=e[i].next) // i=cur[now]是进行了当前边优化，即再次访问到该节点时，之前处理过的边不用再处理了
    {
        cur[now] = i; // 当前边优化
        v = e[i].to;
        if(dis[v] != dis[now]+1) continue; //这个不要忘啊！！！！！！！
        int tmp = dfs(v, min(flow-used, e[i].val));//探索下一个点,送入的流量要么是当前剩余流量全用完(flow-used)要么是下一条边的容量全用完(e[i].val)
        if(tmp)
        {
            e[i] -= tmp;
            e[i^1] += tmp;
            used += tmp;
            if(flow-used == 0) return flow;
        }
    }
    return used;
}

int dinic()
{
    int ans = 0;
    while(bfs())
        ans += dfs(s, 0x7fffffff);
    return ans;
}
