function avg_femei()
    sprintf('Problema 3')
    
    % femei
    x_f = [1.619, 1.61, 1.669, 1.632, 1.608, 1.687, 1.640];
    
    x = mean(x_f);
    sn = std(x_f);
    n = 7;
 
    medie_f = 1.57;
 
    t = (x - medie_f) / (sn / sqrt(n));
    ta = tinv(1 - 0.05 / 2, n - 1);
    
    if (t < ta)
        display('Ipoteza e acceptata.');
    else
        display('Ipoteza e respinsa.');
    end
    
    ttest(x_f, medie_f)
end
