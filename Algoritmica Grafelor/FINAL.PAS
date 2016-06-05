program trecere_de_la_matricea_de_incidenta_la_lista_succesorilor;
{uses crt;}
type sir=array[0..30] of integer;
     matrice=array[1..30,1..30] of integer;
var
  alfa,beta:sir;
  b:matrice;
  n,m:integer;

procedure citire_matricea_de_incidenta(var b:matrice;var n,m:byte);
var i,j:byte;f:text;
begin
  assign(f,'graf.txt');
  reset(f);
  read(f,n);
  readln(f,m);
  for i:=1 to n do
   for j:=1 to m do begin
                     gotoxy(3*j,2*i+2);
                     readln(b[i,j]);
                    end;
   close(f);
end;

procedure afisare_sir(alfa:sir);
var i:integer;
begin
  for i:=1 to a[0] do write(alfa[i],' ');
  writeln
end;

procedure afisare_matrice(a:matrice;n,m:integer);
var i,j:integer;
begin
 for i:=1 to n do
   begin
     for j:=1 to m do write(a[i,j]:3);
     writeln
   end
end;

procedure conversie(alfa,beta:sir;var b:matrice;var n,m:integer);
var i,j,k:integer;
begin
  for i:=1 to n do
  for j:=1 to m do
  if (alfa[i]=alfa[i+1]) then do inc(m)
   for k:=1 to n do
    if (b[i,j]=1) or (b[j,i]=-1) then begin
                                       alfa(i)

 n:=alfa[0]-1;m:=beta[0];
 for i:=1 to beta[0] do
  begin
    k:=1;
    while not((alfa[k]<=i) and (i<alfa[k+1]))and (k<alfa[0]) do inc(k);
    if (k<alfa[0]) then begin a[k,i]:=1;a[beta[i],i]:=-1 end
  end
end;

begin
 {clrscr;}
 citire_matricea_de_incidenta(b,n,m);
 afisare_matrice(b,n,m);
 conversie(alfa,beta,b,n,m);
 afisare_sir(alfa);
 readln
end.
