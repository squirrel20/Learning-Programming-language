-module(shop2).
-export([total/1]).

total([{What, N}|T])	-> shop1:cost(What) * N + total(T);
total([])				-> 0.