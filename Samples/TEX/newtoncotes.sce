deff('y=f1(x)','y=x^3')

function Mf=nc(f,a,b)
    Mf=(b-a)*f((a+b)/2)
endfunction

function Tf=nc2(f,a,b)
    Tf=.5*(b-a)*(f(a)+f(b))
endfunction

function Sf=nc3(f,a,b)
    Sf=((b-a)/6)*(f(a)+4*f((a+b)/2)+f(b))
endfunction

function out=t(a,b,al,be,x)
    out=((b-a)*x+al*be-b*al)/(be-al)
endfunction

function Ig=G(f,f2,x1,x2)
    Ig=0.5*(f(f2(0,1,-1,1,x1))+f(f2(0,1,-1,1,x2)))
endfunction
