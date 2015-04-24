for n=1:10
    p(1,n) = sqrt(2*%pi*n)*(n/%e)^n;
    p(2,n) = factorial(n);
    y(n) = p(2,n) - p(1,n);
    x(n) = y(n)/p(2,n);
end
// p(1,n) - approx.
// p(2,n) - actual
// y - absolute errror
// x - relative error
