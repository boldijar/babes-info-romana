function a=discret(x,p,N)
p=[0 sort(p,'descend')];
q=cumsum(p);
a=[];

for i=1:N
    U=unifrnd(0,1);
    j=1;
    while q(j)<U
        j=j+1;
    end
        a=[a x(j-1)];
    end
end
%adaugam x(j-1) in vectorul a
