#pragma once

/*
http://zh.wikipedia.org/zh/%E8%99%9A%E5%87%BD%E6%95%B0_(%E7%A8%8B%E5%BA%8F%E8%AF%AD%E8%A8%80)
*/
class Animal {
public:
	/*
	基类通过在其成员函数的声明语句之前加上关键字virtual使得该函数执行动态绑定
	*/
	virtual void eat();
};

class Pig : public Animal {
public:
	void eat();
};

class Wolf : public Animal {
public:
	void eat();
};

class OtherAnimal : public Animal {
public:

};

void test();
