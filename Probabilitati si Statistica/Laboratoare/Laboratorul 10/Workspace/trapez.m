function trapez(n)
    % a)
    x = 0:1 / n:1;
    y = x .^ 3;
    a = zeros(1, n);
    for i = 1:n
        a(i) = (1 / 2) * (x(i + 1) - x(i)) * (y(i) + y(i + 1));
    end
    intA = sum(a);
    disp(intA)
 
    % b)
    x1 = 2:1 / n:5;
    y1 = 1 ./ (sqrt(x1 - 1));
    a = zeros(1, n);
    for i = 1:n
        a(i) = (1 / 2) * (x1(i + 1) - x1(i)) * (y1(i) + y1(i + 1));
    end
    intB = sum(a);
    disp(intB)
 
    % c)
    x2 = - 1:1 / n:2;
    y2 = zeros(1, n);
    for i = 1:n
        if x2(i) <= 0
            y2(i) = 1 ./ (1 + x2(i) .^ 2);
        else if x2(i) < 1
            y2(i) = (1 ./ x2(i) .^ 2) * (sin(x2(i) ./ (1 - x2(i))) .^ 2);
        else
            y2(i) = sqrt(2 * x2(i) - x2(i) .^ 2);
        end
    end
end
a = zeros(1, n);
for i = 1:n
    a(i) = (1 / 2) * (x1(i + 1) - x1(i)) * (y1(i) + y1(i + 1));
end
intC = sum(a);
disp(intC)

end
