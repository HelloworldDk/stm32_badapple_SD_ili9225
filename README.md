# stm32_badapple_SD_ili9225
A project to play badapple video on stm32f103c8t6 with ili9225 tft and sd card

# 如何使用 How to use

1. 安装Python3
2. 安装cv2
```
pip3 install opencv-python
```
3. 下载badapple视频，命名为  19fps.mp4 放在 to_pic.mp4 同目录，运行
```
python3 to_pic.py
```
得到images/xxxxx.bmp   
~~文件名是因为我直接拷的我本地文件，可以自己改改~~  
4. 安装 Image2LCD 打开00000.bmp，输出类型 二进制bin ，扫描方式 水平扫描 ，输出灰度 单色，最大宽高 160x120 ，下方五个都不选，点击顶上的批量转换，等待完成，中途未响应是正常现象。  
5. 已经得到images/batch/xxxxx.bin，在此目录下执行
```
copy  /b  *.bin  vb2.bin
```
获得已经组合好的bi 
6. 拷贝 vb2.bin 到sd卡  
7. 安装Arduino IDE 安装库 [TFT_22_ILI9225](https://github.com/Nkawu/TFT_22_ILI9225) (库管理器里安装即可) ,安装开发板 [stm32duino 的这一版](https://github.com/rogerclarkmelbourne/Arduino_STM32)
8. 打开fps32.ino，选中开发板STM32F103C ，频率超频128Mhz，下载到stm32板子上  
9. ili9225 2.2寸 tft和sd卡全部连接到stm32的spi1，屏的片选连接在PA0,sd卡片选在PB6,上电运行即可


