function histograma(x, X, Y)
    clf;
    hold on;
    N = length(x);
 
    % n=ceil(1+log2(N));%->regula lui Sturges
    % determinam nr de subintervale
    n = ceil(2 * N ^ (1 / 3)); % ->regula lui Rice
    f = zeros(1, n); % frecventele absolute pt fiecare subintervale
    x = sort(x); % sortare vector x
    d = (x(N) - x(1)) / n; % lungimea unui subinterval
    a = x(1) + d * (0:n); % generare diviziune echidistanta de pas d
    % a contine capetele subintervalelor
    % calculez frecventele absolute pt fiecare subinterval
    for i = 1:N
        for j = 1:n
            if a(j) <= x(i) & x(i) <= a(j + 1)
                f(j) = f(j) + 1;
            end
        end
    end
 
    p = (1 / N) * f; % p contine frecventele relative
    h = (1 / d) * p; % probabilitatea ca un element dintr-un subinterval sa fie generat
    m = x(1) + d / 2 + d * (0:n - 1); % m=centrele pt bin-uri
    bar(m, h, 'histc'); % reprezentare bin-uri
    plot(X, Y, '-r', 'LineWidth', 2); % reprezentare grafica a densitatii de probabilitate
    set(gca, 'XTick', ceil(x(1)):1.5:ceil(x(N))); % setez markerii pt axa Ox sa mearga cu pas 1.5
end
