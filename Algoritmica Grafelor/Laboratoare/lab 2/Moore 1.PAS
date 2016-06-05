(*
     NUME AUTOR: Mitrea Cristina
        SUBIECT: Teoria grafelor
       TEMA NR.: 2

PROBLEMA:
  Se da un graf G=(X,U) si doua varfuri p,q ale acestui graf. Sa se conceapa
un algorim care determina un drum de valoare minima de la varful p la varful
q folosind si algoritmul lui Moore-Dijkstra var. 1.
  Se considera ca G=(X,U) (X={1,2,3,...,n}) unde G este un graf cu valori
pozitive ale arcelor


NOTATII:

INFINIT-valoarea drumului de la vf. i la vf. j, pntru care nu exista drum
        de la i la j

l(i,j)=l(u) : valoarea arcului (i,j)

       |  INFINIT daca  i=j                    |
v(i,j)=|  l(i,j) daca (i,j)    apartine lui U  | : matricea valorilor arcelor
       |  INFINIT daca (i,j) nu apartine lui U |

H(j)=| 0, daca j=p                       | : valoarea minima
     | min(H(i)+v(i,j), i=1,n) daca j<>p |   a drumurilor  de la p la j
                                           : daca nu exista drum,
                                             val min=INFINIT

S(i)=|0, daca pentru vf. i s-a det. val. min a drumului de la p la i|
     |i, altfel                                                     |
S-multimea vf. pt care s-a det. val. min a drumului de la p la i

d(i)= al i-lea varf dintr-un drum de valoare minima de la p la q

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

  Algoritmul lui Moore-Dijkstra adaptat pentru determinarea minimului
lungimilor drumurilor de la p la i unde i apartine multimii {1,...,n}-{p}:
  in algoritmul anterior se inlocuieste vf. 1 cu vf. p(se poneste de la p) si
se calculeaza valorile minime ale drumurilor de la vf p la toate varfurile
grafului.

   H(p):=0;
   H(i):=|l(p,i), i succesor al lui p|
         |INFINIT,altfel             |
   s:={2,3,..,n}
   repeta
        | * fie j din S a.i. H(j)=min{H(i)/i din S}
         s:=S-{j}
         pentru | * i din intersectie de Succesori(j) si S executa
                H(i):=min{H(I),H(j)+v(j,i)
         sfpentru
   pana cand S={}

  Algoritm pentru det. unui drum de lungime minima de la varful 1 la varful i:

(a)initializari
   citeste i
   j:=i
   k:=1,
   d(k):=j

(b)iteratia de baza
   Cat timp d(k)<>j executa
     | * Fie z un predecesor al lui j pentru care H(z)+v(z,j)=H(j))
      j:=z
      k:=k+1
      d(k):=j
   SfCat

  Algoritm adaptat pentru det. unui drum de lungime minima de la vf. p la
vf. q:
  in algoritmul anterior se inlocuieste vf. 1 cu vf. q si se det. drumul de
lungime minima de la vf. q la vf. i=p

    j:=q
    k:=1, d(k):=j
    Cat timp d(k)<>p executa
     | * Fie i un predecesor al lui j pentru care H(i)+v(i,j)=H(j))
      j:=i
      k:=k+1
      d(k):=j
    SfCat

 Determinand valorile minime ale drumurilor de la vf. p la toate vf. grafului
cu algoritmul lui Moore-Dijkstra adptat vom determina cu ultimul algoritm
desris un drum de valoare minima de la vf. p la vf. q.

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

const MAX=10;
      INFINIT=10000;

type tab=array[1..MAX] of integer;
     mat=array[1..MAX] of tab;


function arc(i,j:integer; v:mat):boolean;
begin
  arc:= (v[i,j]<>INFINIT)
end;

procedure InitCit(w:string;
                  var n:integer; var v:mat;
                  var H,S:tab; var p,q:integer);
var i,j,k:integer;
    f:text;
begin
  assign(f,w);
  reset(f);
  for i:=1 to MAX do
    for j:=1 to MAX do v[i,j]:=INFINIT;
  readln(f,n);
  readln(f,p,q);
  readln(f,i,j,k);
  while i<>0 do begin
    v[i,j]:=k;
    readln(f,i,j,k)
  end;
  H[p]:=0;
  S[p]:=0;
  for i:=1 to n do
     if i<>p then
                   begin
                        H[i]:=v[p,i];
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

procedure Dijkstra(n,p:integer; v:mat; var H,S:tab);
var i,j,min:integer;
begin
  repeat
       min:=INFINIT;
       j:=0;
       for i:=1 to n do
          if ((S[i]<>0)and(H[S[i]]<=min)) then
                                   begin
                                      min:=H[S[i]];
                                      j:=S[i];
                                   end;
       S[j]:=0;
       for i:=1 to n do
          if (arc(j,i,v)and(S[i]=i))
          then if (H[j]+v[j,i] < H[i])
               then H[i]:=H[j]+v[j,i];

         until evida(n,S)
end;

procedure Tip(n:integer; v:mat; H:tab; p,q:integer);
var i,j,k:integer;
    gata:boolean;
    d:tab;
begin
  if H[q]=INFINIT then begin
    writeln('nu exista drum de la ',p,' la ',q);
    halt
  end;
  write('valoarea minima a lungimilor drumurilor ');
  writeln('de la ',p,' la ',q,' este ',H[q]);
  j:=q;
  k:=1;
  d[k]:=j;
  while (d[k]<>p) do begin
    gata:=FALSE; i:=1;
    while (not gata) and (i<=n) do
      if (arc(i,j,v) and (H[i]+v[i,j]=H[j]))
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
    H,S:tab;

begin
  InitCit('tema2.dat',n,v,H,S,p,q);
  Dijkstra(n,p,v,H,S);
  Tip(n,v,H,p,q);
  readln;
end.
