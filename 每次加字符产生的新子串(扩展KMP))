#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
const int N=1e6+10;
int x[N],y[N],te[N],n,m,nxt[N],ex[N];
void pre_exkmp()
{
    nxt[0]=n;
    int now=0;
    while(x[now]==x[1+now]&&now+1<n)now++;//Õâ¾ÍÊÇ´Ó1¿ªÊ¼±©Á¦
    nxt[1]=now;
    int p0=1;
    for(int i=2;i<n;i++)
    {
        if(i+nxt[i-p0]<nxt[p0]+p0)nxt[i]=nxt[i-p0];//µÚÒ»ÖÖÇé¿ö
        else
        {//µÚ¶þÖÖÇé¿ö
            int now=nxt[p0]+p0-i;
            now=max(now,0);//ÕâÀïÊÇÎªÁË·ÀÖ¹i>pµÄÇé¿ö
            while(x[now]==x[i+now]&&i+now<n)now++;//±©Á¦
            nxt[i]=now;
            p0=i;//¸üÐÂp0
        }
    }
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<=n-1;++i) scanf("%d",&x[n-i-1]);
        pre_exkmp();
        for(int i=0;i<=n;i++)
        {
           // cout<<nxt[i]<<" ";
        }
        for(int i=1;i<=m;++i) te[i]=-1;
        nxt[n]=0;
      /*  for(int i=0;i<=n;i++)
        {
            cout<<nxt[i]<<" ";
        }
        */
        for(int i=0;i<=n-1;++i) 
            te[x[i]]=max(nxt[i+1],te[x[i]]);
        int ans=0,p=1;
        for(int i=1;i<=m;++i)
        {
            p=1ll*p*3%mod;
            ans^=1ll*p*(n-te[i])%mod;
        }
        printf("%d\n",ans);
    }
    return 0;
}
