-module(math_functions).
-export([even/1, odd/1, filter/2, split1/1, split2/1]).

even(X) -> X rem 2 =:= 0.
odd(X) -> X rem 2 =:= 1.

filter(F, L) ->
	[X || X <- L, F(X)].

split1(L) ->
	{filter(fun(X) -> X rem 2 =:= 0 end, L), filter(fun(X) -> X rem 2 =:= 1 end, L)}.

split2(L) ->
	split2_acc(L, [], []).

split2_acc([H|T], Odds, Evens) ->
	case (H rem 2) of
		1 -> split2_acc(T, [H|Odds], Evens);
		0 -> split2_acc(T, Odds, [H|Evens])
	end;
split2_acc([], Odds, Evens) -> {Evens, Odds}.