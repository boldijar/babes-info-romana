{Se considera un graf bipartit G=(XsUXt,U),unde card(Xs)=m, card(Xt)=n si
U=Xs*Xt.In fiecare varf i din Xs(varf sursa) se produce o cantitate a[i] din
produsul de transportat,iar in j din Xt se solicita cantitatea b[j] de resur-
sa.Transportul pe arcul (i,j) se face cu o cheltuiala c[i,j] unitati banesti
pe unitatea de resursa.Problema cere sa se determine un program de transport
x[i,j], pentru (i,j) din Xs*Xt, astfel incat costul total de transport sa fie
minim, folosind pentru determinarea unei solutii initiale admisibile metoda
coltului de NV}
type sir=array [1..100] of integer;
     matrice=array[1..25,1..25] of integer;
     matboolean=array[1..25,1..25] of boolean;
     pereche=record
               i,j:integer;
               semn:boolean;
             end; {pt o celula retine extremitatea initiala in i,extremitatea
                   finala in j si marcajul in semn astfel:daca celula a fost
                   marcata cu + retine true,iar daca celula a fost marcata cu
                   - retine false}
     sirper=array[1..25] of pereche; {aceasta structura de date retine ciclul
                   atasat unei celule}
     matsirper=array[1..10,1..10] of sirper; {pentru toate celulele nebazice
                   vom determina ciclul atasat lor}
