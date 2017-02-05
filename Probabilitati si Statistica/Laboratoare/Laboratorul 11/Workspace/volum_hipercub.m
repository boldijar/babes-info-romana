function volum_hipercub(u, v, n, N)
    d = [];
    q = [];
    
    for i = 1:N
        q = zeros(1, n);
        
        for j = 1:n
            q(j) = unifrnd(u(i), v(i));
        end
        
        d(i) = sum(q .^ 2);
    end
    
    mean(d);
end
