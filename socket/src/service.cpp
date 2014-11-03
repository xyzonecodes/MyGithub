/*
 * service.cpp
 *
 *  Created on: 2014年11月7日
 *      Author: xyzone
 */

#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include<string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace std;

int main()
{
	int server_st = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in *addr = new sockaddr_in; //定义一个IP地址结构
	memset(addr, 0, sizeof(*addr));
	addr->sin_family = AF_INET; //将addr结构的属性定位为TCP/IP地址
	addr->sin_port = htons(9000); //将本地字节顺序转化为网络字节顺序。
	addr->sin_addr.s_addr = htonl(INADDR_ANY); //INADDR_ANY代表这个server上所有的地址
	if (server_st < 0)
	{
		cout << "初始化socket出錯 錯誤代碼：" << errno << "  錯誤描述：" << strerror(errno)
				<< endl;
		return -1;
	}
	int rBind = bind(server_st, (struct sockaddr *) addr, sizeof(*addr));
	delete addr;
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
	int client_st = 0; //client端socket
	while (true)
	{
		struct sockaddr_in clientAddr;
		memset(&clientAddr, 0, sizeof(clientAddr));
		socklen_t len = sizeof(clientAddr);
		client_st = accept(server_st, (sockaddr*) &clientAddr, &len);
		if (client_st < 0)
		{
			cout << "accept socket出錯 錯誤代碼：" << errno << "  錯誤描述："
					<< strerror(errno) << endl;
			return -1;
		}
		cout << "accept by " << inet_ntoa(clientAddr.sin_addr) << ":"
				<< clientAddr.sin_port << endl;

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
		cout << "server start!!!" << endl;
	}

	return 0;
}

