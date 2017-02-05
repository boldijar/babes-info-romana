function dice=demere(nrdesimulari)
    sum = 0;
    for exp = 1:nrdesimulari
        mat = unidrnd(6,1,4);
        rez = 0;
        for i = 1:length(mat)
            if mat(i) == 6
                rez = rez + 1;
            end
        end
        if rez ~= 0
            sum = sum + 1;
        end
    end
    dice = sum/nrdesimulari;
end