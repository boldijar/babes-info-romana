% Matricea covariantelor
vmat = [2, 1.5; 1.5, 9];
% Media 
mu = [2 3];
[u,s,v] = svd(vmat);
vsqrt = ( v*(u'.*sqrt(s)))';
% Generez v.a. normala
td = randn(250,2);
% Folosesc transformarea x=z*sigma+mu
data = td*vsqrt+ones(250,1)*mu;
% Folosesc functia 'scatterplot'
plot(data(:,1),data(:,2),'x')
axis equal
% Creez 'scatterplot' folosind functia 'scatter'
scatter(data(:,1),data(:,2),'filled')
axis equal
box on