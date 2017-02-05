% PROBLEMA 2
A = []; % vector nul
for i = 1 : 6
	for j = 1 : 6
		for k = 1 : 6
			A = [A i+j+k];
		end
	end
end
A % 216 sume = 6 x 6 x 6
tabulate (A) % pariem pe sumele care au cea mai mare frecventa

suma_cea_mai_probabila = mode (A);
prob = length (find (A == suma_cea_mai_probabila)) / length (A)

% generam o functie de tip “mode” care ret elem cu cea mai mica frecventa
table = tabulate (A);
[r c] = size (table);
table = table (3 : r, : ); % se elimina primele 2 linii
indici = find (table ( : , 2) == min (table ( : , 2)))
table (indici (1), 1) % ← elementul cu cea mai mica frecventa
prob_minim = table (indici (1), 3)

% simulator
N = 100;
aruncare_3_zaruri = unidrnd (6, N, 3)
sume = sum (aruncare_3_zaruri, 2)
tabulate (sume)
