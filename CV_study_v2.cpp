#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    VideoCapture cap(0);

    // ✅ 해상도 강제 설정 (Galaxy Book 2 Pro 대응)
    cap.set(CAP_PROP_FRAME_WIDTH, 640);
    cap.set(CAP_PROP_FRAME_HEIGHT, 480);
    cap.set(CAP_PROP_FPS, 30);

    if (!cap.isOpened()) {
        cout << "웹캠 열기 실패" << endl;
        return -1;
    }

    // ✅ 실제 적용된 해상도 확인
    cout << "해상도: "
         << cap.get(CAP_PROP_FRAME_WIDTH) << " x "
         << cap.get(CAP_PROP_FRAME_HEIGHT) << endl;

    Mat frame, gray, blurImg, edges;
    vector<vector<Point>> contours;

    while (true) {
        cap.read(frame);

        // ❗ break ❌ → continue ⭕
        if (frame.empty()) {
            cout << "프레임 없음" << endl;
            continue;
        }

        // 🔹 원본 프레임 먼저 출력 (디버깅용)
        imshow("Raw Frame", frame);

        // 1️⃣ 흑백 변환
        cvtColor(frame, gray, COLOR_BGR2GRAY);

        // 2️⃣ 가우시안 블러
        GaussianBlur(gray, blurImg, Size(5, 5), 0);

        // 3️⃣ 엣지 검출
        Canny(blurImg, edges, 50, 150);

        // 4️⃣ 윤곽선 검출
        findContours(edges, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

        // 가장 큰 윤곽선 찾기
        double maxArea = 0.0;
        int maxIdx = -1;

        for (int i = 0; i < contours.size(); i++) {
            double area = contourArea(contours[i]);
            if (area > maxArea) {
                maxArea = area;
                maxIdx = i;
            }
        }

        // 5️⃣ 가장 큰 물체 처리
        if (maxIdx >= 0) {
            drawContours(frame, contours, maxIdx, Scalar(0, 255, 0), 2);

            Moments m = moments(contours[maxIdx]);
            if (m.m00 != 0) {
                int cx = int(m.m10 / m.m00);
                int cy = int(m.m01 / m.m00);

                circle(frame, Point(cx, cy), 5, Scalar(0, 0, 255), -1);

                putText(frame,
                    "Area: " + to_string((int)maxArea),
                    Point(cx - 40, cy - 10),
                    FONT_HERSHEY_SIMPLEX,
                    0.5,
                    Scalar(255, 0, 0),
                    2);
            }
        }

        // ✅ 결과 출력
        imshow("Processed Frame", frame);
        imshow("Edges", edges);

        // ESC 종료
        if (waitKey(1) == 27) break;
    }

    cap.release();
    destroyAllWindows();
    return 0;
}
