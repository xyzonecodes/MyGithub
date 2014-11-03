/*
 * service.cpp
 *
 *  Created on: 2014年11月7日
 *      Author: xyzone
 */

#include <iostream>
#include "serverCls.h"

using namespace std;
using namespace totcp;

int main()
{

	serverCls server;
	server.set_addr("0.0.0.0", 8080);
	int iRes = server.init();
	if (iRes < 0)
		return -1;
	int client_st = 0; //client端socket
	while (true)
	{

		client_st = server.acceptsocket();
		if (client_st > -1)
			server.recvMsg();
		cout << "server start!!!" << endl;
	}

	return 0;
}

