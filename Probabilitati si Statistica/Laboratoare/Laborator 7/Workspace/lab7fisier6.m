% 6. 
% normrnd
% 

N=1000;         % numarul de simulari
v=zeros(1,N);   % vector de o linie si N coloane

for i=1:N
    nor=normrnd(7,1);
    v(i)=nor>4.5 && nor<7;
end

tabulate(v);
% aria de sub grafic de la x=4.5 pana la x=7
rez=normcdf(7,7,1)-normcdf(4.5,7,1);
rez
