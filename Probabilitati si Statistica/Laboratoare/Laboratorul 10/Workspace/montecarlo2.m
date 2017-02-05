function montecarlo2(n)
    % a)
    x = unifrnd(0, 1, 1, n);
    m = max(x .^ 3);
    y = unifrnd(0, m, 1, n);
    intA = mean(y);
    disp(intA)
 
    % b)
    x1 = unifrnd(2, 5, 1, n);
    m1 = max(1 ./ (sqrt(x1 - 1)));
    y1 = unifrnd(0, m1, 1, n);
    intB = mean(y1);
    disp(intB)
 
    % c)
    x2 = unifrnd(- 1, 2, 1, n);
    y = zeros(1, n);
    for i = 1:n
        if x2(i) <= 0
            y(i) = 1 ./ (1 + x2(i) .^ 2);
        else if x2(i) < 1
            y(i) = (1 ./ x2(i) .^ 2) * (sin(x2(i) ./ (1 - x2(i))) .^ 2);
        else
            y(i) = sqrt(2 * x2(i) - x2(i) .^ 2);
        end
    end
end
m2 = max(y);
y2 = unifrnd(1, m2, 1, n);
intC = mean(y2);
disp(intC)

end
