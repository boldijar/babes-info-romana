function rez = polinoame(F, G, k)
    m = length(F);
    n = length(G);
    
    while F(m) == 0
        m = m - 1;
    end
    
    egale = 1;
    
    if m ~= n + 1
        egale = 0;
    else
        d = n;
        r = randsample(100 * d, k);
    
        for i = 1:k
            Fr = F(1);
            Gr = 1;
    
            for j = 1:d
                Fr = Fr + F(j + 1) * r(i) ^ j;
                Gr = Gr * (r(i) - G(j));
            end
    
            if Fr ~= Gr
                egale = 0;
            end
        end 
    end
    
    rez = egale;
end
