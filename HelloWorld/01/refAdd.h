/*
 * refAdd.h
 *
 *  Created on: 2014年11月3日
 *      Author: xyzone
 */

#ifndef REFADD_H_
#define REFADD_H_

#include "../baseCls.h"

namespace totcp {


class refAdd: public baseCls {
	int data;
public:
	refAdd();
	virtual ~refAdd();
	void showMain();
	refAdd(int n);
	void  Add(const refAdd& a,const refAdd& b);
	void show();
};

} /* namespace totcp */

#endif /* REFADD_H_ */
