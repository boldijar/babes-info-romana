(*
     NUME AUTOR: Mitrea Cristina
        SUBIECT: Teoria grafelor
       TEMA NR.: 3

PROBLEMA:
  Sa se conceapa un algorim care determina si afiseaza marjele de timp pentru
fiecare activitate din desfasurarea unui obiectiv.

 Acest obiectiv se poate reprezenta sub forma grafului potentiale ....
 Se considera ca G=(X,U) (X={1,2,3,...,n}) unde G este un graf simplu cu
valori pozitive ale arcelor.


NOTATII:

-INFINIT-valoarea drumului de la vf. i la vf. j, pntru care nu exista drum
        de la i la j

l(i,j)=l(u) : valoarea arcului (i,j)

       |  -INFINIT daca  i=j                   |
v(i,j)=|  l(i,j) daca (i,j)    apartine lui U  | : matricea valorilor arcelor
       |  -INFINIT daca (i,j) nu apartine lui U |

H(j)=| -INFINIT, daca j=p                 | : valoarea maxima
     | v(1,j), i=1,n) daca j<>p           |   a drumurilor  de la 1 la j
                                           : daca nu exista drum,
                                             val max=INFINIT

S(i)=|0, daca pentru vf. i s-a det. val. max a drumului de la p la i|
     |i, altfel                                                     |
S-multimea vf. pt care s-a det. val. max a drumului de la p la i

PROIECTARE:

  Algoritmul lui Moore-Dijkstra care determina valorile minime drumurilor
de la varful 1 la vf. i, unde i apartine multimii {1,...,n}-{p}:

(a)initialzari
   H(1):=0;
   H(i):=|l(p,i), i succesor al lui 1|
         |INFINIT,altfel             |
   s:={2,3,..,n}

(b)testul de stop
   | * fie j din S a.i. H(j)=min{H(i)/i din S}
   s:=S-{j}
   daca S={} atunci stop
   sfdaca

(c)iteratia de baza
   pentru | * i din intersectie de Succesori(j) si S executa
                H(i):=min{H(I),H(j)+v(j,i)
   sfpentru
   goto (b)

  Algoritmul lui Moore-Dijkstra adaptat pentru determinarea maximului
lungimilor drumurilor de la 1 la i unde i apartine multimii {1,...,n}-{p}:
  in algoritmul anterior se inlocuieste min cu max  si "<" cu ">"


   H(i):=|v(1,i),i<>1 |
         |INFINIT,i=1 |
   s:={2,3,..,n}
   repeta
        | * fie j din S a.i. H(j)=max{H(i)/i din S}
         s:=S-{j}
         pentru | * i din intersectie de Succesori(j) si S executa
                H(i):=max{H(I),H(j)+v(j,i)
         sfpentru
   pana cand S={}

   Pentru determinarea marjelor utilizam formula de calcul a acestora:
    m(i):=T(I)-t(i), pt. oricare i din X
   unde
    t(i)-momentul cel mai devreme la care poate ...
    T(i)-...
    Vectorul t(i) il det cu M-j adaptat(vectorul H)
    Vectorul T(i) il det. reursiv cu formula :
            | T(i):=T(succ(i))-v(i,succ(i))
            | T[n]=t(i)                      , i:=n-1,2
    activitatile 1,n sunt activitati critice, deci
     m(1)=0
     m(n)=0



EXEMPLU:
Date
  4
  1 2 4
  1 3 7
  2 4 5
  3 4 2
  0 0 0
Rezultate
 Marja de timp a lui  4 este:0
 Marja de timp a lui  3 este:0
 Marja de timp a lui  2 este:1
 Marja de timp a lui  1 este:0

*)

const MAX=20;
      INFINIT=10000;

type tab=array[0..MAX] of integer;
     mat=array[0..MAX] of tab;


function arc(i,j:integer; v:mat):boolean;
begin
  arc:= (v[i,j]<>-INFINIT)
end;

procedure InitCit(w:string;
                  var n:integer; var v:mat;
                  var H,S:tab);
var i,j,k:integer;
    f:text;
begin
  assign(f,w);
  reset(f);
  for i:=1 to MAX do
    for j:=1 to MAX do v[i,j]:=-INFINIT;

  readln(f,n);
  for i:=0 to n+1 do
             begin
               v[i,0]:=-INFINIT;
               v[n+1,i]:=-INFINIT;
               v[0,i]:=0;
               v[i,n+1]:=0;
             end;
  v[0,0]:=-INFINIT;
  v[0,n+1]:=-INFINIT;
  v[n+1,n+1]:=-INFINIT;

  readln(f,i,j,k);
  while i<>0 do begin
    v[i,j]:=k;
    if k<>0 then
         begin
               v[0,j]:=-INFINIT;
               v[i,n+1]:=-INFINIT;
         end;

    readln(f,i,j,k)
  end;
  H[0]:=INFINIT;
  S[0]:=INFINIT;
  for i:=1 to n+1 do

                   begin
                        H[i]:=v[0,i];
                        S[i]:=i;
                   end;
  close(f)
end;

function evida(n:integer; S:tab):boolean;
var vb:boolean;
    i:integer;
begin
  vb:=true;
  for i:=1 to n do
      if (S[i]<>0) then vb:=false;
  evida:=vb;
end;

procedure Dijkstra(n:integer; v:mat; var H,S:tab);
var i,j,maxim:integer;
begin
  repeat
       maxim:=-INFINIT;
       j:=-1;
       for i:=1 to n do
          if ((S[i]<>0)and(H[S[i]]>=maxim)) then
                                   begin
                                      maxim:=H[S[i]];
                                      j:=S[i];
                                   end;
       S[j]:=0;
       for i:=1 to n do
          if (arc(j,i,v)and(S[i]=i))
          then if (H[j]+v[j,i] > H[i])
               then H[i]:=H[j]+v[j,i];

  until evida(n,S);
  for i:=1 to n do
   if (arc(i,n,v)and(h[n]<h[i]+v[i,n])) then h[n]:=h[i]+v[i,n];
end;

function succesor(v:mat; n:integer; vf:integer):integer;
var i,m:integer;
begin

  succesor:=-1;
  m:=infinit;
  for i:=1 to n do
   if (v[vf,i]<>-infinit)and(v[vf,i]<m) then
    begin
     m:=v[vf,i];
     succesor:=i;
    end;

end;

procedure Tip(n:integer; v:mat; H:tab);
var i,s,m:integer;
    T:tab;
begin

  T[n]:=H[n];
  writeln('Marja de timp a lui  ',n,' este: ',0);
  for i:=n-1 downto 2 do

  begin
  s:=succesor(v,n,i);
  T[i]:=T[s]-v[i,s];
  m:=T[s]-v[i,s]-H[i];
  writeln('Marja de timp a lui  ',i,' este: ',m);

  end;
   writeln('Marja de timp a lui  ',1,' este: ',0);
end;

var n,i:integer;
    v:mat;
    H,S:tab;

begin
  InitCit('tema2.dat',n,v,H,S);
  Dijkstra(n,v,H,S);
  Tip(n,v,H);
  readln;
end.
