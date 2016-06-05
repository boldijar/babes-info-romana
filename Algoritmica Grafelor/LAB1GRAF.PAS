
type sir=array[1..100] of integer;
var
  a,b : sir;
  n,n1,i,j : integer;
  m : array[1..30,1..30] of integer;
begin

 write('n='); readln(n);
 for i:=1 to n do
  begin
   write('sirul a este:'); readln(a[i]);
  end;
 write('n1='); readln(n1);
 for i:=1 to n1 do
  begin
   write('sirul b este:'); readln(b[i]);
  end;
  for i:=1 to 30 do
      for j:=1 to 30 do
      m[i,j]:=0;
      for i:=1 to n-1 do
          if a[i]<>a[i+1] then
             for j:=a[i] to a[i+1]-1 do
             begin
                  m[b[j],i]:=1;
                  m[i,b[j]]:=-1;
             end;
  for i:=1 to n do
  begin
       for j:=1 to n do
       write(m[i,j],' ');
       writeln;
  end;
end.