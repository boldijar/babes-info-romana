function l13-1-tevi(X)
    % X - vector
    n = length(X);
    alpha = 0.01;
    xBara = mean(X);
    sigma0 = 4;
    suma = 0;
 
    for i = 1 : n
        suma = suma + ((X(i) - xBara) ^ 2);
    end
 
    s = ((1 / (n - 1)) * suma) ^ (1 / 2);
    q = ((n - 1) / (sigma0 ^ 2)) * (s ^ 2);
 
    q1Alpha = chi2inv(1 - alpha, n - 1);
 
    if 0 == vartest(X, 4, 0.01, 'right')
        disp('se poate continua');
    else
        disp('NU se poate continua');
    end
end

