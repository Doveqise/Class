
最优性： 最大、最小
可行性： 判断某些状态是否可行 

f[i][j]       从i,j走到底 最大值
f[i][j][k] 0/1 从i,j走到底   答案为k是否可行 

滚动数组

f[2][j][k]  
i
i%2
(i+1)%2
for(int i=1;i<=n;i++){
	for(int j=0;j<=n;j++) f[i%2][j] = 0;
	for(int j=1;j<=n;j++){
		f[i%2][j] = f[(i-1)%2][k]...
	}
}

for(int i=1;i<=n;i++) f[n][i][a[n][i]%100] = true;
for(int i=n-1;i>=1;i--){
	for(int j=1;j<=i;j++){
		for(int k=0;k<100;k++){
			// i,j,k
			// a[i][j]
			int tmp = ((k-a[i][j])%100+100)%100;
			f[i][j][k] = f[i+1][j][tmp] || f[i+1][j+1][tmp];
		}
	}
}

for(int i=99;i>=0;i--) if(f[1][1][i]){
	ans=i;
	break;	
}

0 ~ n-1

f[0][0] = 1
f[i][j] <- f[i-1][j-1 / j+1] 
f[i][j] = f[i-1][(j-1+n)%n] + f[i-1][( j+1)%n] 

        -> f[i+1][j-1 / j+1]        
f[i+1][j-1] += f[i][j] 
f[i+1][j+1] += f[i][j] 


LIS 
2 5 7 5 3 6 7 5 7 8 9 10

2 5 6 7 8 9 10

序列： 以前缀为状态
最长 上升 子序列

1. f[i][j] 前i个数字，最后数字大小为j的最长LIS长度 
f[i][j] = f[i-1][j]
f[i][a[i]] = max(f[i-1][k])+1   k<a[i]
O(n^3)
O(n^2)

1.1 f[i][j] 前i个数字，最后数字大小最大为j的最长LIS长度 
f[i][j] = f[i-1][j]
f[i][j] = f[i-1][j-1]+1  j>=a[i]
O(n^2)

2. f[i] 以i结尾的LIS长度
f[i] = max(f[j]) + 1   j<i a[j]<a[i]
f[i] = 1

O(n^2)

for(int i=1;i<=n;i++){
	f[i]=1;
	for(int j=1;j<i;j++){
		if(a[j]<a[i]) f[i]=max(f[i],f[j]+1);
	}
}
int ans = 0;
for(int i=1;i<=n;i++) ans = max(ans,f[i]);


1. 树状数组
1) 修改某个位置的值
2) 求前缀和

1) 修改某个位置的值 (往大里改) logn
2) 求前缀最大值  logn

f[i] = max(f[j]) + 1   a[j]<a[i]

int tmp[]; // 对已经算好的状态, tmp[a[i]]=f[i] 以a[i]为下标，f[i]为值 
tmp[a[i]]=f[i];

f[i] = max(tmp[k]) + 1   k<a[i]
树状数组(max)维护tmp

f[i] = 1

离散化：
131290381 123183129 2131313 1231231213 12313123 1231232131

7 5 2 4
4 3 1 2

2 4 5 7
1 2 3 4

6 5 5 3 3
3 2 2 1 1

int n;
int a[];
int b[];
for(int i=1;i<=n;i++) b[i]=a[i];
sort(b+1,b+n+1);
int tot = unique(b+1,b+n+1)-(b+1);
for(int i=1;i<=n;i++){
	a[i] = lower_bound(b+1,b+tot+1,a[i])-b;	
}

2. 栈(贪心) 

i<j
a[i]<a[j]
int top;
int stk[];
for(int i=1;i<=n;i++){
	if(top==0 || a[i]>stk[top-1]) stk[top++]=a[i];
	else{
		*lower_bound(stk,stk+top,a[i])=a[i];
	}
}
// top

i<j
a[i]<=a[j]

int top;
int stk[];
for(int i=1;i<=n;i++){
	if(top==0 || a[i]>stk[top-1]) stk[top++]=a[i];
	else{
		*upper_bound(stk,stk+top,a[i])=a[i];
	}
}


BIT
1) 修改某个位置的值 (往大里改) logn
2) 求前缀最大值  logn

f[i] = max(f[j]) + 1  a[j]<a[i]

O(n)

tmp[a[i]] = f[i]
tmp[k]
f[i] = max(tmp[k]) + 1  k<a[i]


LCS
最长 公共 子序列

2 3 5 1 4 2 5
3 1 5 4 2 1 3

3 5 4 2

前缀：
1. f[i][j] A以第i个位置结尾，B以第j个位置结尾的LCS长度

f[i][j] = max(f[k][l]) + 1  k<i l<j  a[i]==b[j]
f[i][j] = max(f[k][l]) k<i l<j
f[i][j] = max(f[k][l])+1  k<i l<j a[i] == b[l] 或 b[j] == a[k]   



2. f[i][j] A的前i个位置与B的前j个位置的LCS长度

f[i][j] = f[i-1][j-1] + 1  a[i]==b[j]
f[i][j] = f[i-1][j]
f[i][j] = f[i][j-1]

O(n^2)


LCS 四个俄罗斯人算法 


两个排列P1和P2
1~n

任意一个上升序列 
1 2 3 4 5 6 7 8
8 7 2 3 1 5 4 6
LIS   -> LCS 

1 2 3 4 5 6 7 8
8 7 2 3 1 5 4 6

int to[];
for(int i=1;i<=n;i++) to[a[i]]=i;
for(int i=1;i<=n;i++) b[i]=to[b[i]];

