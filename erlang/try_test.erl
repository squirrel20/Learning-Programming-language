-module(try_test).
-export([demo1/0,demo2/0,demo3/0]).

generate_exception({1, Who}) -> a;
generate_exception({2, Who}) -> {Who, throw(a)};
generate_exception({3, Who}) -> {Who, exit(a)};
generate_exception({4, Who}) -> {'EXIT', a};
generate_exception({5, Who}) -> {Who, error(a)}.

demo1() ->
	[cathcer(I) || I <- [1,2,3,4,5]].

demo2() ->
	[{I, (catch generate_exception(I))} || I <- [1,2,3,4,5]].

demo3() ->
	try generate_exception(5)
	catch
		error:{developer, X} -> {X, erlang:get_stacktrace()};
		error:{user, X} -> X
	end.

cathcer(N) ->
	try generate_exception(N) of
		Val -> {N, normal, Val}
	catch
		throw:{user, X} -> {N, caught, thrown, X};
		exit:{user, X} -> {N, caught, exited, X};
		error:{user, X} -> {N, caught, error, X};

		throw:{developer, X} -> {N, caught, thrown, X, erlang:get_stacktrace()};
		exit:{developer, X} -> {N, caught, exited, X, erlang:get_stacktrace()};
		error:{developer, X} -> {N, caught, error, X}, erlang:get_stacktrace()
	after
		done
	end.

