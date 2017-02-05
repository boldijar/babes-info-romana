function patrat_cerc(n)
  %simulare: generam aleator n puncte din interiorul patratului si
  %verificam daca apartin cercului inscris

  contor=0; % numaram punctele din interiorul cercului
  clf; %stergem obiectele din figura curenta
  axis equal; %stabilim aceeasi unitate de masura pt axe
  axis([-1 3 -1 3]); %setam limitele axelor
  axis off; % stergem axele de coordonate

  % desenam patratul de latura 2
  rectangle('Position', [0 0 2 2], 'Curvature', [0 0], 'EdgeColor', 'm','LineWidth',3);
  
  % desenam cercul inscris in patrat
  rectangle('Position', [0 0 2 2], 'Curvature', [1 1], 'EdgeColor', 'r','LineWidth',3);

  hold on; % cerem ca reprezentarile din plot sa fie suprapuse peste patrat si cerc
  
  for i=1:n % generam cele n puncte aleator
    x=unifrnd(0,2); % generam aleator o abscisa pt punctul aleator din patrat
    y=unifrnd(0,2); % generam aleator o ordonata pt punctul aleator din patrat
    if (x-1)^2+(y-1)^2<=1 % verificam daca punctul se afla in interiorul cercului
      contor=contor+1; % am gasit un punct in interior si contorizam
      % reprezentam punctul de coordonate (x,y) si folosim markerul
      % (simbol de reprezentare) de tip 'o', de culoare verde ('g'-green)
      plot(x,y,'o','MarkerEdge','g','MarkerSize',2,'MarkerFaceColor','g')
    else
      % punctul se afla in exteriorul cercului
      % desenam punctele din exterior cu acelasi marker, dar de culoare
      % albastra ('b'-blue)
      plot(x,y,'o','MarkerEdge','b','MarkerSize',2,'MarkerFaceColor','b')
    end
  end
  
  % afisez pe figura probabilitatea ca un punct din cele n puncte generate
  % aleator sa fie in interiorul cercului
  text(-1,-0.5, ['Probabilitatea este ', num2str(contor/n)]);
  
  % afisez pe figura o aproximare pt PI (PI=probabilitatea obtinuta din simulare * 4)
  text(-1,-0.75, ['Aproximare pi ', num2str(contor/n*4)]);
end