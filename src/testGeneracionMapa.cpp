#include <iostream>
#include "CttesRobot.h"
#include <vector>
using namespace std;

int mainMapa(){
//int main(){
	Mapa* mapa = new Mapa(10,10,25);
	CttesRobot::mapa=mapa;
	for(unsigned int i=0; i<CttesRobot::mapa->getMapa()->size(); i++){
		for(unsigned int j=0; j<CttesRobot::mapa->getMapa()->at(i)->size(); j++){
			cout<<CttesRobot::mapa->getMapa()->at(i)->at(j)<<" ";
		}
		cout<<endl;
	}
	system("pause");
	return 0;
}