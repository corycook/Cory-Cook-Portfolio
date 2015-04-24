function Y=L_interpolate(x_data,y_data,X)
    // precalculate
    L_c(1)=y_data(1)/((x_data(1)-x_data(2))*(x_data(1)-x_data(3))*(x_data(1)-x_data(4))*(x_data(1)-x_data(5)))
    L_c(2)=y_data(2)/((x_data(2)-x_data(1))*(x_data(2)-x_data(3))*(x_data(2)-x_data(4))*(x_data(2)-x_data(5)))
    L_c(3)=y_data(3)/((x_data(3)-x_data(1))*(x_data(3)-x_data(2))*(x_data(3)-x_data(4))*(x_data(3)-x_data(5)))
    L_c(4)=y_data(4)/((x_data(4)-x_data(1))*(x_data(4)-x_data(2))*(x_data(4)-x_data(3))*(x_data(4)-x_data(5)))
    L_c(5)=y_data(5)/((x_data(5)-x_data(1))*(x_data(5)-x_data(2))*(x_data(5)-x_data(3))*(x_data(5)-x_data(4)))
    
    // main eval
    Y=zeros(X)
    for i=1:max(size(X)) // X
        for lnum=1:5 // L_lnum
            Lval=L_c(lnum)
            for j=1:5 // u_j
                if j~=lnum then
                    Lval=Lval*(X(i)-x_data(j))
                end
            end
            Y(i)=Y(i)+Lval
        end
    end
endfunction
