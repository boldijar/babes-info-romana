% caz general
fav1 = 0;
fav2 = 0;
n = 1;
m = 4;

permutari=perms(1:(n+m+1));
for(i=1:factorial(n+m+1))
  asezare=[ones(1,n), 2*ones(1,m), 3];
  asezare=asezare(permutari(i,:));
  for (j=1:n+m+1)
    if(asezare(j)==3)
      if j==1 || j==n+m+1
        rectangle('Position', [2*j 0 1 1], 'Curvature', [1 1], 'FaceColor',  'r')
      elseif asezare(j-1) && asezare(j+1)==1
        fav2=fav2+1;
      end
    end
  end
end
prob1=fav1/factorial(n+m+1);