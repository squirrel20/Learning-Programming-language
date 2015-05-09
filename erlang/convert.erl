-module(convert).
-export([my_tuple_to_list/1]).

my_tuple_to_list(T) ->
	for(1, erlang:tuple_size(T), T, []).

for(I, Max, T, L) when I < Max -> for(I + 1, Max, T, [erlang:element(I, T)|L]);
for(Max, Max, T, L) -> [erlang:element(Max, T)|L].