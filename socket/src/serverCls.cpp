/*
 * serverCls.cpp
 *
 *  Created on: 2014年11月7日
 *      Author: xyzone
 */

#include "serverCls.h"

namespace totcp
{

serverCls::~serverCls()
{

}

serverCls::serverCls(const char * host, const int port)
{
	server_st = 0;
	client_st = 0;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr(host);
	addr.sin_port = port;
}
void serverCls::set_addr(const char * host, const int port)
{
	server_st = 0;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr(host);
	addr.sin_port = port;
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
	return 0;
}

int serverCls::acceptsocket()
{
	memset(&clientAddr, 0, sizeof(clientAddr));
	socklen_t len = sizeof(clientAddr);
	int client_st = accept(server_st, (sockaddr*) &clientAddr, &len);
	if (client_st < 0)
	{
		cout << "accept socket出錯 錯誤代碼：" << errno << "  錯誤描述：" << strerror(errno)
				<< endl;
		return -1;
	}
	cout << "accept by " << inet_ntoa(clientAddr.sin_addr) << ":"
			<< clientAddr.sin_port << endl;\
	return 0;
}

int serverCls::recvMsg()
{
	char s[1024];
	while (1)
	{
		memset(s, 0, sizeof(s));
		int rc = recv(client_st, s, sizeof(s), 0);
		if (rc <= 0) //如果recv返回小于等于0，代表socket已经关闭或者出错了
		{
			cout << "recv socket出錯 錯誤代碼：" << errno << "  錯誤描述："
					<< strerror(errno) << endl;
			break;
		}
		cout << clientAddr.sin_port << "大小：" << rc << "   內容：" << s << endl;

	}
	return 0;
}

} /* namespace totcp */
