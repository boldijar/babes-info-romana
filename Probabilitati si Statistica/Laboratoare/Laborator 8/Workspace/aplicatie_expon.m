function rez=aplicatie_expon(N,k)
   y=expon(12,N);
   [f x] = ecdf(y, 'censoring', y>=k);
   frecvente=f(length(x));
   disp(frecvente);
   prob=expcdf(k,N);
   rez=prob;
end