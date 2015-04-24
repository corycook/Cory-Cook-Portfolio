function u = _gaussElim(u)
    n = min(size(u))
    for col=1:n-1
        for row=col+1:n
            u(row,:)=u(row,:)-(u(row,col)/u(col,col))*u(col,:)
        end
    end
endfunction


