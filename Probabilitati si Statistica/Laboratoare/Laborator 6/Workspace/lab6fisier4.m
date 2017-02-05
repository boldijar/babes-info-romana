n=3;
for i=0:n
    line([0,n],[i,i]);
    line([i,i],[0,n]);
    line([0,i],[i,0]);
    line([i,n],[n,i]);
end

x=0;
y=n;

while (x~=n) && (y~=0)
    p=unidrnd(3);
    switch p
        case 1
            line([x,x+1],[y,y],'color','r');
            x=x+1;
        case 2
            line([x,x],[y,y-1],'color','r');
            y=y-1;
        case 3
            line([x,x+1],[y,y-1],'color','r');
            x=x+1;
            y=y-1;
    end
end

while x~=n
    line([x,x+1],[y,y],'color','r');
    x=x+1;
end

while y~=0
    line([x,x],[y,y-1],'color','r');
    y=y-1;
end
