// Program: slidingwindow.c
// Sliding Window Protocol Implementation

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int w, i, f, frames[50];

    printf("Enter window size: ");
    scanf("%d", &w);

    printf("\nEnter number of frames to transmit: ");
    scanf("%d", &f);

    printf("\nEnter %d frames: ", f);
    for(i = 1; i <= f; i++)
        scanf("%d", &frames[i]);

    printf("\nWith sliding window protocol the frames will be sent in the following manner (assuming no corruption of frames)\n");
    printf("\nAfter sending %d frames at each stage sender waits for acknowledgement sent by the receiver\n\n", w);

    for(i = 1; i <= f; i++)
    {
        if(i % w == 0)
        {
            printf("%d\n", frames[i]);
            printf("Acknowledgement of above frames sent is received by sender\n\n");
        }
        else
        {
            printf("%d ", frames[i]);
        }
    }

    if(f % w != 0)
        printf("\nAcknowledgement of above frames sent is received by sender\n");

    return 0;
}

/*
------------------------------------ OUTPUT ------------------------------------

Case-1: For Window Size < No. of Frames

[root@localhost ]# gcc slidingwindow.c
[root@localhost ]# ./a.out
Enter window size: 5
Enter number of frames to transmit: 10
Enter 10 frames: 1 2 3 4 5 6 7 8 9 10

With sliding window protocol the frames will be sent in the following manner (assuming no corruption of frames)

After sending 5 frames at each stage sender waits for acknowledgement sent by the receiver

1 2 3 4 5
Acknowledgement of above frames sent is received by sender

6 7 8 9 10
Acknowledgement of above frames sent is received by sender

--------------------------------------------------------------------------------

Case-2: For Window Size = No. of Frames

[root@localhost ]# ./a.out
Enter window size: 5
Enter number of frames to transmit: 5
Enter 5 frames: 1 2 3 4 5

With sliding window protocol the frames will be sent in the following manner (assuming no corruption of frames)

After sending 5 frames at each stage sender waits for acknowledgement sent by the receiver

1 2 3 4 5
Acknowledgement of above frames sent is received by sender

--------------------------------------------------------------------------------

Case-3: For Window Size > No. of Frames

[root@localhost ]# ./a.out
Enter window size: 5
Enter number of frames to transmit: 3
Enter 3 frames: 1 2 3

With sliding window protocol the frames will be sent in the following manner (assuming no corruption of frames)

After sending 3 frames at each stage sender waits for acknowledgement sent by the receiver

1 2 3
Acknowledgement of above frames sent is received by sender

--------------------------------------------------------------------------------
*/
