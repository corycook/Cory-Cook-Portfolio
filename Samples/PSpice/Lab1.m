% Cory Cook & Roman Ruiz
% Lab1 - CSE 403
R = [100 200 300 400];
V = [5 12];
A = [R(1)+R(3) -R(1) -R(3);
     -R(1) R(2)+R(1) 0;
     -R(3) 0 R(4)+R(3)];
b = [V(1); -V(2); 0];
x = A\b;