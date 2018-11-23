#include "cheats.h"
#include <stdbool.h>
#include "hid.h"
#include "values.h"
#include <string.h>

/**ここから下の部分を付け加える**/
#define WRITEFLOAT_P(address, value) *(u32*)(address) += (u32)(value)
#define WRITEFLOAT_M(address, value) *(u32*)(address) -= (u32)(value)
#define SPEED 2  //座標移動のスピード(1の部分)これを#define SPEED 3 みたいに自分好みの速度にする

void sample(void){
	if(is_pressed(Y)){
		if(is_pressed(DR)){
			WRITEFLOAT_P(0x0C51D200,SPEED);
		}
		if(is_pressed(DL)){
			WRITEFLOAT_M(0x0C51D200,SPEED);
		}
		if(is_pressed(DU)){
			WRITEFLOAT_P(0x0C51D208,SPEED);
		}
		if(is_pressed(DD)){
			WRITEFLOAT_M(0x0C51D208,SPEED);
		}
	}
}
