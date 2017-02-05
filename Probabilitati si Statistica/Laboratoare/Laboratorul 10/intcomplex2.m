%intcomplex2
N=input('Number of sample points: ');
rho = @(z) exp(0.5*z);
volumeOfBox=1e3;
vol=0; mass=0;
volsq=0; masssq=0;
for i=1:N
    x=-5+10*rand; y=-5+10*rand; z=-5+10*rand;
    if x*y*z<=1
        vol=vol+1;
        mass = mass +rho(z);
        volsq = volsq+1;
        masssq = masssq +rho(z)^2;
    end
end
volumeOFObject = (vol/N)*volumeOfBox
volvar = (1/N)*(volsq/N-(vol/N)^2)*volumeOfBox^2;
volstd=sqrt(volvar)
massOFObject = (mass/N)*volumeOfBox
massvar = (1/N)*(masssq/N-(mass/N)^2)*volumeOfBox^2;
massstd=sqrt(massvar)