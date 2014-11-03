/*
 * serverCls.cpp
 *
 *  Created on: 2014年11月7日
 *      Author: xyzone
 */

#include "serverCls.h"

namespace totcp
{

void *recvsocket(void *arg);

serverCls::~serverCls()
{

}

serverCls::serverCls(const char * host, const int port)
{
	server_st = 0;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr(host);
	addr.sin_port = htons(port);
}
void serverCls::set_addr(const char * host, const int port)
{
	server_st = 0;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY); // inet_addr(host);
	addr.sin_port = htons(port);
}

int serverCls::init()
{
	this->server_st = socket(AF_INET, SOCK_STREAM, 0);

	if (server_st < 0)
	{
		cout << "初始化socket出錯 錯誤代碼：" << errno << "  錯誤描述：" << strerror(errno)
				<< endl;
		return -1;
	}

//	int on = 1;
//	if (setsockopt(server_st, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) == -1)
//	{
//		printf("setsockopt failed %s\n", strerror(errno));
//		return -1;
//	}

	int rBind = bind(server_st, (struct sockaddr *) &addr, sizeof(addr));
	if (rBind < 0)
	{
		cout << "綁定socket出錯 錯誤代碼：" << errno << "  錯誤描述：" << strerror(errno)
				<< endl;
		return -1;
	}
	if (listen(server_st, 20) < 0)
	{
		cout << "listen socket出錯 錯誤代碼：" << errno << "  錯誤描述：" << strerror(errno)
				<< endl;
		return -1;
	}
	cout << "server start!!!" << endl;

	return 0;
}

int serverCls::acceptsocket()
{
	int client_st;
	struct sockaddr_in clientAddr;
	memset(&clientAddr, 0, sizeof(clientAddr));
	socklen_t len = sizeof(clientAddr);
	client_st = accept(server_st, (sockaddr*) &clientAddr, &len);
	if (client_st < 0)
	{
		cout << "accept socket出錯 錯誤代碼：" << errno << "  錯誤描述：" << strerror(errno)
				<< endl;
		return -1;
	}
	cout << "accept by " << inet_ntoa(clientAddr.sin_addr) << ":"
			<< clientAddr.sin_port << endl;\
	struct ps ps1;
	pthread_t thrd1, thrd2;
	ps1.st = client_st;
	ps1.thr = &thrd2;
	ps1.clientAddr=clientAddr;
	pthread_create(&thrd1, NULL, recvsocket, &ps1);
	pthread_detach(thrd1); //设置线程为可分离
//	pthread_create(&thrd2, NULL, sendsocket, &client_st);
//	pthread_detach(thrd2); //设置线程为可分离
//	recvMsg(client_st, clientAddr);
	cout << "server start!!!" << endl;
	return 0;
}

void *recvsocket(void *arg)
{
	struct ps *p = (struct ps *) arg;
	int client_st = p->st;
	sockaddr_in clientAddr = p->clientAddr;
	char s[1024];
	while (1)
	{
		memset(s, 0, sizeof(s));
		int rc = recv(client_st, s, sizeof(s), 0);
		if (rc <= 0) //如果recv返回小于等于0，代表socket已经关闭或者出错了
		{
			cout << "recv socket出錯或关闭 錯誤代碼：" << errno << "  錯誤描述："
					<< strerror(errno) << endl;
			break;
		}
		cout << clientAddr.sin_port << "大小：" << rc << "   內容：" << s << endl;

	}
	return 0;
}

}
/* namespace totcp */
