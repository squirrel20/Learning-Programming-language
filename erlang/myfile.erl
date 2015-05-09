-module(myfile).
-export([read/1]).

read(File) ->
	try my_func(File)
	catch
		throw:X -> {read_error, X}
	end.

my_func(File) ->
	case file:read_file(File) of
		{ok, Bin} -> Bin;
		{error, Why} -> throw(Why)
	end.