#include <iostream>
#include <windows.h>
using namespace std;
class Box{
public :
	Box();
	Box(Box &Abox);
	void disp_vol();

private:
	double length;
	double width;
	double height;
	double volume;
};
Box::Box()
{
	cout<<"please input length:";
	cin>>length;
	cout<<"please input width:";
	cin>>width;
	cout<<"please input height:";
	cin>>height;
	volume =length*width*height;

}
Box::Box(Box &Abox)
{
	this->length=Abox.length/2;
	this->height=Abox.height/2;
	this->width=Abox.width/2;
	this->volume =length*width*height;
}
void Box::disp_vol()
{
		volume =length*width*height;
	cout<<"The volume of this box is "<<volume<<endl;
}
void TestBox()
{	Box Abox;
	Abox.disp_vol();
	Box Bbox(Abox);
	Bbox.disp_vol();
	system("pause");
}
int main()
{
	TestBox();
	return 0;
}