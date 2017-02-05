function tevi
    n = 50;
    x = normrnd(200, 2, 1, n);
    sn = std(x);
    q = (n - 1) / 4 * sn ^ 2;
    qa = chi2inv(0.01, n - 1);
    qa1 = chi2inv(1 - 0.01, n - 1);
    
    if (q < qa1)
        display('Ipoteza initiala e acceptata.');
    else
        display('Productia e oprita, si e respinsa ipoteza initiala.');
     
    end
    
    %vartest(x,2,0.01,'right')
end
