
#ifndef MAIN_H_
#define MAIN_H_

void handle(int client_sockfd);

int server(int argc, char **argv);

int test_server_fork(int argc, char **argv);
int test_server_select(int argc, char **argv);
int test_server_poll(int argc, char **argv);

void str_echo(int sockfd);
#endif // MAIN_H_
