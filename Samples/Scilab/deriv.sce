x = 0:.001:2;
y=exp(x);
h=.002;
yl=(exp(x)-exp(x-h))/h;
yr=(exp(x+h)-exp(x))/h;
ym=(exp(x+h)-exp(x-h))/(2*h);

h2=.001;
yl2=(exp(x)-exp(x-h2))/h2;
yr2=(exp(x+h2)-exp(x))/h2;
ym2=(exp(x+h2)-exp(x-h2))/(2*h2);

ylr=2*yl2-yl;
yrr=2*yr2-yr;
ymr=2*ym2-ym;
mtlb_semilogy(x,abs(y-yl),'b-',x,abs(y-yr),'g-',x,abs(y-ym),'c-',x,abs(y-yl2),'b--',x,abs(y-yr2),'g--',x,abs(y-ym2),'c--',x,abs(y-ylr),'b:',x,abs(y-yrr),'g:',x,abs(y-ymr),'c:')
