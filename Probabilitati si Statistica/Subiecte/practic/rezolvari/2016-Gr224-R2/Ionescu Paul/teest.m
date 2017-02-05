
%1)
%a)
a = combntns(1:20,8);
size(a,1); 

%b)
b = size(combnts(1:5,3),1);
b1 = size(combnts(1:15,5),1);
rez = b * b1;

%c)
c = size(combnts(1:5,3),1);
c1 = size(combnts(1:3,2),1);
c2 = size(combnts(1:12,3),1);
rezC = c * c1 * c2;

%2)
%schema lui possion pt punctul 2

p1 = 20/25;
q1 = 1 - p1;

p2 = 15/25;
q2 = 1 - p2;

p3 = 10/25;
q3 = 1 - p3;

p4 = 24/25;
q4 = 1 - p4;

poisson = (p1*p2*p3*p4*q4)+ (p1*p2*p4*q3) +(p1*p3*p4*q2) + (p2*p3*p4*q1);

poisson2 = poisson + (p1*p2*p3*p4);

