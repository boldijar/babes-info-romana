program ColtNV;
type el_ciclu = record
                  p,
                  q:integer;
                end;
type sir=array[1..50] of integer;
     mat=array[1..50] of sir;
     cicl=array[1..50] of el_ciclu;
     sirc=array[1..50] of cicl;
 var c,x:mat;
     a,b:sir;
     m,n,cost:integer;

procedure citire(var m:integer; var n:integer; var c:mat; var a:sir; var b:sir; var x:mat);
  var i,j:integer;
    begin
      writeln('dati nr de varfuri sursa: ');
      readln(m);
      writeln('dati nr de varfuri destinatie: ');
      readln(n);
      writeln('dati cheltuiala pt transportul pe fiecare arc in parte: ');
      for i:=1 to m do
         for j:=1 to n do
           begin
             write('c[',i,'][',j,'] = ');
             readln(c[i][j]);
             writeln;
           end;
      writeln('dati cantitatile din produsul de transportat ');
      writeln('produse in fiecare varf sursa: ');
      for i:=1 to m do
           begin
             write('a[',i,'] = ');
             readln(a[i]);
             writeln;
           end;
      writeln('dati cantitatile de produs ');
      writeln('solicitate in fiecare varf destinatie : ');
      for j:=1 to n do
         begin
           write('b[',j,'] = ');
           readln(b[j]);
           writeln;
         end;
      for i:=1 to m do
        for j:=1 to n do  x[i][j]:=0;

    end;


function min(z,t:integer):integer;
  var mn:integer;
    begin
      if z<=t then mn:=z
              else mn:=t;
      min:=mn;
    end;


procedure sol_adm(var a:sir; var b:sir; m,n:integer; var x:mat);
  var i,j:integer;
    begin
      i:=1;
      j:=1;
      while a[i]*b[j]<>0 do
         begin
           x[i][j]:=min(a[i],b[j]);
           a[i]:=a[i]-x[i][j];
           b[j]:=b[j]-x[i][j];
           if a[i]=b[j] then
                          begin
                            x[i+1][j]:=0;
                            if i<m then
                                     begin
                                       i:=i+1;
                                       j:=j+1;
                                     end;
                          end
                        else
                          if b[j]=0 then j:=j+1
                                    else i:=i+1;
         end;
      end;

{procedure det_marc_ciclu(f,g:integer; x,c:mat; m,n:integer; var ciclu:cicl; var marcaj:mat);
   var i,j,k:integer;
     begin
       k:=1;
       marcaj[f][g]:=1;
       ciclu[k].p:=f;
       ciclu[k].q:=g;
       i:=f; j:=g;
       {for i:=f+1 to m do
          if x[i][j]<>0 then
                          begin
                            k:=k+1;
                            ciclu[k].p:=i;
                            ciclu[k].q:=j;
                            break;
                          end;
      if k=1 then
        begin
          for i:=f-1 downto 1 do
              if x[i][j]<>0 then
                          begin
                            k:=k+1;
                            ciclu[k].p:=i;
                            ciclu[k].q:=j;
                            break;
                          end
        end
            else
              begin
        }
 {     for i:=1 to m do
        if x[i][j]<>0 then
                          begin
                            k:=k+1;
                            ciclu[k].p:=i;
                            ciclu[k].q:=j;
                            marcaj[i][j]:=-1;
                            break;
                          end;
      for j:=1 to n do
         if (x[i][j]<>0) and (j<>ciclu[k].q) then
                       begin
                         k:=k+1;
                         ciclu[k].p:=i;
                         ciclu[k].q:=j;
                         marcaj[i][j]:=1;
                         break;
                       end;
       k:=k+1;
       ciclu[k].q:=ciclu[k-1].q;
       ciclu[k].p:=f;
       marcaj[ciclu[k].p][ciclu[k].q]:=-1;
    end;

procedure sol_optima(var a:sir; var b:sir; var x:mat; c:mat; m,n:integer);
  var i,j,k,l:integer;
      d:mat;
      sircicl:sirc;
      marcaj:mat;
    begin
      k:=0;
      for i:=1 to m do
         for j:=1 to n do
           begin
              k:=k+1;
              if x[i][j]<>0 then det_marc_ciclu(i,j,x,c,n,m,sircicl[k],marcaj);
           end;

      for l:=1 to k do
}


procedure tiparire(x:mat; c:mat; m,n:integer);
  var i,j,cost:integer;

     begin
       cost:=0;
       for i:=1 to m do
           for j:=1 to n do
                cost:=cost+c[i][j]*x[i][j];
       writeln('costul transportului este(solutie admisibila) : ',cost);
     end;

BEGIN
  citire(m,n,c,a,b,x);
  sol_adm(a,b,m,n,x);
  tiparire(x,c,m,n);
  readln;
END.
