#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include <string.h>
#include <dos.h>


int getfilesize(char *fname)
{
	int appimagesize;
	unsigned char *appimage = malloc(1024*20);
	FILE *fp = fopen( fname , "rb");
	if(fp==NULL) {
		printf("\ncannot open file : %s",fname);

		return -1;
	}
	appimagesize = fread(appimage,sizeof(unsigned char),1024*20,fp);
	fclose(fp);
	free(appimage);
	return appimagesize;
}



int readfile(char *fname,unsigned  segProcessAppAddr)
{
	int appimagesize;
	unsigned char far *firstInstrAddr;
	unsigned char *appimage = malloc(1024*20);
	FILE *fp = fopen( fname , "rb");
	if(fp==NULL) {
		printf("\ncannot open file : %s",fname);
		return -1;
	}
	appimagesize = fread(appimage,sizeof(unsigned char),1024*20,fp);
	printf( " \nread app file : %s  (size %d)",fname,appimagesize );
	fclose(fp);

	firstInstrAddr = MK_FP(segProcessAppAddr, 0x0100);
	_fmemcpy( (char far*)firstInstrAddr ,
			  (char far*)appimage,
			  appimagesize);
   free( appimage );
   return 0;
}


int loadApp(char *fname)
{
  unsigned  imageSeg;
  int res;
 
  int appimagesize = getfilesize(fname);
  int num_para      = (appimagesize+15+0x100)/16;
  if(appimagesize <=0 ) {
	printf("\n cannot open file %s" , fname);

  }
  printf("\nallocate memory for app  size = %d paragraph (%d byte)" , num_para,appimagesize);
  res = _dos_allocmem( num_para , &imageSeg );
  if(res != 0)
  {
	printf("\ncannot allocate memory for run app  error : %d",res);
  }

  printf("\nload app into memory at segment no. : %x", imageSeg);
  printf("\n\n\n");

  readfile( fname, imageSeg );

  asm  mov es,imageSeg
  asm  mov ds,imageSeg
  asm  mov ss,imageSeg
  
  asm  mov sp,0xFFFE
  asm  mov bp,sp

  asm  push es   	//cs
  asm  mov ax,100h
  asm  push ax		//ip
  asm  retf			//pop cs , pop ip 

  return 0;
}



int main(int argc,char *argv[])
{
	char fname[256];
	FILE *fp;
	printf("\nstart loadiing app : %s",argv[1]);
	//loadApp( fname);
	loadApp( "app2.com");
	printf( " \nloader  terminate" );
	return 0;
}