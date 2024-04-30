# HalconPractise

## HalconProj

### Localization 
#### Mark

----
# Mark Mark点定位法
## Sum
- 光学定位点(mark点)
- Mark点是使用机器焊接时用于定位的点。

 - 表贴元件的pcb更需要设置Mark点，因为在大批量生产时，贴片机都是操作人员手动或者机器自动寻找Mark点进行校准。极少数不设置Mark点也可以，操作非常麻烦，需要使用几个焊盘或孔作为mark点，这些点不能挂焊锡，效率和精度都会下降。使用过孔当作Mark,误差一般在0.15mm左右 ,**使用标准Mark 偏差小于0.05mm**。
   - 设:相机1200W Pixel(4000Pixel X 3000Pixel),视野物象80MM X 60MM;
     - 此时PixelEquation=80MM/4000Pixel=0.02MM/Pixel;拟合mark点实际误差的max: PixelErrorMax=5Pixel;
     - 亚像素处理后PixelErrorMaxPre=2.5Pixel;
     - 实际RealError=PixelEquation X PixelErrorMaxPre= 0.02MM/Pixel X 2.5Pixel = 0.05MM


## 


## Reference
- 
- [光学定位点（mark点）](https://www.cnblogs.com/darren-pty/p/9357621.html)
- 