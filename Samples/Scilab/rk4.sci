function y=rk4(f,y0,x)
    y=zeros(x)
    h=x(2)-x(1)
    y(1)=y0
    for i=2:max(size(x))
        F1=f(x(i),y(i))
        F2=f(x(i)+h/2,y(i)+F1/2)
        F3=f(x(i)+h/2,y(i)+F2/2)
        F4=f(x(i)+h,y(i)+F3)
        y(i)=y(i-1)+h*(F1+2*F2+2*F3+F4)/6
    end
endfunction
