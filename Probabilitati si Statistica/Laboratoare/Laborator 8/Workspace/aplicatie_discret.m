function d=aplicatie_discret(N)
    x=[1,2,3,4];
    p=[23/50,20/50,5/50,2/50];
    y=discret(x,p,N);
    [f x]=ecdf(y);
    frecvente=[f(2) - f(1),f(3)-f(2),f(4)-f(3),f(5)-f(4)];
    disp(frecvente);
end