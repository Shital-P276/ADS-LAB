/*Print all the nodes reachable from a given starting node in a graph using BFS method.*/
#include<stdio.h>
#include<conio.h>

void BFS(int [20][20],int,int [20],int);

void main(){
    int n,a[20][20],i,j,visited[20],source;
    
    printf("Enter the number of vertices:");
    scanf("%d",&n);
	
    printf("\nEnter the adjacency matrix:\n");
    for(i=1;i<=n;i++){
	for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    }
	
    for(i=1;i<=n;i++)
        visited[i]=0;
	
    printf("\nEnter the source node:");
    scanf("%d",&source);
	
    visited[source]=1;
    BFS(a,source,visited,n);
	
    printf("\nSource node: %d",source);
    for(i=1;i<=n;i++)
    {
        if(visited[i]!=0)
            printf("\n Node %d is reachable",i);
        else
            printf("\n Node %d is not reachable",i);
            getch();
    }

}
void BFS(int a[20][20],int source,int visited[20],int n)
{
    int queue[20],f,r,u,v;
    f=0;
    r=-1;
    queue[++r]=source;
    while(f<=r)
    {
        u=queue[f++];
        for(v=1;v<=n;v++)
        {
            if(a[u][v]==1 && visited[v]==0)
            { 
		queue[++r]=v;
                visited[v]=1;
            }
        } //for v
    } // while
}
