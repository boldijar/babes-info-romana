function A=QuickSort(A,p,r)
    i=p;
    j=p;
    % A(r) reprezinta pivotul
    while j<=r
        if A(j)>A(r) % element mai mare decat pivotul, crestem j
            j=j+1;
        elseif A(j)<=A(r) % element mai mic decat pivotul
            % mutam acest element in primul subvector,
            % care va deveni A(p:q-1)
            inter=A(j);
            A(j)=A(i);
            A(i)=inter;
            i=i+1;
            j=j+1;
        end
    end
    q=i-1; %am identificat pozitia finala a pivotului in vectorul sortat
    if p<r
        A1=QuickSort(A,p,q-1); %aplicam alg pt suvectorul A(p:q-1)
        A(p:(q-1))=A1(p:(q-1));
        A2=QuickSort(A,q+1,r); %aplicam alg pt suvectorul A(q+1:r)
        A(q+1:r)=A2(q+1:r);
    end
end