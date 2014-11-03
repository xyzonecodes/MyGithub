/*
 * client.cpp
 *
 *  Created on: 2014年11月7日
 *      Author: xyzone
 */
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include<netinet/in.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>

using namespace std;

int main()
{
	int client_st = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in *addr = new sockaddr_in; //定义一个IP地址结构
	memset(addr, 0, sizeof(*addr));
	addr->sin_family = AF_INET; //将addr结构的属性定位为TCP/IP地址
	addr->sin_port = htons(9000); //将本地字节顺序转化为网络字节顺序。
	addr->sin_addr.s_addr = inet_addr("127.0.0.1"); //INADDR_ANY代表这个server上所有的地址
	if (client_st < 0)
	{
		cout << "初始化socket出錯 錯誤代碼：" << errno << "  錯誤描述：" << strerror(errno)
				<< endl;
		return -1;
	}
	if (connect(client_st, (sockaddr *) addr, sizeof(*addr)) < 0)
	{
		cout << "connect socket出錯 錯誤代碼：" << errno << "  錯誤描述："
				<< strerror(errno) << endl;
		return -1;
	}

	char s[1024];

	while (1)
	{
		memset(s, 0, sizeof(s));
		read(STDIN_FILENO, s, sizeof(s)); //从键盘读取用户输入信息
		int rSend = send(client_st, s, strlen(s)-1, 0);
		if (rSend < 0)
		{
			cout << "send socket出錯 錯誤代碼：" << errno << "  錯誤描述："
					<< strerror(errno) << endl;
			return -1;
		}
		else
		{
			cout << "rSend:" << rSend << endl;
		}
	}
	return 0;
}
