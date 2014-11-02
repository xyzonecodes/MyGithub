/*
 * TemplateCls.h
 *
 *  Created on: 2014年11月2日
 *      Author: xyzone
 */

#ifndef TEMPLATECLS_H_
#define TEMPLATECLS_H_

template<typename T>

class TemplateCls {
public:
	TemplateCls();
	virtual ~TemplateCls();
	void swap(T &a,T &b);
};

#endif /* TEMPLATECLS_H_ */
