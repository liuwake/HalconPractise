# HalconPractise
## Tools
----

# Tools
## Official Tools
### HALCON Variable Inspect (Visual Studio Extension) Halcon变量监视器
- 要求(Hal18.11为准):
  - VS2013-2017,非Express版本
  - 安装.net 4.6(实际开发lang和target版本无关)
  - 开发HALCON/CPP and HALCON/.NET.(其他lang无法监视)
  - 安装有license(eval也可)
- Doc 
  - programmers_guide.pdf P13
  ```
    HALCON Variable Inspect depends on the following components:
     Visual Studio 2013 (Update 5 or higher) through Visual Studio 2017
     .NET 4.6
    Older installations of Visual Studio 2013 might be missing the .NET 4.6 framework. If the installation of HALCON
    Variable Inspect fails with an error, install the .NET 4.6 framework first.
    ```
    - HALCON1811SteadyVariableInspectReadMe(misc文件下README)
    ```
        Installing HALCON Variable Inspect in Visual Studio
    ====================================================

    HALCON includes an extension for the inspection of HALCON variables in
    Visual Studio 2013 or higher. Please note that the extension is 
    provided only for the inspection of iconic objects and tuples 
    in HALCON/CPP and HALCON/.NET. Furthermore, Visual Studio Express
    does not support extensions. The extension needs to be registered
    once for your Visual Studio installation by double-clicking the file 
    'HALCON<version><edition>VariableInspect.vsix' in this directory.

    If multiple versions of Visual Studio are installed on your machine, the
    installer will let you select the version(s) you wish to add the extension to.
    Once installed, the extension should appear in the side pane of Visual Studio.
    If it does not, select 'Tools -> HALCON <version> <edition> Variable Inspect'.
    Please note that the environment variable HALCONROOT must be set for the
    extension to work.

    The HALCON Variable Inspect uses the third-party DLL wow64ext.dll.
    This DLL could be replaced with a copy of your own wow64ext.dll.
    Before doing this, all Visual Studio applications should be closed.

    Please refer to the Programmer's Guide for more information about the
    extension.


    Removing HALCON Variable Inspect from Visual Studio
    ======================================================

    To remove the extension from Visual Studio follow these steps:

    - Open Visual Studio.
    - Select 'Tools -> Extensions and Updates...'.
    - Look for 'HALCON <version> <edition> Variable Inspect' in the list of installed extensions and
    select 'Uninstall'.
    ```
- 注意:
  - ***生效仅在调试模式暂停时(设断点或者手动暂停)***

- Problem
  - *???HalCsConsole at .NET 3.5下图像inspect中一片黑,其他正常*
- Ref
  - [[资料] Halcon12、13新特性之VS可视化调试插件](https://www.51halcon.com/forum.php?mod=viewthread&tid=722&extra=&page=1)



## TODO

- [ ] xx
  - [ ] x

