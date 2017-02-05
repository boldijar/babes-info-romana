% 5. 
% exprnd
% gamcdf

% Daca avem n variabile aleatoare care urmeaza distributia
% biomiala atunci

N=1000;         % numarul de simulari
v=zeros(1,N);   % vector de o linie si N coloane

for i=1:N
    v(i)=(exprnd(5)+exprnd(5)+exprnd(5)) < 12;
end

tabulate(v);
gamcdf(12,3,4)
