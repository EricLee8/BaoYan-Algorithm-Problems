# include <bits/stdc++.h>

int m, n, start;
const int MAXN = 205;
bool vis[MAXN];
int dis[MAXN];

class node{
public:
    int to, len;
    node() {}
    node(int t, int l): to(t), len(l) {}
    bool operator < (const node& n2) const {return len > n2.len;} //小根堆
};

vector<node>* adjList;

void dijkstra()
{
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    priority_queue<node> q;
    q.push(node(start, 0)); dis[start] = 0;
    node tmp;
    int u, v, tmplen;
    while(q.size())
    {
        tmp = q.top(); q.pop();
        u = tmp.to;
        if(vis[u]) continue;
        vis[u] = true;
        for(int i=0; i<adjList[u].size(); i++)
        {
            v = adjList[u][i].to;
            tmplen = dis[u]+adjList[u][i].len;
            if(dis[v] > tmplen)
            {
                dis[v] = tmplen;
                q.push(node(v, dis[v]));
            }
        }
    }
}


// 2020.06.05默写
const int MAXN = 10005;
int strat;

bool vis[MAXN];
int dis[MAXN];

class node{
public:
	int to, len;
	node() {}
	node(int tt, int ll): to(tt), len(ll) {}
	bool operator <(const node& n2) const {return len>n2.len;}
};

vector<node> *adjList;

void dijkstra()
{
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3f, sizeof(dis));
	priority_queue<node> q;
	q.push(node(start, 0)); dis[start] = 0;
	node tmp; int u, v, tmplen;
	while(q.size())
	{
		tmp = q.top(); q.pop();
		u = tmp.to;
		if(vis[u]) continue;
		vis[u] = true;
		for(int i=0; i<adjList[u].size(); i++)
		{
			v = adjList[u][i].to;
			tmplen = dis[u]+adjList[u][i].len;
			if(dis[v]>tmplen)
			{
				dis[v] = tmplen;
				q.push(node(v, dis[v]));
			}
		}
	}
}

//2020.07.03默写
const int MAXN = 10000;
bool vis[MAXN];
int dis[MAXN];
int start;

class node{
public:
	int to, len;
	node() {}
	node(int tt, int ll): to(tt), len(ll) {}
	bool operator < (const node& n2) const {return len>n2.len;} //最小化堆
};

vector<node> *adjList;

void dijkstra()
{
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	priority_queue<node> q;
	q.push(node(start, 0)); dis[start]=0;
	node tmp; int u, v, tmplen;
	while(q.size())
	{
		tmp = q.top(); q.pop();
		u = tmp.to;
		if(vis[u]) continue;
		vis[u] = true;
		for(int i=0; i<adjList[u].size(); i++)
		{
			v = adjList[u][i].to;
			tmplen = adjList[u][i].len;
			if(dis[v]>dis[u]+tmplen)
			{
				dis[v] = dis[u]+tmplen;
				q.push(node(v, dis[v]));
			}
		}
	}
}