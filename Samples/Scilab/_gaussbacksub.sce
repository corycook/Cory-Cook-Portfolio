function x = _gel(u, b)
[uheight uwidth] = size(u);
u = _gaussElim([u b])
b = u(1:uheight, uwidth+1:max(size(u)))
u = u(1:uheight, 1:uwidth)
for n=1:max(size(b))
    x(n) = _backsub(u(:,n), b(:,n))
end
endfunction
//for(i=n:-1:1)
//    x(i)=(b(i)-u(i,i+1:n)*x(i+1:n))/u(i,i);
//end
