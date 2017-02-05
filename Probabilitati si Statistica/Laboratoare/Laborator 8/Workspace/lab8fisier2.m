function urna_simulare(N)
y=discret(1:4,[0.46 0.4 0.1 0.04],N)
[f,x]=ecdf(y);
probabilitati=[0.46 0.4 0.1 0.04]
%Are loc proprietatea P(i-1<=X<i)=f(i)-f(i-1), in cazul nostru P(i-1<=X<i)=P(X=i-1)
frecvente=[f(2)-f(1) f(3)-f(2) f(4)-f(3) f(5)-f(4)]
end
