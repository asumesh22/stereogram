#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <time.h>
#include <iostream>
using namespace std ;
using namespace cv  ;
int main( int argc , char* argv[] )
{
    Mat teapot, img(480, 640, CV_8UC3, Scalar(255,255,255));
    teapot = imread("teapot.pbm", IMREAD_UNCHANGED);
    int ind = 0;
    uchar* pt;
    int val;
    RNG rng(1617620);
    
    for (int i = 0; i<4; i++) {
        for (int row = 0; row < img.rows; row++) {
            for (int col = 0; col < img.cols/4; col++) {
                if (i==0) {
                    unsigned int x = rng . next() ;
                    double y = x * 255.0 / UINT_MAX ;
                    
                    img.at<Vec3b>(Point(col+160*i, row)) = {(int)y,(int)y,(int)y};
                } else {
                    if(teapot.at<uchar>(Point(col+160*(i-1), row))==0){
                        img.at<Vec3b>(Point(col+160*(i), row)) = img.at<Vec3b>(Point(col+160*(i-1)+5, row));
                    } else {
                        img.at<Vec3b>(Point(col+160*(i), row)) = img.at<Vec3b>(Point(col+160*(i-1), row));
                    }
                }
            }
        }
    }
    
    Point2d p1(160,0) , p2(160,480) ;
    Point2d p3(320,0), p4(320,480) ;
    Point2d p5(480,0), p6(480,480) ;
    
    //line( img , p1 , p2 , Scalar(0,0,255) , 2 , LINE_AA ) ;
    //line( img , p3 , p4 , Scalar(0,0,255) , 2 , LINE_AA ) ;
    //line( img , p5 , p6 , Scalar(0,0,255) , 2 , LINE_AA ) ;

    imwrite("stereogram.jpg", img);
    
    return 0 ;
}
//
// end
//
