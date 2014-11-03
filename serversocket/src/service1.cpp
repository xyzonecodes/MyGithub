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
	server.set_addr("127.0.0.1", 9000);
	int iRes = server.init();
	if (iRes < 0)
		return -1;
	while (true)
	{
		server.acceptsocket();
	}

	return 0;
}

