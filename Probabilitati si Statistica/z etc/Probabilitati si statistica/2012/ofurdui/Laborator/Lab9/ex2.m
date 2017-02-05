% Setez parametrii
lam = 2;
n = 1000;
% Generez variabila aleatoare
uni = rand(1,n);
X = -log(uni)/lam;
% Obtin valorile pentru trasarea curbei teoretice 
x = 0:.1:5;
% Functia corespunzatoare din pachetul 'Statistics Toolbox'
y = exppdf(x,1/2);
% Construiesc histogramele
[N,h] = hist(X,10);
N = N/(h(2)-h(1))/n;
% Trasez graficul
bar(h,N,1,'w')
hold on
plot(x,y)
hold off
xlabel('X')
ylabel('f(x) - exponential')