/*
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int n,t;
char s[20];
int ans;
struct node
{
	int to;
	int fl;
};
vector<int> save[100010];
int num;
int to[100010];
int vis[100010];
int to2[100010];
int fl[100010];int cnt[100010];
int fl2[100010];
vector<int> k;
int wolf[100010];
void dfs(int x,int ji,int f,int res)
{
	if (vis[x]!=ji&&vis[x]!=0)
	{
		return ;
	}
	
	if (vis[x]==ji&&f-cnt[x]==1)
	{
	//	k.push_back(res);
//	cout<<res<<endl;
	wolf[num++] = res;
                vis[res] = 1;
		ans++;
		return;
	}
	else if (vis[x]==ji)
	{
		return;
	 } 
	vis[x]=ji;
	cnt[x]=f;
	if (fl[x]==1)
	{
		dfs(to[x],ji,f+fl[x],to[x]);
	}
	else
	{
		dfs(to[x],ji,f+fl[x],res);
	}
		
	
}

void dfs2(int x)
{
//	cout<<x<<" ";
	if (vis[x])
	{
		return ;
	}
	ans++;
	vis[x]=1;
	for(int j=0;j<save[x].size();j++)
	{
		dfs2(save[x][j]);
	}
	
}
int x;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d",&n);
		memset(to,0,sizeof(to));memset(fl,0,sizeof(fl));memset(vis,0,sizeof(vis));
		
			num=0;
		k.clear();
		for(int i=1;i<=n;i++)
		{
			scanf("%d%s",&to[i],s+1);
			save[i].clear();
			if (s[1]=='w')
			{
				fl[i]=1;
				//	to2[to[i]]=i;
				//	fl2[to[i]]=1;
				
			}
			else
			{
				fl[i]=0;
				to2[to[i]]=i;
				fl2[to[i]]=0;
				save[to[i]].push_back(i);
			//	save[to[i]].push_back({i,0});
			}
			vis[i]=0;
			cnt[i]=0;
			//sa[i]=0;
		}
	//	save.clear();
		for(int i=1;i<=n;i++)
		{
			if (!vis[i])
			{
			//	vis[i]=i;
			cnt[i]=0;
				dfs(i,i,0,0);
			}
		//	cout<<i;
		}
		memset(vis,0,sizeof(vis));
		 
	//	 for(int i=0;i<k.size();i++)
	for(int i=0;i<num;i++)
		{
		//	cout<<num<<endl;
           x=wolf[i];     //A:wolf. B->A Villager, B->wolf
            //  int x=k[i];
         //   for(int j = head[x]; ~j; j = edge[j].nxt)
     //    cout<<x<<" "<<save[x].size();
    	    for(int j = 0; j<save[x].size(); j++)
			{
              //  int y = edge[j].v;
              
                 int y = save[x][j];
				 //cout<<"yy"<<y<<endl;
                if(!vis[y])
				{
				//	cout<<y<<" ";
			//		k.push_back(y);
                    wolf[num++] = y;
                    vis[y] = 1;
                }
            }
        }
	/*	for(int i=0;i<k.size();i++)
		{
			vis[k[i]]=1;
		//	cout<<k[i]<<" ";
			for(int j=0;j<save[k[i]].size();j++)
			{
				dfs2(save[k[i]][j]);
			}
		}
		
		printf("0 %d\n",num);
	}
}




3
8
2 v
3 v
4 v
1 w
1 v
1 v
6 v
6 v

#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define pi acos(-1.0)
#define ms(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
 
const int maxn = 1e5+5;
 
int cnt, head[maxn];
int wolf[maxn], vis[maxn];
int fa[maxn];
 
struct node{
    int x, vg;
    char ch[10];
}a[maxn];
 
struct Edge{
    int v, nxt;
}edge[maxn];
 
void add(int u, int v){
    edge[++cnt].v=v;
    edge[cnt].nxt=head[u];
    head[u] = cnt;
}
 
int Find(int x){
    if (fa[x] == x) return fa[x];
    return fa[x] = Find(fa[x]);
}
 
void Union(int x, int y){
    int fx = Find(x);
    int fy = Find(y);
    if(fx != fy)
        fa[x] = fy;
}
 
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        cnt = 0; ms(vis, 0);
        int n; ms(head, -1);
        scanf("%d", &n);
        for(int i=1;i<=n;i++) fa[i]=i;
        for(int i = 1; i <= n; i++){
            scanf("%d%s", &a[i].x, a[i].ch);
            a[i].vg = (a[i].ch[0] == 'v');
            if(a[i].vg == 1)
            {
                add(a[i].x, i); //Build 链式关系结构
                Union(i, a[i].x); //Build Villagers' 并查集
            }
        }
        int num=0; //must Villager' number =0, must wolf' number = ?
 
        for(int i=1;i<=n;i++) //A->B wolf A,B have same father B->wolf
            if(Find(i) == Find(a[i].x) && a[i].vg == 0)
			{
                wolf[num++] = a[i].x;
                vis[a[i].x] = 1;
            }
 
        for(int i=0;i<num;i++)
		{
            int x=wolf[i];     //A:wolf. B->A Villager, B->wolf
            for(int j = head[x]; ~j; j = edge[j].nxt){
                int y = edge[j].v;
                if(!vis[y])
				{
                    wolf[num++] = y;
                    vis[y] = 1;
                }
            }
        }
        printf("0 %d\n", num);
    }
    return 0;
}
*/ 

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <vector>
typedef long long ll;
using namespace std;
int t;
const int maxn = 1e5+100;
int n;
int val[maxn];
int mp[maxn];
vector<int> remp[maxn];
int vis[maxn],vis2[maxn],ok[maxn];
int gao = 0,gao2 = 0;
int cnt = 0;;
void dfs1(int rt,int cnt){
	// if(vis2[rt]) return;
	// printf("1");
	if(vis[rt])
	{
		if(vis[rt]==cnt)
			gao = rt;
		return;
	}
	vis[rt] = cnt;
	if(mp[rt])
	dfs1(mp[rt],cnt);
}

