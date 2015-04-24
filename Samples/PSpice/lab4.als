* Schematics Aliases *

.ALIASES
R_R2            R2(1=0 2=$N_0001 )
R_R3            R3(1=$N_0001 2=$N_0002 )
E_U1            U1(OUT=$N_0002 +=$N_0001 -=$N_0003 )
R_R1            R1(1=$N_0003 2=$N_0002 )
C_C2            C2(1=$N_0003 2=0 )
.ENDALIASES

