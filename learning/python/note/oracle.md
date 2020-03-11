### oracle 常见问题

#### 登录问题

1. 登录命令

   >  sqlplus 账号/密码@//192.168.31.130/orcl

2. ORA-28000: the account is locked

   >  alter user scott account unlock;
   >  commit;

3. oracle账户

   * 账户一：

     > scott
     > tiger
     > normal

   *  账户二：

     > system
     > orcl
     > normal

   * 账户三：

     > sys
     >
     > orcl
     >
     > sysdba

#### 配置

1. 配置客户端

   > C:\app\missb\product\11.2.0\client_1\network\admin\tnsnames.ora

```json
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