var i:integer;
    miu:matsirper; {in miu[i][j] retinem ciclul atasat celulei nebazice (i,j),
       prin care se intelege o succesiune de celule ce porneste din (i,j),
       trece numai prin celule bazice, ajunge la celula (i,j), si oricare doua
       celule consecutive se afla pe aceeasi linie sau pe aceeasi coloana,fara
       ca trei celule consecutive sa se afle pe aceeasi linie sau pe aceeasi
       coloana}
    m, {m=numarul de varfuri sursa din graf}
    n  {n=numarul de varfuri destinatie din graf}
      :integer;
    a, {a[i]=cantitatea de resursa produsa in sursa i,pt i=1,m}
    b  {b[j]=cantitatea de resursa solicitata in destinatia j,pt j=1,n}
      :sir;
    x, {in x retinem programul de transport care va fi determinat}
    c  {c[i][j]=nr de unitati banesti pe unitatea de resursa cheltuiti pentru
        transportul pe arcul (i,j)}
      :matrice;
    baz {baz[i][j]=true daca celula (i,j) este bazica(echivalent cu faptul ca
         variabila x[i][j] este bazica,adica a primit o valoare prin algo-
         ritmul de initializare) si baz[i][j]=false daca celula (i,j) este ne-
         bazica(echivalent cu faptul ca variabila x[i][j] este nebazica)}
      :matboolean;

 procedure citire_date(var m,n:integer;var a,b:sir;var c:matrice);
   {citeste datele problemei,fiecare parametru avand semnificatia descrisa mai
    sus}
   var i,j:integer;
  begin
   write('m=');
   readln(m);
   for i:=1 to m do
      begin
        write('a[',i,']=');
        readln(a[i]);
      end;
   write('n=');readln(n);
   for i:=1 to n do
      begin
        write('b[',i,']=');
        readln(b[i]);
      end;
   for i:=1 to m do
      for j:=1 to n do
         begin
           write('c[',i,',',j,']=');
           readln(c[i,j]);
         end;
  end;

 procedure coltnv(m,n:integer;a,b:sir;c:matrice;var x:matrice;var baz:matboolean);
   {determina o solutie admisibila x,folosind metoda coltului de NORD-VEST;cu
    ajutorul matricei baz retinem celulele bazice,dupa cum a fost descris in
    sectiunea var}
   var i,j:integer;
  begin
   for i:=1 to m do
     for j:=1 to n do
        begin
          baz[i][j]:=false;
          x[i][j]:=0;
        end;{initial,toate celulele sunt nebazice si au valoarea 0}
   i:=1;
   j:=1;
   while a[i]*b[j]<>0 do
      begin
        if a[i]<b[j] then x[i][j]:=a[i]
                     else x[i][j]:=b[j];
        baz[i][j]:=true;
        a[i]:=a[i]-x[i][j];
        b[j]:=b[j]-x[i][j];
        if a[i]=b[j]
           then
             begin
               x[i+1][j]:=0;
               baz[i+1][j]:=true;
               if i<m then begin
                             i:=i+1;
                             j:=j+1;
                           end;
             end
           else
             if b[j]=0 then j:=j+1
                       else i:=i+1;
      end;
  end;

 procedure soloptima(m,n:integer;c:matrice;var baz:matboolean;var x:matrice);
   {determina o solutie optima,adica un program de transport de cost minim}
   var i,j,dkl,aux,e,f,g,h,k,l,teta,i1:integer;
       continua:boolean;
       d:matrice;
  begin
    continua:=true;
    repeat
     for i:=1 to m do
       for j:=1 to n do
         if baz[i][j]=false then {pentru fiecare celula (i,j) nebazica
       vom determina ciclul miu[i][j],si anume o succesiune de celule ce
       porneste din (i,j),trece numai prin celule bazice, ajunge la celula
       (i,j), si oricare doua celule consecutive se afla pe aceeasi linie sau
       pe aceeasi coloana,fara ca trei celule consecutive sa se afle pe a-
       ceeasi linie sau pe aceeasi coloana}
            begin
              d[i][j]:=c[i][j]; {in d[i][j] calculam suma algebrica a costu-
                rilor din celulele ciclului,avand ca semn marcajul celulei}
              miu[i][j][1].i:=i;
              miu[i][j][1].j:=j;
              miu[i][j][1].semn:=true;{retinem marcajul celulei,care pt celula
                initiala este +}
              aux:=-1;i1:=i;
              repeat
               for e:=1 to m do
                if e<>i then
                  if baz[e][j]=true then
                     for f:=1 to n do
                       if f<>j then if baz[e][f]=true then exit;
               miu[i][j][2].i:=e;
               miu[i][j][2].j:=j;
               miu[i][j][2].semn:=false; {am determinat urmatoarea celula din
                ciclu,celula care se afla pe aceeasi coloana cu celula initia-
                la,si am retinut marcajul}
               d[i][j]:=d[i][j]+aux*c[e][j];
               aux:=aux*aux;
               for f:=1 to n do
                if f<>j then
                  if baz[e][f]=true then
                     for g:=1 to m do
                       if g<>e then if baz[g][f]=true then exit;
               miu[i][j][3].i:=e;
               miu[i][j][3].j:=f;
               miu[i][j][3].semn:=true; {am determinat urmatoarea celula din
                ciclu si ii retinem marcajul}
               d[i][j]:=d[i][j]+aux*c[e][f];
               aux:=aux*aux;
               for g:=1 to m do
                if g<>e then
                  if baz[g][f]=true then
                     for h:=1 to n do
                       if h<>f then if baz[g][h]=true then exit;
               miu[i][j][4].i:=g;
               miu[i][j][4].j:=f;
               miu[i][j][4].semn:=false; {determinam urmatoarea celula din ci-
                clu si ii retinem marcajul}
               d[i][j]:=d[i][j]+aux*c[g][f];
               aux:=aux*aux;
               for h:=1 to n do
                if h<>f then
                  if baz[g][h]=true then
                     for k:=1 to m do
                       if k<>g then if baz[k][h]=true then exit;
               i:=g;
              until (g=i1); {repetam pana ajungem pe linia celulei initiale}
       end;
     dkl:=maxint;
     for i:=1 to m do
       for j:=1 to n do
         if baz[i][j]=false then
            if d[i][j]<dkl then begin
                                  dkl:=d[i][j];
                                  k:=i;
                                  l:=j;
                                end; {in dkl retinem min{d[i][j]/(i,j) este ce-
                                      lula nebazica}
     if dkl>=0 then continua:=false; {daca dkl>=0,am gasit solutia optima si
                                                ne oprim}
     teta:=maxint;
     if continua  {daca nu am gasit solutia optima}
      then
       begin
          for i:=1 to 4 do
            if miu[k][l][i].semn=false then
                if x[miu[k][l][i].i,miu[k][l][i].j]<teta then
                  teta:=x[miu[k][l][i].i,miu[k][l][i].j];
             {teta=min{x[i][j]/(i,j) e celula marcata cu - din ciclul atasat
                   celulei (k,l)}
          for i:=1 to 4 do
           begin
            if miu[k][l][i].semn=false then
    x[miu[k][l][i].i,miu[k][l][i].j]:=teta-x[miu[k][l][i].i,miu[k][l][i].j];
            if miu[k][l][i].semn=true then
    x[miu[k][l][i].i,miu[k][l][i].j]:=teta+x[miu[k][l][i].i,miu[k][l][i].j];
            if x[miu[k][l][i].i,miu[k][l][i].j]=0 then baz[miu[k][l][i].i,miu[k][l][i].j]:=false;
           end; {pentru celulele (i,j) marcate cu -: x[i][j]:=teta-x[i][j]
                 pentru celulele (i,j) marcate cu +: x[i][j]:=teta+x[i][j]}
       end;
    until continua=false;{repetam aceste operatii pana cand gasim o solutie
            optima}
  end;

 procedure afisare(x:matrice);
   {afiseaza programul de transport de cost minim,care a fost retinut in x}
    var i,j:integer;
  begin
   for i:=1 to m do
     for j:=1 to n do
       if baz[i][j]=true then
         writeln('x[',i,',',j,']=',x[i][j]);
  end;

 procedure echilibrare(var m,n:integer;var a,b:sir;var c:matrice);
  {verifica daca problema este echilibrata,adica daca
    a[1]+...+a[m]=b[1]+...+b[n];
   daca nu este echilibrata,se adauga un varf sursa sau un varf destinatie
   fictiv care sa produca, respectiv sa ceara diferenta de resursa cu chel-
   tuieli de transport 0}
   var i,s1,s2:integer;
  begin
   s1:=0;
   for i:=1 to m do s1:=s1+a[i];
   s2:=0;
   for i:=1 to n do s2:=s2+b[i];
   if s1<s2 {daca problema nu este echilibrata,si cererea e mai mare decat o-
              ferta,adaugam o sursa fictiva}
     then
       begin
         m:=m+1;
         a[m]:=s2-s1;
         for i:=1 to n do c[m][i]:=0;
       end
     else
       if s1>s2 {daca problema nu este echilibrata,si cererea e mai mica decat
              oferta, adaugam o destinatie fictiva}
         then
           begin
             n:=n+1;
             b[n]:=s1-s2;
             for i:=1 to m do c[i][n]:=0;
           end;
  end;

begin
 for i:=1 to 25 do writeln;
 citire_date(m,n,a,b,c);
 echilibrare(m,n,a,b,c);
 coltnv(m,n,a,b,c,x,baz);
 soloptima(m,n,c,baz,x);
 afisare(x);
 readln;
end.