1 3 2 4 5 7 8 6
5 4 3 7 6 2 1 8
a[i] == b[j]
a[i] != b[j]

a'[i] == b'[j]
a'[i] != b'[j]
 

1 2 3 4 5 6 7 8
5 4 3 7 6 2 1 8

1 2 3 4 5
2 3 1 2 4 A
3 1 2 2 4 B
2 3 (4 1) (4 1) 5 

前缀
后缀

f[i] i..n 最大空闲时间

1. f[i] = f[i+1]+1
2. f[i] = max(f[end[j]+1])  j为从i时刻开始的任务 



f[i] 1..i

f[i] i..n
f[1]

vector<int> v[100000]
scanf("%d%d",&s,&t);
v[s].push_back(t);
v[i]



f[i] 将编号1..i 石子合并成一堆 最小代价

f[l][r] 表示 将编号l..r石子合并成一堆的最小代价

for(int i=1;i<=n;i++)
	f[i][i] = 0;

f[1][n]

f[l][r] =  min_k (f[l][k] + f[k+1][r] + sum[l][r])  l <= k <r

按照区间长度枚举区间
for(int len = 2; len<=n;len++){
	for(int i=1;i<=n;i++){
		int j = i+len-1;
		if(j>n) break;
		f[i][j] = inf;
		for(int k=i;k<j;k++){
			f[i][j] = min(f[i][j],f[i][k]+f[k+1][j]+sum[i][j]);	
		}
	}
}

O(n^3)
f[1][n]
 
O(n^4)


ABCDEF
 BCDEFA
  CDEFAB
   DEFABC
    EFABCD
     FABCDE
ABCDEFABCDEF 

int n;
int a[];
for(int i=1;i<=n;i++) a[i+n] = a[i];
for(int len = 2; len<=n;len++){
	for(int i=1;i<=2*n;i++){ ///!!!
		int j = i+len-1;
		if(j>2*n) break;
		f[i][j] = inf;
		for(int k=i;k<j;k++){
			f[i][j] = min(f[i][j],f[i][k]+f[k+1][j]+sum[i][j]);	
		}
	}
}
for(int i=1;i<=n;i++) ans = max(ans,f[i][i+n-1]);

O(n^3) 

f[l][r][0/1]  老张位置：l/r  已经消耗的最少能量


f[l][r][0] <- f[l+1][r][0]  + (sum(1,n) - sum(l+1,r)) * dist(l,l+1) 
           <- f[l+1][r][1]  + (sum(1,n) - sum(l+1,r)) * dist(l,r) 

O(n^2)


int a[];

i<j
a[i]>a[j]


// 树状数组求逆序对数

离散化
a[i] 1~n 
for(int i=1;i<=n;i++){
	ans += ask(n) - ask(a[i]); // 位置小于i, 值大于a[i]数字数量 
	add(a[i],1);
}

int ask(int pos){
	int ret = 0;
	while(pos>0){
		ret+= a[pos];
		pos-=lowbit(pos);
	}
	return ret;
}
void add(int pos,int k){ 
	while(pos<=n){
		a[pos]+=k;
		pos+=lowbit(pos);
	}
}


int a[];
a[pos] += w    add(pos,w);
a[1..pos]      ask(pos)



i < j    a[i] > a[j]


1,2,3...,n

f[i][j] 数字1~i  j个逆序对 的方案数

i-1

f[i][j] = sum( f[i-1][j-k] )   0 <= k < i

f[i-1][j-(i-1)] ... f[i-1][j]
f[i][j]


f[i][0/1]  以第i个数字结尾 最后以上升/下降结尾 最长 波浪序列长度
f[i][0] = max(f[j][1]) +1; j<i a[j]<a[i]
f[i][1] = max(f[j][0]) +1; j<i a[j]>a[i]

int k=0;
for(int i=1;i<=n;i++){
	int j=i;
	if(k==0){
		while(j<n && a[j]<a[j+1]) j++;
		k=1;	
	}else{
		while(j<n && a[j]>a[j+1]) j++;
		k=0;
	}
	cnt ++;
	i=j;
}
 
 
 
 
10 

体积  价值
5      5
3      7
10     2 

完全背包： 
f[0][0] = 0

f[i][j]   前i个物品 体积j 获得最大价值 
假设装了k个 
体积v[i], 价值w[i]
 
f[i][j] = max(f[i-1][j-v[i]*k] + w[i]*k)

j 0~V
j-v[i]*k >= 0

空间O(n^2)
时间O(n^3)

假设装了k个:
1. 不装当前物品
f[i][j] = f[i-1][j]
2. 多装一个当前物品 
f[i][j] = max(f[i][j], f[i][j-v[i]]+w[i])
j 从小到大转移 
空间O(n^2)
时间O(n^2)

省略第一维
f[j] = max(f[j], f[j-v[i]]+w[i]) 
j 从小到大转移

for(int i=1;i<=n;i++){
	for(int j=v[i];j<=V;j++){
		f[j]=max(f[j],f[j-v[i]]+w[i]);
	}
}
空间O(n)
时间O(n^2)

01背包： 
f[0][0] = 0
f[i][j]   前i个物品 体积j 获得最大价值 
1. 不装当前物品
f[i][j] <- f[i-1][j]
2. 装一个当前物品 
f[i][j] <- f[i-1][j-v[i]]+w[i]
空间O(n^2)
时间O(n^2)


f[j] <- f[j-v[i]]+w[i]
j从大到小循环 
for(int i=1;i<=n;i++){
	for(int j=V;j>=v[i];j--){
		f[j]=max(f[j],f[j-v[i]]+w[i]);
	}
}
空间O(n)
时间O(n^2)






