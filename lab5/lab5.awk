BEGIN{
source1=0
source2=0
source3=0
source4=0
}
{
if($1=="s"&&$3=="_1_"&&$4=="AGT"&&$7=="tcp"&&$8=="1540")
{
source1++;
}
if($1=="s"&&$3=="_4_"&&$4=="AGT"&&$7=="tcp"&&$8=="1540")
{
source2++;
}
if($1=="r"&&$3=="_2_"&&$4=="AGT"&&$7=="tcp"&&$8=="1540")
{
source3++;
}
if($1=="r"&&$3=="_5_"&&$4=="AGT"&&$7=="tcp"&&$8=="1540")
{
source4++;
}
}
END{
printf("\n total number of data packets Sent by Node 1: %d\n", source1++);
printf("\n total number of data packets Sent by Node 4: %d\n", source2++);
printf("\n total number of data packets Received by Node 2: %d\n", source3++);
printf("\n total number of data packets Received by Node 5: %d\n", source4++);
}
