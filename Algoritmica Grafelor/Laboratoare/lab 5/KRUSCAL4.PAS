{   I.TEXTUL PROBLEMEI.
   Fie un graf G=(X,U) oarecare.Sa se determine un arbore de pondere minima
   ce trece printr-o muchie u data, folosind algoritmul lui Kruskal nr. 4.
   II.SPECIFICATIA.
   DATE n   -nr de varfuri ale grafului;
        m   -nr muchiilor grafului
        a,b -doua siruri de m componentece codifica reprezentarea
             grafului prin lista arcelor;
        v   -sir de m componente ce contine valorile arcelor;
   REZULTATE T -data de tip multime ce contine arcele
                arborelui de pondere minima;
   III.ALGORITM.
   Algoritmui Kruskal4 Este;
   ( determina un arbore de pondere minima al grafului G=(X,U),
     unde X={1,..,n),U=[1..m] muchiile sunt numerotate )
     T:=[1..m];
     pentru k:=1,m executa
       T:=T-[k];
       daca conex(X,T)=0 atunci
         fie w=U-T+[k] unicul cociclu al acestui graf naconex
         fie vv î U-T+[k] de valoare minima
         T:=T+[vv];
       sfdaca
     sfpentru
   SfKruskal
   functia conex(X,T) este:
     pentru k:=1,n executa
       (1)modifica (X,T) a.i. k sa fie primul varf
       (2)aplica un algoritm Moore-Dijkstra pt calcularea valorilor
          minime ale drumurilor de la vf 1 la toate celelalte vf din T;
          se determina astfel sirul lambda
       (3)pentru i:=1,m executa
             daca lambda[i]=infinit
               atunci conex:=0 (graful nu e conex pt ca nu exista drum de la
                                1 la i )
                      STOP;
             sfdaca
          sfpentru
      sfpentru
   IV.TEXTUL SURSA
}
program arbore_pondere_minima;
uses crt;
const w=10;     {nr de varfuri}
      ww=20;    {nr de muchii}
type sir=array[1..ww] of integer;
var n,m,o:integer;
    a,b,v:sir;
procedure citire(var n,m:integer;var a,b,v:sir);
var k:integer;
begin
  clrscr;
  write('Dati nr de varfuri n=');readln(n);
  writeln('Introduceti muchiile grafului impreuna cu valorile lor (0=STOP)');
  repeat begin
    m:=k;
    write('muchia :');read(k);
    if(k<>0) then begin
       write('extremitate initiala :');read(a[k]);
       write('extremitate finala   :');read(b[k]);
       write('valoarea muchiei ',k,' :');read(v[k]);
    end;
  end;
  until k=0;
end;
procedure md(n,m:integer;a,b,v:sir;var l:sir);
var k,i,j,min:integer;
    s:set of 2..ww;
begin
    l[1]:=0;for i:=2 to n do l[i]:=MaxInt;
    s:=[2..n];
    for i:=1 to m do begin
      if a[i]=1 then l[b[i]]:=v[i];
      if b[i]=1 then l[a[i]]:=v[i];
    end;
    k:=0;
    repeat
     min:=MaxInt;
     for i:=1 to n do
      if i in s then
       if l[i]<min then begin
         min:=l[i];
         j:=i;
       end;
     s:=s-[j];
     k:=k+1;
     for i:=1 to m do begin
      if a[i]=j then
        if l[j]+v[i]<l[b[i]] then begin
          l[b[i]]:=l[j]+v[i];
          s:=s+[b[i]];
        end;
      if b[i]=j then
        if l[j]+v[i]<l[a[i]] then begin
          l[a[i]]:=l[j]+v[i];
          s:=s+[a[i]];
        end;
    end;
   until (s=[]) or (k>m);
end;
function conex(n,m:integer;a,b,v:sir):integer;
{returneaza 1 daca e conex si 0 in caz contrar}
var i,j,k,t:integer;
    a1,b1,l:sir;
procedure sch(m:integer;i:integer;var a1,b1:sir);
var j,k:integer;
begin
  if i=1 then
    for j:=1 to m do begin a1[j]:=a[j];b1[j]:=b[j];end
  else
  for j:=1 to m do begin a1[j]:=a[j];b1[j]:=b[j];end;
  for j:=1 to m do begin
    if a[j]=1 then a1[j]:=i;
    if b[j]=1 then b1[j]:=i;
    if a[j]=i then a1[j]:=1;
    if b[j]=i then b1[j]:=1;
  end;
end;
begin
  j:=1;
  k:=1;
  while (j<=m)and(k=1) do begin
    sch(m,j,a1,b1);
    md(n,m,a1,b1,v,l);
    for t:=1 to n do
      if l[t]=MaxInt then k:=0;
    j:=j+1;
  end;
  conex:=k;
end;
procedure Kruskal(n,m:integer;a,b,v:sir);
var i,j,k,min,con:integer;
    aa,bb,vv:sir;
    U,T,U_T,cociclu:set of 1..ww;
begin
  U:=[1..m];
  T:=[1..m];
  for i:=1 to m do begin aa[i]:=a[i];bb[i]:=b[i];end;
  for k:=1 to m do begin
    aa[k]:=0;bb[k]:=0;T:=T-[k];
    con:=conex(n,m,aa,bb,v);
    if con=0 then begin
      min:=m+1;
      v[min]:=MaxInt;
      for j:=1 to m do
       if j in U-T+[k] then
        if v[j]<v[min] then min:=j;
      T:=T+[min];
      for j:=1 to m do
       if(j=min)and (aa[j]=0)and(bb[j]=0) then begin
        aa[j]:=a[j];
        bb[j]:=b[j];
       end;
    end;
  end;
  writeln('Arborele de pondere minima este cel ce contine muchiile:');
    for i:=1 to m do
      if i in T then write(' ',i)
                else write('   ');
end;
begin
   citire(n,m,a,b,v);
   Kruskal(n,m,a,b,v);
   repeat until keypressed;
end.