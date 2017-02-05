clear all
%simulare sortare vectori de lungime l
l=10;
N=100;
timp=zeros(1,N);
timp1=zeros(1,N);

for i=1:N
    A=randperm(l);%generam o permutare aleatoare de ordin l

    tic;
    A1=QuickSort(A,1,length(A));
    timp(i)=toc;

    tic;
    A2=RandomizedQuickSort(A,1,length(A));
    timp1(i)=toc;
end

%valoarea medie a timpului de executie pentru cele doua metode de sortare
fprintf('Valoarea medie a timpului de executie la QuickSort:\n');
fprintf('          QuickSort:   %.8f\n',mean(timp));
fprintf('RandomizedQuickSort:   %.8f\n',mean(timp1));