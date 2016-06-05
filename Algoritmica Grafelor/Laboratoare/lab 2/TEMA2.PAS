(*
     NUME: TEMA2.PAS
  SUBIECT: Teoria grafelor
     TEMA: 2
    AUTOR: Petrascu Dragos <pd7936@disco.scs.ubbcluj.ro>,
                           grupa 225, marti 09:30

PROBLEMA:

Se da un graf G=(X,U). Sa se implementeze algoritmul lui Ford pentru aflarea
unui drum de valoare maxima de la varful p la varful q.

PRELIMINARII:

Se considera ca G=(X,U) (X={1,2,3,...,n}) unde G este un graf simplu (nu
contine bucle) si nu contine circuite de valoare pozitiva. Daca ar contine
astfel de circuite atunci poate nu ar exista valoare maxima a drumurilor de
la p la q (unde p apartine intervalului [1,n]).

NOTATII:

l(i,j)=l(u) : valoarea arcului (i,j)

       |       0 daca  i=j                    |
v(i,j)=|  l(i,j) daca (i,j)    apartine lui U | : matricea valorilor arcelor
       | -infint daca (i,j) nu apartine lui U |

lambda(j)=| 0, daca j=p                            | : valoarea maxima
          | max(lambda(i)+v(i,j), i=1,n) daca j>=2 |   a drumurilor
                                                       de la p la i

d(i)= al i-lea varf dintr-un drum de valoare maxima de la p la q

PROIECTARE:

  Algoritm pentru determinarea maximului lungimilor drumurilor de la p la i
unde i apartine multimii {1,...,n}-{p}:

    lambda(i):= (0 daca i=p) sau (v(i,1) daca i<>p)
    Repeta
    | Pentru j:=1,n executa
    | | Daca j<>p atunci
    | | | Pentru (* fiecare i, predecesor al lui j) executa
    | | | | Daca lambda(i) + l(i,j) > lambda(j)
    | | | | |  atunci lambda(j):= lambda(i) + l(i,j)
    | | | | SfDaca
    | | | SfPentru
    | | SfDaca
    | SfPentru
    Pana cand (* lambda nu se mai modifica)

Algoritm pentru reconstituirea unui drum de lungime maxima de la varful p la
varful q:

    j:=q
    k:=1, d(k):=j
    Cat timp d(k)<>p executa
    | * Fie i un predecesor al lui j pentru care lambda(i)+v(i,j)=lambda(j))
    | j:=i
    | k:=k+1, d(k):=j
    SfCat

EXEMPLU:
Date
  7
  3 5
  1 2 7
  2 4 4
  4 7 4
  1 3 1
  3 6 7
  6 5 3
  5 7 10
  3 2 5
  3 5 2
  2 5 2
  2 6 3
  6 4 6
  0 0 0
Rezultate
  valoarea maxima a lungimilor drumurilor de la 3 la 5 este 11
  drumul este: 3-2-6-5
*)

const MAX=20;
      INFINIT=10000;

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
var i,j,k:integer;
    gata:boolean;
    d:tab;
begin
  if lambda[q]=-INFINIT then begin
    writeln('nu exista drum de la ',p,' la ',q);
    halt
  end;
  write('valoarea maxima a lungimilor drumurilor ');
  writeln('de la ',p,' la ',q,' este ',lambda[q]);
  j:=q;
  k:=1; d[k]:=j;
  while d[k]<>p do begin
    gata:=FALSE; i:=1;
    while (not gata) and (i<=n) do
      if arc(i,j,v) and (lambda[i]+v[i,j]=lambda[j])
      then gata:=TRUE
      else inc(i);
    j:=i;
    inc(k); d[k]:=j
  end;
  write('drumul este: '); write(d[k]);
  for i:=k-1 downto 1 do write('-',d[i]);
  writeln
end;

var n,p,q:integer;
    v:mat;
    lambda:tab;

begin
  InitCit('tema2.dat',n,v,lambda,p,q);
  Ford(n,p,v,lambda);
  Tip(n,v,lambda,p,q)
end.
