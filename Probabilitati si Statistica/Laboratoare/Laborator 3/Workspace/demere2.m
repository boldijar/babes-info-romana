function dice = demere2(nrdesimulari)
    sum = 0;
    for i = 1:nrdesimulari
        exp2 = unidrnd(6,2,24);
        rez = 0;
        for j = 1:length(exp2)
            add = exp2(1,j) + exp2(2,j);
            if add == 12
                rez = rez + 1;
            end
        end
        if rez ~= 0
            sum = sum + 1;
        end
    end
    dice = sum/nrdesimulari;
end
    