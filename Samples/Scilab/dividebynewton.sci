function result=dividebynewton(a,b,tol)
    xi=.1+tol*2
    x=.1
    while (abs(x-xi)>tol)
        xi=x
        x=2*xi-b*xi*xi
    end
    result=a*x
endfunction
