-module(time).
-export([my_time/0]).

my_time() ->
	my_time_func(fun() -> my_date_string() end).

my_time_func(F) ->
	F().

my_date_string() ->
	{Year, Month, Day} = date(),
	{Hour, Minute, Second} = time(),
	{Year, Month, Day, Hour, Minute, Second}.