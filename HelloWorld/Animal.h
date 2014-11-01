/*
 * Animal.h
 *
 *  Created on: 2014年11月1日
 *      Author: xyzone
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_

class Animal {
protected:
	char* name;
	int age;
public:
	Animal(){
		name="我是一只鸟";
	}
	void eat();
	void getName();
};

#endif /* ANIMAL_H_ */
