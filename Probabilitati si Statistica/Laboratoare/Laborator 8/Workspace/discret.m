function d = discret(x,p,N)
p=[0 sort(p,'descend')];
q=cumsum(p);
a=[];
for i=1:N
    u=unifrnd(0,1);
    j=1;
    while q(j)<u
        j=j+1;
    end
    a=[a x(j-1)];
end
%disp(a);
d=a;
end