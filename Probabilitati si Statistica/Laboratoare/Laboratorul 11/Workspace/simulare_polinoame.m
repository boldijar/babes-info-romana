function simulare_polinoame(F, G, k, N)
    p = 0;
    
    for i = 1:N
        rez = polinoame(F, G, k);
        
        if rez == 0
            p = p + 1;
        end
    end
    
    disp(p / N);
    disp(hygecdf(k - 1, N, 3, k));
end
