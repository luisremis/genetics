#if !defined PARAMETRO_H
#define PARAMETRO_H
#include <string>

using namespace std;
class Parametro
{

public:
	Parametro(void);
	virtual ~Parametro(void);
	virtual string getNombre();
	virtual double getValor();
};
#endif