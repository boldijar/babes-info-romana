function test(N)
    format long
    distributie = [round(0:30); binopdf(0:30, 30, 1 / 4)]
    A = binornd(30, 1 / 4, 1, N);
    hist(A, 15);
    set(gca, 'XTick', 0:30);
end
