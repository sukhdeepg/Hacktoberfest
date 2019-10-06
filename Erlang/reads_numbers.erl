-module(int2txt).
-export([convert/1]).

convert(0) -> "zero";
convert(N) -> convert1(N).

convert1(0) -> "";
convert1(100) -> "cem";
convert1(N) when N>=1000 ->
    join(convert_thou(thoubit(N), 0),convert1(N rem 1000));
convert1(N) when (N>=100) and (N < 1000)->
    join(hundreds(N div 100), "e", convert1(N rem 100));
convert1(N) when N>=20 ->
    join(tens((N div 10)-1), "e", convert1(N rem 10));
convert1(N) when (N>=10) and (N<20) -> teens((N rem 10) + 1);
convert1(N) -> ones(N).

convert_thou({0,0},_) -> "";
convert_thou({0,N2},C) -> convert_thou(thoubit(N2),C+1);
convert_thou({N,N2},C) -> join(convert_thou(thoubit(N2),C+1),
                   convert1(N),thouword(C)).

thoubit(N) -> {(N div 1000) rem 1000,N div 1000}.

ones(N) -> element(N,{"um","dois","três","quatro","cinco","seis","sete",
              "oito","nove"}).
tens(N) -> element(N,{"vinte","trinta","quarenta", "cinquenta", "sessenta", "setenta", "oitenta", "noventa"}).
teens(N) -> element(N,{"dez","onze","doze", "treze", "catorze", "quinze", "dezesseis", "dezessete", "dezoito", "dezenove"}).
hundreds(N) -> element(N,{"cento","duzentos", "trezentos", "quatrocentos", "quinhentos", "seiscentos", "oitocentos", "novecentos"}).
thouword(0) -> "mil";
thouword(C) -> illions(C) ++ "ilhões".
illions(N) -> element(N,{"m","b","tr","quadr","quint","sex","sept",
                         "oct","non","dec"}).

join(X,Y,Z) -> join(join(X,Y),Z).
join("",X) -> X;
join(X,"") -> X;
join(X,Y) -> X++" "++Y.