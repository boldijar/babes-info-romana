% Generez v.a. de tip normal (standard)
n = 10;
data = randn(1,n);
% Voi obtine estimarea densitatii ptr. valorile x
x = linspace(-4,4,50);
fhat = zeros(size(x));
h = 1.06*n^(-1/5);
hold on
for i=1:n
% evaluez functia  in fiecare x (centrat)
f = exp(-(1/(2*h^2))*(x-data(i)).^2)/sqrt(2*pi)/h;
plot(x,f/(n*h));
fhat = fhat+f/(n);
end
plot(x,fhat);
% hold off