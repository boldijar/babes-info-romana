% Creez v.a. bivariata normala
% Creez domeniul grid 
[x,y] = meshgrid(-3:.1:3,-3:.1:3);
% Evaluam folosind modelul standard bivariat normal:
z = (1/(2*pi))*exp(-0.5*(x.^2+y.^2));
% Realizarea graficului
surf(x,y,z)