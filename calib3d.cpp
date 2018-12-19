#include "calib3d.h"


void Fisheye_UndistortImage(Mat distorted, Mat undistorted, Mat k, Mat d) {
    cv::fisheye::undistortImage(*distorted, *undistorted, *k, *d);
}

void Fisheye_UndistortImageWithParams(Mat distorted, Mat undistorted, Mat k, Mat d, Mat knew, Size size) {
    cv::Size sz(size.width, size.height);
    cv::fisheye::undistortImage(*distorted, *undistorted, *k, *d, *knew, sz);
}

Mat FindEssentialMatrix(Mat points1, Mat points2, double focalLen, Point ppPt, int method, double prob, double threshold, Mat mask) {
    cv::Point2d pp(ppPt.x, ppPt.y);
    return new cv::Mat(cv::findEssentialMat(*points1, *points2, focalLen, pp, method, prob, threshold, *mask));
}

void RecoverPose(Mat essentialMat, Mat points1, Mat points2, Mat R, Mat t, double focalLen, Point ppPt, Mat mask) {
    cv::Point2d pp(ppPt.x, ppPt.y);

    cv::recoverPose(*essentialMat, *points1, *points2, *R, *t, focalLen, pp, *mask);
}

