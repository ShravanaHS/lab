BEGIN{
a=0
b=0
}
{
if($1=="r"&&$4=="2"&&$5=="tcp"&&$6=="1040")
{
a++;
}
if($1=="r"&&$4=="2"&&$5=="cbr"&&$6=="1000")
{
b++;
}
}
END{
printf("\n total number of TCP data packets sent between Node 0 and Node 2: %d\n", a++);
printf("\n total number of UDP data packets sent between Node 1 and Node 2: %d\n", b++);
}
