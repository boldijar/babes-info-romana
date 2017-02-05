function avg_barbati()
    sprintf('Problema 3')
 
    % barbati
    x_b = [1.848, 1.69, 1.763, 1.728, 1.70, 1.80, 1.755];
    
    x = mean(x_b);
    sn = std(x_b);
    n = 7;
 
    medie_b = 1.72;
 
    t = (x - medie_b) / (sn / sqrt(n));
    ta = tinv(1 - 0.05 / 2, n - 1);
    
    if (t < ta)
        display('Ipoteza e acceptata.');
    else
        display('Ipoteza e respinsa.')
    end
    
    ttest(x_b, medie_b)
end
