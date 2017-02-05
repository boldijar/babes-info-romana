function volum_sfera(r, N, expo)
    cont = 0;
    
    for i = 1:N
        x = unifrnd(- abs(r), abs(r));
        y = unifrnd(- abs(r), abs(r));
        z = unifrnd(- abs(r), abs(r));
        
        if x ^ 2 + y ^ 2 + z ^ 2 <= r ^ 2
            cont = cont + 1;
        end
    end
    
    disp(((2 * r) ^ expo) * (cont / N));
    disp(sqrt(pi ^ expo) * (r ^ expo) / gamma(3 / 2 + 1));
end
