server : main.o func.o conf.o
	gcc -o server main.o func.o conf.o

main.o : main.c func.h main.h
	gcc -c main.c
func.o : func.c func.h
	gcc -c func.c
conf.o : conf.c conf.h func.h
	gcc -c conf.c

clean :
	rm server *.o

test :
	gcc -o test_client func.c test_client.c func.h
	
udpserver :
	gcc -o udp_server func.c udp_server.c func.h
	
udpclient :
	gcc -o udp_client func.c udp_client.c func.h
	