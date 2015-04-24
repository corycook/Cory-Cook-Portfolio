function Area = midpt(f, x)
    Area=0
    for i=1:size(x, 1)-1
        Area = Area + f((x(i)+x(i+1))/2)*(x(i+1)-x(i))
    end
endfunction
