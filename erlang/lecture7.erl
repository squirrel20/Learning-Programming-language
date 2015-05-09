-module(lecture7).
-export([convert_byte/1]).

convert_byte(Bin) ->
	list_to_binary(convert_list(binary_to_list(Bin), [])).

convert_list([H|T], L) ->
	if
		%% 真的是好奇怪的命名方式，求列表长度函数名为Length，求元组长度为tupe_size
		length(T) > 0 ->
			convert_list(T, [H|L]);
		true ->
			[H|L]
	end.

term_to_packet(Term) -> 
	Bin = term_to_binary(Term),
	N = bit_size(Bin) / 8,

packet_to_term(Packet) -> .