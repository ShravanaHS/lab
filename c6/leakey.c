// Program: leakybucket.c
// Leaky Bucket Algorithm Implementation

#include <stdio.h>
#include <stdlib.h>

int min(int x, int y)
{
    if (x < y)
        return x;
    else
        return y;
}

int main()
{
    int drop = 0, count = 0, inp[25];
    int mini, nsec, cap, i, process;

    printf("\n Enter the Bucket Size: ");
    scanf("%d", &cap);

    printf("\n Enter the Operation Rate: ");
    scanf("%d", &process);

    printf("\n Enter the no. of Seconds you want to Simulate: ");
    scanf("%d", &nsec);

    for (i = 0; i < nsec; i++)
    {
        printf("\n Enter the Size of the Packet entering at %d sec: ", i + 1);
        scanf("%d", &inp[i]);
    }

    printf("\nSecond | PacketReceived | PacketSent | PacketLeft | PacketDropped\n");
    printf("-------------------------------------------------------------------\n");

    for (i = 0; i < nsec; i++)
    {
        count += inp[i];
        if (count > cap)
        {
            drop = count - cap;
            count = cap;
        }

        printf("%d\t\t", i + 1);
        printf("%d\t\t", inp[i]);
        mini = min(count, process);
        printf("%d\t\t", mini);
        count = count - mini;
        printf("%d\t\t", count);
        printf("%d\n", drop);
        drop = 0;
    }

    for (; count != 0; i++)
    {
        if (count > cap)
        {
            drop = count - cap;
            count = cap;
        }
        printf("%d\t\t", i + 1);
        printf("0\t\t");
        mini = min(count, process);
        printf("%d\t\t", mini);
        count = count - mini;
        printf("%d\t\t", count);
        printf("%d\n", drop);
    }
    return 0;
}

/*
-------------------------------------- OUTPUT --------------------------------------

[root@localhost ]# gcc leakybucket.c
[root@localhost ]# ./a.out

 Enter the Bucket Size: 5
 Enter the Operation Rate: 2
 Enter the no. of Seconds you want to Simulate: 3

 Enter the Size of the Packet entering at 1 sec: 5
 Enter the Size of the Packet entering at 2 sec: 4
 Enter the Size of the Packet entering at 3 sec: 3

Second | PacketReceived | PacketSent | PacketLeft | PacketDropped
-------------------------------------------------------------------
1               5               2               3               0
2               4               2               3               2
3               3               2               3               1
4               0               2               1               0
5               0               1               0               0

--------------------------------------------------------------------------------------
Result: Leaky Bucket Algorithm Successfully Implemented
*/
