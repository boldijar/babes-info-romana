function patrat_segmente(n)
  %simulare: generam aleator n puncte din interiorul patratului si
  %verificam carui regiuni apartin
  contor1=0; % contor pt punctele din regiunea D
  contor2=0; % contor pt punctele din regiunea A
  clf;
  
  axis equal;
  axis([-1 11 -1 11]);
  axis off;
  
  % desenam patratul de latura 10
  rectangle(’Position’,[0 0 10 10],’Curvature’,[0 0],’EdgeColor’,’m’,’LineWidth’,3);
  hold on;

  for i=1:n
    % generam cele n puncte aleator
    x=unifrnd(0,10); % generam aleator o abscisa pt punctul aleator din patrat
    y=unifrnd(0,10); % generam aleator o ordonata pt punctul aleator din patrat
    
    l1=sqrt((x-10)^2+(y-10)^2);% distanta fata de varful de coordonate (10,10)
    l2=sqrt((x-0)^2+(y-10)^2);% distanta fata de varful de coordonate (0,10)
    l3=sqrt((x-10)^2+(y-0)^2);% distanta fata de varful de coordonate (10,0)
    l4=sqrt((x-0)^2+(y-0)^2);% distanta fata de varful de coordonate (0,0)
    
    if l1>=9 && l2<9 && l3<9 && l4<9
      %punctul apartine regiunii D
      contor1=contor1+1;
      plot(x,y,’o’,’MarkerEdge’,’g’,’MarkerSize’,2,’MarkerFaceColor’,’b’)
    elseif
      % .....
    elseif l1<9 && l2<9 && l3<9 && l4<9
      %punctul apartine regiunii A
      contor2=contor2+1;
      plot(x,y,’o’,’MarkerEdge’,’g’,’MarkerSize’,2,’MarkerFaceColor’,’r’)
    else
      % punct care nu apartine niciunei regiuni (le coloram cu negru ’k’)
      plot(x,y,’o’,’MarkerEdge’,’b’,’MarkerSize’,2,’MarkerFaceColor’,’k’)
    end
  end
  %afisez cele doua probabilitati
  prob1=contor1/n
  prob2=contor2/n
end