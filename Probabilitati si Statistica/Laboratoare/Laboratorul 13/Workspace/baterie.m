function baterie()
    ore = [343 * ones(1, 25), 345 * ones(1, 15), 347 * ones(1, 132), 348 * ones(1, 84), 349 * ones(1, 40), 350 * ones(1, 34), 352 * ones(1, 51), 353 * ones(1, 8), 355 * ones(1, 11)];
    frecv = [25, 15, 132, 84, 40, 34, 51, 8, 11];
    
    x = mean(ore);
    sn = std(ore);
    n = sum(frecv);
    t = (x - 350) / (sn / sqrt(n));
    ta = tinv(0.01, n - 1);
    
    if (t > ta)
        display('Ipoteza e acceptata.');
    else
        display('Ipoteza e respinsa. Publicitatea companiei e falsa!')
    end
    
    ttest(x, 350, 0.01, 'left')
end
