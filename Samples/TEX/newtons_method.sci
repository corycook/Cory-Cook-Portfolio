function x = newtons_method(myfunc, myfuncder, x0, tol)
    xp = x0+tol*2
    xn = x0
    while(abs(xn-xp) > tol)
        xp = xn
        xn = xp-myfunc(xp)/myfuncder(xp)
    end
    x = xn
endfunction
