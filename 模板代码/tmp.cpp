const int MAXN = 50000;
int trees[MAXN];
int n;

int lowbit(int x) {return x&(-x);}

void tadd(int x, int k)
{
	while(x<=n)
	{
		trees[x] += k;
		x += lowbit(x);
	}
}

int tsearch(int x)
{
	int ans = 0;
	while(x)
	{
		ans += trees[x];
		x -= lowbit(x);
	}
	return ans;
}