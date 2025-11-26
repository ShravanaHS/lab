// Program: stopnwait.c
// Program for Stop-and-Wait Protocol
/*Compile and run
[root@localhost ]# gcc stopnwait.c
[root@localhost ]# ./a.exe
No of frames is 6
Sending frame 1
Acknowledgement for frame 1
Sending frame 2
Acknowledgement for frame 2
Sending frame 3
Acknowledgement for frame 3
Sending frame 4
Acknowledgement for frame 4
Sending frame 5
Waiting for 1 second
Sending frame 5
Acknowledgement for frame 5
Sending frame 6
Waiting for 1 second
Sending frame 6
Acknowledgement for frame 6
End of stop and wait protocol*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>   // for sleep()

int main()
{
    int i = 1, noframes, r, delay, k;

    printf("\nEnter number of frames : ");
    scanf("%d", &noframes);

    while(noframes > 0)
    {
        printf("\nSending frame %d", i);
        r = rand() % 5;   // Random number (0 to 4)

        if(r == 0)        // Simulating lost frame or timeout
        {
            delay = rand() % 5 + 1;  // Random delay 1-5 seconds
            printf("\nWaiting for %d seconds...", delay);
            sleep(delay);            // wait
            printf("\nTimeout! Resending frame %d", i);
            continue;                // resend same frame
        }

        printf("\nAcknowledgement received for frame %d", i);
        noframes--;   // Next frame
        i++;
    }

    printf("\n\n----- End of Stop and Wait Protocol -----\n");
    return 0;
}
