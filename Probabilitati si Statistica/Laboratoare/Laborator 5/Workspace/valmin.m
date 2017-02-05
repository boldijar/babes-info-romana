function k=valmin(n,p)
%pentru p=0.75 se obtine valoarea k ceruta in problema
k=1;
while repartitie(n,k)<0.75
  k=k+1;
end
clear all
n=1:10:100;
k=[];
for i=1:length(n)
  k=[k valmin(n(i),0.75)];
end
plot(n,k,’o-’)