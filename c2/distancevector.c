/* [root@localhost ]# gcc dist_vector.c
[root@localhost ]# ./a.exe
Enter distance to the node 1 to other nodes
Please enter 999 if there is no direct route
Enter distance to the node 2:1
Enter distance to the node 3:2
Enter distance to the node 4:4
Enter distance to the node 5:999
Enter distance to the node 2 to other nodes
Please enter 999 if there is no direct route
Enter distance to the node 1:1
Enter distance to the node 3:999
Enter distance to the node 4:2
Enter distance to the node 5:999
Enter distance to the node 3 to other nodes
Please enter 999 if there is no direct route
Enter distance to the node 1:2
Enter distance to the node 2:999
Enter distance to the node 4:1
Enter distance to the node 5:6
Enter distance to the node 4 to other nodes
Please enter 999 if there is no direct route
Enter distance to the node 1:4
Enter distance to the node 2:2
Enter distance to the node 3:1
Enter distance to the node 5:3
Enter distance to the node 5 to other nodes
Please enter 999 if there is no direct route
Enter distance to the node 1:999
Enter distance to the node 2:999
Enter distance to the node 3:6
Enter distance to the node 4:3 */



#include <stdio.h>
#include <stdlib.h>

#define nul 1000
#define nodes 10

int no = 5;

struct node
{
    int a[nodes][3];   // a[x][0]=Dest, a[x][1]=NextHop, a[x][2]=Distance
} router[nodes];

void init(int r)
{
    int i;
    for(i = 1; i <= no; i++)
    {
        router[r].a[i][0] = i;      // destination
        router[r].a[i][1] = nul;    // next hop
        router[r].a[i][2] = 999;    // distance
    }
    router[r].a[r][2] = 0;   // cost to itself is 0
    router[r].a[r][1] = r;   // next hop to itself
}

void inp(int r)
{
    int i;
    printf("\n Enter distance from node %d to other nodes", r);
    printf("\n Enter 999 if no direct route\n");

    for(i = 1; i <= no; i++)
    {
        if(i != r)
        {
            printf(" Distance to node %d : ", i);
            scanf("%d", &router[r].a[i][2]);
            router[r].a[i][1] = i;
        }
    }
}

void display(int r)
{
    int i;
    printf("\n\n Routing Table for Node %d", r);
    printf("\n Dest\tNextHop\tDist");

    for(i = 1; i <= no; i++)
    {
        printf("\n %d\t   %d\t   %d", router[r].a[i][0],
               router[r].a[i][1], router[r].a[i][2]);
    }
}

void dv_algo(int r)
{
    int i, j, new_cost;
    for(i = 1; i <= no; i++)
    {
        if(router[r].a[i][2] != 999 && router[r].a[i][2] != 0)
        {
            for(j = 1; j <= no; j++)
            {
                new_cost = router[r].a[i][2] + router[i].a[j][2];
                if(router[r].a[j][2] > new_cost)
                {
                    router[r].a[j][2] = new_cost;
                    router[r].a[j][1] = i;
                }
            }
        }
    }
}

void find(int x, int y)
{
    if(router[x].a[y][1] != y)
    {
        find(x, router[x].a[y][1]);
        printf("%d-->", router[x].a[y][1]);
        find(router[x].a[y][1], y);
        return;
    }
}

int main()
{
    int i, j, x, y, choice;

    for(i = 1; i <= no; i++)
    {
        init(i);
        inp(i);
    }

    printf("\n\n Initial Routing Tables");
    for(i = 1; i <= no; i++)
        display(i);

    for(j = 1; j <= no; j++)
        for(i = 1; i <= no; i++)
            dv_algo(i);

    printf("\n\n Routing Tables After Computation");
    for(i = 1; i <= no; i++)
        display(i);

    while(1)
    {
        printf("\n\n Enter 1 to Continue, 0 to Quit: ");
        scanf("%d", &choice);
        if(choice != 1)
            break;

        printf("\n Enter nodes between which shortest path is needed: ");
        scanf("%d %d", &x, &y);

        printf("\n Shortest Path: %d-->", x);
        find(x, y);
        printf("%d", y);

        printf("\n Path Cost = %d", router[x].a[y][2]);
    }
    return 0;
}
