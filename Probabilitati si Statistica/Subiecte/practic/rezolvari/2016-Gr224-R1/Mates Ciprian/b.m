
N = 10000;
numara = 0;
verif = 0;
for i=1:N
    a = randi([1 30]); % hipertensiune
    bb = randi([1 30]); % colesterol
    
    while a+bb<30 && a > 30 && bb > 30 
        a = randi([1 30]);
        bb = randi([1 30]);
    end
    
    doar_hip = 30 - bb;
    doar_col = 30 - a;
    ambele = 30 - (doar_hip + doar_col);
    if doar_hip + doar_col + ambele + 10 == 40
        %disp('total 40');
        verif = verif + 1;
    end
    if ambele == 0
       %disp('au ambele');
       numara = numara + 1; 
    end
end
numara
verif
p = numara/N