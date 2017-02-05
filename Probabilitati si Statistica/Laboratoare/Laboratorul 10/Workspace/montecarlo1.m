function montecarlo1(n)
    % a)
    x = unifrnd(0, 1, 1, n);
    m = max(x .^ 3);
    y = unifrnd(0, m, 1, n);
    p = 0;
    for i = 1:n
        if y(i) <= x(i) .^ 3
            p = p + 1;
        end
    end
    intA = m * (1 - 0) * p / n;
    disp(intA);
 
    % b)
    x1 = unifrnd(2, 5, 1, n);
    m1 = max(1 ./ (sqrt(x1 - 1)));
    y1 = unifrnd(0, m1, 1, n);
    p1 = 0;
    for i = 1:n
        if y1(i) <= 1 / (sqrt(x1(i) - 1))
            p1 = p1 + 1;
        end
    end
    intB = m1 * (5 - 2) * p1 / n;
    disp(intB);
 
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
p2 = 0;
for i = 1:n
    if x2(i) <= 0
        if y2(i) <= 1 ./ (1 + x2(i) .^ 2)
            p2 = p2 + 1;
        end
    else if x2(i) < 1
        if y2(i) <= (1 ./ x2(i) .^ 2) * (sin(x2(i) ./ (1 - x2(i))) .^ 2)
            p2 = p2 + 1;
        end
    else
        if y2(i) <= sqrt(2 * x2(i) - x2(i) .^ 2)
            p2 = p2 + 1;
        end
    end
end
end

intC = m2 * (5 - 2) * p2 / n;
disp(intC);

end
