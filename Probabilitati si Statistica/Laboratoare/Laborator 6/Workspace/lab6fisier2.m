n = 100;
k = 20;
m = 1;

while ((1 - hygepdf(0,n,k,m)) < 0.5)
    m = m + 1;
end

m

