/*
 * baseCls.h
 *
 *  Created on: 2014年11月3日
 *      Author: xyzone
 */

#ifndef BASECLS_H_
#define BASECLS_H_

namespace totcp {

class baseCls {
	  int baseInt;
public:
	baseCls();
	virtual ~baseCls();
	void setVale(int n);
	int getValue();
	virtual void showMain();
};

} /* namespace totcp */

#endif /* BASECLS_H_ */
