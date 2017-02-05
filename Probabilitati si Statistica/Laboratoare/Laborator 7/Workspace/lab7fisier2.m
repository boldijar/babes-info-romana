% 2. Distributie geometrica
% geornd
% geopdf

N=1000;         % numarul de simulari
v=zeros(1,N);   % vector de o linie si N coloanev=zeros(1,N);

for i=1:N
    v(i)=geornd(0.95);
end

tabulate(v);
disp([(1:4)',100*geopdf(1:4,0.95)']);
