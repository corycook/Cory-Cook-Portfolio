function x = secant_method(func, tol)
    x = func(0)
    xp = 0
    while(abs(func(x)) > tol)
        temp = x
        x = x - func(x)*(x-xp)/(func(x)-func(xp))
        xp = temp
    end
endfunction

function y=afunc(x)
    y = x^3-2
endfunction
