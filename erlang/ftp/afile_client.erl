-module(afile_client).
-export([test/0, ls/1, get_file/2, put_file/3]).

test() ->
	Server = afile_server:start("."),
	put_file(Server, "notice.html", "notice2.html").

ls(Server) ->
	Server ! {self(), list_dir},
	receive
		{Server, FileList} ->
			FileList
	end.

get_file(Server, File) ->
	Server ! {self(), {get_file, File}},
	receive
		{Server, Content} ->
			Content
	end.

put_file(Server, FromFile, ToFile) ->
	Server ! {self(), {put_file, ToFile, file:read_file(FromFile)}},
	receive
		{Server, {ok, MSG}} ->
			MSG
	end.