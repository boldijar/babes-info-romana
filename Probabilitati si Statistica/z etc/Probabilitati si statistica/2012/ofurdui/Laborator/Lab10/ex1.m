load data1
subplot(1,2,1)
[n,x] = hist(data1);
bar(x,n,1);
axis square
title('Histograma frecventelor')
% creez histograma frecventelor relative 
% Divizam setul de date la numarul total de puncte
subplot(1,2,2)
bar(x,n/140,1)
title('Histograma frecventelor relative')
axis square