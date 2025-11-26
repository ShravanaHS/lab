#include <stdio.h>
#include <stdlib.h>
#define INFINITY 9999
#define MAX 10
void dijkstra( int G[MAX][MAX], int n, int startnode);
int main ()
{
int G[MAX][MAX ],i, j, n, u; 
printf("Enter no. of vertices:");
scanf("%d",&n);
printf ("\nEnter the adjacency matrix:\n");
for(i=0; i<5; i++)
for(j=0; j<5; j++)
scanf("%d", &G[i][j]);
printf("Enter the starting node:");
scanf("%d", &u);
dijkstra(G,n,u);
return 0;
}
void dijkstra(int G[MAX][MAX],int n, int startnode)
{
int cost[MAX][MAX], distance[MAX], pred[MAX];
int visited[MAX], count, mindistance, nextnode, i, j;
/*pred[] stores the predecessor of each nod
count gives the number of nodes seen so far and create the cost matrix */
for(i=0; i<n; i++)
for(j=0; j<n; j++)
if(G[i][j]==0)
cost[i][j]=INFINITY;
else
cost[i][j]=G[i][j];
//initialize pred[],distance[] and visited[]
for(i=0; i<n; i++)
{
distance[i]=cost[startnode][i];
pred[i]=startnode;
visited[i]=0;
}
distance[startnode]=0;
visited[startnode]=1;
count=1;
while(count<n-1)
{
mindistance=INFINITY;
//next node gives the node at minimum distance
for (i=0; i<n; i++)
if((distance[i]<mindistance) && (!visited[i]))
{
mindistance=distance[i];
nextnode=i;
}
//check if a better path exists through nextnode
visited[nextnode]=1;
for(i=0; i<n; i++)
if(!visited[i])
if((mindistance+cost[nextnode][i])<distance[i])
{
distance[i]=nextnode;
}
count++;
}
//print the path and distance of each node
for(i=0; i<n; i++)
if(i!=startnode)
{
printf("\nDistance of node%d=%d",i,distance[i]);
printf("\nPath=%d", i);
j=i;
do{
j=pred[j];
printf("%d", j);
}while(j!=startnode);
}
}
/*Enter no. of vertices:5
0 1 03 10
1 0 50 0
0 5 0 2 1
302 0 6
10 0 1 6 0
Enter thestarting node:0
Distance of node1=1
Path=10
Distance of node2=5
Path=230
Distance of node3=3
Path=30
Distance of node4=6
Path=4230
*/