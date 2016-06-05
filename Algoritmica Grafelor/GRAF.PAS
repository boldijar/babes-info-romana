program trecere_de_la_lista_succesorilor_la_matricea_de_incidenta;
{uses crt;}
type sir=array[0..30] of integer;
     matrice=array[1..30,1..30] of integer;
var
  alfa,beta:sir;{pe pozitia 0 se pune dimensiunea}
  b:matrice;
  n,m:integer;

procedure citire_lista_succesorilor(var a,b:sir);
var i:integer;f:text;
begin
 assign(f,'graf.txt');
 reset(f);
 read(f,a[0]);
 for i:=1 to a[0] do read(f,a[i]);
 read(f,b[0]);
 for i:=1 to b[0] do read(f,b[i]);
 close(f)
end;

procedure afisare_sir(a:sir);
var i:integer;
begin
  for i:=1 to a[0] do write(a[i],' ');
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

procedure trecere(alfa,beta:sir;var a:matrice;var n,m:integer);
var i,j,k:integer;
begin
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
 citire_lista_succesorilor(alfa,beta);
 afisare_sir(alfa);
 afisare_sir(beta);
 trecere(alfa,beta,b,n,m);
 afisare_matrice(b,n,m);
 readln
end.
