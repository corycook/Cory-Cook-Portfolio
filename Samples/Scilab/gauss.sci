function Area=gauss(f,a,b)
    c=0.33998104
    d=0.65214515
    e=0.86113631
    g=0.34785485
    x1=(c*b-a+a+b)/2
    x2=(-c*b-a+a+b)/2
    x3=(e*(b-a)+a+b)/2
    x4=(-e*(b-a)+a+b)/2
    Area=d*f(x1)+d*f(x2)
    Area=Area+g*f(x3)+g*f(x4)
endfunction
