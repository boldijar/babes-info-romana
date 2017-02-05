%% Poker hand simulation
% simuleaza o mana la poker (distributie a 5 carti)
%
%% Initializare
% Generarea configuratiilor
%clear
[C,V]=meshgrid(1:4,2:14);
config=[C(:),V(:)];
value={'1','2','3','4','5','6','7','8','9','10','J','Q','K','A'};
color={'club','diamond','cup','spade'};
%% Deal a poker hand.
% simuleaza o mana
ci=cell(5);
deck=randperm(52);
for j=1:4
    hand=deck((1:5)+(j-1)*5);
    %disp(hand);
    for k=1:5
        %disp([config(hand(k),2), config(hand(k),1)]);      
        disp([value{config(hand(k),2)},', ',...
            color{config(hand(k),1)}])
        nf=sprintf('cartijoc\\cj%d.png',hand(k));
        [ci{k},map]=imread(nf);
        subplot(4,5,5*(j-1)+k)
        image(ci{k}); axis equal;
        axis off;
    end
end