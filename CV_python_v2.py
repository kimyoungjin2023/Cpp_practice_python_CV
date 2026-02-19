import cv2
import numpy as np
import time

cap = cv2.VideoCapture(0)

# 해상도 강제 지정 (웹캠 오류 방지용)
cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)

if not cap.isOpened():
    print("웹캠 열기 실패")
    exit()

prev_time = time.time()

while True:
    ret, frame = cap.read()

    if not ret or frame is None:
        print("프레임 읽기 실패")
        continue   # break 말고 continue (중요)

    # =====================
    # FPS 계산
    # =====================
    current_time = time.time()
    fps = int(1 / (current_time - prev_time))
    prev_time = current_time

    # 1️⃣ 흑백 변환
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    # 2️⃣ 가우시안 블러
    blurImg = cv2.GaussianBlur(gray, (5, 5), 0)

    # 3️⃣ 엣지 검출
    edges = cv2.Canny(blurImg, 50, 150)

    # 4️⃣ 윤곽선 검출
    contours, _ = cv2.findContours(
        edges, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE
    )

    maxArea = 0
    maxContour = None

    for cnt in contours:
        area = cv2.contourArea(cnt)
        if area > maxArea:
            maxArea = area
            maxContour = cnt

    # 5️⃣ 가장 큰 물체 처리
    if maxContour is not None:
        cv2.drawContours(frame, [maxContour], -1, (0, 255, 0), 2)

        M = cv2.moments(maxContour)
        if M["m00"] != 0:
            cx = int(M["m10"] / M["m00"])
            cy = int(M["m01"] / M["m00"])

            cv2.circle(frame, (cx, cy), 5, (0, 0, 255), -1)

            cv2.putText(
                frame,
                f"Area: {int(maxArea)}",
                (cx - 50, cy - 10),
                cv2.FONT_HERSHEY_SIMPLEX,
                0.5,
                (255, 0, 0),
                2
            )

    # FPS 표시
    cv2.putText(
        frame,
        f"FPS: {fps}",
        (10, 30),
        cv2.FONT_HERSHEY_SIMPLEX,
        0.8,
        (0, 255, 255),
        2
    )

    # =====================
    # 화면 출력
    # =====================
    cv2.imshow("Frame (Original + Result)", frame)
    cv2.imshow("Edges", edges)

    key = cv2.waitKey(1)
    if key == 27:  # ESC
        break

cap.release()
cv2.destroyAllWindows()
