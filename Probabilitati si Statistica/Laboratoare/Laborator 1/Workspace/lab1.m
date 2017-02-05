clc
v=1:15;
disp(v)
%b)
v=v';
disp(v)
%c)
v=reshape(v,3,5);
disp(v)
%d)
v=v(:,2:4);
disp(v)
%e)
v=v.^2;
disp(v)
%f)
v=v+3*eye(3);
disp(v)
%g)
v=v(2:3,:);
disp(v)
%h)
v=reshape(v,6,1);
disp(v)
%i)
v=v(3:6);
disp(v)
%j)
perms(v)
%k)
i = randperm(numel(v));
disp(v(i))
%l)
v2 = nchoosek(v, 2);
disp(v2)
%m)
i = randsample(v,2);
disp(i)
%n)
disp(v)
comb=nchoosek(v, 3);
A=[];
for i = 1:length(v)
    A = [A;perms(comb(i,:))];
end
disp(A)

%II
%pass = [randsample('012',2),randsample('*#',1),randsample('abc',2)];
comb1 = nchoosek('012',2);
comb2 = nchoosek('*#',1);
comb3 = nchoosek('abc',2);
a =[];
v1 = [];
v3 = [];

for i = 1:length(comb1)
    v1 = [v1;perms(comb1(i,:))];
    v3 = [v3;perms(comb3(i,:))];
end

for i = 1:length(v1)
    for j = 1:length(comb2)
        for k = 1:length(v3)
            a = [a;[v1(i,:),comb2(j,:),v3(k,:)]];
        end
    end
end
disp(a)

