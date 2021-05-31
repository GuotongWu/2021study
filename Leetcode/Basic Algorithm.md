## 1. 基础算法

### 1.1 归并排序

每当遇到 左子数组当前元素 > 右子数组当前元素 时，意味着 「左子数组当前元素 至 末尾元素」 与 「右子数组当前元素」 构成了若干 「逆序对」 。

```C++
#include<iostream>
using namespace std;

const int N = 100010;
int a[N], n;
unsigned long res;
int temp[N];

void mergesort(int a[], int l, int r)
{
    if(l == r)
        return;
    int mid = l+r>>1;
    mergesort(a, l, mid);
    mergesort(a, mid+1, r);
    int i=l, j=mid+1, k=0;
    while(i<=mid && j<=r){
        if(a[i] <= a[j])
            temp[k++] = a[i++];
        else{
            res += mid-i+1;
            temp[k++] = a[j++];
        }
    }
    while(i<=mid)
        temp[k++] = a[i++];
    while(j<=r)
        temp[k++] = a[j++];
    for(int i=0, j=l; j<=r; )
        a[j++] = temp[i++];
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
        scanf("%d", &a[i]);
    mergesort(a, 0, n-1);
    cout<<res;
    return 0;
}
```

### 1.2 区间合并

```c++
// 使用vector作为函数参数时，欲改变其中元素(eg. swap(a[i], a[j]))，记得加引用符号&
void quick_sort(vector<PII> &a, int l, int r)
```

## 2. 数据结构

### 2.1 链表

单链表

```C++
#include<iostream>
using namespace std;

const int N = 1e5+10;
int head, e[N], ne[N], idx;

void init(){
    head = -1;
    idx = 0;
}

void insert_to_head(int x){
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    ++idx;
}

void delete_posi(int k){
    if(k==-1){
        head = ne[head];
        return;
    }
    ne[k] = ne[ne[k]];
}

void insert_to_posi(int k, int x){
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    ++idx;
}

void traverse(){
    for(int curr=head; curr!=-1; curr=ne[curr])
        printf("%d ", e[curr]);
}

int main(){
    int M;
    scanf("%d", &M);
    
    init();
    
    char op;
    int k,x;
    while(M--){
        cin>>op;
        if(op == 'H'){
            scanf("%d", &x);
            insert_to_head(x);
        }
        else if(op == 'I'){
            scanf("%d%d", &k, &x);
            insert_to_posi(k-1, x);
        }else{
            scanf("%d", &k);
            delete_posi(k-1);
        }
    }
    
    traverse();
    
    return 0;
}
```

双链表

```C++
#include<iostream>
using namespace std;

const int N = 1e5+10;
int e[N], l[N], r[N], idx;

void init(){
    l[1] = 0;
    r[0] = 1;
    idx = 2;
}

void add_right(int k, int x){
    e[idx] = x;
    l[idx] = k;
    r[idx] = r[k];
    l[r[k]] = idx;
    r[k] = idx;
    ++idx;
}

void add_left(int k, int x){
    e[idx] = x;
    r[idx] = k;
    l[idx] = l[k];
    r[l[k]] = idx;
    l[k] = idx;
    ++idx;
}

void remove(int k){
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

void traverse(){
    for(int i=0; i!=1; i=r[i])
        if(i != 0)
            printf("%d ", e[i]);
}

int main(){
    int M;
    cin>>M;
    
    init();
    
    while(M--){
        string op;
        int k,x;
        cin>>op;
        if(op == "L"){
            scanf("%d", &x);
            add_right(0, x);
        }
        else if(op == "R"){
            scanf("%d", &x);
            add_left(1, x);
        }
        else if(op == "D"){
            scanf("%d", &k);
            remove(k+1);
        }
        else if(op ==  "IL"){
            scanf("%d%d", &k, &x);
            add_left(k+1,x);
        }
        else{
            scanf("%d%d", &k, &x);
            add_right(k+1,x);
        }
    }
    
    traverse();
    return 0;
}
```

### 2.2 栈

```C++
#include<iostream>
#include<string>
using namespace std;

const int N = 1e5+10;
int s[N], tt=0;

int main(){
    int M;
    scanf("%d", &M);
    
    while(M--){
        string op;
        int x;
        
        cin>>op;
        if(op == "push"){
            scanf("%d", &x);
            s[++tt] = x;
        }
        else if(op == "pop")
            --tt;
        else if(op == "query")
            printf("%d\n", s[tt]);
        else
            tt?cout<<"NO"<<endl: cout<<"YES"<<endl;
    }
    return 0;
}
```

### 2.3 队列

```C++
#include<iostream>
#include<string>
using namespace std;

const int N = 1e5+10;
int q[N], h=0, t=-1;

int main(){
    int M;
    scanf("%d", &M);
    
    while(M--){
        string op;
        int x;
        
        cin>>op;
        if(op == "push"){
            scanf("%d", &x);
            q[++t] = x;
        }
        else if(op == "pop")
            ++h;
        else if(op == "query")
            printf("%d\n", q[h]);
        else
            h>t?cout<<"YES"<<endl:cout<<"NO"<<endl;
    }
    
    return 0;
}
```

### 2.4 KMP算法

```c++
#include<iostream>
using namespace std;

const int N = 1e5+10, M = 1e6+10;
char S[N], P[M];
int ne[M];
int n, m;

int main(){
    cin>>n>>P>>m>>S;
    
    ne[0] = -1;
    for(int i=1; i<n; ++i){
        int j = ne[i-1];
        while(j>0 && P[j+1]!=P[i])
            j = ne[j];
        if(P[j+1] == P[i])
            ne[i] = j + 1;
        else 
            ne[i] = -1;
    }
    
    for(int i=0, j=0; i<m; ){
        if(S[i] == P[j]){
            ++j;
            ++i;
        }
        else if(j > 0) 
            j = ne[j-1] + 1;
        else 
            ++i;
        if(j == n){
            printf("%d ", i-n);
            j = ne[j-1] + 1;
        }
    }
            
    return 0;
}
```

### 2.5 Trie数

```C++
#include<iostream>
using namespace std;

const int N = 1e5 + 10;
int son[N][26], cnt[N], idx; // son[p][u]存储的是下一个结点的第一坐标
string x;

void insert(string x){
    int p = 0;
    for(int i=0; i<x.length(); ++i){
        int u = x[i] - 'a';
        if(!son[p][u])
            son[p][u] = ++idx;
        p = son[p][u];
    }
    ++cnt[p];
}

int query(string x){
    int p = 0;
    for(int i=0; i<x.length(); ++i){
        int u = x[i] - 'a';
        if(!son[p][u])
            return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        string q;
        cin>>q;
        if(q == "I"){
            cin>>x;
            insert(x);
        }
        else{
            cin>>x;
            printf("%d\n", query(x));
        }
    }
    
    return 0;
}
```

