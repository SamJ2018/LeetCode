#### 一、tmux ####

1. 运行tmux：

```shell
[root@ames ~]# tmux
```

2. ==新建会话==： ()

```shell
tmux  new  -s  SESSION-NAME
```

单独运行tmux命令，即开启一个tmux会话 ; 

==不能在tmux会话里面再新建会话，会报错："sessions should be nested with care, unset $TMUX to force"==

3. ==查看已创建的会话==：

```shell
[root@ames ~]# tmux ls
```

4. 进入一个已知会话：

```shell
 # tmux  a  -t SESSION-NAME  
 # tmux  attach  -t  SESSION-NAME
```

5. 暂时离开当前会话：

   (  该命令会从当前会话中退出去, 因此才会有稍后重新接入会话这么一说 )

```shell
[root@ames ~]# tmux detach
```

6. 关闭会话：( 在会话内部或外部执行均可)

```shell
# tmux kill-session -t  SESSION-NAME
```

**==水平分屏==**

快捷键：先按 ctrl+b, 放开后再按%

**垂直分屏**

快捷键：先按 ctrl+b, 放开后再按 "

==**在当前窗口的基础上再打开一个新的窗口** ==

快捷键：先按ctrl+b, 放开后再按c

**终止一个终端窗口(需确认)** 

快捷键：exit 或 先按ctrl+b, 放开后再按 &

**查看面板编号** 

快捷键：先按ctrl+b, 放开后再按q

 **终端内显示时间** 

快捷键：先按ctrl+b, 放开后再按t



>control+b //唤起tmux(命令前缀)
>c //创建新窗口
>w //查看所有窗口
>" //横分面板
>% //竖分面板
>, //修改窗口名
>? //查看所有命令,q退出
>q //显示面板号,快速输入面板号可以选择相应面板
>d //挂起当前会话
>s //查看所有会话,q退出
>$ //修改会话名称
>p //切换窗口
>: //命令行模式





