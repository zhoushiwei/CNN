#include "channel_3.h"

using namespace cv;
using namespace std;

Mat
parallel3(func f, const Mat &M){
    vector<Mat> M_3;
    split(M, M_3);
    vector<Mat> res;
    Mat dst = Mat::zeros(M.rows, M.cols, CV_64FC3);
    for(int i = 0; i < 3; i++){
        res.push_back(f(M_3[i]));
    }
    merge(res, dst);
    M_3.clear();
    res.clear();
    return dst;
}

Mat
parallel3(func2 f, const Mat &M1, const Mat &M2){
    vector<Mat> M1_3;
    vector<Mat> M2_3;
    split(M1, M1_3);
    split(M2, M2_3);
    vector<Mat> res;
    Mat dst;
    for(int i = 0; i < M1_3.size(); i++){
        res.push_back(f(M1_3[i], M2_3[i]));
    }
    merge(res, dst);
    M1_3.clear();
    M2_3.clear();
    res.clear();
    return dst;
}

Mat
parallel3(func3 f, const Mat &M1, const Mat &M2, int a){
    vector<Mat> M1_3;
    vector<Mat> M2_3;
    if(M1.channels() == 3) split(M1, M1_3);
    else{for(int i = 0; i < 3; i++) M1_3.push_back(M1);}
    if(M2.channels() == 3) split(M2, M2_3);
    else{for(int i = 0; i < 3; i++) M2_3.push_back(M2);}
    vector<Mat> res;
    Mat dst;
    for(int i = 0; i < 3; i++){
        res.push_back(f(M1_3[i], M2_3[i], a));
    }
    merge(res, dst);
    M1_3.clear();
    M2_3.clear();
    res.clear();
    return dst;
}

Mat
parallel3(func4 f, const Mat &M, int a){
    vector<Mat> M_3;
    split(M, M_3);
    vector<Mat> res;
    Mat dst = Mat::zeros(M.rows, M.cols, CV_64FC3);
    for(int i = 0; i < M_3.size(); i++){
        res.push_back(f(M_3[i], a));
    }
    merge(res, dst);
    M_3.clear();
    res.clear();
    return dst;
}

Mat
parallel3(func5 f, const Mat &M1, const Mat &M2, int a, int b, int c){
    vector<Mat> M1_3;
    vector<Mat> M2_3;
    if(M1.channels() == 3) split(M1, M1_3);
    else{for(int i = 0; i < 3; i++) M1_3.push_back(M1);}
    if(M2.channels() == 3) split(M2, M2_3);
    else{for(int i = 0; i < 3; i++) M2_3.push_back(M2);}
    vector<Mat> res;
    Mat dst;
    for(int i = 0; i < 3; i++){
        res.push_back(f(M1_3[i], M2_3[i], a, b, c));
    }
    merge(res, dst);
    M1_3.clear();
    M2_3.clear();
    res.clear();
    return dst;
}

Mat
parallel3(func6 f, const Mat &M, int a, int b){
    vector<Mat> M_3;
    split(M, M_3);
    vector<Mat> res;
    Mat dst = Mat::zeros(M.rows, M.cols, CV_64FC3);
    for(int i = 0; i < M_3.size(); i++){
        res.push_back(f(M_3[i], a, b));
    }
    merge(res, dst);
    M_3.clear();
    res.clear();
    return dst;
}

