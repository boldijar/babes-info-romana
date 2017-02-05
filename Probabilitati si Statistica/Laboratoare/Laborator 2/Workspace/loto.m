clc
clear
n = 6; %cate numere se aleg
N = 8; %total de numere
M = 100000; %cati participanti
alese = randsample(1:N,n);
c1=0;
c2=0;
c3=0;
c4=0;

for i=1:M
    bilet=randsample(1:N,n);
    equ = numel(intersect(alese,bilet))
    if equ == 6
        c1=c1+1;
    elseif equ == 5
        c2=c2+1;
    elseif equ == 4
        c3=c3+1;
    elseif equ == 3
        c4=c4+1;
    end
end
fprintf('cat1 : %d\n',c1)
fprintf('cat2 : %d\n',c2)
fprintf('cat3 : %d\n',c3)
fprintf('cat4 : %d\n',c4)