void dfs2(int rt,int v){
	// printf("@");
	if(val[rt]) gao2 = mp[rt];
	if(vis2[rt]){
		if(v==1) gao = maxn;
		return;
	}
	vis2[rt] = 1;
	// v += val[rt];
	if(mp[rt])
	dfs2(mp[rt],v+val[rt]);
}
void dfs3(int rt){
	// printf("%d\n",rt);
	/*if(val[rt]==0)
	{
		
	 } 
	
	else return;
	*/
		ok[rt]=vis2[rt] = 1;
	for(int i = 0;i<remp[rt].size();i++){
		if(vis2[remp[rt][i]]) continue;
	//	if(remp[rt][i])
		dfs3(remp[rt][i]);
	}
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
    	cnt = 0;
    	scanf("%d",&n);
    	int a;
    	char b[10];
    	for(int i = 1;i<=n;i++)
		{
    		vis[i] = vis2[i] = 0;
    		remp[i].clear();
    		ok[i] = 0;
    	}


    	for(int i = 1;i<=n;i++){
    		scanf("%d%s",&a,b);
    		mp[i] = a;
    		
    		val[i] = (b[0]=='w');
			if (b[0]!='w')
	    	{
	    		remp[a].push_back(i);
			}
    	}
    	
    	for(int i = 1;i<=n;i++){
    		gao = 0;
    		gao2 = 0;
    		dfs1(i,++cnt);
    		if(gao) dfs2(gao,0);
    		if(gao==maxn) ok[gao2] = 1;
    	}
    	for(int i = 1;i<=n;i++)
		{
    		if(ok[i]&&vis2[i]){
    			dfs3(i);
    		}
    	}
    	int res = 0;
    	for(int i = 1;i<=n;i++){
    		if(ok[i]) res++;
    		// res+=ok[i];
    	}
    	printf("%d %d\n",0,res);

    }

    return 0;
}



