#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        printf("웹캠 열기 실패\n");
        return -1;
    }

    Mat frame, gray, blurImg, edges;
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    // ✅ FPS 계산용 변수 추가
    double prevTime = (double)getTickCount();
    double fps = 0.0;

    while (true) {
        cap >> frame;
        if (frame.empty()) break;

        // =====================
        // FPS 계산
        // =====================
        double currentTime = (double)getTickCount();
        fps = getTickFrequency() / (currentTime - prevTime);
        prevTime = currentTime;

        // 1️⃣ 흑백 변환
        cvtColor(frame, gray, COLOR_BGR2GRAY);

        // 2️⃣ 가우시안 블러
        GaussianBlur(gray, blurImg, Size(5, 5), 0);

        // 3️⃣ 엣지 검출
        Canny(blurImg, edges, 50, 150);

        // 4️⃣ 윤곽선 찾기
        findContours(edges, contours, hierarchy,
                     RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

        double maxArea = 0;
        int maxIdx = -1;

        for (int i = 0; i < contours.size(); i++) {
            double area = contourArea(contours[i]);
            if (area > maxArea) {
                maxArea = area;
                maxIdx = i;
            }
        }

        if (maxIdx >= 0) {
            drawContours(frame, contours, maxIdx, Scalar(0, 255, 0), 2);

            Moments m = moments(contours[maxIdx]);
            if (m.m00 != 0) {
                int cx = int(m.m10 / m.m00);
                int cy = int(m.m01 / m.m00);

                circle(frame, Point(cx, cy), 5, Scalar(0, 0, 255), -1);

                putText(frame,
                    "Area: " + to_string((int)maxArea),
                    Point(cx - 50, cy - 10),
                    FONT_HERSHEY_SIMPLEX,
                    0.5,
                    Scalar(255, 0, 0),
                    2);
            }
        }

        // ✅ FPS 화면 출력 (⭐ 핵심)
        putText(frame,
            "FPS: " + to_string((int)fps),
            Point(10, 30),
            FONT_HERSHEY_SIMPLEX,
            0.8,
            Scalar(0, 255, 255),
            2);

        imshow("Original", frame);
        imshow("Edges", edges);

        if (waitKey(1) == 27) break;
    }

    return 0;
}
