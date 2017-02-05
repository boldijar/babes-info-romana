function volum_elipsoid(a, b, c, N)
    cont = 0;
    
    for i = 1:N
        x = unifrnd(- abs(a), abs(a));
        y = unifrnd(- abs(b), abs(b));
        z = unifrnd(- abs(c), abs(c));
    
        if x .^ 2 / a .^ 2 + y .^ 2 / b .^ 2 + z .^ 2 / c .^ 2 <= 1
            cont = cont + 1;
        end
    end
    
    disp(8 * a * b * c * (cont / N));
    disp((4 / 3) * a * b * c * pi);
end
