#include "cheats.h"
#include <stdbool.h>
#include "hid.h"
#include "values.h"
#include <string.h>
#include "ID.h"
#define YOKAI 62
#define ADDRESS 0x08758FA0

/**妖怪をボス妖怪にするかなり雑なソースww**/
void	Boss(void){
	static unsigned int tmp = 0;
	static u32 Y_offset = ADDRESS;
	static u32 backup[YOKAI] = {0};
	if(is_pressed(Y+DU)){
		for(int i = 0;i < YOKAI;i++){
			if(tmp != 1){
				backup[i] = READU32(Y_offset);
			}
			WRITEU32(Y_offset,BOSS[i]);
			Y_offset += 0xCC;
		}
		tmp = 1;
		Y_offset = ADDRESS;
	}
	if(is_pressed(Y+DD)){
		for(int i = 0;i < YOKAI;i++){
			WRITEU32(Y_offset,backup[i]);
			Y_offset += 0xCC;
		}
		Y_offset = ADDRESS;
	}
}
