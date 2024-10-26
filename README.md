# AIATL2024
By: Keshav Anand and Lavanya Natarajan

# CV Model

## Download yolo-v9 Models:

[`yolov9-c.pt`](https://github.com/WongKinYiu/yolov9/releases/download/v0.1/yolov9-c.pt) [`yolov9-e.pt`](https://github.com/WongKinYiu/yolov9/releases/download/v0.1/yolov9-e.pt) [`gelan-c.pt`](https://github.com/WongKinYiu/yolov9/releases/download/v0.1/gelan-c.pt) [`gelan-e.pt`](https://github.com/WongKinYiu/yolov9/releases/download/v0.1/gelan-e.pt)

## Run Models:

``` shell
# run yolov9 (gelan-c) code for video
python detect.py --weights gelan-c.pt --source 0 --view-img

# run yolov9 (gelan-e) code for video
python detect.py --weights gelan-e.pt --source 0 --view-img

```
