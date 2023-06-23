#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(){

	Mat m = (Mat_<int>(3,3) << 1,2,3,4,5,6,7,8,9 );
	Mat d0 = m.diag(0);
	Mat d1 = m.diag(1);
	Mat d_1 = m.diag(-1);

	int i,j;

	cout << "Main diagonal" << endl;
	cout << d0 ;
	
	//waitKey(0);

	return 0;
}
