% Rand 1

% a.) Intr-un grup de 40 de persoane, 10 sunt sanatoase, iar restul au fie
% hipertensiune, fie un nivel ridical al colesterolului sau sufera de ambele
% afectiuni. Care este probabilitatea ca o persoane sa aiba cele doua afectiuni,
% stiind ca sunt 15 persoane care au hipertensiune si 25 de persoane care au
% colesterolul crescut?

display("PUNCTUL A");

t=40;   % numarul total de persoane
s=10;   % numarul de persoane care sunt sanatoase 
h=15;   % numarul de persoane care au hipertensiune
c=25;   % numarul de persoane care au colesterolul ridicat
b=t-s;  % numarul de persoane care sunt bolnave

%hc=abs(b-h-c);
hc=abs(t-h-c);

%pos=b; % numarul de cazuri posibile
pos=t; % numarul de cazuri posibile
fav=hc;

display("Cazuri favorabile:");
display(fav);

display("Cazuri posibile:");
display(pos);

