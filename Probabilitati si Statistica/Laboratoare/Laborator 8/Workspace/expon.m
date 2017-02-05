function rez=expon(lambda,N)
    a=[];
    for i=1:N
        u=unifrnd(0,1);
        x=-lambda*log(1-u);
        a=[a x];
    end
    rez=a;
end