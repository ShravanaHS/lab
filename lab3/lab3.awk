BEGIN{
a=0
}
{
if($1=="r"&&$4=="7"&&$5=="cbr"&&$6=="1000")
{
a++;
}
}
END{
printf("\n total number of data packets at Node 7: %d\n", a++);
}
