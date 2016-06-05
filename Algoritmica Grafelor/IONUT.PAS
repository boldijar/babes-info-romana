program safdsf;

var  a,b:array[1..50] of integer;
     matri:array[1..20,1..20] of integer;
     n,m:integer;
     i,j:integer;

procedure citire_matr_in;
begin
write('n=');readln(n);
write('m=');readln(m);

for i:=1 to n do
   for j:=1 to m do begin
                  write('matri[',i,',',j,',]=');
                  readln(matri[i,j]);
                  end;
end;

procedure tipar_lista_pred;
begin
writeln('Sirul alfa');
for i:=1 to n do write(a[i],' ');
writeln('Sirul beta');
for i:=1 to m do write(b[i],' ');
end;

procedure trans;
var k,u,q:integer;

begin
 k:=1;
 for i:=1 to n do
     begin
     a[i]:=k;
     for u:=1 to m do begin
         if matri[i,u]=-1 then begin
            for j:=1 to n do  begin
                if matri[j,u]=1 then q:=j;
                               end;
                       b[k]:=q;
                       k:=k+1;
                       end;
                       end;
     end;
     a[n+1]:=m+1;
end;

BEGIN
citire_matr_in;
trans;
tipar_lista_pred;
END.
