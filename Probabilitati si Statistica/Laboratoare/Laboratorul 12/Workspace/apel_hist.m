clear all
x = chi2rnd(4, 1, 200);
X = min(x):0.001:max(x);
Y = chi2pdf(X, 4);
figure(1)
histograma(x, X, Y);

clear all
x = betarnd(2, 3, 1, 200);
X = min(x):0.01:max(x);
Y = betapdf(X, 2, 3);
figure(2)
histograma(x, X, Y);

clear all
x = gamrnd(2, 3, 1, 200);
X = min(x):0.01:max(x);
Y = gampdf(X, 2, 3);
figure(3)
histograma(x, X, Y);

clear all
x = trnd(8, 1, 200);
X = min(x):0.001:max(x);
Y = tpdf(X, 8);
figure(4)
histograma(x, X, Y);
