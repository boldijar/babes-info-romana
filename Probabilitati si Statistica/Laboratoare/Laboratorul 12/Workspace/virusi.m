% n fixat
N = 1000;
for n = 1:20
    clf
    for i = 1:N
        virusi_pe_n_zile = exprnd(0.01, 1, n);
        media_n_zile(i) = mean(virusi_pe_n_zile);
    end
    hist(media_n_zile);
    pause();
    % vom apasa o tasta pt a trece la urmatoarea hist
end
