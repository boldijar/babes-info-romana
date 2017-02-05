load data3
% Calculez parametrul de estimare al distributiei normale
mu = mean(data3);
v = var(data3);
% Obtin 'normpdf' pe baza parametrului de estimare
xp = linspace(min(data3),max(data3));
yp = normpdf(xp,mu,v);
% Colectez informatia necesara construirii histogramelor.
[nu,x] = hist(data3);
h = x(2)-x(1);
% Trasez graficul densitatii prin histograme 
bar(x,nu/(140*h),1)
hold on
plot(xp,yp)
xlabel('Lungime')
title('Histograma densitatii si estimarea densitatii normale')
hold off