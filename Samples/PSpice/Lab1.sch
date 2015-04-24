*version 9.1 198917033
u 87
R? 6
V? 4
? 8
@libraries
@analysis
.DC 0 0 0 0 1 1
+ 0 0 V
+ 0 4 0
+ 0 5 20
+ 0 6 .1
.STMLIB Lab1.stl
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
pageloc 1 0 2759 
@status
n 0 113:03:11:13:41:59;1365712919 e 
s 2832 113:03:11:13:42:02;1365712922 e 
*page 1 0 970 720 iA
@ports
port 29 GND_EARTH 250 250 h
@parts
part 5 VDC 150 200 h
a 0 sp 0 0 22 37 hln 100 PART=VDC
a 1 u 13 0 -11 18 hcn 100 DC=5V
a 0 x 0:13 0 0 0 hln 100 PKGREF=Vs1
a 1 xp 9 0 24 7 hcn 100 REFDES=Vs1
part 61 r 330 210 v
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 x 0:13 0 0 0 hln 100 PKGREF=R4
a 0 xp 9 0 15 0 hln 100 REFDES=R4
a 0 u 13 0 15 35 hln 100 VALUE=400
part 62 VDC 160 140 v
a 0 sp 0 0 22 37 hln 100 PART=VDC
a 1 u 13 0 -11 18 hcn 100 DC=12V
a 0 x 0:13 0 0 0 hln 100 PKGREF=Vs2
a 1 xp 9 0 24 7 hcn 100 REFDES=Vs2
part 60 r 210 140 h
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 x 0:13 0 0 0 hln 100 PKGREF=R2
a 0 xp 9 0 15 0 hln 100 REFDES=R2
a 0 u 13 0 15 25 hln 100 VALUE=200
part 2 r 180 190 h
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R1
a 0 ap 9 0 15 0 hln 100 REFDES=R1
a 0 u 13 0 15 25 hln 100 VALUE=100
part 3 r 250 240 v
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 x 0:13 0 0 0 hln 100 PKGREF=R3
a 0 xp 9 0 15 0 hln 100 REFDES=R3
a 0 u 13 0 15 35 hln 100 VALUE=300
part 1 titleblk 970 720 h
a 1 s 13 0 350 10 hcn 100 PAGESIZE=A
a 1 s 13 0 180 60 hcn 100 PAGETITLE=
a 1 s 13 0 340 95 hrn 100 PAGECOUNT=1
a 1 s 13 0 300 95 hrn 100 PAGENO=1
part 86 nodeMarker 330 140 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 4 22 hlb 100 LABEL=7
@conn
w 66
a 0 up 0:33 0 0 0 hln 100 V=
s 160 140 150 140 65
s 150 190 150 200 38
s 150 190 180 190 11
a 0 up 33 0 165 189 hct 100 V=
s 150 140 150 190 67
w 76
a 0 up 0:33 0 0 0 hln 100 V=
s 330 210 330 250 75
s 150 240 150 250 32
s 250 250 250 240 46
s 250 250 150 250 19
a 0 up 33 0 200 249 hct 100 V=
s 330 250 250 250 77
w 64
a 0 up 0:33 0 0 0 hln 100 V=
s 200 140 210 140 63
a 0 up 33 0 205 139 hct 100 V=
w 28
a 0 up 0:33 0 0 0 hln 100 V=
s 250 190 220 190 27
a 0 up 33 0 275 184 hct 100 V=
s 250 190 250 200 37
s 250 140 250 190 69
s 330 140 330 170 73
s 330 140 250 140 79
@junction
j 220 190
+ p 2 2
+ w 28
j 250 200
+ p 3 2
+ w 28
j 150 200
+ p 5 +
+ w 66
j 180 190
+ p 2 1
+ w 66
j 150 190
+ w 66
+ w 66
j 250 190
+ w 28
+ w 28
j 150 240
+ p 5 -
+ w 76
j 250 240
+ p 3 1
+ w 76
j 250 250
+ w 76
+ w 76
j 330 170
+ p 61 2
+ w 28
j 330 210
+ p 61 1
+ w 76
j 250 250
+ s 29
+ w 76
j 330 140
+ p 86 pin1
+ w 28
j 200 140
+ p 62 -
+ w 64
j 160 140
+ p 62 +
+ w 66
j 210 140
+ p 60 1
+ w 64
j 250 140
+ p 60 2
+ w 28
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
