#include<opencv2/imgproc.hpp>
#include<opencv2/opencv.hpp>
#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>
#include<iostream>


using namespace std; 
using namespace cv; 


//function to manipulate
void manipulate(Mat &ob,int args)
{
	switch(args)
	{
		case 0:
			for(int i=0; i<ob.rows; i++)
			{
				for(int j=0; j<ob.cols; j++)
				{
					ob.at<float>(i,j) = (float)(i+j+1);
				}
				cout<<endl;
			}
		break;



		case 1:
			for(int i=0; i<ob.rows; i++)
			{
				for(int j=0; j<ob.cols; j++)
				{
					ob.at<Vec2f>(i,j) = { (float)(i+j+1), (float)(i+j+1) };
				}
				cout<<endl;
			}
		break;


		case 2:
			for(int i=0;i<ob.rows;i++)
			{
				for(int j=0; j<ob.cols; j++)
				{
					ob.at<Vec3f>(i,j) = { (float)(i+j+1), (float)(i+j+1), (float)(i+j+1) };
				}
				cout<<endl;
			}
		break;
	}


}


//function to display
void display(Mat &ob,int args)
{
	switch(args)
	{
		case 0:
			for(int i=0; i<ob.rows; i++)
			{
				for(int j=0; j<ob.cols; j++)
				{
					cout << ob.at<Vec<float,1>>(i,j) << " ";
				}
				cout<<endl;
			}
		break;



		case 1:
			for(int i=0; i<ob.rows; i++)
			{
				for(int j=0; j<ob.cols; j++)
				{
					cout << ob.at<Vec2f>(i,j) << " ";
				}
				cout<<endl;
			}
		break;


		case 2:
			for(int i=0; i<ob.rows; i++)
			{
				for(int j=0; j<ob.cols; j++)
				{
					cout << ob.at<Vec3f>(i,j) << " ";
				}
				cout<<endl;
			}
		break;


		default : 
			cout << "Invalid args" << endl;
	
	}

}


int main()
{
	Scalar _mean; 
	Mat src;
	src = Mat(2,5,CV_32FC3,Scalar(3,2,1));

	manipulate(src,2);
	display(src,2);

	_mean = mean(src);
	cout << endl;
	cout << _mean << endl; 
	cout << endl; 


	return 0;
}

