% 4. Legea Poisson
% binornd
% poisspdf

N=1000;         % numarul de simulari
n=40000;        % 
p=0.0025;       % valoarea probabilitatii
v=zeros(1,N);   % vector de o linie si N coloane

for i=1:N
    b=binornd(1,p,1,n);  % vector cu n=40000 elem si p col
    v(i)=sum(b);
end

tabulate(v);
lambda=n*p;
disp([(1:20)',100*poisspdf(1:20,lambda)']);

%
%daca avem n variabile aleatorre care urmeaza distr bino
%atunci
%N = 1000; % nr de simulari
%n = 40000;
%p = 0.0025;% probab
%v = zeros(1,N); %vetor de o linie si N col
%for i = 1:N
%    b = binornd(1, p, 1, n); %vector cu n = 40000 elem
%    v(i) = sum(b);
%end
%tabulate(v);
%lambda = n * p;
%disp([(0:20)', 100 * poisspdf(0:20, lambda)']);
%%binopdf(0:15, 15, 0.18)']
