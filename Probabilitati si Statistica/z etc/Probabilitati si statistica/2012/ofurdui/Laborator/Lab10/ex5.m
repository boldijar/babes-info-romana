% Generez un experiment cu reprezentare normala pentru fiecare dimensiune.
n = 1000;
d = 2;
x = randn(n,d);
% Originea sistemului.
bin0 = [floor(min(x(:,1))) floor(min(x(:,2)))];
h = 3.504*n^(-0.25)*ones(1,2);
% gasirea numarului ce reprezinta pe 'bin'
nb1 = ceil((max(x(:,1))-bin0(1))/h(1));
nb2 = ceil((max(x(:,2))-bin0(2))/h(2));
% folosesc functia 'mesh'
t1 = bin0(1):h(1):(nb1*h(1)+bin0(1));
t2 = bin0(2):h(2):(nb2*h(2)+bin0(2));
[X,Y] = meshgrid(t1,t2);
% Frecventele lui 'bin'
[nr,nc] = size(X);
vu = zeros(nr-1,nc-1);
for i = 1:(nr-1)
for j = 1:(nc-1)
xv = [X(i,j) X(i,j+1) X(i+1,j+1) X(i+1,j)];
yv = [Y(i,j) Y(i,j+1) Y(i+1,j+1) Y(i+1,j)];
in = inpolygon(x(:,1),x(:,2),xv,yv);
vu(i,j) = sum(in(:));
end
end
Z = vu/(n*h(1)*h(2));
% Trasarea axelor 
[XX,YY] = meshgrid(linspace(-3,3,nb1),...
linspace(-3,3,nb2));
surf(XX,YY,Z)