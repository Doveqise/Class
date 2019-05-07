
�����ԣ� �����С
�����ԣ� �ж�ĳЩ״̬�Ƿ���� 

f[i][j]       ��i,j�ߵ��� ���ֵ
f[i][j][k] 0/1 ��i,j�ߵ���   ��Ϊk�Ƿ���� 

��������

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

���У� ��ǰ׺Ϊ״̬
� ���� ������

1. f[i][j] ǰi�����֣�������ִ�СΪj���LIS���� 
f[i][j] = f[i-1][j]
f[i][a[i]] = max(f[i-1][k])+1   k<a[i]
O(n^3)
O(n^2)

1.1 f[i][j] ǰi�����֣�������ִ�С���Ϊj���LIS���� 
f[i][j] = f[i-1][j]
f[i][j] = f[i-1][j-1]+1  j>=a[i]
O(n^2)

2. f[i] ��i��β��LIS����
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


1. ��״����
1) �޸�ĳ��λ�õ�ֵ
2) ��ǰ׺��

1) �޸�ĳ��λ�õ�ֵ (�������) logn
2) ��ǰ׺���ֵ  logn

f[i] = max(f[j]) + 1   a[j]<a[i]

int tmp[]; // ���Ѿ���õ�״̬, tmp[a[i]]=f[i] ��a[i]Ϊ�±꣬f[i]Ϊֵ 
tmp[a[i]]=f[i];

f[i] = max(tmp[k]) + 1   k<a[i]
��״����(max)ά��tmp

f[i] = 1

��ɢ����
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

2. ջ(̰��) 

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
1) �޸�ĳ��λ�õ�ֵ (�������) logn
2) ��ǰ׺���ֵ  logn

f[i] = max(f[j]) + 1  a[j]<a[i]

O(n)

tmp[a[i]] = f[i]
tmp[k]
f[i] = max(tmp[k]) + 1  k<a[i]


LCS
� ���� ������

2 3 5 1 4 2 5
3 1 5 4 2 1 3

3 5 4 2

ǰ׺��
1. f[i][j] A�Ե�i��λ�ý�β��B�Ե�j��λ�ý�β��LCS����

f[i][j] = max(f[k][l]) + 1  k<i l<j  a[i]==b[j]
f[i][j] = max(f[k][l]) k<i l<j
f[i][j] = max(f[k][l])+1  k<i l<j a[i] == b[l] �� b[j] == a[k]   



2. f[i][j] A��ǰi��λ����B��ǰj��λ�õ�LCS����

f[i][j] = f[i-1][j-1] + 1  a[i]==b[j]
f[i][j] = f[i-1][j]
f[i][j] = f[i][j-1]

O(n^2)


LCS �ĸ�����˹���㷨 


��������P1��P2
1~n

����һ���������� 
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

ǰ׺
��׺

f[i] i..n ������ʱ��

1. f[i] = f[i+1]+1
2. f[i] = max(f[end[j]+1])  jΪ��iʱ�̿�ʼ������ 



f[i] 1..i

f[i] i..n
f[1]

vector<int> v[100000]
scanf("%d%d",&s,&t);
v[s].push_back(t);
v[i]



f[i] �����1..i ʯ�Ӻϲ���һ�� ��С����

f[l][r] ��ʾ �����l..rʯ�Ӻϲ���һ�ѵ���С����

for(int i=1;i<=n;i++)
	f[i][i] = 0;

f[1][n]

f[l][r] =  min_k (f[l][k] + f[k+1][r] + sum[l][r])  l <= k <r

�������䳤��ö������
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

f[l][r][0/1]  ����λ�ã�l/r  �Ѿ����ĵ���������


f[l][r][0] <- f[l+1][r][0]  + (sum(1,n) - sum(l+1,r)) * dist(l,l+1) 
           <- f[l+1][r][1]  + (sum(1,n) - sum(l+1,r)) * dist(l,r) 

O(n^2)


int a[];

i<j
a[i]>a[j]


// ��״�������������

��ɢ��
a[i] 1~n 
for(int i=1;i<=n;i++){
	ans += ask(n) - ask(a[i]); // λ��С��i, ֵ����a[i]�������� 
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

f[i][j] ����1~i  j������� �ķ�����

i-1

f[i][j] = sum( f[i-1][j-k] )   0 <= k < i

f[i-1][j-(i-1)] ... f[i-1][j]
f[i][j]


f[i][0/1]  �Ե�i�����ֽ�β ���������/�½���β � �������г���
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

���  ��ֵ
5      5
3      7
10     2 

��ȫ������ 
f[0][0] = 0

f[i][j]   ǰi����Ʒ ���j �������ֵ 
����װ��k�� 
���v[i], ��ֵw[i]
 
f[i][j] = max(f[i-1][j-v[i]*k] + w[i]*k)

j 0~V
j-v[i]*k >= 0

�ռ�O(n^2)
ʱ��O(n^3)

����װ��k��:
1. ��װ��ǰ��Ʒ
f[i][j] = f[i-1][j]
2. ��װһ����ǰ��Ʒ 
f[i][j] = max(f[i][j], f[i][j-v[i]]+w[i])
j ��С����ת�� 
�ռ�O(n^2)
ʱ��O(n^2)

ʡ�Ե�һά
f[j] = max(f[j], f[j-v[i]]+w[i]) 
j ��С����ת��

for(int i=1;i<=n;i++){
	for(int j=v[i];j<=V;j++){
		f[j]=max(f[j],f[j-v[i]]+w[i]);
	}
}
�ռ�O(n)
ʱ��O(n^2)

01������ 
f[0][0] = 0
f[i][j]   ǰi����Ʒ ���j �������ֵ 
1. ��װ��ǰ��Ʒ
f[i][j] <- f[i-1][j]
2. װһ����ǰ��Ʒ 
f[i][j] <- f[i-1][j-v[i]]+w[i]
�ռ�O(n^2)
ʱ��O(n^2)


f[j] <- f[j-v[i]]+w[i]
j�Ӵ�Сѭ�� 
for(int i=1;i<=n;i++){
	for(int j=V;j>=v[i];j--){
		f[j]=max(f[j],f[j-v[i]]+w[i]);
	}
}
�ռ�O(n)
ʱ��O(n^2)






