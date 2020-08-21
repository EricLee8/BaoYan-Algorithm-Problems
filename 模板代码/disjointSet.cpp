class disjointset{
public:
	int *parent;
	disjointset(int n)
	{
		parent = new int[n];
		for(int i=0; i<n; i++) parent[i] = -1;
	}
	~disjointset() {delete [] parent;}
	int disfind(int x)
	{
		if(parent[x] < 0) return x;
		return parent[x] = disfind(parent[x]); //路径压缩
	}
	void disunion(int root1, int root2)
	{
		if(parent[root1] > parent[root2]) parent[root2] += parent[root1], parent[root1] = root2;
		else parent[root1] += parent[root2], parent[root2] = root1;
	}
};