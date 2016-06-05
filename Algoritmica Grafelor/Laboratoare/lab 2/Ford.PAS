{  Sa se scrie un program care determina fluxul maxim intr-o retea de
 transport folosind algoritmul lui Ford-Fulkerson. }


uses crt;
const maxvirf=20;
type matrad=array [1..maxvirf,1..maxvirf] of integer; { matrice de adiacenta }
     drum=array [1..maxvirf] of integer;     { drum intre doua virfuri }
var n:integer;         { numarul de virfuri in graf }
    m:integer;         { numarul arcelor in graf }
    c:matrad;          { graful capacitatilor }
    s,d:integer;       { sursa si destinatia }
    fi:array [1..maxvirf,1..maxvirf] of integer;  { fluxul maxim in graf }
    ft:integer;            { fluxul total in graf }
    i,j,k,l,cod:integer;
    f:text;


procedure CautaDrum(n:integer;var a:matrad;s,d:integer;
  var k:integer;var dr:drum);
{ Cauta un drum in graful cu n virfuri si matricea de adiacenta a intre
 s si d. Returneaza in k numarul virfurilor prin care trece drumul gasit
 si in dr aceste virfuri in ordine inversa. (alg. Moore-Dijkstra) }
var V1,V2,V3:set of byte;
    landa:array [1..maxvirf] of integer;
    i,j,l:integer;
begin
  l:=0;V1:=[s];V2:=[s];
  for i:=1 to n do landa[i]:=32767;
  landa[s]:=0;
  repeat
    V3:=[];
    for i:=1 to n do
      if i in V1 then
        for j:=1 to n do
           if (a[i,j]<>0) then
             begin
               if not(j in V2) then
                 begin V3:=V3+[j];landa[j]:=l+1 end;
               if j=d then
                 begin
                   k:=1;dr[k]:=d;
                   while landa[j]>0 do
                     begin
                       i:=1;
                       while not((a[i,j]<>0) and (landa[i]=landa[j]-1))
                         do i:=i+1;
                       j:=i;k:=k+1;dr[k]:=j;
                     end;
                   exit;
                 end;
             end;
    V1:=V3;
    V2:=V2+V1;
    l:=l+1;
  until V1=[];
  k:=0;
end;


procedure FordFulkerson;
{ Calcularea fluxului maxim in graf folosind algoritmul lui Ford-Fulkerson }
var i,j,k:integer;
    ge:matrad;      { graful ecarturilor }
    dr:drum;
    eps:integer;
begin
  for i:=1 to n do
    for j:=1 to n do fi[i,j]:=0;
  ft:=0;
  while True do
    begin
     { construim graful ecarturilor }
      for i:=1 to n do
        for j:=1 to n do ge[i,j]:=0;
      for i:=1 to n do
        for j:=1 to n do
          if c[i,j]>0 then
            begin
              if fi[i,j]<c[i,j] then ge[i,j]:=c[i,j]-fi[i,j];
              if fi[i,j]>0 then ge[j,i]:=-fi[i,j];
            end;
      CautaDrum(n,ge,s,d,k,dr);
      if k<2 then exit;
     { determinam capacitatea reziduala a drumului gasit }
      eps:=32767;
      for i:=k-1 downto 1 do
        if abs(ge[dr[i+1],dr[i]])<eps then
          eps:=abs(ge[dr[i+1],dr[i]]);
     { calculam fluxul nou obtinut }
      ft:=ft+eps;
      for i:=k-1 downto 1 do
        if ge[dr[i+1],dr[i]]>0 then Inc(fi[dr[i+1],dr[i]],eps)
                               else Dec(fi[dr[i+1],dr[i]],eps);
    end;
end;


begin
  Clrscr;
  Writeln('Determinarea fluxului maxim intr-o retea de transport:');
  Writeln;

 { Citirea datelor de intrare }
  if ParamCount=0 then cod:=1
   else
    begin
      Assign(f,ParamStr(1));
      {$I-} Reset(f); {$I+}
      if IOResult<>0 then cod:=1
                     else cod:=0;
    end;
  for i:=1 to maxvirf do
    for j:=1 to maxvirf do c[i,j]:=0;
  if cod=1 then
    begin
      Write('Nr de virfuri: ');Readln(n);
      Write('Nr de arce: ');Readln(m);
      Writeln('Arcele grafului:');
      for l:=1 to m do
        begin
          Write('  ');Readln(i,j,k);
          c[i,j]:=k;
        end;
      Write('Sursa: ');Readln(s);
      Write('Destinatia: ');Readln(d);
      Writeln;
    end
   else
    begin
      Readln(f,n);
      Readln(f,m);
      for l:=1 to m do
        begin
          Readln(f,i,j,k);
          c[i,j]:=k;
        end;
      Readln(f,s);
      Readln(f,d);
      Close(f);
    end;

 { Aplicarea algoritmului Ford-Fulkerson }
  FordFulkerson;

 { Tiparirea fluxului maxim }
  Writeln('Fluxul maxim este:');
  for i:=1 to n do
    for j:=1 to n do
      if fi[i,j]>0 then
        Writeln('  (',i,',',j,') - ',fi[i,j]);
  Writeln('Fluxul total este: ',ft);
  repeat until keypressed;
end.