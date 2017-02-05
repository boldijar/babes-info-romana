function intcomplex1
f = @(x,y,z) cos(x.*y.*exp(z));
%f = @(x,y,z) cos(x.*y).*exp(z);
for k=1:3
    int(k)=intMC1(1e4);
    inta(k)=intMC1(1e6);
end
int, inta
    function int=intMC1(N)
        %intcomplex1
        %compute int_0^1 (int_x^1 int_{xy}^2 cos(x*y*exp(z))dz)dy)dx

        int = 0;                           %init
        for i=1:N                          %loop
            x = rand; y = rand; z=2*rand;  %generate a point from sorrounding box
            if (x<=y) && (x*y<=z)          %is in region
                int = int +f(x,y,z);       %if yes add to int
            end
        end
        int =(int/N)*2;
    end
end