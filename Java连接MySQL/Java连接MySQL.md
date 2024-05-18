# Java连接MySQL

## 准备工作

##### 1.下载连接驱动 https://dev.mysql.com/downloads/file/?id=527658

##### 2.把.jar文件引入Java工程文件，并作为库

##### 3.创建一个数据库

```sql
-- 创建bank数据库
create database bank;
use bank;
```

## 连接数据库

##### 加载驱动

##### `mysql5` 写法 `com.mysql.jdbc.Driver`;

##### `mysql8`写法`com.mysql.cj.jdbc.Driver`

##### `url`地址一般是`jdbc:mysql://localhost:3306`,后面跟上数据库名

```java
public class TestConnection {
    public static void main(String[] args) {
        //mysql5 写法 com.mysql.jdbc.Driver
        String driver = "com.mysql.cj.jdbc.Driver"; //驱动就是一个类名
        String url = "jdbc:mysql://localhost:3306/bank";
        //用户名
        String user = "root";
        //密码
        String password = "123456";

        try {
            //1.加载驱动
            Class.forName(driver);
            //2.创建连接
            Connection connection = DriverManager.getConnection(url, user, password);
            //检查是否连接成功
            System.out.println("连接成功" + connection);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
```

##### 看见以下输出代表连接成功

![1716023452647](C:\Users\Lucas\Documents\WeChat Files\wxid_rk5o1d9esq9a21\FileStorage\Temp\1716023452647.png)

## 插入数据

#### 数据库创建表

```sql
-- 创建表
create table account(
    accid int primary key auto_increment,
    accname varchar(30),
    password varchar(30),
    balance float,
    state int(1),
    accdata datetime
);
```

#### Java程序

##### 返回的是影响的列数，也就是有几条数据受到影响

##### 记得关闭`connection`和`statement`，后创建的先关闭；先创建的`connection`，后创建的`statement`;先删除`statement.close();`,再删除`connection.close();`

##### `sql`语句如果拿不准可以先在数据库查询控制台验证一下

##### `sql`插入语句本体

```sql
insert into account (accid, accname, password, balance, state, accdate)
values (1,'Lucas','123456',1000,1,now());
```

```java
package cn.guet.demo2;
import java.sql.Connection;
import java.sql.Driver;
import java.sql.DriverManager;
import java.sql.Statement;

/**
 * 目标：记录的插入，入库
 * 准备：先在MySQL创建表
 *
 * 步骤
 * 1.加载驱动
 * 2.创建连接
 * 3.创建statement
 * 4.执行SQL
 * 5.关闭
 */

public class TestInsert {
    public static void main(String[] args) {
        String driver = "com.mysql.cj.jdbc.Driver";
        String url = "jdbc:mysql://localhost:3306/bank";
        String user = "root";
        String password = "123456";

        //1.加载驱动
        try {
            //1.加载驱动
            Class.forName(driver);
            //2.创建连接
            Connection connection = DriverManager.getConnection(url,user,password);
            //3.创建statement
            Statement statement = connection.createStatement();
            //4.执行SQL
            String sql = "insert into account ( accname, password, balance, state, accdate)"+
                    "values ('Tom','45678',2000,0,now())";

            //执行SQL
            int rows = statement.executeUpdate(sql);
            //返回影响的行数
            System.out.println(">>>>rows" + rows);

            //关闭 释放资源
            statement.close();
            connection.close();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

```

## 修改数据

##### 只用修改sql语句就可以了

```java
package cn.guet.demo2;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;

/**
 * DMl:insert update delete 更新操作 --- excuteUpdate()
 * DQL:select               查询操作 --- excuteQuery()
 * Statement
 */

public class Testupdate {
    public static void main(String[] args) {
        String driver = "com.mysql.cj.jdbc.Driver";
        String url = "jdbc:mysql://localhost:3306/bank";
        String user = "root";
        String password = "123456";

        //1.加载驱动
        try {
            //1.加载驱动
            Class.forName(driver);
            //2.创建连接
            Connection connection = DriverManager.getConnection(url,user,password);
            //3.创建statement
            Statement statement = connection.createStatement();
            //4.执行SQL
            String sql = "update account set accname = 'Sam',password = '66666' where accid = 3";

            //执行SQL返回影响的行数
            int rows = statement.executeUpdate(sql);
            System.out.println(">>>>rows" + rows);

            //关闭 释放资源
            statement.close();
            connection.close();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

```

## 删除数据

```java
package cn.guet.demo2;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;

/**
 * 删除操作
 */

public class TestDelete {
    public static void main(String[] args) {
        String driver = "com.mysql.cj.jdbc.Driver";
        String url = "jdbc:mysql://localhost:3306/bank";
        String user = "root";
        String password = "123456";

        //1.加载驱动
        try {
            //1.加载驱动
            Class.forName(driver);
            //2.创建连接
            Connection connection = DriverManager.getConnection(url,user,password);
            //3.创建statement
            Statement statement = connection.createStatement();
            //4.执行SQL
            String sql = "delete from account where accid = 2";

            //执行SQL返回影响的行数
            int rows = statement.executeUpdate(sql);
            System.out.println(">>>>rows" + rows);

            //关闭 释放资源
            statement.close();
            connection.close();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

```

## 查询数据

##### 查询语句是`DQL`语句，不同于此前的`DML`语句

1. DMl:insert update delete    更新操作 --- excuteUpdate()
2. DQL:select              	       查询操作 --- excuteQuery()
##### excuteQuery()返回的是结果集(`ResultSet`)，需要使用`while`读取信息

##### `resultSet.next()`函数是查询下一列是否有数据，如果有数据返回`true`，没有返回`false`; 注意！默认游标指向第一行之前，也就是说从第一行之前开始遍历

##### `resultSet`也要记得关闭

```java
package cn.guet.demo3;

import java.sql.*;

/**
 * 目标：查询账户中所有记录并打印输出
 * 结果类
 */

public class TestSelect {
    public static void main(String[] args) {
        String driver = "com.mysql.cj.jdbc.Driver";
        String url = "jdbc:mysql://localhost:3306/bank";
        String user = "root";
        String password = "123456";

        //1.加载驱动
        try {
            //1.加载驱动
            Class.forName(driver);
            //2.创建连接
            Connection connection = DriverManager.getConnection(url,user,password);
            //3.创建statement
            Statement statement = connection.createStatement();
            //4.执行SQL 返回一个结果集 ResultSet
            String sql = "select * from account";
            ResultSet resultSet = statement.executeQuery(sql);
            //5.遍历result结果集 默认游标指向第一行之前
            while (resultSet.next()) {
                //获取当前游指向的记录数据
                //什么类型的数据用什么类型的变量接收
                int accid= resultSet.getInt(1); //1表示列的位置，从1开始
                String accname = resultSet.getString(2);
                String accpass = resultSet.getString(3);
                Float balance = resultSet.getFloat(4);
                int state= resultSet.getInt(5);
                Date date = resultSet.getDate(6);

                System.out.println(accid + "===" + accname + "===" + accpass + "===" + balance + "===" + state);
            }

            //6.关闭 释放资源
            resultSet.close();
            statement.close();
            connection.close();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

```

##### 运行结果

![1716025006786](C:\Users\Lucas\Documents\WeChat Files\wxid_rk5o1d9esq9a21\FileStorage\Temp\1716025006786.png)



