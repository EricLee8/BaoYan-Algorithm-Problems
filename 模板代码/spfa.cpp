# include <bits/stdc++.h>

int m, n, start;
const int MAXN = 205;
bool vis[MAXN];
bool dis[MAXN];

class node{
public:
    int to, len;
    node() {}
    node(int t, int l): to(t), len(l) {}
};

vector<node>* adjList;

void spfa()
{
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    queue<int> q;
    q.push(start); dis[start] = 0; vis[start] = true;
    int u, v, tmplen;
    while(q.size())
    {
        u = q.front(); q.pop();
        vis[u] = false;
        for(int i=0; i<adjList[u].size(); i++)
        {
            v = adjList[u][i].to;
            tmplen = adjList[u][i].len;
            if(dis[v] > dis[u] + tmplen)
            {
                dis[v] = dis[u] + tmplen;
                if(!vis[v])q.push(v), vis[v] = true;
            }
        }
    }
}


// 2020.06.06默写
const int MAXN = 1005;
int n, start;
bool vis[MAXN];
int dis[MAXN];

class node{
public:
	int to, len;
	node() {}
	node(int tt, int ll): to(tt), len(ll) {}
};

vector<node>* adjList;

void spfa()
{
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3f, sizeof(dis));
	queue<int> q;
	q.push(start); dis[start]=0; vis[start]=true;
	int u, v, tmplen;
	while(q.size())
	{
		u = q.front(); q.pop();
		vis[u] = false;
		for(int i=0; i<adjList[u].size(); i++)
		{
			v = adjList[u][i].to;
			tmplen = adjList[u][i].len;
			if(dis[v] > dis[u]+tmplen)
			{
				dis[v] = dis[u]+tmplen;
				if(!vis[v]) q.push(v), vis[v] = true;
			}
		}
	} 
}


//2020.07.03默写
const int MAXN = 10005;
bool vis[MAXN];
int dis[MAXN];
int start;

class node{
public:
	int to, len;
	node() {}
	node(int tt, int ll): to(tt), len(ll) {}
};

vector<node> *adjList;

void spfa()
{
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x7f, sizeof(dis));
	queue<int> q;
	q.push(start); dis[start]=0; vis[start]=true;
	int u, v, tmplen;
	while(q.size())
	{
		u = q.front(); q.pop();
		vis[u] = false;
		for(int i=0; i<adjList[u].size(); i++)
		{
			v = adjList[u][i].to;
			tmplen = dis[u] + adjList[u][i].len;
			if(dis[v] > tmplen)
			{
				dis[v] = tmplen;
				if(!vis[v]) q.push(v), vis[v]=true;
			}
		}
	}
}