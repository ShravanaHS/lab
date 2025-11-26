BEGIN{
a=0
}
{
if($1=="r"&&$3=="3"&&$4=="4"&&$5=="cbr"&&$6=="1500")
{
a++;
}
}
END{
printf("\n total number of data packets received at Node 4: %d\n", a++);
}
