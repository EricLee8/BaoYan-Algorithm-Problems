const int N = 105;
bool line[N][N];
bool used[N];
int result[N];
int n, m;

bool found(int x)
{
	for(int i=1; i<=m; i++)
	{
		if(!used[i] && line[x][i])
		{
			used[i] = true;
			if(result[i]==0 || found(result[i]))
			{
				result[i] = x;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int cnt = 0;
	memset(line, 0, sizeof(line));
	memset(result, 0, sizeof(result));
	// ... construct array line according to the problem
	for(int i=1; i<=n; i++)
	{
		memset(used, 0, sizeof(used));
		if(found(i)) cnt++;
	}
	cout << cnt << endl;
	return 0;
}

// 2020.07.11默写
const int N = 105;
bool line[N][N];
int result[N];
bool used[N];
int n, m;

bool found(int x)
{
	for(int i=1; i<=m; i++)
	{
		if(line[x][i] && !used[i])
		{
			used[i] = true;
			if(result[i]==0 || found(result[i]))
			{
				result[i] = x;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	memset(result, 0, sizeof(result));
	memset(line, 0, sizeof(line));
	//constructing binary graph...
	int ans = 0;
	for(int i=1; i<=n; i++)
	{
		memset(used, 0, sizeof(used));
		if(found(i)) ans++;
	}
	cout << ans << endl;
	return 0;
}