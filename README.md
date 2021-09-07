# SnackProject
贪吃蛇(C++版本)
1.clone 地址;
2.下载7zip文件！


# 基本功能(已经实现)
 #####    1.实现一个能在屏幕任何位置输出字符串的函数；
 #####    2.实现一个受控制的自由移动的小点；
 #####    3.实现一个自动移动的小点(需要进行时间控制，不然太快了看不到);
 #####    4.给这个小点设置一个障碍物，当小点移动到边界或触碰到自身的躯体时能够让游戏结束；
 #####    5.吃到食物后能够让身体增长；

# 进阶功能
## · 01 : 光标闪动； （以实现，调用api实现）
```cpp


    //系统头文件
    system("title 贪吃蛇快跑");
    system("mode con cols=120 line=50");
    
    //切换中英文

    void ShowCursor(bool isShow) {
    //封装一个可以在控制台输出字符的函数
	HANDLE hOutStd = GetStdHandle(STD_OUTPUT_HANDLE);			
    //控制台光标信息结构类型
	CONSOLE_CURSOR_INFO cci;									
    //光标大小
	cci.dwSize = 1;												
    //是否显示光标
	cci.bVisible = isShow;										
    //设置控制台光标大小和可见性
	SetConsoleCursorInfo(hOutStd,&cci);							
}

```
##	· 02 : 显示地图，冰面效果； 

```cpp
    老师提供的思路如下->

现在的问题是怎么显示地图，怎样才能正常显示地图；
void Mouseloop()
{
  // 获取到当前输出缓冲区的标识，有了标识就知道要操作的是谁了
  HANDLE input = GetStdHandle(STD_INPUT_HANDLE);

  // 定义结构体用于保存接收到的事件信息
  DWORD count = 0;
  INPUT_RECORD input_record = { 0 };

  // 设置控制台的模式，允许控制台接收鼠标事件
  DWORD mode = 0;
  GetConsoleMode(input, &mode);            // 先获取原有模式
  SetConsoleMode(input, mode | ENABLE_MOUSE_INPUT | ENABLE_WINDOW_INPUT);  // 在原有基础上增加鼠标事件

  COORD tempWall;
  // 1. 读取哪一个控制台缓冲区接收到的事件信息
  // 2. 保存输入事件信息的结构体
  // 3. 参数二传入的缓冲区保存了几个结构体
  // 4. 传入给函数，返回当前接收到的事件的个数
  Writechar({ 7, 36 }, WHITE_COLOR, "绘图结束后按任意键开始游戏");
  Writechar({ 8, 36 }, WHITE_COLOR, "关闭编辑模式重新启动才能绘图");
  while (ReadConsoleInput(input, &input_record, 1, &count))
  {
    // 如果接收不到鼠标事件，可能是下面的两个原因
    //  1. 设置控制台的属性: 控制台标题右键设置属性，取消选中的快速选择模式
    //  2. 设置控制台的模式: 允许控制台接收到鼠标的事件信息(点击、移动等)
    if (input_record.EventType == KEY_EVENT)
    {
      KEY_EVENT_RECORD ker = input_record.Event.KeyEvent;
      if (ker.bKeyDown)
        break;


    }
    // 如果接收到了鼠标事件，就输出相应的内容
    if (input_record.EventType == MOUSE_EVENT)
    {
      auto mosue_event = input_record.Event.MouseEvent;

      // 无论是什么鼠标事件，都输出鼠标的坐标
      auto point = mosue_event.dwMousePosition;
      /*char buffer[0x20] = { 0 };
      sprintf_s(buffer, 0x20, "(%02hd, %02hd)", point.X, point.Y);
      Writechar({ 0, 0 }, WHITE_COLOR, buffer);*/

      // 捕获到鼠标的左键点击事件
      if (mosue_event.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
      {
        // 输出函数的坐标已经经过了转换，但是当前我们得到的坐标是控制台坐标
        Writechar({ point.Y, point.X / 2 }, WHITE_COLOR, "■");
        tempWall.X = point.Y;
        tempWall.Y = point.X / 2;
        g_wall.push_back(tempWall);
      }
      // 假设按下了鼠标右键就擦除
      else if (mosue_event.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
      {
        Writechar({ point.Y, point.X / 2 }, WHITE_COLOR, "  ");
      }
    }
  }
}    

```

##	· 03 : 吃东西加速； 
	吃了东西怎么加速，控制变量加速然后 直接加速就可以了；

##	· 04 : 暂停，撞到自己； 

##	· 05 : 界面计分功能； 

##	· 06 : 界面细节； 

##	· 07 : 背景音乐；

--------------------------

## 常见问题

###### Q:贪吃蛇地图如何实现功能？
     	
      A~~~~ :-> 实现方案有哪些- > WriteChar 获取障碍物信息 
               1.画一下地图，然后在去使用其他字符；
      B~~~~ :-> 障碍物，创建食物

###### Q:大概功能如何实现?
      A~~~~ :-> 部分基础功能的实现细节：
         0.1 设置控制台的大小和标题-> 使用命令设置列宽[cols] 和 行宽[lines],此方法简单快捷

         ~~~~~ 1. system("title xxx");设置控制台的标题;
         ~~~~~ 2. system("mode con cols = 120 lines = 50"); //设置此控制台的宽度和高度;

         0.2 启动时中文输入法问题
          打开控制台时，往往默认为中文输入法，按键会被输入法先捕获，可以模拟按键SHIFT来修改输入法为英文状态！
         ~~~~~ keybd_event(VK_SHIFT,0,0,0); //使用shift是否会被监听掉，会做些什么操作？
         ~~~~~ sleep(100);
         ~~~~~ ketbd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);//键盘按下抬起，事件处理；
###### Q:实现地图的思路，怎么实现地图功能？
       A~~~~:->  1.查看源码分析思路；
       B~~~~:->  2.项目实战分析源码设计思路；




