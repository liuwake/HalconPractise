#

## Example
----
## hdevelop

```C:\Users\Public\Documents\MVTec\HALCON-18.11-Steady\examples```

----
## Applications

```C:\Users\Public\Documents\MVTec\HALCON-18.11-Steady\examples\hdevelop\Applications\```

### Bar-Codes
- [x] circular_barcode:圆拉伸变换
  - [x] 轴承变换,识别二维码


### SurfaceInspect
#### 表面
- [x] detect_indent_fft.hdev Detect defects on the surface of plastic items 
  - 在塑料表面检测突起
- [x] detect_mura_defects_blur.hdev
  - [ ] Detect mura defects in blurred images
  - [ ] 在*模糊?*图像中检测不均匀(线状)
- [x] detect_mura_defects_texture.hdev
  - [ ] xx
  - [x] 检测不匀纹理 
####  光度立体学
- [ ] determine_tilt_slant_photometric_stereo.hdev
  - [x] 照圆球光照角度
- [ ] inspect_blister_photometric_stereo.hdev
  - [ ] 光度立体学检测药片锡纸包装起泡(blister)
- [ ] inspect_flooring_photometric_stereo.hdev
  - [ ] 光度立体学检测墙面
- [ ] inspect_flooring_uncalib_photometric_stereo.hdev
  - [ ] 同上,没cali
- [ ] inspect_leather_photometric_stereo.hdev
  - [ ] 皮革
- [ ] inspect_shampoo_label_photometric_stereo.hdev
  - [ ] 洗发水瓶子

### 3D
- check_for_holes_sheet_of_light.hdev
  - 检测孔眼
- compare_surface_sheet_of_light.hdev
  - 用什么方法检测零件??

## Method 方法
### 拼接

- [x] adjust_mosaic_images
  - [ ] 教堂图片弯曲拼接
- [x] blended_mosaic
  - [ ] 教堂图片弯曲拼接,*???啥区别*
- [x] bundle_adjusted_mosaicking
  - [ ] 10张芯片拼成一张*??? 啥区别*
- [x] *gen_projective_mosaic*
  - [ ] 6张PCB拼一张
  

- [x] mosaicking
  - [ ] 10张芯片拼成一张
- [x] inspect_bottle_label_360_degree.hdev 
  - [x] 4张图像恢复瓶身标签带
- [x] mosaicking_pyramid.hdev
  - [x] 两张芯片图像不同金字塔层级拼接,并比较速度.
- [x] proj_match_points_distortion_ransac.hdev
  - [ ] 两张楼房图片成功(失败)拼接
- [ ] proj_match_points_distortion_ransac_guided
  - [x] 两张楼房图片成功拼接 *???guided*
- [x] stationary_camera_self_calibration
  - [ ] *标定*

----
## solution_guide
```C:\Users\Public\Documents\MVTec\HALCON-18.11-Steady\examples\solution_guide```
### 1d_measuring
- [ ] measure_ring
  - [ ] 测量多个螺母的半径
    - [ ] 测试运行,效果测量了一行螺母的半径?




- [ ] Ref
    - [x] [Halcon一日一练：图像拼接技术2:步骤与例程](https://www.cnblogs.com/amosyang/p/8478213.html?utm_source=debugrun&utm_medium=referral) 中文讲解