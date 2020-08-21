int KMP(string text, string pattern)
{
	int i, j, m = pattern.size(), n = text.size();
	int* nxt = new int [m];
	nxt[0] = -1; // nxt[i]表示i这个位置前后缀相等的最大前缀的最后一个字符的下标哈
	for(int i=1; i<m; i++)
	{
		j = i-1; //首先你想peach地认为，i-1这个位置的最大前后缀相等的最后一个字符+1刚好和i这个位置的字符相等
		while(j>=0 && pattern[nxt[j]+1]!=pattern[i]) j = nxt[j]; //如果不相等就一直往nxt[j]找下去直到相等或者j<0
		if(j<0) nxt[i] = -1;
		else nxt[i] = nxt[j]+1; //刚刚相等的那个地方
	}

	i = j = 0; //开始从头匹配
	while(i<n && j<m)
	{
		if(text[i] == pattern[j]) {i++; j++;}
		else if(j==0) i++; //j为0了说明要重新匹配，把i往右移一位
			else j = nxt[j-1] + 1; //j这个位置不匹配了，要从j-1这个位置的最大前后缀匹配的最后一个字符+1的位置找起
	}
	delete [] nxt;
	if(j==m) return i-j; //如果是j==m，表示匹配上了，返回i-j匹配字符在text中的第一个字符的下标
	else return -1;
}

//2020.03.16默写
int KMP(string text, string pattern)
{
    int m = pattern.size(), n = text.size(), i, j;
    int* nxt = new int[m];
    nxt[0] = -1;
    for(i=1; i<m; i++)
    {
        j = i - 1;
        while(j>=0 && pattern[nxt[j]+1]!=pattern[i]) j = nxt[j];
        if(j<0) nxt[i] = -1;
        else nxt[i] = nxt[j] + 1;
    }
    i = j = 0;
    while(i<n && j<m)
    {
        if(text[i] == pattern[j]) {i++, j++;}
        else if(j==0) i++;
            else j = nxt[j-1] + 1;
    }
    delete [] nxt;
    if(j==m) return i-j;
    else return -1;
}

//2020.05.26默写
int KMP(string text, string pattern)
{
	int i, j, m=pattern.size(), n=text.size();
	int* nxt = new int [m];
	nxt[0] = -1;
	for(i=1; i<m; i++)
	{
		j = i-1;
		while(j>=0 && pattern[nxt[j]+1]!=pattern[i]) j = nxt[j];
		if(j<0) nxt[i] = -1;
		else nxt[i] = nxt[j]+1;
	}
	i = j = 0;
	while(i<n && j<m)
	{
		if(text[i] == pattern[j]) {i++; j++;}
		else if(j==0) i++;
			else j = nxt[j-1]+1;
	}
	delete [] nxt;
	if(j==m) return i-j;
	else return -1;
}

//有重叠的匹配次数计算
int KMP(string text, string pattern)
{
	// ======================= 正常的预处理 =========================
	int i, j, m = pattern.size(), n = text.size(), cnt = 0;
	int* nxt = new int[m];
	nxt[0] = -1;
	for(int i=1; i<m; i++)
	{
		j = i - 1;
		while(j>=0 && pattern[nxt[j]+1]!=pattern[i]) j = nxt[j];
		if(j<0) nxt[i] = -1;
		else nxt[i] = nxt[j] + 1;
	}
	// ========================= 多重匹配 ===========================
	i = j = 0;
	while(i<n)
	{
		while(i<n && j<m)
		{
			if(text[j] == pattern[j]) {i++; j++;}
			else if(j==0) i++;
				else j = nxt[j-1] + 1;
		}
		if(j==m) {cnt++; j=nxt[j-1]+1;} //从有可能重叠的地方的最大下标开始新一轮匹配
	}
	delete [] nxt;
	return cnt;
}

//2020.07.11默写
int KMP(string text, string pattern)
{
	int i, j, m=pattern.size(), n=text.size();
	int *nxt = new int [m];
	nxt[0] = -1;
	for(int i=1; i<m; i++)
	{
		j = i-1;
		while(j>=0 && pattern[nxt[j]+1]!=pattern[i]) j = nxt[j];
		if(j<0) nxt[i] = -1;
		else nxt[i] = nxt[j]+1;
	}
	//默写一下多重匹配的
	i = j =0;
	int num = 0;
	while(i<n)
	{
		while(i<n && j<m)
		{
			if(text[i]==pattern[j]) {i++; j++;}
			else if(j==0) i++;
				else j = nxt[j-1]+1;
		}
		if(j==m) {num++; j=nxt[j-1]+1;}
	}
	delete [] nxt;
	return ans;
}