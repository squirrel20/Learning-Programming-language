/**
  * 20171229
  */

package test.local


trait Logged {
    def log(msg: String) { }
}

trait ConsoleLogger extends Logged {
    override def log(msg: String): Unit = println(msg)
}

trait TimestampLogger extends Logged {
    override def log(msg: String): Unit = {
        super.log(new java.util.Date() + " " + msg)
    }
}

trait ShortLogger extends Logged {
    // 特质中具体的字段
    val maxLength = 15

    override def log(msg: String): Unit = {
        super.log(
            if (msg.length <= maxLength) msg else msg.substring(0, maxLength - 3) + "..."
        )
    }
}

class Accout { }

class SavingsAccount extends Accout with Logged {
    def withdraw(): Unit = {
        log("Insufficient funds")
    }
}

object Test {
    def main(args: Array[String]): Unit = {
        println("hello")
        logTest()
    }

    def logTest(): Unit = {
        // acct1 先执行ShortLogger打印日志，就已经阶截断了，然后TimetampLogger再加上了日期信息
        val acct1 = new SavingsAccount with ConsoleLogger with TimestampLogger with ShortLogger
        val acct2 = new SavingsAccount with ConsoleLogger with ShortLogger with TimestampLogger
        acct1.withdraw()
        acct2.withdraw()
    }
}
