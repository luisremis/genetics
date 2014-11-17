#ifndef PROTOTYPE_H
#define PROTOTYPE_H

class Prototype
{
public:
	Prototype(void);
	~Prototype(void);
	virtual Prototype* copiar()=0;
};

#endif