#===========================================
# Simulation Parameters
#===========================================
set val(stop) 10.0    ;# simulation stop time (seconds)

#===========================================
# Initialization
#===========================================
# Create the simulator instance
set ns [new Simulator]

# Open trace and NAM files
set tracefile [open lab6.tr w]
$ns trace-all $tracefile

set namfile [open lab6.nam w]
$ns namtrace-all $namfile

#===========================================
# Node Definition
#===========================================
# Create 5 nodes (n0–n4)
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]

#===========================================
# Link Definition
#===========================================
# Create duplex links between nodes with bandwidth, delay, and queue type
$ns duplex-link $n0 $n1 100Mb 10ms DropTail
$ns queue-limit $n0 $n1 50

$ns duplex-link $n0 $n2 100Mb 10ms DropTail
$ns queue-limit $n0 $n2 50

$ns duplex-link $n2 $n3 100Mb 10ms DropTail
$ns queue-limit $n2 $n3 50

$ns duplex-link $n1 $n3 100Mb 10ms DropTail
$ns queue-limit $n1 $n3 50

$ns duplex-link $n3 $n4 100Mb 10ms DropTail
$ns queue-limit $n3 $n4 50

$ns duplex-link $n0 $n3 100Mb 10ms DropTail
$ns queue-limit $n0 $n3 50

$ns duplex-link $n1 $n2 100Mb 10ms DropTail
$ns queue-limit $n1 $n2 50

#===========================================
# NAM Visualization (optional link orientation)
#===========================================
$ns duplex-link-op $n0 $n1 orient right
$ns duplex-link-op $n0 $n2 orient right-down
$ns duplex-link-op $n2 $n3 orient right
$ns duplex-link-op $n1 $n3 orient left-down
$ns duplex-link-op $n3 $n4 orient left-down
$ns duplex-link-op $n0 $n3 orient right-down
$ns duplex-link-op $n1 $n2 orient left-down

#===========================================
# Node Positions (for NAM visualization)
#===========================================
# Set manual coordinates for each node
$n0 set X_ 100
$n0 set Y_ 200

$n1 set X_ 300
$n1 set Y_ 200

$n2 set X_ 200
$n2 set Y_ 350

$n3 set X_ 400
$n3 set Y_ 300

$n4 set X_ 500
$n4 set Y_ 150

#===========================================
# Link Costs (for LS routing)
#===========================================
$ns cost $n0 $n1 2
$ns cost $n0 $n2 1
$ns cost $n0 $n3 3
$ns cost $n1 $n0 2
$ns cost $n1 $n2 2
$ns cost $n1 $n3 3
$ns cost $n2 $n0 1
$ns cost $n2 $n1 2
$ns cost $n2 $n3 1
$ns cost $n3 $n0 3
$ns cost $n3 $n1 3
$ns cost $n3 $n2 1
$ns cost $n3 $n4 2
$ns cost $n4 $n3 2

#===========================================
# Agent Definition
#===========================================
# Setup a UDP agent
set udp0 [new Agent/UDP]
$ns attach-agent $n0 $udp0

# Setup a Null agent as sink
set null1 [new Agent/Null]
$ns attach-agent $n4 $null1

# Connect UDP source to Null sink
$ns connect $udp0 $null1
$udp0 set packetSize_ 1500

#===========================================
# Application Definition
#===========================================
# Setup a CBR (Constant Bit Rate) traffic over UDP
set cbr0 [new Application/Traffic/CBR]
$cbr0 attach-agent $udp0
$cbr0 set packetSize_ 1500
$cbr0 set rate_ 1Mb
$cbr0 set random_ false

# Start/Stop times
$ns at 1.0 "$cbr0 start"
$ns at 5.0 "$cbr0 stop"

# Use Link State routing protocol
$ns rtproto LS

#===========================================
# Termination Procedure
#===========================================
proc finish {} {
    global ns tracefile namfile
    $ns flush-trace
    close $tracefile
    close $namfile
    exec nam lab6.nam &
    exit 0
}

# Schedule simulation end
$ns at $val(stop) "finish"

# Print done message
$ns at $val(stop) "puts \"Simulation completed\""

#===========================================
# Run Simulation
#===========================================
$ns run

