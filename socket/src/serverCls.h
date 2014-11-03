/*
 * serverCls.h
 *
 *  Created on: 2014年11月7日
 *      Author: xyzone
 */

#ifndef SRC_SERVERCLS_H_
#define SRC_SERVERCLS_H_

#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include<string.h>

using namespace std;

namespace totcp
{

class serverCls
{
	socklen_t server_st;
	struct sockaddr_in addr;
	int client_st;
	struct sockaddr_in clientAddr;
public:
	virtual ~serverCls();
public:
	serverCls( const char * host="0.0.0.0", const int port = 8080);
	void set_addr(const char * host="0.0.0.0", const int port = 8080);
	int init();
	int acceptsocket();
	int recvMsg();
};

} /* namespace totcp */

#endif /* SRC_SERVERCLS_H_ */
