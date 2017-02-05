% 1. Distributie biomiala
% binornd
% binopdf

N=1000;         % numarul de simulari
v=zeros(1,N);   % vector de o linie si N coloane

for i=1:N
   a=binornd(15, 0.6);  % juc trec toate nivelurile
   v(i)=binornd(a,0.3);
end

% tabulate - tabel de frecvebtam de cate ori apare un numar si afis si in frecv
% tabulate in octave nu afiseaza pentru 0
tabulate(v)
%100*binopdf(1:15,15,0.18)' % apostrof pt 
disp([(1:15)',100*binopdf(1:15,15,0.18)'])
