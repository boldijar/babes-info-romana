contor = 0;
M = 100;
n = 100;
k = 10;
m = 5;

for i = 1:M
    cast = randsample(n, k); %n bilete din care k castig
    cum = randsample(n, m);
    vect = ismember(cast, cum);  %un vect cu elem true sau false
    c = sum(vect);  % vedem cati castigatori sunt dintre cumparatori
    if c > 0
        contor = contor + 1;
    end
end

contor
