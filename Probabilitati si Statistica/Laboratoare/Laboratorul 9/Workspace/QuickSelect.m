function A=QuickSelect(A,p,r,indice_cautat)
    i=p;
    j=p;
    while j<=r
        if A(j)>A(r) %element mai mic decat pivotul
            j=j+1;
        elseif A(j)<=A(r) % element mai mare decat pivotul
            inter=A(j);
            A(j)=A(i);
            A(i)=inter;
            i=i+1;
            j=j+1;
        end
    end
    q=i-1;
    if q==indice_cautat %al i-lea cel mai mic element se afla pe pozitia pivotului
        return;
    end
    if q>indice_cautat && p<r
        A1=QuickSelect(A,p,q-1,indice_cautat);
        A(p:(q-1))=A1(p:(q-1));
    elseif q<indice_cautat && p<r
        A2=QuickSelect(A,q+1,r,indice_cautat);
        A(q+1:r)=A2(q+1:r);
    end
end