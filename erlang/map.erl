-module(map).
-export([map_search_pred/2]).

map_search_pred(Map, Pred) ->
	L = maps:to_list(Map),
	mp(L, Pred).

mp([{Key, Val}|T], Pred) ->
	Stat = Pred(Key, Val),
	if
		Stat ->
			{Key, Val};
		length(T) > 0 ->
			mp(T, Pred);
		true ->
			{no, one}
	end.
