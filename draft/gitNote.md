# Devops   Dev ops 开发、运维

敏捷开发？？    上线发布！

过程规范、协作方式   工具   生产环境

- 怎么吸引用户使用我们的功能？

- 开发需要经常改变，运维为了确保稳定不经常改变，出错了不敢上线
    - 因此Dev 和 ops 有冲突    
        - 软件生命周期
        - 
        
Devops 
-   自动化测试   （码云）
-   持续集成
    - 命令集合在代码中（？）
-   代码质量管理工具
-   程序员鼓励师（? 搞笑的）

#### vcs  'version control system'
-   版本控制作用
    -   记录文件的所有历史变化，可以代码回滚
    -   多人协作

#### git基本命令
    -   git status 查看当前仓库状态
    -   git add <file> 添加文件到暂存区
    -   git add . /  git add * 添加当前所有文件到暂存区
    -   git rm --cached 撤出暂存区
    -   git rm -f 同上，同时删除工作目录和暂存区的文件
    -   git commit -m 从缓存区提交到本地仓库

    -   git mv old-filename new-filename 不会出现delete而是rename信息
    -   git diff 默认比对工作区和暂存区
        -   git diff --cached 比对暂存区和本地仓库

    -   git log -p 详细信息
        -   git log -p -1 只显示一条信息
    

    -   回到原来的快照信息
        -   git reset --hard (hash值)
        -   git relog  查看所有历史操作


### tree .git   查看本地仓库文件
    -   objects 本地仓库   可以通过本地仓库回到快照
    -   index  暂存区   




- 命令总结
*	设置颜色
	* git config --global color.ui true
*	回退上一个版本
	git reset --hard  version_num

















