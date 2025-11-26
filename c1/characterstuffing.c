#include <stdio.h>
#include <string.h>

/*[root@localhost ]# gcc bytestuf.c
[root@localhost ]# ./a.exe
Output:
Enter the characters to be stuffed: javed
After stuffing, transmitted data:dlestxjaveddleetx
*/

int main()
{
    char c[80], d[80], ed[10], sd[10];
    int i, j, m;

    strcpy(sd, "dle");  // Start delimiter Example
    strcpy(ed, "etx");  // End delimiter Example

    printf("\nEnter the characters to be stuffed: ");
    scanf("%s", c);

    strcpy(d, sd); // Add start flag first
    m = strlen(c);
    j = strlen(sd);

    for (i = 0; i < m; i++, j++)
    {
        // Byte stuffing: if substring is "dle" add another "dle"
        if (c[i] == 'd' && c[i+1] == 'l' && c[i+2] == 'e')
        {
            d[j++] = 'd';
            d[j++] = 'l';
            d[j++] = 'e';
        }
        d[j] = c[i];
    }

    // Append end delimiter
    strcat(d, ed);

    printf("\nAfter stuffing, transmitted data: %s", d);
    return 0;
}
