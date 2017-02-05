% Creez domeniul
[x,y,z] = meshgrid(-3:.1:3,-3:.1:3,-3:.1:3);
[n,d] = size(x(:));
% Evaluez datele trivariate normal reprezentate.
a = (2*pi)^(3/2);
arg = (x.^2 + y.^2 + z.^2);
prob = exp((-.5)*arg)/a;
% Trasez planele x=0, y=0, z=0:
slice(x,y,z,prob,0,0,0)
xlabel('Axa X'),ylabel('Axa Y'),zlabel('Axa Z')