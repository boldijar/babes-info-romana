% 1 fete    rosu        r
% 2 baieti  albastru    b
% 3 x       verge       g

n = 1; m = 2; N = 5;
contor1 = 0; % X capat
contor2 = 0; % X intre 2 vecine

for i = 1 : N
    clf
    axis equal
    axis([1 2*(m+n+1)+1 -2 2]);
    axis off;
    title('SIMULARE')
    asezare = [ones(1, n), 2 * ones(1, m), 3]; % constructia vectorului de asezare
    asezare = asezare(randperm(n + m + 1));
    for j = 1 : n + m + 1
        if asezare(j) == 1
            rectangle('Position', [2*j 0 1 1], 'Curvature', [1 1], 'FaceColor', 'r')
        end
        if asezare(j) == 2
            rectangle('Position', [2*j 0 1 1], 'Curvature', [1 1], 'FaceColor', 'b')
        end
        if asezare(j) == 3
          rectangle('Position', [2*j 0 1 1], 'Curvature', [1 1], 'FaceColor', 'g')
          if j == 1 || j == n + m + 1
            contor1 = contor1 + 1;
          elseif asezare(j-1) == 1 && asezare(j + 1) == 1
            contor2 = contor2 + 1;
          end
        end
    end
    
    text(3, -1, num2str(contor1))
    text(5, -1, num2str(contor2))
    pause(5);
end