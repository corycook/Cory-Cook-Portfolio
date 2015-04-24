function xopt=gradient_descent (funct,grad,x0)
    tol = 1e-6
    alpha = .2
if(norm(x0)>tol)
    xold = (1+2*tol/norm(x0)).*x0
else
    xold = x0;
    xold(1) = xold(1) + 2*tol;
end
    xnew = x0
    while(norm(xnew-xold)>tol)
        xold = xnew
        xnew = xold-alpha*grad(xold)
    end
    xopt = xnew
endfunction
