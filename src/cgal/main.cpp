#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/convex_hull_2.h>
#include <iostream>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace std;
using namespace cv;
typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 Point_2;
typedef std::vector<Point_2> Points;//Points是二维数组
int main()
{
  Points points, result;
  points.push_back(Point_2(10,0));
  points.push_back(Point_2(40,40));
  points.push_back(Point_2(110,10));
  points.push_back(Point_2(60,50));
  points.push_back(Point_2(60,30));


  CGAL::convex_hull_2( points.begin(), points.end(), std::back_inserter(result) );
  for(int i=0;i<result.size();++i)
  {
      printf("x:%g,y:%g\n",result[i][0],result[i][1]);
  }
  std::cout << result.size() << " points on the convex hull" << std::endl;
  Mat img=Mat::ones(Size(200,100),CV_8UC3);
  for(int i=0;i<points.size();i++)
  {
      cv::circle(img,Point(points[i][0],points[i][1]),0.5,Scalar(0,0,255),0.5,8,0);
  }
  for(int i=0;i<result.size();++i)
  {
      if(i==result.size()-1)
      {
          int j=result.size()-1;
          cv::line(img,Point(result[0][0],result[0][1]),Point(result[j][0],result[j][1]),Scalar(255,0,255),1,8,0);
          break;
      }
      else
      {
          cv::line(img,Point(result[i][0],result[i][1]),Point(result[i+1][0],result[i+1][1]),Scalar(255,0,255),1,8,0);
      }
  }
  cv::namedWindow("img",WINDOW_NORMAL);
  cv::imshow("img",img);
  cv::waitKey(0);
  return 0;
}
