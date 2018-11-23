#include "cheats.h"
#include <stdbool.h>
#include <stdio.h>
#include "hid.h"
#include "values.h"
#include <string.h>
#include "ID.h"
#define YOKAI 62
#define ADDRESS 0x08758FA0
#define WRITEFLOAT(address, value) *(u32*)(address) += (u32)(value)

/**妖怪をボス妖怪にするかなり雑なソースww(失敗作)**/
void	Boss(void){
	FILE *tmp_file;
	static unsigned int tmp = 0;
	static u32 Y_offset = ADDRESS;
	static u32 backup[YOKAI] = {0};
	if(is_pressed(Y+DU)){
		for(int i = 0;i < YOKAI;i++){
			if(tmp != 1){
				tmp_file = fopen("Backup.tk","wb");
				backup[i] = READU32(Y_offset);
				fwrite(&backup[i],sizeof(u32),1,tmp_file);
			}
			fclose(tmp_file);
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

void	load(void){
	static u32 read[YOKAI] = {0};
	static u32 Y_offset = ADDRESS;
	FILE *file;
	file = fopen("Backup.tk","rb");
	for(int i = 0;i < YOKAI;i++){
		fread(&read[i],sizeof(u32),1,file);
		WRITEU32(Y_offset,read[i]);
		Y_offset += 0xCC;
	}
	Y_offset = ADDRESS;
	fclose(file);
}

void	movement(void){
	
}