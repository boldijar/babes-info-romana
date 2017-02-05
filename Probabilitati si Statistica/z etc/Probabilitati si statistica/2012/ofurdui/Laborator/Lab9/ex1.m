% Vectorul variabilelor aleatoare uniforme in (0,1)
x = rand(1,1000);
% Construim graficul cu 'histogram'
[N,X] = hist(x,15);
% Folosim functia 'bar' pentru construirea graficului:
bar(X,N,1,' w')
title('Variabilele aleatoare uniform distribuite')
xlabel('X')
ylabel('Frecventa')