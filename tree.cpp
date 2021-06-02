#include <iostream>
#include <cstdio>
using namespace std;
const int N=300005;
int head[N],nxt[N*2],pnt[N*2],E=1;
int size[N],fa[N],ans[N];

void add_edge(int a,int b){
	pnt[E]=b;
	nxt[E]=head[a];
	head[a]=E++;
}

void dfs(int u){
	int i,v,mx=0,mxn=-10;
	size[u]=1;
	ans[u]=u;
	for(i=head[u];i;i=nxt[i]){
		v=pnt[i];
		dfs(v);
		size[u]+=size[v];
		if(size[v]>mx){
			mx=size[v];
			mxn=v;
		}
	}
	if(mxn==-10) return ;
	int c;
	if(size[mxn]*2>size[u]){
		c=ans[mxn];
		while((size[u]-size[c])*2>size[u]){
			c=fa[c];
		}
		ans[u]=c;
	}
}

int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	int i,x;
	for(i=2;i<=n;i++){
		scanf("%d",&fa[i]);
		add_edge(fa[i],i);
	}
	fa[1]=-1;
	dfs(1);
	for(i=1;i<=q;i++){
		scanf("%d",&x);
		printf("%d\n",ans[x]);
	}
	return 0;
}