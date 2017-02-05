function  A=RandomizedQuickSort(A,p,r)
    i=p;
    j=p;
    
    if p<r
        %indice=randi([p,r]);
        indice=round(unifrnd(p,r));
        aux=A(indice);
        A(indice)=A(r);
        A(r)=aux;
    end
    
    while j<=r
        if A(j)>A(r)
            j=j+1;
        elseif A(j)<=A(r)
            inter=A(j);
            A(j)=A(i);
            A(i)=inter;
            i=i+1;
            j=j+1;
        end
    end
    
    q=i-1;

    if p<r
        A1=RandomizedQuickSort(A,p,q-1); %aplicam algoritmul pt suvectorul A(p:q-1)
        A(p:(q-1))=A1(p:(q-1));

        A2=RandomizedQuickSort(A,q+1,r); %aplicam algoritmul pt suvectorul A(q+1:r)
        A(q+1:r)=A2(q+1:r);
    end
end
   


