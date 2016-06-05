{Fiind dat un graf orientat G=(X,U) si doua varfuri p,q din X, pentru care sa existe
drum de la p la q, sa se determine un drum de valoare minima de la p la q. }
program Dijkstra;
const max=maxint div 2;
var c:array[1..100,1..100] of integer;  {c este matricea (costurilor),arcelor}
    k,i,j,nrarc,m,n,li,lf,lun_arc,p,q:integer;
    s,lung,prec:array[1..100] of integer;
    g:boolean;

procedure min(var k:integer);
var m,i:integer;
begin
   m:=max*2;
   for i:=1 to n do
     if(s[i]=1) and (lung[i]<m) then
       begin
          m:=lung[i];
          k:=i;
       end
end;

procedure drum(i:integer);
begin
   if i<>0 then
     begin
        drum(prec[i]);
        write(i);
     end
   else writeln
end;

begin
   writeln('Dati nr. de varfuri:');
   read(n);
   for i:=1 to n do
      for j:=1 to n do      c[i,j]:=max;
   for i:=1 to n do         c[i,i]:=0;
   writeln('Dati nr. de arce:');
   read(nrarc);
   for i:=1 to nrarc do
     begin
        write('Dati arcul',i,'si lungimea');
        readln(li,lf,lun_arc);
        c[li,lf]:=lun_arc;
     end;
   writeln('Dati varfurile pentru care trebuie determinat drumul de valoare minima:');
   readln(p,q);
   for i:=1 to n do
     begin
        lung[i]:=c[p,i];
        s[i]:=1;
        if c[p,i]<max then prec[i]:=p
        else prec[i]:=0;
     end;
   s[p]:=0;
   prec[p]:=0;
   g:=true;
   li:=0;
   repeat
      min(k);
      li:=li+1;
      if (lung[k]=max) or  (li=q) then g:=false
      else
        begin
           s[k]:=0;
           for j:=1 to n do
             if (s[j]=1) and (lung[j]>lung[k]+c[k,j]) then
               begin
                  lung[j]:=lung[k]+c[k,j];
                  prec[j]:=k;
               end;
        end;
   until (not g);
     if (p<>q) then
       if lung[q]=max then
         begin
            write('Nu exista drum de la ',p,' la ',q);
            writeln;
         end
       else
         begin
            write('Drum minim de la ',p,' la ',q,' este: ');
            drum(q);
            writeln(' si este de lungime ',lung[q]);
            writeln;
         end
end.