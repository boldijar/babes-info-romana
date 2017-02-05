% Domeniul de reprezentare al functiei
t = linspace(-pi,pi);
% Evaluarea valorilor functiei corespunzatoare fiecarui set de date.
f1 = 2/sqrt(2)+6*sin(t)+4*cos(t);
f2 = 5/sqrt(2)+7*sin(t)+3*cos(t);
f3 = 1/sqrt(2)+8*sin(t)+9*cos(t);
plot(t,f1,'.',t,f2,'*',t,f3,'o')
legend('Functia1','Functia2','Functia3')
xlabel('t')