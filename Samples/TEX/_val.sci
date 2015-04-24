function out= _val(init, func)
    
    for i=1:3
        x(i) = func(init(i))
    end
endfunction
