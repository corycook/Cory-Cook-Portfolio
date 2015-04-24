*version 9.1 4252646315
u 129
C? 3
R? 4
U? 3
? 2
@libraries
@analysis
@targets
@attributes
@translators
a 0 u 13 0 0 0 hln 100 PCBOARDS=PCB
a 0 u 13 0 0 0 hln 100 PSPICE=PSPICE
a 0 u 13 0 0 0 hln 100 XILINX=XILINX
@setup
unconnectedPins 0
connectViaLabel 0
connectViaLocalLabels 0
NoStim4ExtIFPortsWarnings 1
AutoGenStim4ExtIFPorts 1
@index
pageloc 1 0 2489 
@status
n 0 113:04:16:23:06:28;1368770788 e 
s 2832 113:04:16:23:06:28;1368770788 e 
*page 1 0 970 720 iA
@ports
port 3 GND_EARTH 210 360 h
port 2 GND_EARTH 210 240 h
@parts
part 13 r 220 340 h
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R2
a 0 ap 9 0 15 0 hln 100 REFDES=R2
part 14 r 310 340 h
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R3
a 0 ap 9 0 15 0 hln 100 REFDES=R3
part 20 OPAMP 270 300 U
a 0 sp 11 0 50 60 hln 100 PART=OPAMP
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=U1
a 0 ap 9 0 14 0 hln 100 REFDES=U1
part 12 r 310 220 h
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R1
a 0 ap 9 0 15 0 hln 100 REFDES=R1
part 113 c 250 220 H
a 0 sp 0 0 0 10 hlb 100 PART=c
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=CK05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=C2
a 0 ap 9 0 15 0 hln 100 REFDES=C2
a 0 u 13 13 10 -10 hln 100 IC=10V
part 1 titleblk 970 720 h
a 1 s 13 0 350 10 hcn 100 PAGESIZE=A
a 1 s 13 0 180 60 hcn 100 PAGETITLE=
a 1 s 13 0 300 95 hrn 100 PAGENO=1
a 1 s 13 0 340 95 hrn 100 PAGECOUNT=1
part 103 nodeMarker 350 280 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 4 22 hlb 100 LABEL=1
@conn
w 27
a 0 up 0:33 0 0 0 hln 100 V=
s 270 300 270 340 28
s 310 340 270 340 50
a 0 up 33 0 290 339 hct 100 V=
s 270 340 260 340 54
w 90
a 0 up 0:33 0 0 0 hln 100 V=
s 210 340 220 340 89
s 210 360 210 340 87
a 0 up 33 0 212 350 hlt 100 V=
w 97
a 0 up 0:33 0 0 0 hln 100 V=
s 350 340 350 280 60
s 350 280 350 220 62
a 0 up 33 0 352 250 hlt 100 V=
w 112
a 0 up 0:33 0 0 0 hln 100 V=
s 270 260 270 220 43
s 270 220 310 220 48
a 0 up 33 0 290 219 hct 100 V=
s 270 220 250 220 116
w 8
a 0 up 0:33 0 0 0 hln 100 V=
s 210 220 210 240 6
s 210 220 220 220 122
@junction
j 310 340
+ p 14 1
+ w 27
j 260 340
+ p 13 2
+ w 27
j 270 340
+ w 27
+ w 27
j 220 340
+ p 13 1
+ w 90
j 210 360
+ s 3
+ w 90
j 350 340
+ p 14 2
+ w 97
j 350 220
+ p 12 2
+ w 97
j 350 280
+ p 103 pin1
+ w 97
j 270 300
+ p 20 +
+ w 27
j 350 280
+ p 20 OUT
+ w 97
j 350 280
+ p 103 pin1
+ p 20 OUT
j 270 260
+ p 20 -
+ w 112
j 310 220
+ p 12 1
+ w 112
j 210 240
+ s 2
+ w 8
j 250 220
+ p 113 1
+ w 112
j 270 220
+ w 112
+ w 112
j 220 220
+ p 113 2
+ w 8
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
