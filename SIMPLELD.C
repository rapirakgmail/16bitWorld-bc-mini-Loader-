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


char far *firstInstrProcessApp;
int loadApp(char *fname)
{
  unsigned  segProcessAppAddr;
  char far *ptrProcessAppAddr;
  int res;
  /*
	allocate memory for app
	unsigned _dos_allocmem(unsigned size, unsigned *segp);
	size ³ The number of 16-byte paragraphs requested
	segp ³ Pointer to a word that will be assigned the

	segment address of the newly allocated block
	On success,
	 _dos_allocmem returns 0
  */
  /*
  unsigned segProcessAppAddr;
  char far *ptrProcessAppAddr;
  int res;
  unsigned int c_ax,c_bx,c_cx,c_dx;
  unsigned int c_si,c_di,c_bp,c_sp;
  unsigned int c_es,c_ds,c_ss;
  void (far *directCall_setBank)(void);
  */
  int appimagesize = getfilesize(fname);
  int num_para      = (appimagesize+15+0x100)/16;
  if(appimagesize <=0 ) {
	printf("\n cannot open file %s" , fname);

  }
  printf("\nallocate memory for app  size = %d paragraph (%d byte)" , num_para,appimagesize);
  res = _dos_allocmem( num_para , &segProcessAppAddr );
  if(res != 0)
  {
	printf("\ncannot allocate memory for run app  error : %d",res);
  }

  printf("\nload app into memory at segment no. : %x", segProcessAppAddr);
  printf("\n\n\n");

  readfile( fname, segProcessAppAddr );

  firstInstrProcessApp = MK_FP(segProcessAppAddr, 0x0100);

  asm  mov bx,word
  asm  mov es,segProcessAppAddr
  asm  mov ds,segProcessAppAddr
  asm  mov ss,segProcessAppAddr
  asm  mov sp,0xFFFE
  asm  mov bp,sp
  asm  jmp dword ptr [cs:firstInstrProcessApp]

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