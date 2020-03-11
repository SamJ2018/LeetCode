# 1. oracle简介和安装

### 1.1.1. 常见的问题
-    登录问题
    1. 远程客户端登录命令
        sqlplus 账号/密码@//192.168.31.130/orcl
    2. ORA-28000: the account is locked
        user scott account unlock;
        commit;

    3. oracle账户
      - 账户一：
              scott
              tiger
              normal
      -  账户二：
              system
              orcl
              normal
    
      -  账户三：
              sys
              orcl
              sysdba

3、配置
>C:\app\missb\product\11.2.0\client_1\network\admin\tnsnames.ora

```xml
LISTENER_ORCL=
     (ADDRESS = (PROTOCOL = TCP)(HOST = 192.168.31.130)(PORT = 1521))
  
ORCL =
     (DESCRIPTION =
       (ADDRESS = (PROTOCOL = TCP)(HOST = 192.168.31.130)(PORT = 1521))
      (CONNECT_DATA =
        (SERVER = DEDICATED)
        (SERVICE_NAME = orcl)
      )
    )
```



```c++
#include <iostream>
using namespace std;

class Person{
    
};

int main(int agrc,char* argv[])
{
    cout << "hello world\n";
    return 0;
}
```

