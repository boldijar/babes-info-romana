function A=RandomPerm(n)
%RANDOMPERM - generate a random permutation
A=1:n;
for i = 1:n-1
    j=randi([i,n]);
    %swap A[i] and A[j]
    A([i,j])=A([j,i]);
end
