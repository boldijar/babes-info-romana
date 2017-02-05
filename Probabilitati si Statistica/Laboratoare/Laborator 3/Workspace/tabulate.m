function s = tabulate()
    m = unidrnd(6,3,4);
    a = zeros(18,1);
    for i = 1:length(m)
        sum = 0;
        for j = 1:3
            sum = sum + m(j,i);
        end
        a(sum) = a(sum) + 1;
    end
    for i = 1:18
        p = a(i)/4 * 100;
        fprintf('%d %d %d%% \n',i,a(i),p);
    end
end