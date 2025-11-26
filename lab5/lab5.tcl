set val(chan) Channel/WirelessChannel
set val(prop) Propagation/TwoRayGround
set val(netif) Phy/WirelessPhy
set val(mac) Mac/802_11
set val(ifq) Queue/DropTail/PriQueue
set val(ll) LL
set val(ant) Antenna/OmniAntenna
set val(ifqlen) 50
set val(nn) 8
set val(rp) AODV
set val(x) 2483
set val(y) 2506
set val(stop) 6.0


set ns [new Simulator]
set topo [new Topography]
$topo load_flatgrid $val(x) $val(y)
create-god $val(nn)
set tracefile [open lab5.tr w]
$ns trace-all $tracefile
set namfile [open lab5.nam w]
$ns namtrace-all $namfile
$ns namtrace-all-wireless $namfile $val(x) $val(y)
set chan [new $val(chan)]

$ns node-config -adhocRouting $val(rp) \
-llType $val(ll) \
-macType $val(mac) \
-ifqType $val(ifq) \
-ifqLen $val(ifqlen) \
-antType $val(ant) \
-propType $val(prop) \
-phyType $val(netif) \
-channel $chan \
-topoInstance $topo \
-agentTrace ON \
-routerTrace ON \
-macTrace ON \
-movementTrace ON

set n0 [$ns node]
$n0 set X_ 1752
$n0 set Y_ 1142
$n0 set Z_ 0.0
$ns initial_node_pos $n0 20
set n1 [$ns node]
$n1 set X_ 1590
$n1 set Y_ 962
$n1 set Z_ 0.0
$ns initial_node_pos $n1 20
set n2 [$ns node]
$n2 set X_ 1862
$n2 set Y_ 950
$n2 set Z_ 0.0
$ns initial_node_pos $n2 20
set n3 [$ns node]
$n3 set X_ 2202
$n3 set Y_ 1171
$n3 set Z_ 0.0
$ns initial_node_pos $n3 20
set n4 [$ns node]
$n4 set X_ 2135
$n4 set Y_ 982
$n4 set Z_ 0.0
$ns initial_node_pos $n4 20
set n5 [$ns node]
$n5 set X_ 2383
$n5 set Y_ 1029
$n5 set Z_ 0.0
$ns initial_node_pos $n5 20
set n6 [$ns node]
$n6 set X_ 1975
$n6 set Y_ 1202
$n6 set Z_ 0.0
$ns initial_node_pos $n6 20
set n7 [$ns node]
$n7 set X_ 1971
$n7 set Y_ 1406
$n7 set Z_ 0.0
$ns initial_node_pos $n7 20
$ns at 0.0 "$n0 label AP1"
$ns at 0.0 "$n1 label Source1"
$ns at 0.0 "$n2 label Destination2"
$ns at 0.0 "$n3 label AP2"
$ns at 0.0 "$n4 label Source2"
$ns at 0.0 "$n5 label Destination1"
$ns at 0.0 "$n6 label Router"
$ns at 0.0 "$n7 label Server/Gateway"

set tcp0 [new Agent/TCP]
$ns attach-agent $n1 $tcp0
set sink9 [new Agent/TCPSink]
$ns attach-agent $n5 $sink9
$ns connect $tcp0 $sink9
$tcp0 set packetSize_ 1500

set tcp11 [new Agent/TCP]
$ns attach-agent $n4 $tcp11
set sink10 [new Agent/TCPSink]
$ns attach-agent $n2 $sink10
$ns connect $tcp11 $sink10
$tcp11 set packetSize_ 1500

set ftp0 [new Application/FTP]
$ftp0 attach-agent $tcp0
$ns at 1.0 "$ftp0 start"
$ns at 3.0 "$ftp0 stop"

set ftp4 [new Application/FTP]
$ftp4 attach-agent $tcp11
$ns at 3.5 "$ftp4 start"
$ns at 5.0 "$ftp4 stop"

proc finish {} {
    global ns tracefile namfile
    $ns flush-trace
    close $tracefile
    close $namfile
    exec nam lab5.nam &
    exit 0
}

for {set i 0} {$i < $val(nn) } { incr i } {
    $ns at $val(stop) "\$n$i reset"
}
$ns at $val(stop) "$ns nam-end-wireless $val(stop)"
$ns at $val(stop) "finish"
$ns at $val(stop) "puts \"done\" ; $ns halt"
$ns run

