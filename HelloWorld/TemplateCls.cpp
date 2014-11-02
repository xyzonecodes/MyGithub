/*
 * TemplateCls.cpp
 *
 *  Created on: 2014年11月2日
 *      Author: xyzone
 */

#include "TemplateCls.h"

template<typename T>
TemplateCls<T>::TemplateCls() {
	// TODO Auto-generated constructor stub

}

template<typename T>
TemplateCls<T>::~TemplateCls() {
	// TODO Auto-generated destructor stub
}

template<typename T>
void TemplateCls<T>::swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

