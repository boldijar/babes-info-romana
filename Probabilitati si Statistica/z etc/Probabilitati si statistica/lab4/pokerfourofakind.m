%% Poker hand simulation
% simuleaza o mana la poker (distributie a 5 carti)
%
%% Initializare
% Generarea configuratiilor
[C,V]=meshgrid(1:4,2:14);
config=[C(:),V(:)];
value={'1','2','3','4','5','6','7','8','9','10','J','Q','K','A'};
color={'club','diamond','cup','spade'};

%% Probabilities of poker hands
% Frecvente si probabilitati teoretice

straightflush=40;
fourofakind=13*48;
fullhouse=13*12*4*nchoosek(4,2);
flush=4*nchoosek(13,5)-40;
straight=10*4^5-40;
threeofakind=13*4*48*44/2;
twopair=nchoosek(13,2)*nchoosek(4,2)*nchoosek(4,2)*44;
pair=13*nchoosek(4,2)*48*44*40/factorial(3);
squat=nchoosek(13,5)*4^5-straight-flush-straightflush;
hands=[straightflush,fourofakind,fullhouse,flush,straight,threeofakind,...
    twopair,pair,squat]
total=sum(hands);
totalshouldbe=nchoosek(52,5)
format long
probabilities=hands/total


%% Simulation four of a kind
% simulare careu
N=input('# hand:');
count=0;
for k=1:N
    deck=randperm(52);
    hand=deck(1:5);
    p=config(hand,2)';
    u=unique(p);
    if length(u)==2 && (sum(u(1)==p)==4 || sum(u(2)==p)==4)
        count=count+1; %p
    end
end
prob=count/N
format short  