
				  	   				AUTOR: Musetescu Mircea
									Grupa: 225
									Data predarii: 19.12.2001

					Laborator Nr.3

PROBLEMA:

  Avand data problema ordonantarii si graful potentiale-etape (PERT) asociat
acestei probleme, descrieti un algoritm pentru a determina toate drumurile
critice din acest graf.

PROIECTARE:

  In aceasta problema avem pentru , determinat toate drumurile de lungime maxima din graful Pert de la varful p la varful q ( unde p - etapa initiala de realizare a proiectului, iar q - ultima etapa de realizare a proiectului respectiv).
  In graful PERT varfurile reprezinta etape ale realizarii proiectului
iar arcele grafului reprezinta activitati (valoarea arcelor codificand
durata de desfasurare a activitatilor respective). Pentru determinarea
valorii maxime a drumurilor de dintre varful 1 si varful n voi folosi algoritmul lui Ford.
(*
procedure Ford(n,p:integer; v:mat; var lambda:tab);
var i,j:integer;
    lambda1:tab;
begin
  lambda1:=lambda;
  repeat
    lambda:=lambda1;
    for j:=1 to n do
      if j<>p then
        for i:=1 to n do
          if arc(i,j,v)
          then if lambda1[i]+v[i,j] > lambda1[j]
               then lambda1[j]:=lambda1[i]+v[i,j]
  until egal(n,lambda,lambda1)
end;
*)
  Presupunand format vectorul lambda cu semnificatia lambda[i] = valoarea
maxima a drumurilor de la varful 1 la varful i, ramane de rezolvat problema
reconstituirii tuturor drumurilor de valoare maxima de la varful 1 la
varful n.
  Pentru reconstituirea acestor drumuri voi folosi metoda BACKTRACKING.
Consider potrivita folosirea acestei metode de programare deoarece se cer
'toate' drumurile de lungime maxima. Metoda de parcurgere a acestor drumuri
nu difera in totalitate de metoda de reconstituire a unui singur drum de
valoare maxima (TEMA2), diferenta constand in faptul ca trebuie realizata o
parcurgere cu reveniri (pentru determinarea tuturor variantelor).






Subalgoritmul Back(k) este:
  Daca	 (* Am ajuns in varful p)
  | atunci 	 (* Tipareste drumul)
  | altfel Pentru (* Fiecare i, predecesor al lui d[k-1]) executa
  |        | d[k]:=i
  |        | Daca (lambda(d(k))+v(d(k),d(k-1)) = lambda(d(k-1)))
  |        | | atunci Cheama Back(k+1)
  |        | SfDaca
  |        SfPentru
  SfDaca
SfBack

  Subalgoritmul se va apela cu Back(2), presupunand ca inainte s-a facut
initializarea d[1]:=q.


const MAX=20;
      INFINIT=99999;

type tab=array[1..MAX] of integer;
     mat=array[1..MAX] of tab;

function egal(n:integer; a,b:tab):boolean;
var i:integer;
begin
  i:=1;
  while (i<=n) and (a[i]=b[i]) do inc(i);
  egal:= (i>n)
end;

function arc(i,j:integer; v:mat):boolean;
begin
  arc:= (i<>j) and (v[i,j]<>-INFINIT)
end;

procedure InitCit(s:string;
                  var n:integer; var v:mat;
                  var lambda:tab; var p,q:integer);
var i,j,k:integer;
    f:text;
begin
  assign(f,s);
  reset(f);
  for i:=1 to MAX do
    for j:=1 to MAX do v[i,j]:=-INFINIT;
  for i:=1 to n do v[i,i]:=0;
  readln(f,n);
  readln(f,p,q);
  readln(f,i,j,k);
  while i<>0 do begin
    v[i,j]:=k;
    readln(f,i,j,k)
  end;
  lambda[p]:=0;
  for i:=1 to n do
    if i<>p then lambda[i]:=v[i,1];
  close(f)
end;

procedure Ford(n,p:integer; v:mat; var lambda:tab);
var i,j:integer;
    lambda1:tab;
begin
  lambda1:=lambda;
  repeat
    lambda:=lambda1;
    for j:=1 to n do
      if j<>p then
        for i:=1 to n do
          if arc(i,j,v)
          then if lambda1[i]+v[i,j] > lambda1[j]
               then lambda1[j]:=lambda1[i]+v[i,j]
  until egal(n,lambda,lambda1)
end;

procedure Tip(n:integer; v:mat; lambda:tab; p,q:integer);
var i,j:integer;
    gata:boolean;
    d:tab;

  procedure Solutie(n:integer);
  var i:integer;
  begin
    write('drum: ',d[n]);
    for i:=n-1 downto 1 do
      write('-(',v[d[i+1],d[i]],')-',d[i]);
    writeln
  end;

  procedure Back(k:integer);
  var i:integer;
  begin
    if d[k-1]=p
      then Solutie(k-1)
      else for i:=1 to n do begin
             d[k]:=i;
             if arc(d[k],d[k-1],v) and
                (lambda[d[k]]+v[d[k],d[k-1]]=lambda[d[k-1]])
               then Back(k+1)
           end
  end;

begin
  if lambda[q]=-INFINIT then begin
    writeln('nu exista drum de la ',p,' la ',q);
    halt
  end;
  write('valoarea maxima a lungimilor drumurilor ');
  writeln('de la ',p,' la ',q,' este ',lambda[q]);
  d[1]:=q; Back(2)
end;

var n,p,q:integer;
    v:mat;
    lambda:tab;

begin
  InitCit('tema3.dat',n,v,lambda,p,q);
  Ford(n,p,v,lambda);
  Tip(n,v,lambda,p,q)
end.
