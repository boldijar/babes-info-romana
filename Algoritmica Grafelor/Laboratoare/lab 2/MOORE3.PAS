{       GRAFE         LABORATOR II              MOLDOVAN FLORIN  223
  I.TEXTUL PROBLEMEI.
   Se da un graf in care arcele au diferite valori.
   Sa se conceapa un program care determina un drum de valoare minima
   de la varful p la varful q (p,q-oarecare) folosind algoritmul lui
   Moore-Dijkstra intr-un graf oarecare (cazul general).
  II.SPECIFICATIA.
      DATE      nÓN -numarul de varfuri al grafului;
                ‡,· -siruri;graful e reprez prin lista succesorilor;
                LÓMn(N)-matrice patratica cu valorile arcelor;
                p,q -varfurile intre care se cauta un drum minim;
      REZULTATE v   -valoarea minima a drumului gasit;
                d   -sir de varfuri ce reprez drumul minim gasit.
  III.ALGORITM.
    Algoritmul DetDrumMin Este:
     1. citeste n;-nr de varfuri
     2. cit_graf; -procedura ce construieste sirurile ‡ si ·,
                   si matricea L;
     3. citeste p,g;
     4. sch_1k;-procedura ce plecand de la graful initial construieste un
                alt graf,schimband numerotarea varfurilor 1 si p intre ele;
     5. sch_l; -procedura ce construieste o noua matrice L',actualizand
                matricea initiala L, conform schimbarii facute anterior;
     6. MDgen; -procedura ce materializeaza algoritmul lui Moore-Dijkstra
                pt cazul general,care calculeaza valorile minime ale
                drumurilor de la varful 1 la celelalte varfuri ale grafului;
     7. suc_pred;-procedura ce construieste reprezentarea grafului
                  prin lista predecesorilor;
     8. drum; -procedura ce determina un drum minim (sirul d)de la vf 1
               (=p,conform schimbarilor facute la pct 4. si 5.),la vf q,
               cu ajutorul valorilor minime determinate la pct 6.,
               si a listei predecesorilor determinata la pct 7.
     9. tiparire;-procedrura ce tipareste valoarea v gasita la pct 6.
                  si drumul minim de la p la q, gasit la pct 8.
    SF_Algoritm.
  IV.TEXTUL SURSA.                                                       }
   program drum_minim;
   const w=6;     {nr de varfuri}
         ww=15;    {nr de arce}
   type mat=array[1..w+1,1..w+1] of integer;
        ind=array[1..w+1] of integer;
        suc=array[1..ww+1] of integer;
   var  a,aa,a1,dm:ind;b,bb,b1,dr:suc;l,ll:mat;
        p,q,k,x,xx,n:integer;c:char;
   procedure citire(nn:integer;var s1:ind;var s2:suc;var l:mat);
   var i,j:integer;
   begin
     for i:=1 to nn do
       for j:=1 to nn do begin
         l[i,j]:=MaxInt;
        end;
     j:=0;
     writeln('Introd succ pt fiecare varf / pt stop dati 0');
     for i:=1 to nn do begin
       writeln('succ lui ',i,' :');
       read(x);
       s1[i]:=j+1;
       while(x<>0) do begin
         j:=j+1;
         s2[j]:=x;
         writeln('val arc [',i,',',s2[j],']:');read(xx);
         l[i,s2[j]]:=xx;
         read(x);
       end;
     end;
     s1[i+1]:=j+1;
     s2[j+1]:=0;
   end;
   procedure sch_1k(s1:ind;s2:suc;var a1:ind;var a2:suc;var k:integer);
   var i,l,l1,l2,l3:integer;
   begin
     l:=(s1[k+1]-s1[k])-(s1[2]-s1[1]);
     l1:=s1[2]-s1[1];
     l2:=s1[k+1]-s1[k];
     l3:=s1[k]-s1[2];
     for i:=1 to l2 do a2[i]:=s2[s1[k]+i-1];
     for i:=1 to l3 do a2[l2+i]:=s2[s1[2]+i-1];
     for i:=1 to l1 do a2[l2+l3+i]:=s2[i];
     for i:=2 to k do a1[i]:=a1[i]+l;
     i:=l1+l2+l3+1;
     while(s2[i]<>0) do begin a2[i]:=s2[i];i:=i+1;end;
     i:=1;
     while(s2[i]<>0) do begin
       if b1[i]=1 then b1[i]:=k
       else if b1[i]=k then b1[i]:=1;
       i:=i+1;
     end;

     for i:=1 to n+1 do a1[i]:=s1[i];
     for i:=2 to k do a1[i]:=a1[i]+l;
   end;
   procedure sch_l(l:mat;k:integer;var ll:mat);
   var i:integer;
   begin
     ll:=l;
     if p<>1 then begin
        ll[1,k]:=l[k,1];
        ll[k,1]:=l[1,k];
        for i:=1 to n do
         if(i<>1) and (i<>k) then begin
           ll[1,i]:=l[k,i];
           ll[k,i]:=l[1,i];
           ll[i,1]:=l[i,k];
           ll[i,k]:=l[i,1];
         end;
     end;
   end;
   procedure MDgen(nn:integer;s1:ind;s2:suc;l:mat;var min:ind);
   var i,j,k,minim,su,m:integer;
       s:set of 2..w;
   begin
      m:=0;
      for i:=1 to n do
        for j:=1 to n do
         if(l[i,j]<>MaxInt)and(l[i,j]<>0) then m:=m+1;
      s:=[2..nn];
      min[1]:=0;
      for i:=2 to nn do min[i]:=l[1,i];{s2[i-1]];}
      k:=0;
      repeat begin
        minim:=MaxInt;j:=1;
        for i:=2 to w do begin
          if i in s then
            if min[i]<minim then begin
              minim:=min[i];
              j:=i;
            end;
        end;
        s:=s-[j];
        k:=k+1;
        for i:=s1[j] to s1[j+1]-1 do begin
          su:=s2[i];
          if min[j]+l[j,su]<min[su] then begin
            min[su]:=min[j]+l[j,su];
            s:=s+[su];
          end;
        end;
      end;
      until (s=[]) or (k>m);
      if (k>m) then begin
        writeln('Exista circuit de valoare negativa.');
        writeln('Nu exista solutie!');
      end;
   end;
   procedure suc_pred(n:integer;s1:ind;s2:suc;var ss1:ind;var ss2:suc);
   var i,j,k,cod,m,e:integer;
   begin
     m:=0;
     while (s2[m+1]<>0) do m:=m+1;
     k:=0;
     for i:=1 to n do begin
       cod:=0;
       for j:=1 to m do
         if s2[j]=i then begin
           cod:=cod+1;
           e:=1;
           while( (j<s1[e]) or (j>=s1[e+1]) ) do e:=e+1;
           k:=k+1;
           ss2[k]:=e;
         end;
       if cod =0 then ss1[i]:=k+1
                 else ss1[i]:=k-cod+1;
     end;
     ss1[n+1]:=k+1;
     ss2[m+1]:=0;
   end;
  procedure drum(a:ind;b:suc;dm:ind;vf:integer;l:mat;var d:suc;var k:integer);
   var i,j:integer;
   begin
     d[1]:=vf;
     k:=1;
     while(d[k]<>1) do begin
      for j:=a[d[k]] to a[d[k]+1]-1 do
        if dm[b[j]]+l[b[j],d[k]]=dm[d[k]] then
          i:=b[j];
      k:=k+1;
      d[k]:=i;
     end;
   end;
   procedure tipdr(i,j:integer;dm:ind;d:suc;n:integer);
   var l:integer;
   begin
     write('Drumul minim intre ',i,' si ',j,' are valoarea ');
     if j=1 then write('## ',dm[i],' ##')
     else write('## ',dm[j],' ##');
     writeln(' si este urmatorul :');
     for l:=n downto 1 do begin
       if i<>1 then begin
         if d[l]=1 then write(i,' ');
         if d[l]=i then write(1,' ');
         if (d[l]<>1)and(d[l]<>i) then write(d[l],' ');
         end
       else write(d[l],' ');
      end;
   end;
   begin
    write('Dati n:');read(n);
    citire(n,a,b,l);
    repeat begin
       writeln('Dati varfurile intre care se calculeaza drumul minim :');
       write('p=');readln(p);
       write('q=');readln(q);
          sch_1k(a,b,a1,b1,p);
          sch_l(l,p,ll);
       MDgen(n,a1,b1,ll,dm);
       suc_pred(n,a1,b1,aa,bb);
       if q=1 then drum(aa,bb,dm,p,ll,dr,k)
              else drum(aa,bb,dm,q,ll,dr,k);
       tipdr(p,q,dm,dr,k);
       readln;
      end;
      write('Continuati ? (_/n) :');readln(c);
    until (c='n') or (c='N');
   end.
{ V.DATE DE TEST.
          n=5
          (1,2)-2   p=1  val min = 4
          (1,3)-1   q=5  drum    : 1 3 5
          (2,4)-3
          (3,5)-2   p=3   val min = 5
          (4,3)-3   q=2   drum    : 3 5 1 2
          (5,1)-1                            }
