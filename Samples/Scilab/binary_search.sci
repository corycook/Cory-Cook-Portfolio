function x =binary_search(funct,l,u,tol)
    fu=funct(u);
    while((u-l)>tol)
        m=(u+l)/2;
        fm=funct(m);
        if (fm*fu>0) 
            u=m;
            fu=fm;
        elseif(abs(fm)<tol)
            u=m;
            l=m;
        else
            l=m;
        end
    end
     x=m;   


endfunction
