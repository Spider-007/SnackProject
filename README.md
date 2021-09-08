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
##	· 02 : 显示地图，冰面效果； （自定义地图已经实现，暂不考虑，后期优化）

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

```cpp

    使用sleep实现效果！
    控制蛇的移动；speed是控制速度，设置模式可以控制速度，所以是入口地方需要处理一下；

```

##	· 04 : 暂停，撞到自己； 

```cpp
    判断头和尾部来处理
```


##	· 05 : 界面计分功能； 
 
```
 界面计分->吃到食物增加分数，仅此而已！
```

##	· 06 : 界面细节； 

```cpp
    界面颜色，欢迎界面以及游戏选项界面,右侧小地图，gameOver界面优化！
```

##	· 07 : 背景音乐；

```cpp
		PlaySoundA(file, NULL, SND_ASYNC | SND_NODEFAULT);
```
--------------------------

## 常见问题

###### Q:贪吃蛇地图功能如何实现？
     	
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

###### Q:自定义地图应该怎么才能显示出来，自定义地图使用的是什么功能实现的？

        A~~~:-> 1.判断键盘和鼠标事件，然后调用windows.h api，给数组赋值；
        B~~~:-> 2.赋值之后，把元素WriteChar出来，注意下标/2；

###### Q:界面显示颜色为什么是全屏显示，而不是字符显示？
        
       A~~~:->全屏显示说明是代码的问题，不是界面设置的问题；
       B~~~:->调用背景颜色应该使用SetConsoleTextAttribute函数，设置的变量应该为FOREGROUND开头才可以！

    
###### Q:怎么开始不了游戏了，程序哪里出问题了？

        A~~~~：-> 开始游戏的时候注意颜色设置！ 是否与默认颜色冲突？
        B~~~~: -> 注意调用光标的函数需要写道printf之前，不然可能首行会显示其他颜色；

###### Q:怎么实现右侧小地图?
        A~~~~：->思路使用数组实现，右侧定义vector，添加元素进去，然后可以光标移动也可以获取下标，根据选中下标实现功能；
        B~~~：->右侧小地图实现功能好么？还是只是做一个用户交互的操作，让用户可以看到自己具体的操作即可！

###### Q:右侧小地图别人都是怎么实现的呢？

        A~~~~:-> 输出光标字符，给用户提示；可以上下控制移动即可！

###### Q:计分功能怎么实现，计分是全局变量么？
        

###### Q.蛇一闪一闪的
    
       A~~~~:->蛇越长就越闪动；

###### Q.撞不到自己
    
       A~~~~:->判断数组下标，是否可以撞到自己？

###### Q.食物吃多了就没了
       
       A~~~~:->食物吃多了没有了！

###### Q.键盘回车后没反应，需要再次单机

       A~~~~:->重复显示的问题已修复；已修复重复显示问题！

##### Q:单机功能正常实现，问题是右侧小地图功能怎么才能实现出来？

       A~~~:->显示右侧小地图，提示暂停和计分功能，添加一个时间功能，计时功能；

##### Q:怎么想着设计一下，本来就没有特别大的设计
       A~~~:->提示暂停和计分功能！


##### Q:撞到墙体之后，y继续，n返回，提示重新开始，退出游戏

       A~~~:->y是继续，N是返回


##### Q:怎么控制蛇的分数？

        A~~~~：->定义变量接受蛇的数值，无法实时更新蛇的下标；
