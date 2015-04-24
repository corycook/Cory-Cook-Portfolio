function x = _backsub(u, b)
    n = max(size(u))
    x = zeros(n,1)
    for row = n:-1:1
        x(row)=(b(row)-u(row,row+1:n)*x(row+1:n))/u(row,row);
    end
endfunction
