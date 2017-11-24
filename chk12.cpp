#include<bits/stdc++.h>
using namespace std;
int graph[1000][1000];
int color[1000];
bool isSafe(int n,int v,int c)
{
    for(int i=0;i<n;i++)
    {
        if(graph[v][i]==1 && c==color[i])
            return false;
    }
    return true;
}
bool graphColoring(int n,int v)
{
    if(v>=n)
    {
        int maxm=0;
        cout<<"Vertex :";
        for(int i=0;i<n;i++)
        {
            cout<<i;
        }
        cout<<endl<<"Color :";
        for(int i=0;i<n;i++)
        {
            cout<<color[i];
            if(maxm<color[i])
                maxm=color[i];
        }
        cout<<endl<<"Chromatic Number "<<maxm<<endl;
        return true;
    }
    for(int i=1;i<=n;i++)
    {
        if(isSafe(n,v,i))
        {
            color[v]=i;
            if(graphColoring(n,v+1))
               return true;
            color[v]=0;
        }
    }
    return false;
}
int main()
{
    int n;
    cout<<"Enter the number of nodes"<<endl;
    cin>>n;

     graph[n][n];
     color[n];
    for(int i=0;i<n;i++)
    {
        color[i]=0;
        for(int j=0;j<n;j++)
        {
            cin>>graph[i][j];
        }
    }
    if(!graphColoring(n,0))
        cout<<"No Solution"<<endl;
}
