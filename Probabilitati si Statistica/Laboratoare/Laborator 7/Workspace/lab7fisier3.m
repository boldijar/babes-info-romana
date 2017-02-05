% 3. Distributie hipergeometrica
% hygernd
% hygepdf

N=1000;         % numarul de simulari
v=zeros(1,N);   % vector de o linie si N coloanev=zeros(1,N);

for i=1:N
    v(i)=hygernd(12.,5,4);
end

tabulate(v);
disp([(1:4)',100*hygepdf(1:4,12,5,4)']);
