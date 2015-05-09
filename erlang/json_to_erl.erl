-module(json_to_erl).
-export([json_to_map/1]).

json_to_map(Path) ->
	maps:from_json(file:read_file(Path)).
