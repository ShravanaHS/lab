#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//00011111122222 invalid input frame
//1001111101111110101011110 valid input frame
int main()
{
char a[100],b[100];
int i,j,k,count,n,flag;
strcpy(a,""); strcpy(b,"");
for(;;){
flag=0;
printf("Enter input frame (0's & 1's only):");
scanf("%s",a);
n = strlen(a);
for(i=0; i<n; i++){
if ((a[i]=='0') || (a[i]=='1' )){
continue;
}
else{
flag=1; break;
}
}
if(flag){
printf ("Invalid Input frame\n:");
exit (0);
}
else{
printf ("Valid Input frame\n:");
printf ("Frame length = %d\n", n); break;
 }
}
i=0; j=0; flag=0;
while(i<n)
{
if (a[i]=='1')
{
b[j] = a[i]; count=1;
for(k=i+1; a[k]=='1' && k<n && count<5; k++)
{
j++;
b[j]=a[k];
count++;
if(count==5)
{
j++;
b[j]='0'; count=0;
}
i=k;
}
if(k<n){
if(a[k]=='0'){
j++;
b[j] = a[k];
}
i=k;
 }
else{ flag=1; break; }
}
else{
b[j] = a[i];
i++;
j++;
 }
 }
j++; b[i] = '\0';
printf("\nAfter stuffing the frame is:");
printf("%s\n",b);
return 0;
}