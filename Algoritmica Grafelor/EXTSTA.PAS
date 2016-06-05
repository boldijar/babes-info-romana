program mult_ext;
type mat=array [1..30,1..30] of integer;
type sir=array[1..50] of integer;
var a:mat;
    n,l:integer;
    m:sir;
procedure citire(var a:mat;var n:integer);
var i,j:integer;
begin
write('dati numarul de varfuri');
readln(n);
for i:=1 to n do
    for j:=1 to n do begin
	write('a[',i,',',j,']=');
	readln(a[i,j]);
		    end;
end;
procedure citmul(var m:sir;var l:integer);
var i:integer;
begin
write('nr de el din multime sunt:');
readln(l);
for i:=1 to l do begin
      write('m[',i,']=');
      readln(m[i]);
   end;
end;
function gasit(m:sir;c:integer;g:integer):boolean;
var i:integer;
begin
gasit:=false;
for i:=1 to g  do
  if m[i]=c then  gasit:=true;
end;
function verificare(m:sir;l:integer;a:mat;n:integer):boolean;
var i,j,k,p,r:integer;
    s:sir;
begin
verificare:=false;
j:=0;
for i:=1 to n do
  if not gasit(m,i,l) then begin
			 j:=j+1;
			 s[j]:=i;
end;
r:=0;
for p:=1 to j do
    for k:=1 to n do if (a[s[p]][k]=1)and(gasit(m,k,l)) then  r:=r+1;
if r=j then verificare:=true;
end;
begin
citire(a,n);
citmul(m,l);
if (verificare(m,l,a,n)) then writeln('multimea e exterior stabila')
			 else writeln('multimea nu e exterior stabila');
readln;
end.