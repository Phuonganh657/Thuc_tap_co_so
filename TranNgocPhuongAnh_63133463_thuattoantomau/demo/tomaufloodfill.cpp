#include<winbgim.h>
#include<stdio.h>
#include<math.h>
#define maxdinh 20
#define INPUT "scanline.txt"

//khai bao bien
int a[maxdinh][2];//toa do cac dinh cua da giac
int sodinh;//so dinh cua da giac
FILE *fp;//con tro tap tin fp
int i;
int xc, yc;

void nhapdagiac(){
	fp=fopen(INPUT,"r");//mo tap tin de doc
	if(fp==NULL){
		printf("File not found");
	}
	fscanf(fp,"%d",&sodinh);
	printf("So dinh cua da giac: %d",sodinh);
	//doc cac dinh cua da giac
	for(int i=0;i<sodinh;i++){
		for(int j=0;j<2;j++){
			fscanf(fp,"%d",&a[i][j]);	
		}
	}
	//them 1 dinh thu 4 == dinh thu 0
	a[sodinh][0]=a[0][0];//x[n] = x[0]
	a[sodinh][1]=a[0][1];//y[n] = y[0]
	//in ra cac dinh cua da giac
	printf("\nToa do cac dinh cua da giac: \n");
	for(int i=0; i<sodinh; i++){
		for(int j=0;j<2;j++){
			printf("%10d",a[i][j]);
		}
		printf("\n");
	}
	fclose(fp);
	//xac dinh diem ban dau thuoc ben trong da giac
			printf("Toa do diem ben trong da giac:\n");
	  printf("xc = ");
	  scanf("%d",&xc);
	  printf("yc = ");
	  scanf("%d",&yc);
}
	
void vedagiac()
{
	  setcolor(4);
	  for(i=0;i<sodinh;i++)
	  {
	  	  line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
			}
}

//to mau ben phai
void FillRight(int xa, int ya)
{
			
	  if(getpixel(xa,ya) == 0) //mau nen la mau den (BLACK) nen ham getpixel tra ve gia tri la 0
	  {
	  	  putpixel(xa,ya,2);
	  	  //delay(2);
						//to mau het ve phia ben phai
	  	  FillRight(++xa,ya);
	  	  
	  	  xa--;
	  	  
						//to mau tu diem ke bien den tan cung ben duoi
	  	  FillRight(xa,ya+1);
	  	  
	  	  //to mau tu diem ke bien den tan cung ben tren
	  	  FillRight(xa,ya-1);
			}
		
}

//to mau ben trai
void FillLeft(int xa, int ya)
{ 
			
	  if(getpixel(xa,ya) == 0) //mau nen la mau den (BLACK) nen ham getpixel tra ve gia tri la 0
	  {
	  	  putpixel(xa,ya,2);
	  	  //delay(2);
						//to mau het ve phia ben trai
	  	  FillLeft(--xa,ya);
	  	  
	  	  xa++;
	  	  
						//to mau tu diem ke bien den tan cung ben duoi
	  	  FillLeft(xa,ya+1);
	  	  
	  	  //to mau tu diem ke bien den tan cung ben tren
	  	  FillLeft(xa,ya-1);
			}
		
}

//to mau da giac
void FloodFill()
{ 
  FillRight(xc,yc);
	 FillLeft(xc-1,yc);
}

//chuong trinh chinh
int main()
{
	  //nhap thong tin da giac
	  nhapdagiac();
	  
	  initwindow(600,600);
	  
	  //ve da giac
	  vedagiac();
	  
	  //to mau
	  FloodFill();
	  
	  getch();
	  //10 dinh
	  //(75,250),(210,250),(250,128),(291,250),(425,250)
	  //(318,331),(360,460),(249,380),(140,460),(182,331)
	  
}
