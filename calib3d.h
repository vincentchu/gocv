#ifndef _OPENCV3_CALIB_H_
#define _OPENCV3_CALIB_H_

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
#include <opencv2/calib3d.hpp>


extern "C" {
#endif

#include "core.h"

//Calib
void Fisheye_UndistortImage(Mat distorted, Mat undistorted, Mat k, Mat d);
void Fisheye_UndistortImageWithParams(Mat distorted, Mat undistorted, Mat k, Mat d, Mat knew, Size size);
Mat FindEssentialMatrix(Mat points1, Mat points2, double focalLen, Point ppPt, int method, double prob, double threshold, Mat mask);

#ifdef __cplusplus
}
#endif

#endif //_OPENCV3_CALIB_H
