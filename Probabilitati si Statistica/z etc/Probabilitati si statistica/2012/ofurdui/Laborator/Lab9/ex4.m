n = 1000;
t = 3;
lam = 2;
U = rand(t,n);
logU = -log(U)/lam;
X = sum(logU);
[N,h] = hist(X,10);
N = N/(h(2)-h(1))/n;
x = 0:.1:6;
y = gampdf(x,t,1/lam);
bar(h,N,1,'w')
hold on
plot(x,y,'k')
hold off