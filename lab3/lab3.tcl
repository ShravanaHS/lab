set ns [new Simulator]

set tf [open lab3.tr w]
$ns trace-all $tf

set nf [open lab3.nam w]
$ns namtrace-all $nf

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]
set n6 [$ns node]
set n7 [$ns node]

$ns make-lan "$n0 $n1 $n2 $n3" 100Mb 300ms LL Queue/DropTail Mac/802_3
$ns make-lan "$n4 $n5 $n6 $n7" 100Mb 300ms LL Queue/DropTail Mac/802_3

$ns duplex-link $n3 $n4 100Mb 300ms DropTail

set err [new ErrorModel]
$ns lossmodel $err $n3 $n4
$err set rate_ 0.5

set udp [new Agent/UDP]
$ns attach-agent $n1 $udp

set cbr [new Application/Traffic/CBR]
$cbr attach-agent $udp
$cbr set fid_ 0
$cbr set packetSize_ 1500
$cbr set interval_ 0.001

set null [new Agent/Null]
$ns attach-agent $n7 $null
$ns connect $udp $null

proc finish {} {
    global ns nf tf
    $ns flush-trace
    close $nf
    close $tf
    exec nam lab3.nam &
    exit 0
}

$ns at 0.1 "$cbr start"
$ns at 3.0 "finish"
$ns run

