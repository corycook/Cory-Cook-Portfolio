cd("C:\Users\Cory\SkyDrive\Documents\College\CSE535")
getd("C:\Users\Cory\SkyDrive\Documents\College\CSE535")

b = read("b.txt",5,19);
A=[10  8  6  4  2
    8 10  8  6  4
    6  8 10  8  6
    4  6  8 10  8
    2  4  6  8 10];
A=A/norm(A);


function x = _gel(u, b)
    [uh uw] = size(u);
u = _gaussElim([u b]);
b = u(1:uh, uw+1:max(size(u)))
u = u(1:uh, 1:uw)
for col = 1:max(size(b))
    x(:,col) = _backsub(u, b(:,col));
end
endfunction
